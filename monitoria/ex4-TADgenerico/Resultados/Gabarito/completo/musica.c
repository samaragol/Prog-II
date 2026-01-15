#include "musica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM_PARTICIPANTES 5

struct Musica{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int nParticipantes;
    char participantes[MAXTAM_PARTICIPANTES][MAXTAM_STRINGS];
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
};

Musica* musica_read_and_construct(){
    
    Musica* m = (Musica*)calloc(1,sizeof(Musica));

    scanf("%s %s %d%*c",m->titulo,m->artista,&m->nParticipantes);
    for(int i = 0; i < m->nParticipantes; i++){
        scanf("%s%*c",m->participantes[i]);
    }
    scanf("%s %s%*c",m->album,m->genero);

    return m;
}

void musica_print(void* m){
    Musica* musica = (Musica*)m;
    printf("MUSICA\n");
    printf("%s - %s", musica->artista, musica->titulo);
    if(musica->nParticipantes){
        printf(" (feat.");
        for(int i=0; i< musica->nParticipantes; i++){
            printf(" %s",musica->participantes[i]);
            if(i + 1 < musica->nParticipantes)printf(",");
        }
        printf(")");
    }
    printf("\n");
    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}

void musica_destroy(void* m){
    Musica* musica = (Musica*)m;
    if(musica)free(musica);
}