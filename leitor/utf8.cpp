#include "utf8.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

// essa função vai retornar um vetor de char
// pegar o cp info em questão usar o length para iterar e "concatenar" a string 
char* Utf8_decoder(cp_info *cp_info_pointer){
    
    // pegar o tamanho
    u2 length = cp_info_pointer->constant_type_union.Utf8.length;
    printf("length %d\n", length);


    // alocando espaço em memória para a string
    char* string = (char *) malloc((length) * sizeof(char)); 
    // alimentando a string com os caracteres?
    for(u2 i = 0; i < length; i++){
        // pegar o byte em questão e transfomar para char
        printf("%p\n", cp_info_pointer->constant_type_union.Utf8.bytes);
        printf("%d\n", cp_info_pointer->constant_type_union.Utf8.bytes[0]);
        u1 byte = cp_info_pointer->constant_type_union.Utf8.bytes[i];
        string[i] =  byte;
    };

    return string;
}