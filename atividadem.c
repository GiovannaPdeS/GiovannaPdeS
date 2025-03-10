#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    long cpf;
    int idade;
    struct pessoa* conjuge;
} PESSOA;

void envelhecer1(PESSOA p) {
    p.idade++; 
}

void envelhecer2(PESSOA* p) {
    p->idade++; 
}

void envelhecer3(PESSOA p) {
    if (p.conjuge != NULL) {
        p.conjuge->idade++; 
    }
}

void envelhecer4(PESSOA* p) {
    if (p->conjuge != NULL) {
        p->conjuge->idade++; 
    }
}

void separar(PESSOA* p1, PESSOA* p2) {
    p1->conjuge = NULL; 
    p2->conjuge = NULL; 
}

void casar(PESSOA* p2, PESSOA* solteira) {
    p2->conjuge = solteira; 
    solteira->conjuge = p2; 
}

int main() {
    PESSOA* pessoal = (PESSOA*)malloc(sizeof(PESSOA));
    PESSOA* pessoa2 = (PESSOA*)malloc(sizeof(PESSOA));
    PESSOA* solteira = (PESSOA*)malloc(sizeof(PESSOA));

    pessoal->cpf = 310000000;
    pessoal->idade = 36;
    pessoa2->cpf = 290000000;
    pessoa2->idade = 35;
    pessoal->conjuge = pessoa2;
    pessoa2->conjuge = pessoal;

    solteira->cpf = 230000000;
    solteira->idade = 30;
    solteira->conjuge = NULL;

    envelhecer1(*pessoal);
    envelhecer2(pessoal);
    envelhecer3(*pessoal);
    envelhecer4(pessoal);

    printf("Pessoa 1 - CPF: %ld, Idade: %d, Cônjuge: CPF: %ld\n", pessoal->cpf, pessoal->idade, pessoal->conjuge->cpf);
    printf("Pessoa 2 - CPF: %ld, Idade: %d, Cônjuge: CPF: %ld\n", pessoa2->cpf, pessoa2->idade, pessoa2->conjuge->cpf);
    printf("Pessoa Solteira - CPF: %ld, Idade: %d, Cônjuge: NULL\n", solteira->cpf, solteira->idade);

    separar(pessoal, pessoa2);

    printf("\nApós Separação:\n");
    printf("Pessoa 1 - CPF: %ld, Idade: %d, Cônjuge: NULL\n", pessoal->cpf, pessoal->idade);
    printf("Pessoa 2 - CPF: %ld, Idade: %d, Cônjuge: NULL\n", pessoa2->cpf, pessoa2->idade);

    casar(pessoa2, solteira);

    printf("\nApós Casamento:\n");
    printf("Pessoa 2 - CPF: %ld, Idade: %d, Cônjuge: CPF: %ld\n", pessoa2->cpf, pessoa2->idade, pessoa2->conjuge->cpf);
    printf("Pessoa Solteira - CPF: %ld, Idade: %d, Cônjuge: CPF: %ld\n", solteira->cpf, solteira->idade, solteira->conjuge->cpf);

    free(pessoal);
    free(pessoa2);
    free(solteira);

    return 0;
}
