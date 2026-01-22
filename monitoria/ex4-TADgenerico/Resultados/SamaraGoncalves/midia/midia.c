#include "midia.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura do tipo Mídia, contendo:
 *
 * - Dado : a midia em si (ponteiro void que guarda um Livro, Música ou Pintura)
 *
 * - Print_fn: objeto do tipo PrintFunction que guarda qual a função que imprime a Mídia
 *
 * - Free_fn: objeto do tipo FreeFunction que guarda qual a função que libera a Mídia
 */
struct Midia
{
    void *dado;
    PrintFunction print_fn;
    FreeFunction free_fn;
};

/**
 * @brief Cria uma Mídia alocada dinamicamente, a partir dos parâmetros dados.
 *
 * OBS: Ao usar/chamar a função, print_fn e free_fn devem ser funções já criadas nos outros TADs,
 * passadas diretamente como argumentos.
 * @param dado a midia em si (ponteiro void que guarda um Livro, Música ou Pintura).
 * @param print_fn objeto do tipo PrintFunction que guarda qual a função que imprime a Mídia.
 * @param free_fn objeto do tipo FreeFunction que guarda qual a função que libera a Mídia.
 * @return Um objeto do tipo música lido da entrada padrão e devidamente alocado.
 */
Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    Midia *mid;

    mid = (Midia *)calloc(1, sizeof(Midia));
    mid->dado = dado;
    mid->print_fn = print_fn;
    mid->free_fn = free_fn;

    return mid;
}

/**
 * @brief Imprime uma Mídia na tela, usando a função de impressão presente na própria Mídia.
 * @param m Mídia a ser impressa.
 */
void midia_print(Midia *m)
{
    m->print_fn(m->dado);
}

/**
 * @brief Libera uma Mídia da memória, usando a função de liberação presente na própria Mídia.
 * @param m Mídia a ser liberada.
 */
void midia_destroy(Midia *m)
{
    m->free_fn(m->dado);
    free(m);
}
