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
    Lista aux = *p_l;
    Lista anterior = NULL;
    Lista novo = (No_lista *)malloc(sizeof(No_lista));
    novo->info = e;
    if (*p_l == NULL) // se a lista estiver vazia insere no primeiro elemento
    {
        novo->ant = NULL;
        novo->prox = NULL;
        *p_l = novo;
    }
    while (aux->prox != NULL && aux->info < e)
    {
        aux = aux->prox;
    }
    if (aux->info == e) // caso o elemento ja esteja na lista
    {
        free(novo);
        return 0;
    }
    if (aux->ant == NULL) // caso seja o primeiro elemento
    {
        novo->prox = *p_l;
        novo->ant = NULL;
        return 1;
    }
    novo->ant = aux;
    novo->prox = aux->prox->prox;
    aux->prox = novo;
    return 1;
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l)
{
    Lista aux = *p_l;
    if (aux == NULL)
    { // retorna 0 caso a lista esteja vazia
        return 0;
    }
    if (aux->prox == NULL)
    { // se a lista só tem um elemento esta ordenada
        return 1;
    }
    while (aux->prox != NULL)
    {
        if (aux->info < aux->prox->info)
        { // retorna 0 caso a lista não esteja ordenada
            return 0;
        }

        aux = aux->prox; // avança o ponteiro auxiliar
    }
}

/* Ordena a lista */
void ordena(Lista *p_l)
{
    // Casos base: lista vazia ou com apenas um elemento
    if (*p_l == NULL || (*p_l)->prox == NULL) {
        return;
    }

    Lista ordenada = NULL;  // Lista ordenada (inicialmente vazia)
    Lista atual = *p_l;     // Ponteiro para percorrer a lista original

    while (atual != NULL) {
        Lista proximo = atual->prox;  // Guarda o próximo nó antes de modificá-lo
        
        // Caso 1: lista ordenada está vazia ou o elemento atual é menor que o primeiro
        if (ordenada == NULL || atual->info <= ordenada->info) {
            atual->prox = ordenada;
            atual->ant = NULL;
            if (ordenada != NULL) {
                ordenada->ant = atual;
            }
            ordenada = atual;
        } 
        // Caso 2: inserir no meio ou final da lista ordenada
        else {
            Lista temp = ordenada;
            // Encontra o ponto de inserção
            while (temp->prox != NULL && temp->prox->info < atual->info) {
                temp = temp->prox;
            }
            // Insere o nó atual
            atual->prox = temp->prox;
            atual->ant = temp;
            if (temp->prox != NULL) {
                temp->prox->ant = atual;
            }
            temp->prox = atual;
        }

        atual = proximo;  // Avança para o próximo nó
    }

    *p_l = ordenada;  // Atualiza o ponteiro da lista
}

/* Remove o elemento que está no início da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e)
{
    if (*p_l == NULL)
    { // retorna 0 caso a lista estja vazia
        return 0;
    }
    *p_l = (*p_l)->prox;
    (*p_l)->ant = NULL;
}

/* Remove o elemento que está no final da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e)
{
    Lista remove;
    if (*p_l == NULL)
    {
        return 0;
    }
    while ((*p_l)->prox != NULL) // precorre o ponteiro ate o final
    {
        (*p_l) = (*p_l)->prox;
    }
    remove = *p_l;
    (*p_l) = (*p_l)->ant;
    (*p_l)->prox = NULL; // remove o ultimo elemento
    free(remove);
    while ((*p_l)->ant != NULL)
    {
        *p_l = (*p_l)->ant;
    }
}

/* Remove o nó de valor e.
   Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e)
{
    Lista aux = *p_l;
    if(*p_l == NULL){
        return 0; //lista vazia
    }
    if((*p_l) ->info == e){
        *p_l = NULL; // somente um elemento
    }
    while(aux ->prox != NULL){
        if(aux->info == e){
            if(aux->ant == NULL){
                aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            }
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            aux = NULL;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;

}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l)
{
    Lista aux = *p_l;
    Lista temp = NULL;
    
    // Caso especial: lista vazia ou com apenas um elemento
    if (aux == NULL || aux->prox == NULL) {
        return;
    }
    
    // Percorre a lista trocando os ponteiros
    while (aux != NULL) {
        // Guarda o ponteiro anterior
        temp = aux->ant;
        
        // Inverte os ponteiros
        aux->ant = aux->prox;
        aux->prox = temp;
        
        // Avança para o próximo nó (que agora está em ant)
        aux = aux->ant;
    }
    
    // Atualiza o ponteiro da lista para o novo primeiro elemento
    if (temp != NULL) {
        *p_l = temp->ant;
    }
}

/* Remove todos os nós da lista */
void libera(Lista *p_l)
{
    Lista aux = *p_l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    while(aux->ant != NULL){

    }


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
