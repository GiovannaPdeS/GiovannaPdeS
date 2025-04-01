// Objetivo da Atividade:
// Desenvolver a habilidade de manipular pilhas estáticas utilizando apenas
// suas operações fundamentais (push, pop) e simular um algoritmo de
// ordenação sem acessar diretamente os índices.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int topo;
    int itens[MAX];
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int item) {
    if (!estaCheia(p)) {
        p->topo++;
        p->itens[p->topo] = item;
    }
}

int pop(Pilha *p) {
    if (!estaVazia(p)) {
        int item = p->itens[p->topo];
        p->topo--;
        return item;
    }
    return -1; 
}

int peek(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[p->topo];
    }
    return -1; 
}

void inserirOrdenado(Pilha *p, int item) {
    if (estaVazia(p) || peek(p) <= item) {
        push(p, item);
        return;
    }
    int temp = pop(p);
    inserirOrdenado(p, item);
    push(p, temp);
}

void ordenarPilha(Pilha *p) {
    if (!estaVazia(p)) {
        int temp = pop(p);
        ordenarPilha(p);
        inserirOrdenado(p, temp);
    }
}

void imprimirPilha(Pilha *p) {
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha P;
    inicializar(&P);
    
    push(&P, 3);
    push(&P, 1);
    push(&P, 4);
    push(&P, 2);
    
    printf("Pilha antes da ordenação:\n");
    imprimirPilha(&P);
    
    ordenarPilha(&P);
    
    printf("Pilha depois da ordenação:\n");
    imprimirPilha(&P);
    
    return 0;
}
