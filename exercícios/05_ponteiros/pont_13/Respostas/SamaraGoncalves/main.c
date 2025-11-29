#include <stdio.h>
#include "rolagem.h"

void fazAlgo(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs)
{ 
}

int main()
{
    int qtd, i;
    int tamanhoDisplay = 30, tempoFim;
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];

    scanf("%d\n", &qtd);

    for (i = 0; i < qtd; i++)
    {
        scanf("%[^\n]\n", msg[i]);
    };

    scanf("%d", &tempoFim);

    RolaMsg(fazAlgo, tamanhoDisplay, tempoFim);

    return 0;
}