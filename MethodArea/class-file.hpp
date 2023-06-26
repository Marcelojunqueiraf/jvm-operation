#include "../common/index.hpp"


#ifndef	CLASS_FILE_H
#define CLASS_FILE_H


typedef struct {
  u1 tag;
  union {
    struct {
      u2 name_index;
    } CONSTANT_Class;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_Fieldref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_Methodref;
    struct {
      u2 class_index;
      u2 name_and_type_index;
    } CONSTANT_InterfaceMethodref;
    struct {
      u2 string_index;
    } CONSTANT_String;
    struct {
      u4 bytes;
    } CONSTANT_Integer;
    struct {
      u4 bytes;
    } CONSTANT_Float;
    struct {
      u4 high_bytes;
      u4 low_bytes;
    } CONSTANT_Long;
    struct {
      u4 high_bytes;
      u4 low_bytes;
    } CONSTANT_Double;
    struct {
      u2 name_index;
      u2 descriptor_index;
    } CONSTANT_NameAndType;
    struct {
      u2 length;
      u1 * bytes;
    } CONSTANT_Utf8;
    struct {
      u1 reference_kind;
      u2 reference_index;
    } CONSTANT_MethodHandle;
    struct {
      u2 descriptor_index;
    } CONSTANT_MethodType;
    struct {
      u2 bootstrap_method_attr_index;
      u2 name_and_type_index;
    } CONSTANT_InvokeDynamic;
  };
} cp_info;

typedef struct {
  u2 attribute_name_index;
  u4 attribute_length;
  u1 * info;
} attribute_info;

typedef struct {
 u2 access_flags;
 u2 name_index;
 u2 descriptor_index;
 u2 attributes_count;
 attribute_info * attributes;
} field_info;

typedef struct Method_info{
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info * attributes;
} Method_info;

typedef struct {
  u4 magic_number;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  cp_info * constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  u2 * interfaces;
  u2 fields_count;
  field_info * fields;
  u2 methods_count;
  Method_info * methods;
  u2 attributes_count;
  attribute_info * attributes;
} ClassFile;

//attributes
typedef struct{
  u2 start_pc;
  u2 end_pc;
  u2 handler_pc;
  u2 catch_type;
} Exception_table;

typedef struct  {
  u2 max_stack;
  u2 max_locals;
  u4 code_length;
  u1 * code;
  u2 exception_table_length;
  Exception_table * exception_table;
  u2 attributes_count;
	attribute_info * attributes;
} code_attribute;

typedef struct {
  u2 start_pc;
  u2 line_number;
} Line_number_table;

typedef struct {
  u2 line_number_table_length;
  Line_number_table * line_number_table; // Alocar com line_number_table_length
} LineNumberTable_attribute;

typedef struct {
  u2 sourcefile_index;
} SourceFile_attribute;

typedef struct {
  u2 number_of_exceptions;
  u2 * exception_index_table; // Alocar com number_of_exceptions
} Exceptions_attribute;

typedef struct {
  u2 constantvalue_index;
} ConstantValue_attribute;

typedef struct {
    u2 inner_class_info_index;
    u2 outer_class_info_index;
    u2 inner_name_index;
    u2 inner_class_access_flags;
} ClassType;

typedef struct {
  u2 number_of_classes;
  ClassType * classes; // Alocar com number_of_classes
} InnerClasses_attribute;

typedef struct { 
  u2 start_pc;
  u2 length;
  u2 name_index;
  u2 descriptor_index;
  u2 index;
} Local_variable_table;

typedef struct {
  u2 local_variable_table_length;
  Local_variable_table * local_variable_table; // Alocar com local_variable_table_length
} LocalVariableTable_attribute;

#endif
