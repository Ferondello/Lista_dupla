#include "listaDupla.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa uma lista */
void cria(Lista *p_l)
{
    *p_l = NULL;
}

/* Verifica se a lista está vazia ou não */
int vazia(Lista *p_l)
{
    if (*p_l == NULL)
    {
        return 1;
    }
    return 0;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, elem_t e)
{
    Lista novo;
    novo = (No_lista *)malloc(sizeof(No_lista));
    novo->info = e;
    novo->ant = NULL;
    novo->prox = *p_l;

    if (*p_l != NULL)
    {
        (*p_l)->ant = novo;
    }

    *p_l = novo;
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e)
{
    Lista aux = *p_l;
    Lista novo = (No_lista *)malloc(sizeof(No_lista));
    novo->info = e;
    novo->prox = NULL; // aloca espaço para mais informações

    if (*p_l == NULL)
    { // se a lista estiver vazia, insere no primeiro elemento
        *p_l = novo;
    }

    while (aux->prox != NULL)
    {
        aux = aux->prox; // percorre a variavel aux ate o fim da lista
    }
    novo->ant = aux;
    aux->prox = novo; // insere o novo elemento no final
}

/* Insere um elemento na lista de maneira ordenada.
   Retorna 0 caso o elemento já exista na lista.
   Assume que a lista está ordenada */
int insere_ordenado(Lista *p_l, elem_t e)
{
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l)
{
}

/* Ordena a lista */
void ordena(Lista *p_l)
{
}

/* Remove o elemento que está no início da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e)
{
}

/* Remove o elemento que está no final da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e)
{
}

/* Remove o nó de valor e.
   Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e)
{
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l)
{
}

/* Remove todos os nós da lista */
void libera(Lista *p_l)
{
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l)
{
    Lista aux = *p_l;

    while (aux != NULL)
    {
        printf("-> %d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
