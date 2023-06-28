#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitor.hpp"

#include <iostream>

using namespace std;

// Funçoes que iremos utilizar para a leitura dos arquivos

// file reader
// FILE* fopen(const char* filename, const char* mode);

// ----------------- LEITOR DE BYTES -------------------------------- //

// funcoes que retornam u bytes.
// read u1 (8bits) getc -> return e fd++
u1 u1Read(FILE *fd)
{
    u1 toReturn = getc(fd);
    return toReturn;
};
// read u2 (16bits)
u2 u2Read(FILE *fd)
{
    u2 toReturn = getc(fd);
    toReturn = (toReturn << 8 | getc(fd));
    return toReturn;
};
// read u4 (32bits)
u4 u4Read(FILE *fd)
{
    u4 toReturn = getc(fd);
    for (int i = 0; i < 3; i++)
    {
        toReturn = (toReturn << 8 | getc(fd));
    }
    return toReturn;
};
// read u8 (64bits)
u8 u8Read(FILE *fd)
{
    u8 toReturn = getc(fd);
    for (int i = 0; i < 7; i++)
    {
        toReturn = (toReturn << 8 | getc(fd));
    }
    return toReturn;
};

// ----------------- CODE EXCEPTION TABLE -------------------------------- //

void read_attribute_code_exception_table(FILE *fd, Exception_table *exception_table, u2 exception_table_length)
{
    for (int i = 0; i < exception_table_length; i++)
    {
        exception_table[i].start_pc = u2Read(fd);
        exception_table[i].end_pc = u2Read(fd);
        exception_table[i].handler_pc = u2Read(fd);
        exception_table[i].catch_type = u2Read(fd);
    };
};

// ----------------- ATTRIBUTE CONSTANT -------------------------------- //

void read_attribute_constant(FILE *fd, Attribute_info *attr_info)
{
    attr_info->attribute_info_union.constantvalue_index = u2Read(fd);
}

// ----------------- ATTRIBUTE CODE -------------------------------- //

void read_attribute_code(FILE *fd, Attribute_info *attr_info, cp_info *cp)
{
    attr_info->attribute_info_union.code_attribute.max_stack = u2Read(fd);
    attr_info->attribute_info_union.code_attribute.max_locals = u2Read(fd);
    attr_info->attribute_info_union.code_attribute.code_length = u4Read(fd);

    // alocar na memória o array de byte/up codes
    attr_info->attribute_info_union.code_attribute.code = (u1 *)malloc(attr_info->attribute_info_union.code_attribute.code_length * sizeof(u1));

    // alocando os bytecodes no code[code_length]
    for (int i = 0; i < attr_info->attribute_info_union.code_attribute.code_length; i++)
    {
        attr_info->attribute_info_union.code_attribute.code[i] = u1Read(fd);
    };

    // alocando tamanho da tabela de excessões
    attr_info->attribute_info_union.code_attribute.exception_table_length = u2Read(fd);

    // alocando espaço para as tabelas de excessão
    attr_info->attribute_info_union.code_attribute.exception_table = (Exception_table *)malloc(attr_info->attribute_info_union.code_attribute.exception_table_length * sizeof(Exception_table));

    // preenchendo -> passar o endereço para array e o seu tamanho
    read_attribute_code_exception_table(fd, attr_info->attribute_info_union.code_attribute.exception_table, attr_info->attribute_info_union.code_attribute.exception_table_length);

    // realizar a leitura dos attributes da função
    attr_info->attribute_info_union.code_attribute.attribute_count = u2Read(fd);

    // alocando espaço para os attributes
    attr_info->attribute_info_union.code_attribute.attributes = (Attribute_info *) malloc(attr_info->attribute_info_union.code_attribute.attribute_count * sizeof(Attribute_info));

    read_attributes(fd, attr_info->attribute_info_union.code_attribute.attributes, attr_info->attribute_info_union.code_attribute.attribute_count, cp);
}

// ----------------- ATTRIBUTE EXCEPTIONS -------------------------------- //

void read_attribute_exceptions(FILE *fd, Attribute_info *attr_info)
{
    attr_info->attribute_info_union.exceptions_attribute.number_of_exceptions = u2Read(fd);
    attr_info->attribute_info_union.exceptions_attribute.exception_index_table = (u2 *)malloc(attr_info->attribute_info_union.exceptions_attribute.number_of_exceptions * sizeof(u2));
    for (int i = 0; i < attr_info->attribute_info_union.exceptions_attribute.number_of_exceptions; i++)
    {
        attr_info->attribute_info_union.exceptions_attribute.exception_index_table[i] = u2Read(fd);
    }
}

// ----------------- ATTRIBUTE INNER CLASSES -------------------------------- //

void read_attribute_innerClasses(FILE *fd, Attribute_info *attr_info)
{
    attr_info->attribute_info_union.innerClasses_attribute.number_of_classes = u2Read(fd);
    attr_info->attribute_info_union.innerClasses_attribute.inner_classes = (inner_classes *)malloc(attr_info->attribute_info_union.innerClasses_attribute.number_of_classes * sizeof(inner_classes));
    
    // lendo o number of classes do innerclass
    for (int i = 0; i < attr_info->attribute_info_union.innerClasses_attribute.number_of_classes; i++)
    {
        attr_info->attribute_info_union.innerClasses_attribute.inner_classes[i].inner_class_info_index = u2Read(fd);
        attr_info->attribute_info_union.innerClasses_attribute.inner_classes[i].outer_class_info_index = u2Read(fd);
        attr_info->attribute_info_union.innerClasses_attribute.inner_classes[i].inner_name_index = u2Read(fd);
        attr_info->attribute_info_union.innerClasses_attribute.inner_classes[i].inner_class_access_flags = u2Read(fd);
    }
}

// ----------------- ATTRIBUTE LINENUMBERTABLE -------------------------------- //

void read_attribute_lineNumberTable(FILE *fd, Attribute_info *attr_info)
{
    attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table_length = u2Read(fd);
    attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table = (line_number_table *)malloc(attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table_length * sizeof(line_number_table));
    for (int i = 0; i < attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table_length; i++)
    {
        attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table[i].start_pc = u2Read(fd);
        attr_info->attribute_info_union.lineNumberTable_attribute.line_number_table[i].line_number = u2Read(fd);
    }
}

// ----------------- ATTRIBUTE LOCALVARIABLETABLE -------------------------------- //

void read_attribute_localVariableTable(FILE *fd, Attribute_info *attr_info)
{
    attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table_length = u2Read(fd);
    attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table = (Local_variable_table *)malloc(attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table_length * sizeof(Local_variable_table));
    for (int i = 0; i < attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table_length; i++)
    {
        attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table[i].start_pc = u2Read(fd);
        attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table[i].length = u2Read(fd);
        attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table[i].name_index = u2Read(fd);
        attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table[i].descriptor_index = u2Read(fd);
        attr_info->attribute_info_union.localVariableTable_attribute.local_variable_table[i].index = u2Read(fd);
    }
}

// aqui já passamos o attribute info em questão
void read_attributes(FILE *fd, Attribute_info *attr_info, u2 attr_count, cp_info *cp)
{
    for (int i = 0; i < attr_count; i++)
    {
        Attribute_info *attr = &attr_info[i];
        
        attr->attribute_name_index = u2Read(fd);

        // The value of the attribute_length item indicates the length of the subsequent information in bytes.  Indica a quantidade de bytes que temos que pular (info util para ignorar os tipos de atributos que não iremos utilizar)
        attr->attribute_length = u4Read(fd);

        // com base nessa variavel iremos escolher o tipo de attribute.
        u2 attribute_name_index = attr->attribute_name_index;
        // u4 attribute_length = attr->attribute_length;

        // agora vamos trabalhar com a union
        char *attribute_name = Utf8_decoder(&cp[attribute_name_index]);

        // aqui o switch não é a solução, não há como utilizar switch com strings
        if (!strcmp(attribute_name, "ConstantValue"))
        {
            read_attribute_constant(fd, attr);
        }
        else if (!strcmp(attribute_name, "Code"))
        {
            //Aposto que o erro é aqui
            read_attribute_code(fd, attr, cp); 
        }
        else if (!strcmp(attribute_name, "Exceptions"))
        {
            read_attribute_exceptions(fd, attr);
        }
        else if (!strcmp(attribute_name, "InnerClasses"))
        {
            read_attribute_innerClasses(fd, attr);
        }
        else if (!strcmp(attribute_name, "LineNumberTable"))
        {
            read_attribute_lineNumberTable(fd, attr);
        }
        else if (!strcmp(attribute_name, "LocalVariableTable"))
        {
            read_attribute_localVariableTable(fd, attr);
        } else
        {
            for (u4 byte = 0; byte < attr_info[i].attribute_length; byte++)
            {
                // ler o fd para pular length bytes para as instruções que não temos!
                u1Read(fd);
            }
        };
    };
};

// ----------------- METHODS -------------------------------- //
void read_methods(FILE *fd, ClassFile *cf)
{

    // alocando dinamicamente os methdos com base no contador
    cf->methods = (Method_info *)malloc(cf->methods_count * sizeof(Method_info));

    // iterar e ir lendo os methods...
    for (int i = 0; i < cf->methods_count; i++)
    {

        cf->methods[i].access_flags = u2Read(fd);

        cf->methods[i].name_index = u2Read(fd);

        cf->methods[i].descriptor_index = u2Read(fd);

        cf->methods[i].attributes_count = u2Read(fd);

        // alocando o espaço para os attributes do field
        cf->methods[i].attributes = (Attribute_info *)malloc(cf->attributes_count * sizeof(Attribute_info));

        // lendo os attributes
        if(cf->methods[i].attributes_count){
            read_attributes(fd, cf->methods[i].attributes, cf->methods[i].attributes_count, cf->constant_pool);
        };
    };
};

// ----------------- FIELDS -------------------------------- //
// represent all fields, both class variables and instance variables

void read_fields(FILE *fd, ClassFile *cf)
{
    // alocando ESPAÇO para o cp_info
    cf->fields = (field_info *)malloc(cf->fields_count * sizeof(field_info));


    // alocar em memória os fields
    for (int i = 0; i < cf->fields_count; i++)
    {
        // lendo flags
        cf->fields[i].access_flags = u2Read(fd);

        // lendo name_index
        cf->fields[i].name_index = u2Read(fd);

        // lendo descriptor_index
        cf->fields[i].descriptor_index = u2Read(fd);

        // lendo attributes_count
        cf->fields[i].attributes_count = u2Read(fd);
        // debug count:
        // printf("%d\n",cf->fields[i].attributes_count);

        // alocando o espaço para os attributes do field
        cf->fields[i].attributes = (Attribute_info *)malloc(cf->fields[i].attributes_count * sizeof(Attribute_info));
        // printf("attr_count: %d \n", cf->fields[i].attributes_count);

        // lendo field attributes
        if (cf->fields[i].attributes_count){
            read_attributes(fd, cf->fields[i].attributes, cf->fields[i].attributes_count, cf->constant_pool);
        }
    };
};

// ----------------- CONSTANT POOL -------------------------------- //

// Lendo as tags
// no Constant Pool temos os Cp_infos que dependem da tag para fazermos a alocacao

/* exemplo de atribuicao com base na tag
cp_info teste;
teste.tag = 10;
teste.constant_type.Methodref_info.name_index = 20;
teste.constant_type.testando = 10;
*/

// para double e integer "If a CONSTANT_Long_info or CONSTANT_Double_info structure is the item in the constant_pool table at index n, then the next usable item in the pool is located at index n+2. The constant_pool index n+1 must be valid but is considered unusable."

// switch do cp info -> aqui com base na tag que o constant pool object tiver teremos que decidir que tipo de estrurura iremos ler

// passar o endereco do ponteiro

// -------------------------- read cp info ----------------------------------- //
void read_cp_info(FILE *fd, ClassFile *cf)
{

    // alocando ESPAÇO para o cp_info na memória e endereçando no ponteiro constant_pool.
    cf->constant_pool = (cp_info *)malloc(cf->constant_pool_count * sizeof(cp_info));

    for (int cp_index = 1; cp_index < cf->constant_pool_count; cp_index++)
    {

        cp_info *cp_info = &cf->constant_pool[cp_index];

        cp_info->tag = u1Read(fd);

        // pegar a tag e com base no seu número, selecionar a estrutura.
        u1 tag = cp_info->tag;

        // perguntar pro ladeira a outra alternativa para realizar isso.
        switch (tag)
        {
        case (CONSTANT_Class_info): {
            cp_info->constant_type_union.Class_info.name_index = u2Read(fd);
            break;
        }
        case (CONSTANT_Fieldref_info): {
            cp_info->constant_type_union.Fieldref_info.class_index = u2Read(fd);
            cp_info->constant_type_union.Fieldref_info.name_and_type_index = u2Read(fd);
            break;
        }
        case (CONSTANT_Methodref_info): {
            cp_info->constant_type_union.Methodref_info.class_index = u2Read(fd);
            cp_info->constant_type_union.Methodref_info.name_and_type_index = u2Read(fd);
            break;
        }
        case (CONSTANT_InterfaceMethodref_info): {
            cp_info->constant_type_union.InterfaceMethodref_info.class_index = u2Read(fd);
            cp_info->constant_type_union.InterfaceMethodref_info.name_and_type_index = u2Read(fd);
            break;
        }
        case (CONSTANT_String_info):{
            cp_info->constant_type_union.String.string_index = u2Read(fd);
            break;
        }

        case (CONSTANT_Integer_info):{
            // IEEE 754 floating-point single format
            cp_info->constant_type_union.Float.bytes = u4Read(fd);
            break;
        }

        case (CONSTANT_Float_info):{   
            // IEEE 754 floating-point single format
            // na hora de representar tem que utilizar -> result of the mathematical expression s · m · 2e-150.
            cp_info->constant_type_union.Float.bytes = u4Read(fd);
            break;
        }

        case (CONSTANT_Long_info): {
            cp_index++;
            // também tem toda uma técnica na hora de representar
            cp_info->constant_type_union.Long.high_bytes = u4Read(fd);
            cp_info->constant_type_union.Long.low_bytes = u4Read(fd);
            break;
        }
            // pular o indice? SIM
        case (CONSTANT_Double_info): {
            cp_index++;
            // também tem toda uma técnica na hora de representar
            cp_info->constant_type_union.Double.high_bytes = u4Read(fd);
            cp_info->constant_type_union.Double.low_bytes = u4Read(fd);
            break;
        }
            // pular o indice? SIM
        case (CONSTANT_NameAndType_info): {
            cp_info->constant_type_union.NameAndType.name_index = u2Read(fd);
            cp_info->constant_type_union.NameAndType.descriptor_index = u2Read(fd);
            break;
        }
        // erro aqui
        case (CONSTANT_Utf8_info):{

            // the number of bytes in the bytes array (not the length of the resulting string)
            cp_info->constant_type_union.Utf8.length = u2Read(fd);

            u2 length = cp_info->constant_type_union.Utf8.length;

            // bytes é um ponteiro para um array de length bytes -> alocando espaco e memoria para os bytes
            cp_info->constant_type_union.Utf8.bytes = (u1 *)malloc(length * sizeof(u1));

            // iterar dentro do do (0 até length - 1)
            for (int i = 0; i < length; i++){
                cp_info->constant_type_union.Utf8.bytes[i] = u1Read(fd);
            }
        }
            break;

        case (CONSTANT_MethodHandle_info):{   
            u1Read(fd);
            u2Read(fd);
        }
            break;

        case (CONSTANT_MethodType_info):{   
            u2Read(fd);
        }
            break;

        case (CONSTANT_InvokeDynamic_info):{   
            u4Read(fd);
        }
            break;
        }
    };
};

// -------------------------- .CLASS READING ----------------------------------- //

void class_reader(FILE *fd, ClassFile *cf)
{

    // Lendo o magic
    cf->magic = u4Read(fd);

    // Lendo minor_version
    cf->minor_version = u2Read(fd);

    // Lendo major_version
    cf->major_version = u2Read(fd);

    // Lendo constant_pool_count
    cf->constant_pool_count = u2Read(fd);
    // lendo o cp
    read_cp_info(fd, cf);


    // lendo acess flags
    cf->access_flags = u2Read(fd);

    // lendo this_class
    cf->this_class = u2Read(fd);

    // lendo super_class
    cf->super_class = u2Read(fd);

    // lendo interfaces count
    cf->interfaces_count = u2Read(fd);

    // alocando em memória o interfaces count
    cf->interfaces = (u2 *)malloc(cf->interfaces_count * sizeof(u2));

    // preenchendo o vetor de interfaces
    for (int i = 0; i < cf->interfaces_count; i++)
    {
        cf->interfaces[i] = u2Read(fd);
    };

    // lendo fields count
    cf->fields_count = u2Read(fd);

    // lendo os FIELDS
    read_fields(fd, cf);
    
    // // lendo method count
    // cf->methods_count = u2Read(fd);

    // // lendo os METHODS
    // read_methods(fd, cf);

    // // pegar o count de attributes
    // cf->attributes_count = u2Read(fd);
    
    // // alocar os attributes do .class
    // cf->attributes = (Attribute_info *) malloc(cf->attributes_count * sizeof(Attribute_info));

    // // lendo os Attributes
    
    // read_attributes(fd, cf->attributes, cf->attributes_count, cf->constant_pool);

};
