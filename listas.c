#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int data;
    struct TNode *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

void init(List *lista);
void add(List *lista, int valor);
void show(List *lista);
void clear(List *lista);
int removeFirst(List *lista);
int removeLast(List *lista);
int removePosition(List *lista, int posicao);
void addFirst(List *lista, int valor);
void insertPosition(List *lista, int position, int valor);

void init(List *lista)
{
    lista->head = lista->tail = NULL;
    lista->size = 0;
}

void add(List *lista, int valor)
{
    Node *novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    if (lista->size == 0)
    {
        lista->head = novo;
    }
    else
    {
        lista->tail->next = novo;
    }
    lista->tail = novo;
    lista->size++;
}

void show(List *lista)
{
    Node *aux = lista->head;
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void clear(List *lista)
{
    // while(lista->size > 0)
    // removeFirst(lista);

    Node *aux = lista->head;
    while (aux != NULL)
    {
        aux = aux->next;
        free(lista->head);
        lista->head = aux;
    }
    lista->tail = NULL;
    lista->size = 0;
}

int removeFirst(List *lista)
{
    Node *aux = lista->head;
    lista->head = aux->next;
    int valor = aux->data;
    lista->size--;
    if (lista->size == 0)
    { // Lista vazia?
        lista->tail = NULL;
    }
    free(aux);
    return valor;
}

int removeLast(List *lista){
    Node *aux = lista->head;
    if(lista->size == 1){
        removeFirst(lista);
    }

    //enquanto não for o PENÚLTIMO ELEMENTO
    while(aux->next != lista->tail){
        aux = aux->next;
    }

    int valor = aux->next->data;
    aux->next = NULL;
    lista->tail = aux;
    lista->size--;

    //libera o nodo da memória
    free(aux->next);
    return valor;
}

int removePosition(List *lista, int posicao){

    Node *aux = lista->head;

    if(posicao == 0) return removeFirst(lista);
    if(posicao == lista->size-1) return removeLast(lista);

    for(int i = 0; i<posicao-1; i++){
        aux = aux->next;
    }

    Node *target = aux->next;
    int valor = target->data;
    aux->next = target->next;
    lista->size--;
    free(target);

    return valor;
}

void addFirst(List *lista, int valor)
{
    if (lista->size == 0){
        add(lista,valor);
        return;
    }

    Node *novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->next = lista->head;
    lista->head = novo;
    lista->size++;
}

int main()
{
    List minhaLista;
    for (int i = 0; i < 100; i++)
        addFirst(&minhaLista, i);

    show(&minhaLista);
/*
    while (minhaLista.size > 0)
    {
        int v = removeFirst(&minhaLista);
        printf("Primeiro elemento: %d\n", v);
    }
    clear(&minhaLista);
    */

    /*
    for(int i = 0; i<5; i++){
        printf("\n");
        removeLast(&minhaLista);
        show(&minhaLista);
    }*/
    for(int i = 1; i<99; i++){
    removePosition(&minhaLista, 1);
    show(&minhaLista);
    }
    printf("\n%d\n", minhaLista.size);
}