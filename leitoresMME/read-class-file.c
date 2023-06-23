#include "read-class-file.h"
#include "read-bytes.h"
#include "../common/int-types.h"
#include "../common/erros.h"
#include "../common/get-utf8.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "attributes/attributes.h"

int readClassFile(char path[], ClassFile *classFile)
{
  if (!strstr(path, ".class"))
  {
    fprintf(stderr, "Arquivo não é .class\n");
    return INVALID_ARGUMENTS;
  }

  FILE *fp = fopen(path, "rb");
  if (!fp)
  {
    fprintf(stderr, "Não foi possível abrir o arquivo\n");
    return WRONG_PATH;
  }

  classFile->magic_number = readU4(fp);
  if (classFile->magic_number != 0xCAFEBABE)
  {
    fprintf(stderr, "Magic number não bateu: %x", classFile->magic_number);
    fclose(fp);
    return WRONG_MAGIC_NUMBER;
  }

  classFile->minor_version = readU2(fp);
  classFile->major_version = readU2(fp);

  classFile->constant_pool_count = readU2(fp);

  classFile->constant_pool = malloc((classFile->constant_pool_count + 1) * sizeof(cp_info));
  cp_info *begin = classFile->constant_pool + 1;
  cp_info *end = begin + classFile->constant_pool_count - 1;
  int cp_index = 1;
  for (cp_info *constant = begin; constant < end; constant++)
  {
    constant->tag = readU1(fp);
    cp_index += 1;
    switch (constant->tag)
    {
    case 7: // class
      constant->CONSTANT_Class.name_index = readU2(fp);
      break;
    case 9: // fieldRef
      constant->CONSTANT_Fieldref.class_index = readU2(fp);
      constant->CONSTANT_Fieldref.name_and_type_index = readU2(fp);
      break;
    case 10: // MethodRef
      constant->CONSTANT_Methodref.class_index = readU2(fp);
      constant->CONSTANT_Methodref.name_and_type_index = readU2(fp);
      break;
    case 11: // InterfaceMethod
      constant->CONSTANT_InterfaceMethodref.class_index = readU2(fp);
      constant->CONSTANT_InterfaceMethodref.name_and_type_index = readU2(fp);
      break;
    case 8: // String
      constant->CONSTANT_String.string_index = readU2(fp);
      break;
    case 3: // Integer
      constant->CONSTANT_Integer.bytes = readU4(fp);
      break;
    case 4: // Float
      constant->CONSTANT_Float.bytes = readU4(fp);
      break;
    case 5: // Long
      constant->CONSTANT_Long.high_bytes = readU4(fp);
      constant->CONSTANT_Long.low_bytes = readU4(fp);
      constant++;
      cp_index++;
      break;
    case 6: // Double
      constant->CONSTANT_Double.high_bytes = readU4(fp);
      constant->CONSTANT_Double.low_bytes = readU4(fp);
      constant++;
      cp_index++;
      break;
    case 12: // NameAndType
      constant->CONSTANT_NameAndType.name_index = readU2(fp);
      constant->CONSTANT_NameAndType.descriptor_index = readU2(fp);
      break;
    case 1: // utf8
      constant->CONSTANT_Utf8.length = readU2(fp);
      constant->CONSTANT_Utf8.bytes = (u1 *)malloc(sizeof(u1) * constant->CONSTANT_Utf8.length);
      for (int i = 0; i < constant->CONSTANT_Utf8.length; i++)
      {
        constant->CONSTANT_Utf8.bytes[i] = readU1(fp);
      }
      break;
    case 15: // MethodHandle
      constant->CONSTANT_MethodHandle.reference_kind = readU1(fp);
      constant->CONSTANT_MethodHandle.reference_index = readU2(fp);
      break;
    case 16: // MethodType
      constant->CONSTANT_MethodType.descriptor_index = readU2(fp);
      break;
    case 18: // InvokeDynamic
      constant->CONSTANT_InvokeDynamic.bootstrap_method_attr_index = readU2(fp);
      constant->CONSTANT_InvokeDynamic.name_and_type_index = readU2(fp);
      break;
    default:
      printf("Tag não reconhecida: %d \nabortando leitura!!\n", constant->tag);
      exit(1);
    }
  }

  classFile->access_flags = readU2(fp);

  classFile->this_class = readU2(fp);

  classFile->super_class = readU2(fp);

  classFile->interfaces_count = readU2(fp);

  classFile->interfaces = malloc((classFile->interfaces_count) * sizeof(u2));

  for (u2 interface_index = 0; interface_index < classFile->interfaces_count; interface_index++)
  {
    u2 *interface = &(classFile->interfaces[interface_index]);
    *interface = readU2(fp);
  }

  classFile->fields_count = readU2(fp);

  classFile->fields = malloc((classFile->fields_count) * sizeof(field_info));
  for (u2 field_index = 0; field_index < classFile->fields_count; field_index++)
  {
    field_info *field = &(classFile->fields[field_index]);

    field->access_flags = readU2(fp);

    field->name_index = readU2(fp);

    field->descriptor_index = readU2(fp);

    field->attributes_count = readU2(fp);

    field->attributes = malloc((field->attributes_count) * sizeof(attribute_info));

    readAttributes(classFile->constant_pool, field->attributes, fp, field->attributes_count);
  }

  classFile->methods_count = readU2(fp);
  classFile->methods = malloc((classFile->methods_count) * sizeof(method_info));
  ;
  for (u2 i = 0; i < classFile->methods_count; i++)
  {
    method_info *method = &(classFile->methods[i]);

    method->access_flags = readU2(fp);

    method->name_index = readU2(fp);

    method->descriptor_index = readU2(fp);
    // dá pra reutilizar o código de atributos
    method->attributes_count = readU2(fp);

    method->attributes = malloc((method->attributes_count) * sizeof(attribute_info));
    readAttributes(classFile->constant_pool, method->attributes, fp, method->attributes_count);
  }

  classFile->attributes_count = readU2(fp);

  classFile->attributes = malloc((classFile->attributes_count) * sizeof(attribute_info));

  readAttributes(classFile->constant_pool, classFile->attributes, fp, classFile->attributes_count);
  fclose(fp);

  return 0;
}
