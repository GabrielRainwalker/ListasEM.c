#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int vet[MAX];

typedef struct lista {
    int info;
    struct lista* prox;
    struct lista* ant;
} Lista;

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

void imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int vazia(Lista* l) {
    return (l == NULL);
}

Lista* busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL;
}

Lista* retira(Lista* l, int v) {
    Lista* p = busca(l, v);
    if (p == NULL) {
        return l;
    }
    if (p->ant == NULL) {
        l = p->prox;
    } else {
        p->ant->prox = p->prox;
    }
    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

void libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int main (void) {
 Lista* l; /* declara uma lista não iniciada */
 l = inicializa(); /* inicia lista vazia */
 l = insere(l, 23); /* insere na lista o elemento 23 */
 l = insere(l, 45); /* insere na lista o elemento 45 */
 l = insere(l, 56); /* insere na lista o elemento 56 */
 l = insere(l, 78); /* insere na lista o elemento 78 */
 imprime(l); /* imprimirá: 78 56 45 23 */
 l = retira(l, 78);
 imprime(l); /* imprimirá: 56 45 23 */
 l = retira(l, 45);
 imprime(l); /* imprimirá: 56 23 */
 libera(l);
 return 0;
}
