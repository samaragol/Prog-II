#include "pintura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pintura{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int ano;
};

Pintura* pintura_read_and_construct(){
    Pintura* p = malloc(sizeof(Pintura));
    scanf("%s%s%s%s%d%*c",p->titulo,p->artista,p->movimento,p->material,&p->ano);
    return p;
}

void pintura_print(void* p){
    Pintura* pintura = (Pintura*)p;
    printf("PINTURA\nTitulo: %s\nArtista: %s\nMovimento: %s\nMaterial: %s\nAno: %d\n",
    pintura->titulo,pintura->artista,pintura->movimento,pintura->material,pintura->ano);
}

void pintura_destroy(void* p){
    Pintura* pintura = (Pintura*)p;
    if(pintura)free(pintura);
}