#include "exibidor.hpp"

using namespace exibidor;
using namespace std;

int bytecode_group(u1);
void bytecode_print( u1*, int *, int, cp_info *);

// print u1 em hexadecimal
// void exibir_u1_hexa(u1 estrutura){
// }


string class_decoder(cp_info *cp, u2 classIndex) {
    u2 UTF8index = cp[classIndex].constant_type_union.Class_info.name_index;
    string className = utf8ToString(&cp[UTF8index]);
    return className;
}

// ----------------------------- CONSTANTVALUE -------------------------------------

void constantValue_type_exibitor(cp_info *cp, ClassFile *cf) {
    switch (cp->tag)
    {
    case (CONSTANT_Long_info):
    {
        cout << '<' << u4ToLong(cp->constant_type_union.Long.low_bytes, cp->constant_type_union.Long.high_bytes) << '>' << endl << endl;
        break;
    }
    case (CONSTANT_Float_info):
    {
        cout << '<' << u4ToFloat(cp->constant_type_union.Float.bytes) << '>' << endl << endl;
        break;
    }
    case (CONSTANT_Double_info):
    {
        cout << '<' << u4ToDouble(cp->constant_type_union.Double.low_bytes, cp->constant_type_union.Double.high_bytes) << '>' << endl << endl;
        break;
    }
    case (CONSTANT_Integer_info):
    {
        cout << '<' << u4ToInt(cp->constant_type_union.Integer.bytes) << '>' << endl << endl;
        break;
    }
    case (CONSTANT_String_info):
    {
        u2 index = cp->constant_type_union.String.string_index;
        cout << '<' << utf8ToString(&cf->constant_pool[index]) << '>' << endl << endl;
        break;
    }
    }
}

void constantValue_exibitor(Attribute_info *attribute, ClassFile *cf) {
    u2 constantValue_index = attribute->attribute_info_union.constantvalue_index;
    cout << "\tSpecific info:" << endl;
    cout << "\tConstant value index: cp_info #" << constantValue_index << endl;
    constantValue_type_exibitor(&cf->constant_pool[constantValue_index], cf);
}


// ----------------------------- CODE -------------------------------------
void code_exibitor(Attribute_info *attribute, ClassFile *cf){
    
    // MISC    
    cout << "\n\tMISC: \n\n";
    cout << "\tMaximum stack size: " << attribute->attribute_info_union.code_attribute.max_stack << "\n";
    cout << "\tMaximum local variables: " << attribute->attribute_info_union.code_attribute.max_locals << "\n";
    cout << "\tMaximum code length: " << attribute->attribute_info_union.code_attribute.code_length << "\n\n";
    

    cout << "\tBytecodes: \n\n";
    // code mnermonicos!
    int line = 1;
    // iterar para cada byte
    for(int i = 0; i < attribute->attribute_info_union.code_attribute.code_length; i++){
        cout << "\t" << line << " | " << i << " ";

        

        //bytecode em questão 
        u1 bytecode = attribute->attribute_info_union.code_attribute.code[i];
        
        // pegar o grupo
        int group = bytecode_group(bytecode);

        
        // se for lookupswitch break e print instrução não implementada
        if(bytecode == lookupswitch){
            cout << "Instrução não implementada!\n";
            break;
        };

        // printar com base no grupo
        bytecode_print(attribute->attribute_info_union.code_attribute.code, &i, group, cf->constant_pool);
        
        line++;
    };
    
    cout << endl;

    attributes_exibitor(attribute->attribute_info_union.code_attribute.attributes, attribute->attribute_info_union.code_attribute.attribute_count, cf, 2);

};



// -------------------------- EXCEPTIONS ---------------------- 

void exceptions_exibitor(Attribute_info *attribute, ClassFile *cf) {
    u2 length = attribute->attribute_info_union.exceptions_attribute.number_of_exceptions;
    cp_info *cp = cf->constant_pool;
    cout << "\tSpecific info:\n";

    for (int i = 0; i < length; i++) {
        u2 exception_index = attribute->attribute_info_union.exceptions_attribute.exception_index_table[i];
        cout << "\tNúmero: " << i << " - Exception: cp_info #" << exception_index << " <" << class_decoder(cp, exception_index) << ">\n";
    }

    cout << endl;
}

// -------------------------- INNERCLASSES ---------------------- 

void innerClasses_exibitor(Attribute_info *attribute, ClassFile *cf) {
    u2 length = attribute->attribute_info_union.innerClasses_attribute.number_of_classes;
    cp_info *cp = cf->constant_pool;
    cout << "Specific info:\n\n";
    
    for (int i = 0; i < length; i++) {
        inner_classes *inner_class = &attribute->attribute_info_union.innerClasses_attribute.inner_classes[i];
        cout << "Número: " << i << " - Inner Class: cp_info #" << inner_class->inner_class_info_index << " <" << class_decoder(cp, inner_class->inner_class_info_index) << "> - Outer Class: cp_info #" << inner_class->outer_class_info_index << " <" << class_decoder(cp, inner_class->outer_class_info_index) << "> - Inner Name: cp_info #" << inner_class->inner_name_index << " <" << utf8ToString(&cp[inner_class->inner_name_index]) << "> - Access Flags: 0x" << inner_class->inner_class_access_flags << " [" << accFlag_decoder(inner_class->inner_class_access_flags) << "]\n\n";
    }

}

// -------------------------- LINENUMBERTABLE ---------------------- 

void lineNumberTable_exibitor(Attribute_info *attribute, ClassFile *cf) {
    u2 length = attribute->attribute_info_union.lineNumberTable_attribute.line_number_table_length;
    cout << "\t\tSpecific info:\n";

    for (int i = 0; i < length; i++) {
        line_number_table *line_number_table = &attribute->attribute_info_union.lineNumberTable_attribute.line_number_table[i];
        cout << "\t\tNúmero: " << i << " - Start PC: " << line_number_table->start_pc << " - Line Number: " << line_number_table->line_number << "\n";
    }

    cout << endl;
}
// -------------------------- LOCALVARIABLETABLE ---------------------- 

void localVariableTable_exibitor(Attribute_info *attribute, ClassFile *cf) {
    u2 length = attribute->attribute_info_union.localVariableTable_attribute.local_variable_table_length;
    cp_info *cp = cf->constant_pool;
    cout << "\tSpecific info:\n";
    
    for (int i = 0; i < length; i++) {
        Local_variable_table *local_variable_table = &attribute->attribute_info_union.localVariableTable_attribute.local_variable_table[i];
        cout << "\tNúmero: " << i << " - ";
        cout << "Start PC: " << local_variable_table->start_pc << " - ";
        cout << "Length: " << local_variable_table->length << " - ";
        cout << "Name Index: #" << local_variable_table->name_index << " <" << utf8ToString(&cp[local_variable_table->name_index]) << "> - ";
        cout << "Descriptor Index: #" << local_variable_table->descriptor_index << " <" << utf8ToString(&cp[local_variable_table->descriptor_index]) << "> - ";
        cout << "Index: " << local_variable_table->index << "\n";
        if (utf8ToString(&cp[local_variable_table->descriptor_index]) == "J" || utf8ToString(&cp[local_variable_table->descriptor_index]) == "D") {
            i++;
        }
    }

    cout << endl;
}


// ----------------------------- ATTRIBUTES -------------------------------------

void attributes_exibitor(Attribute_info *attributes, u2 attributes_count, ClassFile * cf, int tabs_count){
    string tabs = (char*) malloc(tabs_count * 2 * sizeof(char));
    if (tabs_count == 0) {
        cout <<"Início attributes: \n\n"; 
    }
    if (tabs_count == 1) {
        tabs = "\t";
    } else if (tabs_count == 2) {
        tabs = "\t\t";
    } else if (tabs_count == 3) {
        tabs = "\t\t\t";
    }

    for (int i = 0; i < attributes_count; i++) {
        Attribute_info *attr = &attributes[i];
        u2 length = attr->attribute_length;
        u2 name_index = attr->attribute_name_index;
        cout << tabs << "Attribute[" << i << "]\n";

        cout << tabs << "Attribute name index: cp_info #" << name_index << " <" << utf8ToString(&cf->constant_pool[name_index]) << ">\n";

        cout << tabs << "Attribute length: " << length << "\n";

        string  name = utf8ToString(&cf->constant_pool[name_index]);
        // usar o code length aqui não faz sentido porque não é pra printar um code para cada length.
        // entramos na função e com base no bytecode vamos ter que tomar nossas decisões do que fazer
        if (name == "ConstantValue")
        {   
            constantValue_exibitor(attr, cf);
        }
        else if (name == "Code")
        {
            code_exibitor(attr, cf);
        }
        else if (name == "Exceptions")
        {
            exceptions_exibitor(attr, cf);
        }
        else if (name == "InnerClasses")
        {
            innerClasses_exibitor(attr, cf);
        }
        else if (name == "LineNumberTable")
        {
            lineNumberTable_exibitor(attr, cf);
        }
        else if (name == "LocalVariableTable")
        {
            localVariableTable_exibitor(attr, cf);
        } else {
            cout << "\n";
        }
    }

    if (tabs_count == 0) {
        cout << "Fim attributes\n\n";
    }   
    
};

// ----------------------------- FIELDS -------------------------------------

void fields_exibitor(ClassFile *cf) {
    u2 fields_count = cf->fields_count;
    cout <<"Início Fields\n\n";
    for (int i = 0; i < fields_count; i++) {
        field_info *field = &cf->fields[i];
        cp_info *cp = cf->constant_pool;
        cout << "Field[" << i << "]\n";
        cout << "Name: #" << field->name_index << " <" << utf8ToString(&cp[field->name_index]) << ">\n";
        cout << "Descriptor: #" << field->descriptor_index << " <" << utf8ToString(&cp[field->descriptor_index]) << ">\n";
        cout << "Access flags: 0x" << hex << field->access_flags << dec << " [" << accFlag_decoder(field->access_flags) << "]\n\n";
        attributes_exibitor(field->attributes, field->attributes_count, cf, 1);
    }
    cout <<"Fim Fields\n\n";
}

// ----------------------------- METHODS -------------------------------------

void methods_exibitor(ClassFile *cf){

    u2 methods_count = cf->methods_count;

    cout << "Início Methods:\n\n";

    // iterar em cada method
    for (int i = 0; i < methods_count; i++){
            
        // pegar o method
        Method_info *method = &cf->methods[i]; 
        
        cout << "Method[" << i << "]\n";

        //name
        cout << "Name: #" << method->name_index << "<" << utf8ToString(&cf->constant_pool[method->name_index]) << ">\n";

        // discriptor 
        cout << "Descriptor: #" << method->descriptor_index << " <" << utf8ToString(&cf->constant_pool[method->descriptor_index]) << ">\n";
        
        // access flags
        cout << "Access Flags: 0x" << hex << method->access_flags << dec << " [" << accFlag_decoder(method->access_flags) << "]\n\n";

        // attributes
        attributes_exibitor(method->attributes, method->attributes_count, cf, 1);
    };


};


string  accFlag_decoder(u2 accFlag) {
    string flagName = "";
    if (accFlag & 0x0001) flagName += "public ";
    if (accFlag & 0x0002) flagName += "private ";
    if (accFlag & 0x0004) flagName += "protected ";
    if (accFlag & 0x0008) flagName += "static ";
    if (accFlag & 0x0010) flagName += "final ";
    if (accFlag & 0x0020) flagName += "super ";
    if (accFlag & 0x0200) flagName += "interface ";
    if (accFlag & 0x0400) flagName += "abstract ";
    if (accFlag & 0x1000) flagName += "synthetic ";
    if (accFlag & 0x2000) flagName += "annotation ";
    if (accFlag & 0x4000) flagName += "enum ";

    if (flagName.size() > 0) {
        flagName = flagName.substr(0, flagName.size() - 1);
    }
    return flagName;
}

void interfaces_exibitor (ClassFile *cf) {
    u2 interfaces_count = cf->interfaces_count;
    cout << "Início Interfaces: \n \n";
    for (int i = 0; i < interfaces_count; i++) {
        u2 interface = cf->interfaces[i];
        cout << "Interface[" << i << "]\n";
        cout << "Interface: #" << interface << " <" << class_decoder(cf->constant_pool, interface) << ">\n\n";
    }
    cout << "Fim Interfaces \n\n";
}

// exibir o cp_info
// iremos precisar de um ponteiro para o classfile 
void cp_info_exibitor(ClassFile *classFile){
    
    // pegar o contador de constant pool
    int cp_info_count = classFile->constant_pool_count;

    // pegar o endereço do constant pool salvo e colocar no ponteiro constantPool.
    cp_info *constantPool = classFile->constant_pool;
    
    cout << "\nInício Constant Pool \n \n";
    

    // iterar nos constant pools e ir printando com base em cada um de (1 até cp_count - 1) 
    for(int i = 1; i < cp_info_count; i++){

        // constantPoolItem é um ponteiro que aponta para a cp em questão
        // aqui pegamos no &constantPool[i] o endereço do cp_info localizado nessa posição
        // cp_info *constantPoolItem = &constantPool[i];

        // imprimir o indice do constant pool
        cout << "[" << i << "] ";
        // agora temos o restante que depende do tag, aplicar um SWITCH
        // para cada estrutura, agora temos que realizar os devidos prints
        switch(constantPool[i].tag){

            case(0) :
            {
                cout << "(large numeric continued)\n\n";
                break;
            }
            case(CONSTANT_Class_info):
            { 
                cout << "CONSTANT_Class_info" << endl;
                u2 class_name_index = constantPool[i].constant_type_union.Class_info.name_index;
                // aqui pegamos o index para accessar a constante utf_8 para a nossa função
                cout << "Class name: cp_info #" << class_name_index << " <" << utf8ToString(&constantPool[class_name_index]) << ">\n\n";
                break;
            }
            case(CONSTANT_Fieldref_info):
            {
                cout << "CONSTANT_Fieldref_info" << endl;
                    
                u2 fieldref_class_index = constantPool[i].constant_type_union.Fieldref_info.class_index;
                u2 fieldref_name_and_type_index = constantPool[i].constant_type_union.Fieldref_info.name_and_type_index;
                
                // meio confuso, tem outras formas de implementar
                // aqui o class_index aponta para uma classe no constant poll e depois essa class_info aponta para um utf8.
                
                // printando o class name
                cout << "Class name: cp_info #" << fieldref_class_index << " <" << utf8ToString(&constantPool[constantPool[fieldref_class_index].constant_type_union.Class_info.name_index]) << ">\n";
                // printando o name and type
                // name
                cout << "Name and type: cp_info #" << fieldref_name_and_type_index << " <" << utf8ToString(&constantPool[constantPool[fieldref_name_and_type_index].constant_type_union.NameAndType.name_index]) << " : ";

                // descriptor
                cout << utf8ToString(&constantPool[constantPool[fieldref_name_and_type_index].constant_type_union.NameAndType.descriptor_index]) << ">\n\n";
                break;
            }
            case(CONSTANT_Methodref_info):
            {
                cout << "CONSTANT_Methodref_info" << endl;

                u2 methodref_class_index = constantPool[i].constant_type_union.Methodref_info.class_index;
                u2 methodref_name_and_type_index = constantPool[i].constant_type_union.Methodref_info.name_and_type_index;
                
                // meio confuso, tem outras formas de implementar
                // aqui o class_index aponta para uma classe no constant poll e depois essa class_info aponta para um utf8.
                
                // printando o class name
                cout << "Class name: #" << (u4) methodref_class_index << " <" << utf8ToString(&constantPool[constantPool[methodref_class_index].constant_type_union.Class_info.name_index]) << ">\n";
                
                // printando o name and type

                // name
                cout << "Name and type: #" << (u4) methodref_name_and_type_index;
                cout << " <" << utf8ToString(&constantPool[constantPool[methodref_name_and_type_index].constant_type_union.NameAndType.name_index]) << " : ";

                // descriptor
                cout << utf8ToString(&constantPool[constantPool[methodref_name_and_type_index].constant_type_union.NameAndType.descriptor_index]) << ">\n\n";

                break;
            }
            case(CONSTANT_InterfaceMethodref_info): 
            {
                cout << "CONSTANT_InterfaceMethodref_info" << endl;
                u2 interface_index = constantPool[i].constant_type_union.InterfaceMethodref_info.class_index;
                u2 name_and_type_index = constantPool[i].constant_type_union.InterfaceMethodref_info.name_and_type_index;

                u2 utf8_interface_index = constantPool[interface_index].constant_type_union.Class_info.name_index;
                u2 utf8_name_and_type_index_name = constantPool[name_and_type_index].constant_type_union.NameAndType.name_index;
                u2 utf8_name_and_type_index_descriptor = constantPool[name_and_type_index].constant_type_union.NameAndType.descriptor_index;

                cout << "Interface name: cp_info #" << interface_index << " <" << utf8ToString(&constantPool[utf8_interface_index]) << ">\n";

                cout << "Name and type: cp_info #" << name_and_type_index << " <" << utf8ToString(&constantPool[utf8_name_and_type_index_name]) << " " << utf8ToString(&constantPool[utf8_name_and_type_index_descriptor]) << ">\n\n";
                break;
            }
            case(CONSTANT_String_info):
            {
                cout << "CONSTANT_String_info" << endl;

                u2 string_info_index = constantPool[i].constant_type_union.String.string_index;
                cout << "String: cp_info #" << (u4) string_info_index << " <" << utf8ToString(&constantPool[string_info_index]) << ">\n\n";
                break;
            }
            case(CONSTANT_Integer_info): 
            {
                cout << "CONSTANT_Integer_info" << endl;
                u4 bytes = constantPool[i].constant_type_union.Integer.bytes;
                cout << "Integer value: " << bytes << "\n\n";
                break;
            }
            case(CONSTANT_Float_info):
            {
                cout << "CONSTANT_Float_info" << endl;
                u4 bytes = constantPool[i].constant_type_union.Float.bytes;
                cout << "Float value: " << u4ToFloat(bytes) << "\n\n";
                break;
            }   
            case(CONSTANT_Long_info): 
            {
                cout << "CONSTANT_Long_info" << endl;
                u4 high_bytes = constantPool[i].constant_type_union.Long.high_bytes;
                u4 low_bytes = constantPool[i].constant_type_union.Long.low_bytes;
                cout << "Long value: " << u4ToLong(low_bytes, high_bytes) << "\n\n";
                break;
            }
            case(CONSTANT_Double_info): 
            {
                cout << "CONSTANT_Double_info" << endl;
                u4 high_bytes = constantPool[i].constant_type_union.Double.high_bytes;
                u4 low_bytes = constantPool[i].constant_type_union.Double.low_bytes;
                cout << "Double value: " << u4ToDouble(low_bytes, high_bytes) << "\n\n";
                break;
            }
            case(CONSTANT_NameAndType_info):
            {
                cout << "CONSTANT_NameAndType_info" << endl;
                u2 name_index = constantPool[i].constant_type_union.NameAndType.name_index;
                u2 descriptor_index = constantPool[i].constant_type_union.NameAndType.descriptor_index;

                cout << "Name: cp_info #" << name_index << " " << utf8ToString(&constantPool[name_index]) << "\n";
                cout << "Descriptor: cp_info #" << descriptor_index << " " << utf8ToString(&constantPool[descriptor_index]) << "\n\n";
                break;
            }
            case(CONSTANT_Utf8_info):
            {   
                cout << "CONSTANT_Utf8_info" << endl;
                // length of byte array?
                cout << "length of Byte array: " << constantPool[i].constant_type_union.Utf8.length << "\n";
                // length of string?
                cout << "length of string: " << constantPool[i].constant_type_union.Utf8.length << "\n";
                // String
                cout << "String: " << utf8ToString(&constantPool[i]) << "\n\n";
                break;
            }   
            default:
                cout << "\n";
                break;
        };
    }

    cout << "Fim Constant Pool \n \n";

}

void class_exibitor(ClassFile *cf) {
    // Exibição magic number
    cout << "Magic: 0x" << hex << cf->magic << dec << "\n";

    // Exibição minor version
    cout << "Minor version: " << cf->minor_version << "\n";

    // Exibição major version
    cout << "Major version: " << cf->major_version << "\n";

    // Java version
    cout << "Java version: 1." << cf->major_version - 44 << "\n";

    // Exibição constant pool size
    cout << "Constant Pool Count: " << cf->constant_pool_count << "\n";
    // Exibição access flags
    cout << "Access flags: 0x" << hex << cf->access_flags << dec << " [" << accFlag_decoder(cf->access_flags) << "] \n";
    // Exibição this class 
    cout << "This class: #" << cf->this_class << " <" << class_decoder(cf->constant_pool, cf->this_class) << "> \n";

    // Exibição super class
    cout << "Super class: #" << cf->super_class << " <" << class_decoder(cf->constant_pool, cf->super_class) << "> \n";

    // Exibição interfaces count
    cout << "Interfaces count: " << cf->interfaces_count << "\n";

    // Exibição fields count 
    cout << "Fields count: " << cf->fields_count << "\n";

    // Exibição methods count
    cout << "Methods count: " << cf->methods_count << "\n";

    // Exibição attributes count
    cout << "Attributes count: " << cf->attributes_count << "\n";

    // Exibição constant pool
    cp_info_exibitor(cf);
    
    // Exibição interfaces
    interfaces_exibitor(cf);

    // Exibição fields
    fields_exibitor(cf);

    // Exibição methods
    methods_exibitor(cf);
    
    // Exibição attributes
    attributes_exibitor(cf->attributes, cf->attributes_count, cf, 0);

}


// -------------------------- CODE NAME ---------------------- 
// função que pega o nome baseado no opcode.

const string bytecode_to_opcode_string(value_to_opcode op)
{
    switch (op)
    {

    case    nop:                      return "nop";       
    case    aconst_null:              return "aconst_null";               
    case    iconst_m1:                return "iconst_m1";             
    case    iconst_0:                 return "iconst_0";            

    case    iconst_1:                 return "iconst_1";            
    case    iconst_2:                 return "iconst_2";            
    case    iconst_3:                 return "iconst_3";            
    case    iconst_4:                 return "iconst_4";            

    case    iconst_5:                 return "iconst_5";            
    case    lconst_0:                 return "lconst_0";            
    case    lconst_1:                 return "lconst_1";            
    case    fconst_0:                 return "fconst_0";            

    case    fconst_1:                 return "fconst_1";            
    case    fconst_2:                 return "fconst_2";            
    case    dconst_0:                 return "dconst_0";            
    case    dconst_1:                 return "dconst_1";            

    case    bipush:                   return "bipush";          
    case    sipush:                   return "sipush";          
    case    ldc:                      return "ldc";       
    case    ldc_w:                    return "ldc_w";         
    case    ldc2_w:                   return "ldc2_w";          

    case    iload:                    return "iload";         
    case    lload:                    return "lload";         
    case    fload:                    return "fload";         
    case    dload:                    return "dload";         
    case    aload:                    return "aload";         

    case    iload_0:                  return "iload_0";           
    case    iload_1:                  return "iload_1";           
    case    iload_2:                  return "iload_2";           
    case    iload_3:                  return "iload_3";           
    case    lload_0:                  return "lload_0";           

    case    lload_1:                  return "lload_1";           
    case    lload_2:                  return "lload_2";           
    case    lload_3:                  return "lload_3";           
    case    fload_0:                  return "fload_0";           
    case    fload_1:                  return "fload_1";           

    case    fload_2:                  return "fload_2";           
    case    fload_3:                  return "fload_3";           
    case    dload_0:                  return "dload_0";           
    case    dload_1:                  return "dload_1";           
    case    dload_2:                  return "dload_2";           

    case    dload_3:                  return "dload_3";           
    case    aload_0:                  return "aload_0";           
    case    aload_1:                  return "aload_1";           
    case    aload_2:                  return "aload_2";           
    case    aload_3:                  return "aload_3";           

    case    iaload:                   return "iaload";          
    case    laload:                   return "laload";          
    case    faload:                   return "faload";          
    case    daload:                   return "daload";          
    case    aaload:                   return "aaload";          
    case    baload:                   return "baload";          

    case    caload:                   return "caload";          
    case    saload:                   return "saload";          
    case    istore:                   return "istore";          
    case    lstore:                   return "lstore";          
    case    fstore:                   return "fstore";          
    case    dstore:                   return "dstore";          

    case    astore:                   return "astore";          
    case    istore_0:                 return "istore_0";            
    case    istore_1:                 return "istore_1";            
    case    istore_2:                 return "istore_2";            
    case    istore_3:                 return "istore_3";            

    case    lstore_0:                 return "lstore_0";            
    case    lstore_1:                 return "lstore_1";            
    case    lstore_2:                 return "lstore_2";            
    case    lstore_3:                 return "lstore_3";            
    case    fstore_0:                 return "fstore_0";            

    case    fstore_1:                 return "fstore_1";            
    case    fstore_2:                 return "fstore_2";            
    case    fstore_3:                 return "fstore_3";            
    case    dstore_0:                 return "dstore_0";            
    case    dstore_1:                 return "dstore_1";            

    case    dstore_2:                 return "dstore_2";            
    case    dstore_3:                 return "dstore_3";            
    case    astore_0:                 return "astore_0";            
    case    astore_1:                 return "astore_1";            
    case    astore_2:                 return "astore_2";            

    case    astore_3:                 return "astore_3";            
    case    iastore:                  return "iastore";           
    case    lastore:                  return "lastore";           
    case    fastore:                  return "fastore";           
    case    dastore:                  return "dastore";           

    case    aastore:                  return "aastore";           
    case    bastore:                  return "bastore";           
    case    castore:                  return "castore";           
    case    sastore:                  return "sastore";           
    case    pop:                      return "pop";       
    case    pop2:                     return "pop2";        

    case    dup:                      return "dup";       
    case    dup_x1:                   return "dup_x1";          
    case    dup_x2:                   return "dup_x2";          
    case    dup2:                     return "dup2";        
    case    dup2_x1:                  return "dup2_x1";           
    case    dup2_x2:                  return "dup2_x2";           
    case    swap_:                     return "swap";        

    case    iadd:                     return "iadd";        
    case    ladd:                     return "ladd";        
    case    fadd:                     return "fadd";        
    case    dadd:                     return "dadd";        
    case    isub:                     return "isub";        
    case    lsub:                     return "lsub";        
    case    fsub:                     return "fsub";        
    case    dsub:                     return "dsub";        

    case    imul:                     return "imul";        
    case    lmul:                     return "lmul";        
    case    fmul:                     return "fmul";        
    case    dmul:                     return "dmul";        
    case    idiv:                     return "idiv";        
    case    inst_ldiv:                return "inst_ldiv";             
    case    fdiv:                     return "fdiv";        
    case    ddiv:                     return "ddiv";        

    case    irem:                     return "irem";        
    case    lrem:                     return "lrem";        
    case    frem:                     return "frem";        
    case    inst_drem:                return "inst_drem";             
    case    ineg:                     return "ineg";        
    case    lneg:                     return "lneg";        
    case    fneg:                     return "fneg";        
    case    dneg:                     return "dneg";        

    case    ishl:                     return "ishl";        
    case    lshl:                     return "lshl";        
    case    ishr:                     return "ishr";        
    case    lshr:                     return "lshr";        
    case    iushr:                    return "iushr";         
    case    lushr:                    return "lushr";         
    case    iand:                     return "iand";        
    case    land:                     return "land";        

    case    ior:                      return "ior";       
    case    lor:                      return "lor";       
    case    ixor:                     return "ixor";        
    case    lxor:                     return "lxor";        
    case    iinc:                     return "iinc";        
    case    i2l:                      return "i2l";       
    case    i2f:                      return "i2f";       
    case    i2d:                      return "i2d";       
    case    l2i:                      return "l2i";       

    case    l2f:                      return "l2f";       
    case    l2d:                      return "l2d";       
    case    f2i:                      return "f2i";       
    case    f2l:                      return "f2l";       
    case    f2d:                      return "f2d";       
    case    d2i:                      return "d2i";       
    case    d2l:                      return "d2l";       
    case    d2f:                      return "d2f";       
    case    i2b:                      return "i2b";       
    case    i2c:                      return "i2c";       
    case    i2s:                      return "i2s";       
    case    lcmp:                     return "lcmp";        
    case    fcmpl:                    return "fcmpl";         
    case    fcmpg:                    return "fcmpg";         
    case    dcmpl:                    return "dcmpl";         
    case    dcmpg:                    return "dcmpg";         
    case    ifeq:                     return "ifeq";        

    case    ifne:                     return "ifne";        
    case    iflt:                     return "iflt";        
    case    ifge:                     return "ifge";        
    case    ifgt:                     return "ifgt";        
    case    ifle:                     return "ifle";        
    case    if_icmpeq:                return "if_icmpeq";             
    case    if_icmpne:                return "if_icmpne";             

    case    if_icmplt:                return "if_icmplt";             
    case    if_icmpge:                return "if_icmpge";             
    case    if_icmpgt:                return "if_icmpgt";             
    case    if_icmple:                return "if_icmple";             
    case    if_acmpeq:                return "if_acmpeq";             

    case    if_acmpne:                return "if_acmpne";             
    case    inst_goto:                return "inst_goto";             
    case    jsr:                      return "jsr";       
    case    ret:                      return "ret";       
    case    tableswitch:              return "tableswitch";               

    case    lookupswitch:             return "lookupswitch";                
    case    ireturn:                  return "ireturn";           
    case    lreturn:                  return "lreturn";           
    case    freturn:                  return "freturn";           
    case    dreturn:                  return "dreturn";           

    case    areturn:                  return "areturn";           
    case    inst_return:              return "return";               
    case    getstatic:                return "getstatic";             
    case    putstatic:                return "putstatic";             
    case    getfield:                 return "getfield";            

    case    putfield:                 return "putfield";            
    case    invokevirtual:            return "invokevirtual";                 
    case    invokespecial:            return "invokespecial";                 
    case    invokestatic:             return "invokestatic";                

    case    invokeinterface:          return "invokeinterface";               
    case    invokedynamic:            return "invokedynamic";                   
    case    new_:                      return "new";            
    case    newarray:                 return "newarray";            
    case    anewarray:                return "anewarray";             

    case    arraylength:              return "arraylength";               
    case    athrow:                   return "athrow";          
    case    checkcast:                return "checkcast";             
    case    instanceof:               return "instanceof";

    case    monitorenter:             return "monitorenter";                
    case    monitorexit:              return "monitorexit";               
    case    wide:                     return "wide";        
    case    multianewarray:           return "multianewarray";                  
    case    ifnull:                   return "ifnull";          

    case    ifnonnull:                return "ifnonnull";             
    case    goto_w:                   return "goto_w";          
    case    jsr_w:                    return "jsr_w";         
        }

    return "Unknown op";
}

// -------------------------- CODE GROUP ---------------------- 
int bytecode_group(u1 bytecode){


    switch(bytecode){

        // começando pelas de index number - 1 byte
            case aload:
            case astore:
            case dload:
            case dstore:
            case fload:
            case fstore:
            case iload:
            case istore:
            case lload:
            case lstore:
            case ret: return 1;

        // index pool - 1 byte ---> String, int, float, Class
            case ldc: return 11;

        // newarray - 1 byte:
            case newarray: return 12;

        // bipush
            case bipush: return 13;


        // ------------------- 2 bytes -------------

        // index pool - 2 bytes

            // class 
            case anewarray:
            case checkcast:
            case instanceof:
            case new_:

            // field
            case getfield:
            case getstatic:
            case putfield:
            case putstatic: 

            // method
            case invokespecial:
            case invokestatic:
            case invokevirtual:

            // String, int, float, Class
            case ldc_w:
            // double, long
            case ldc2_w:

            return 2;  


        // branch Type 2.1 - 2 bytes
            case inst_goto:
            case if_acmpeq:
            case if_acmpne:
            case if_icmpeq:
            case if_icmpge:
            case if_icmpgt:
            case if_icmple:
            case if_icmplt:
            case if_icmpne:
            case ifge:
            case ifgt:
            case ifeq:
            case ifle:
            case iflt:
            case ifne:
            case ifnonnull:
            case ifnull:
            case jsr: 
            return 21;


        // iinc increment local variable #index by signed byte const
            case iinc: 
            return 22;

        // index number 2.2 - 2 bytes
            case sipush:
            return 23;


        // ------------- 3 bytes-------------

        case multianewarray:
        return 3;


        // ------------ 4 bytes ------------------
        case jsr_w: 
        return 4;

        case invokeinterface: 
        return 41;

        case invokedynamic:
        return 42;

        case goto_w:
        return 43;


        // ----------- 16+ bytes ----------------
        case tableswitch:
        return 100;

        case lookupswitch:
        return 101;

        case wide:
        return 102;

        default:
            return 0;
    }


};


// array code attr comp

string  code_arr_to_string(int atype){
    if(atype == T_BOOLEAN){
        return "boolean";
    }
    else if (atype == T_CHAR){
        return "char";
    }
    else if (atype == T_FLOAT){
        return "float";
    }
    else if (atype == T_DOUBLE){
        return "double";
    }
    else if (atype == T_BYTE){
        return "byte";
    }
    else if (atype == T_SHORT){
        return "short";
    }
    else if (atype == T_INT){
        return "int";
    }
    else if (atype == T_LONG){
        return "long";
    };
    return "unknown";
};

// -------------------------- GROUP PRINT ---------------------- 
// baseado nos grupos iremos printar os codes
void bytecode_print( u1* code_array, int *index, int bytecode_group, cp_info *constant_pool){
    
    switch(bytecode_group){

        // 1 byte:
        
        // index number group (1):
        case(1):{

            // printando bytecode
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";
            
            ++(*index);
            
            // printando o número
            cout << *index << " \n";
        }
        break;



        // index cp_info group (1.1):
        case(11):{

            // printando
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";

            ++(*index);

            int pool_index = code_array[*index];

            // pegar a tag fazer os casos
            // String, int, float, Class
            int tag = constant_pool[pool_index].tag;

            if(tag == CONSTANT_String_info){
                cout << "#" << pool_index << " " << utf8ToString(&constant_pool[constant_pool[pool_index].constant_type_union.String.string_index]) << " \n";
            }
            else if(tag == CONSTANT_Integer_info){
                cout << "#" << pool_index << " " << constant_pool[pool_index].constant_type_union.Integer.bytes << " \n";
            }
            else if(tag == CONSTANT_Float_info){
                cout << "#" << pool_index << " " << u4ToFloat(constant_pool[pool_index].constant_type_union.Integer.bytes) << " \n";
            }
            else if(tag == CONSTANT_Class_info){
                cout << "#" << pool_index << " " << utf8ToString(&constant_pool[constant_pool[pool_index].constant_type_union.Class_info.name_index]) << " \n";
            }
            else{
            };
            
            // printando o cp_info
            // aqui o pool_index aponta -> CONSTANT_String_info
        }
        break;

        case(12):{

            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";
            
            ++(*index);
            int atype = code_array[*index];


            // ver qual o tipo do array
            string atype_string = code_arr_to_string(atype);

            cout << atype << " (" << atype_string << ") \n";

        };
        break;


        case(13):{
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";

            ++(*index);
            int byte_to_push = code_array[*index];

            cout << byte_to_push << " \n";

        }
        break;

        // index _info group - 2bytes;
        case(2):{

            value_to_opcode bytecode = (value_to_opcode)code_array[*index];

            // printando
            
            ++(*index);
            int first_bytes = code_array[*index];
            
            ++(*index);
            int second_bytes = code_array[*index];

            uint16_t cp_index = (first_bytes << 8) | second_bytes; 
            // ver qual é o tipo e ir 

            
            cout << bytecode_to_opcode_string(bytecode) << " ";

            // class
            if (bytecode_to_opcode_string(bytecode) == "anewarray" || bytecode_to_opcode_string(bytecode) == "checkcast" || bytecode_to_opcode_string(bytecode) == "instanceof" || bytecode_to_opcode_string(bytecode) == "new") {
                cout << "#" << cp_index << " " << utf8ToString(&constant_pool[constant_pool[cp_index].constant_type_union.Class_info.name_index]) << " \n";
            }
            // field
            else if(bytecode_to_opcode_string(bytecode) == "getfield" || bytecode_to_opcode_string(bytecode) == "getstatic" || bytecode_to_opcode_string(bytecode) == "putfield" || bytecode_to_opcode_string(bytecode) == "putstatic"){
                cout << "#" << cp_index << " <" << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Fieldref_info.class_index].constant_type_union.Class_info.name_index]) << " : " << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Fieldref_info.name_and_type_index].constant_type_union.NameAndType.descriptor_index]) << "> \n";
            
            }
            // method
            else if(bytecode_to_opcode_string(bytecode) == "invokespecial" || bytecode_to_opcode_string(bytecode) == "invokestatic" || bytecode_to_opcode_string(bytecode) == "invokevirtual") {
                cout << "#" << cp_index << " <" << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Methodref_info.class_index].constant_type_union.Class_info.name_index]) << " : " << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Methodref_info.name_and_type_index].constant_type_union.NameAndType.descriptor_index]) << ">\n";
            }
            else if(bytecode_to_opcode_string(bytecode) == "ldc_w"){

                int tag = constant_pool[cp_index].tag;

                if(tag == CONSTANT_String_info){
                    cout << "#" << cp_index << " " << utf8ToString(&constant_pool[constant_pool[cp_index].constant_type_union.String.string_index]) << endl;
                }
                else if(tag == CONSTANT_Integer_info){
                    cout << "#" << cp_index << " " << constant_pool[cp_index].constant_type_union.Integer.bytes << endl;
                }
                else if(tag == CONSTANT_Float_info){
                    cout << "#" << cp_index << " " << u4ToFloat(constant_pool[cp_index].constant_type_union.Integer.bytes) << endl;
                }
                else if(tag == CONSTANT_Class_info){
                    cout << "#" << cp_index << " <" << utf8ToString(&constant_pool[constant_pool[cp_index].constant_type_union.Class_info.name_index]) << ">\n";
                }
                else{
                    cout << endl;
                };
            }
            else if(bytecode_to_opcode_string(bytecode) == "ldc2_w"){
                // double, long

                int tag = constant_pool[cp_index].tag;

                if(tag == CONSTANT_Double_info){
                    cout << "#" << cp_index << " " << u4ToDouble(constant_pool[cp_index].constant_type_union.Double.low_bytes,constant_pool[cp_index].constant_type_union.Double.high_bytes) << endl;
                }
                else if(tag == CONSTANT_Long_info){
                    cout << "#" << cp_index << " " << u4ToLong(constant_pool[cp_index].constant_type_union.Long.low_bytes,constant_pool[cp_index].constant_type_union.Long.high_bytes) << endl;
                }
                else{
                    cout << endl;
                }

            };
        } 
        break;

        case(21):{
            
            value_to_opcode bytecode = (value_to_opcode)code_array[*index];

            // pegando o indice do momento
            int start_index = *index;

            ++(*index);
            int first_bytes = code_array[*index];
            
            ++(*index);
            int second_bytes = code_array[*index];

            uint16_t branch_jump = (first_bytes << 8) | second_bytes; 

            // calculando local final
            uint16_t final = start_index + branch_jump;

            cout << bytecode_to_opcode_string(bytecode) << ' ';
            // local final  (+numero de pualos)
            cout << final << " (+" << branch_jump << ")\n";
        }
        break;

        case(22):{
            // printando
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";

            ++(*index);
            int local_variable_index = code_array[*index];
            
            ++(*index);
            int constant = code_array[*index];

            cout << local_variable_index << " by " << constant << endl;
        }
        break;

        case(23):{
            // printando
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << " ";

            ++(*index);
            int first_bytes = code_array[*index];
            
            ++(*index);
            int second_bytes = code_array[*index];

            uint16_t sum = (first_bytes << 8) | second_bytes; 

            cout << sum << endl;

        }   
        break;

        case(4):{
            
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << endl;


            ++(*index);
            ++(*index);        
            ++(*index);
            ++(*index);
        }
        break;

        case(41):{

            value_to_opcode bytecode = (value_to_opcode)code_array[*index];

            // printando
            
            ++(*index);
            int first_bytes = code_array[*index];
            
            ++(*index);
            int second_bytes = code_array[*index];

            uint16_t cp_index = (first_bytes << 8) | second_bytes; 
            
            ++(*index);
            int count = code_array[*index]; 
            ++(*index);
        
            cout << bytecode_to_opcode_string(bytecode) << ' ';
            cout << "#" << cp_index << " <" << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Methodref_info.class_index].constant_type_union.Class_info.name_index]) << " : " << utf8ToString(&constant_pool[constant_pool[constant_pool[cp_index].constant_type_union.Methodref_info.name_and_type_index].constant_type_union.NameAndType.descriptor_index]) << "> count " << count << endl;

        }
        break;

        case(42):{
            value_to_opcode bytecode = (value_to_opcode)code_array[*index];
            
            ++(*index);
            int first_bytes = code_array[*index];
            
            ++(*index);
            int second_bytes = code_array[*index];

            uint16_t cp_index = (first_bytes << 8) | second_bytes; 
            
            ++(*index);
            ++(*index);

            cout << bytecode_to_opcode_string(bytecode) << ' ';

            // %s é feito de forma diferente, iterar até o : no primeiro e pegar o que tiver
            // string  name_and_type_start = ;


            // identified by method reference index in constant pool
            cout << "#" << cp_index << endl;
            
        }
        break;

        case(43):{
            // goto_w
            // goto_w 14 (+4)

            value_to_opcode bytecode = (value_to_opcode)code_array[*index];
            
            int start = *index;

            ++(*index);
            int branch_byte1 = code_array[*index];
            ++(*index);
            int branch_byte2 = code_array[*index];
            ++(*index);
            int branch_byte3 = code_array[*index];
            ++(*index);
            int branch_byte4 = code_array[*index];

            int32_t branch_byte = (branch_byte1 << 24 | branch_byte2 << 16 | branch_byte3 << 8 | branch_byte4);

            int32_t final = start + branch_byte;

            cout << bytecode_to_opcode_string(bytecode) << ' ';

            cout << final << " (+" << branch_byte << ")\n";
        }
        break;


        case(3):{
            value_to_opcode bytecode = (value_to_opcode)code_array[*index];

            ++(*index);
            int first_bytes = code_array[*index];
            ++(*index);
            int second_bytes = code_array[*index];
            ++(*index);
            int dimensions = code_array[*index];

            uint16_t cp_index = (first_bytes << 8) | second_bytes; 

            cout << bytecode_to_opcode_string(bytecode) << ' ';

            cout << "#" << cp_index << " <" << utf8ToString(&constant_pool[constant_pool[cp_index].constant_type_union.Class_info.name_index]) << "> dim " << dimensions << "\n";
            

        }
        break;

        // tableswitch 
        case(100):{
        
        int start_position = *index;

        value_to_opcode bytecode = (value_to_opcode)code_array[*index];
        cout << bytecode_to_opcode_string(bytecode) << "\n";
        // ++(*index);
        
        // pular o padding
        // int padding = *(index) % 4;

        int fator; 
        if(*index < 4){
            fator = 4 - *index;
        }
        else if(*index > 4){
            fator = *(index) % 4;
        }
        else if(*index == 4){
            fator = 1;
        };
        for(int i=0; i < fator;i++){
            ++(*index);
        }
        
        // defaultbyte1, defaultbyte2, defaultbyte3, defaultbyte4, lowbyte1, lowbyte2, lowbyte3, lowbyte4, highbyte1, highbyte2, highbyte3, highbyte4
        int defaultbyte1 = code_array[*index];
        ++(*index); 
        int defaultbyte2 = code_array[*index];
        ++(*index); 
        int defaultbyte3 = code_array[*index];
        ++(*index); 
        int defaultbyte4 = code_array[*index];
        ++(*index); 

        int lowbyte1 = code_array[*index];
        ++(*index); 
        int lowbyte2 = code_array[*index];
        ++(*index); 
        int lowbyte3 = code_array[*index];
        ++(*index); 
        int lowbyte4 = code_array[*index];
        ++(*index); 

        int highbyte1 = code_array[*index];
        ++(*index); 
        int highbyte2 = code_array[*index];
        ++(*index); 
        int highbyte3 = code_array[*index];
        ++(*index); 
        int highbyte4 = code_array[*index];
        ++(*index); 

        int32_t default_bytes =  defaultbyte1 << 24 | defaultbyte2 << 16 | defaultbyte3 << 8 | defaultbyte4; 
        int32_t low_bytes =  lowbyte1 << 24 | lowbyte2 << 16 | lowbyte3 << 8 | lowbyte4; 
        int32_t high_bytes =  highbyte1 << 24 | highbyte2 << 16 | highbyte3 << 8 | highbyte4;


        // iterar entre tamanho de high_bytes 
        for (int i = low_bytes; i <= high_bytes; i++){
            
            int byte1 = code_array[*index];
            ++(*index); 
            int byte2 = code_array[*index];
            ++(*index); 
            int byte3 = code_array[*index];
            ++(*index); 
            int byte4 = code_array[*index];
            ++(*index); 
            

            int32_t bytes =  byte1 << 24 | byte2 << 16 | byte3 << 8 | byte4;
            
            int32_t jump_bytes = start_position + bytes;
            
            cout << "\t\t" << i + 1 << ": " << jump_bytes << " (+" << bytes << ")\n";
        };


        // default:
        cout << "\t\tdefault: " << start_position + default_bytes << " (+" << default_bytes << ")\n";


        --(*index);

        };
        break;


        // lookupswitch
        // case(101):{

        // ++(*index);
        // int padding = *(index) % 4;
        // for(int i=0; i< padding;i++){
        //     ++(*index);
        // }


        // // byte byte byte byte default
        // // byte byte byte byte 
        // ++(*index);
        // ++(*index);
        // ++(*index);
        // ++(*index);
        // ++(*index);
        // int byte1 = code_array[*index];
        // ++(*index);
        // int byte2 = code_array[*index];
        // ++(*index);
        // int byte3 = code_array[*index];
        // ++(*index);
        // int byte4 = code_array[*index];

        // int32_t byten = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
        
        // for(int i=0; i< byten;i++){
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     ++(*index);
        //     }
        // };
        // break;


        case(102):{
            value_to_opcode bytecode = (value_to_opcode)code_array[*index];

            cout << bytecode_to_opcode_string(bytecode) << ' ';

            ++(*index);
            if(code_array[*index] == iinc){
                ++(*index);
                ++(*index);
                ++(*index);
                ++(*index);
                
            }
            else{
                //opcode index1 index2
                ++(*index); 
                ++(*index);
            }

        }
        break;

        // noarguments group 
        case(0):
            cout << bytecode_to_opcode_string((value_to_opcode)code_array[*index]) << "\n";
        break;

    };


};

