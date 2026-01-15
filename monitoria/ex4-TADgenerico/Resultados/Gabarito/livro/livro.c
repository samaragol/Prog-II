#include "livro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro{
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int ano;
};

Livro* livro_read_and_construct(){
    Livro* l = (Livro*)malloc(sizeof(Livro));

    scanf("%s %s %s %s %d%*c",l->titulo,l->autor,l->genero,l->editora,&l->ano);

    return l;
}

void livro_print(void* l){
    Livro* livro = (Livro*)l;
    printf("LIVRO\nTitulo: %s\nAutor: %s\nGenero: %s\nEditora: %s\nAno: %d\n",
    livro->titulo,livro->autor,livro->genero,livro->editora,livro->ano);
}

void livro_destroy(void* l){
    Livro* livro = (Livro*)l;
    if(livro)free(livro);
}