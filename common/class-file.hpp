#include <stdint.h>
#include <string>
#ifndef TYPESH
#define TYPESH

using namespace std;


// definindo os tamanhos
/// @brief Tipo u1 - 8bits
typedef uint8_t u1;

/// @brief Tipo u2 - 16bits
typedef uint16_t u2;

/// @brief Tipo u4 - 32bits
typedef uint32_t u4;

/// @brief Tipo u8 - 64bits
typedef uint64_t u8;

// referenciando o attribute
struct Attribute_info;

const string JAVA_OBJ_CLASSNAME = "java/lang/Object";
const string JAVA_PRINT_CLASSNAME = "java/io/PrintStream";
const string JAVA_STRING_CLASSNAME = "Ljava/lang/String;";


// ---------------------------- LOCAL VARIABLE TABLE STRUCTURE ----------------------------- //

/// @brief Struct para a definição da local variable table
typedef struct Local_variable_table{   
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
} Local_variable_table;

// ---------------------------- LOCAL VARIABLE TABLE ATTRIBUTE ----------------------------- //

/// @brief Struct para a definição da local variable table attribute
typedef struct LocalVariableTable_attribute {
    u2 local_variable_table_length;
    Local_variable_table *local_variable_table;
} LocalVariableTable_attribute;


// ---------------------------- LINE NUMBER TABLE STRUCTURE ----------------------------- //

/// @brief Struct para a definição da line number table
typedef struct line_number_table{
    u2 start_pc;
    u2 line_number;
} Line_number_table;

// ---------------------------- LINE NUMBER TABLE ATTRIBUTE ----------------------------- //

/// @brief Struct para a definição da line number table attribute
typedef struct LineNumberTable_attribute{
    u2 line_number_table_length;
    Line_number_table *line_number_table;
} LineNumberTable_attribute;


// ---------------------------- INNER CLASS STRUCTURE ----------------------------- //

/// @brief Struct para a definição das inner classes
typedef struct inner_classes{
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;
} Inner_classes;

// ---------------------------- INNER CLASS ATTRIBUTE ----------------------------- //

/// @brief Struct para a definição das inner classes attribute
typedef struct InnerClasses_attribute {
    u2 number_of_classes;
    Inner_classes *inner_classes;
} InnerClasses_attribute;

// ---------------------------- EXCEPTION TABLE STRUCTURE ----------------------------- //

/// @brief Struct para a definição da exception table
typedef struct Exception_table{
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
} Exception_table;

// ---------------------------- EXCEPTION ATTRIBUTE ----------------------------- //

/// @brief Struct para a definição dos exceptions attribute
typedef struct exceptions_attribute {
    u2 number_of_exceptions;
    // cada valor é um constant pool index -> constant class info
    u2 *exception_index_table;
} Exceptions_attribute;


// ---------------------------- CODE ATTRIBUTE ----------------------------- //

// se for abstract ou native nao tem codigo... se não, temos que ter apenas um atributo de código
/// @brief Struct para a definição do code attribute
typedef struct code_attribute{
    u2 max_stack;
    u2 max_locals;
    u2 code_length; //aqui temos a quantidade de bytes no code array
    u1 *code; //aqui temos um ponteiro para o code array que apresenta os opcodes 
    u2 exception_table_length;
    Exception_table *exception_table;  
    u2 attribute_count;
    struct Attribute_info *attributes; //como está aqui embaixo, temos que referenciar como struct
} Code_attribute;

// ---------------------------- ATTRIBUTE ----------------------------- //

/// @brief Struct para a definição do attribute info
typedef struct Attribute_info{
    u2 attribute_name_index; //nome em utf8
    u4 attribute_length; //

    // aqui temos as diferencas entre os atributos
    union attribute_info_union{
        u2 constantvalue_index; //aqui não precisamos de uma struct completa visto que temos apenas campo 
        Code_attribute code_attribute;
        Exceptions_attribute exceptions_attribute;
        InnerClasses_attribute innerClasses_attribute;
        LineNumberTable_attribute lineNumberTable_attribute;
        LocalVariableTable_attribute localVariableTable_attribute;
    } attribute_info_union;
    
} Attribute_info;


// ---------------------------- METHODS ----------------------------- //

/// @brief Struct para a definição do Method Info
typedef struct Method_info{
    u2 access_flags; 
    u2 name_index;          //aqui nesse caso pode ser <init>, <clinit> ou um nome valido para o metodo
    u2 descriptor_index;            
    u2 attributes_count;
    Attribute_info *attributes;  //aqui acessamos o atribute info utilizando o count para acessar uma estrutura de atribute info

}Method_info;

// ---------------------------- FIELDS ----------------------------- //

/// @brief Struct para a definição do Field Info
typedef struct field_info{
    u2 access_flags; 
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    Attribute_info *attributes;  //aqui acessamos o atribute info utilizando o count
}field_info;

/// @brief Struct para a definição do cp_info
typedef struct cp_info{
    u1 tag;

    union constant_type_union{

        struct{
            u2 name_index;
        } Class_info;

        struct{
            u2 class_index;
            u2 name_and_type_index;
        } Fieldref_info;

        struct{
            // representa um indice para um tipo class_info na constant pool
            u2 class_index;
            u2 name_and_type_index;
        } Methodref_info;
        
        struct{
            u2 class_index;
            u2 name_and_type_index;
        } InterfaceMethodref_info;
        
        struct{
            u2 name_index;
            u2 descriptor_index;
        } NameAndType;
        
        struct{
            u2 length;          //indica o número de bytes no array bytes (embaixo) pode ser 1, 2 ou 3 bytes
            u1 *bytes;          //quando formos alocar os bytes levamos em conta o numero de bytes aqui é um array

            // u1 *bytes = (u1 *) malloc(length * sizeof(u1));     //aqui criamos um espaço de memória do tamanho do problema. (u1 tem 1 bit)
        } Utf8;
        
        struct{
            u2 string_index;
        } String;
        
        struct{
            u4 bytes;
        } Integer;
        
        struct{
            u4 bytes;
        } Float;
        
        struct{
            u4 high_bytes;
            u4 low_bytes;
        } Long;
        
        struct{
            u4 high_bytes;
            u4 low_bytes;
        } Double;

    } constant_type_union;

} cp_info;



/// @brief Struct para a definição da ClassFile
typedef struct ClassFile
{
    u4 magic;
    u2 minor_version;
    u2 major_version;
    u2 constant_pool_count;
    // aqui temos um array/tabela do tipo cp_info que contem todas as constantes do constant pool
    cp_info *constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    u2 *interfaces; //aqui temos um array com os indices apontando para o constant poll
    u2 fields_count;
    field_info *fields;
    u2 methods_count;
    Method_info *methods;
    u2 attributes_count;
    Attribute_info *attributes;

} ClassFile;


/// @brief Struct Enum para [POOL DE CONSTANTES TIPOS VÁLIDOS DE TAGS]
enum tag_to_class
{
    CONSTANT_Class_info = 7,
    CONSTANT_Fieldref_info = 9,
    CONSTANT_Methodref_info = 10,
    CONSTANT_InterfaceMethodref_info = 11,
    CONSTANT_String_info = 8,
    CONSTANT_Integer_info = 3,
    CONSTANT_Float_info = 4,
    CONSTANT_Long_info = 5,
    CONSTANT_Double_info = 6,
    CONSTANT_NameAndType_info = 12,
    CONSTANT_MethodHandle_info = 15,
    CONSTANT_MethodType_info = 16,
    CONSTANT_InvokeDynamic_info = 18,
    CONSTANT_Utf8_info = 1,
};

#endif