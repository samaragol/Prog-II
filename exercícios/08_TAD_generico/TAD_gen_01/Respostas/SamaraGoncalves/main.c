#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type, numElem;
    tGeneric *vetor;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d\n", &type, &numElem);
    vetor = CriaGenerico(type, numElem);
    LeGenerico(vetor);
    ImprimeGenerico(vetor);
    DestroiGenerico(vetor);
    return 0;
}