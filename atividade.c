#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    long cpf;
    int idade;
    struct pessoa* conjuge;
} PESSOA;

void envelhecer (PESSOA* p) {
    p->idade++;
}

void envelhercer (PESSOA* p){
    if (p->conjuge != NULL){
        P->conjuge->idade++;
    }
}

void separar (PESSOA* p1, PESSOA*p2){
    p1->conjuge = NULL;
    p2->conjuge = NULL;
}

void casar (PESSOA* p1, PESSOA*p2) {
    p1->conjuge = p2
    p2->conjuge = p1
}

int main() {
    PESSOA* pessoa1 = (PESSOA*)malloc(sizeof(PESSOA));
    PESSOA* pessoa2 = (PESSOA*)malloc(sizeof(PESSOA));
    PESSOA* solteira = (PESSOA*)malloc(sizeof(PESSOA));

pessoa1->cpf = 310000000;
pessoa1->idade = 36;
pessoa2->cpf = 290000000;
pessoa2->idade = 35
pessoa1->conjuge = pessoa2;
pessoa2->conjuge = pessoa1;

solteira->cpf = 230000000;
solteira->idade = 30
solteira->conjuge = NULL;

envelhercer(pessoa1);
envelhecerConjuge(pessoa1);

printf("Antes da Separação:\n");
printf("Pessoa 1: CPF = %1d, Idade = %d, Conjuge = CPF = %1d\n", pessoa1->cpf. pessoa1->idade, pessoa1->cpf);
printf("Pessoa 2: CPF = %1d, Idade = %d, Conjuge = CPF = %1d\n", pessoa2->cpf. pessoa2->idade, pessoa2->cpf);
printf("Pessoa Solteira: CPF = %1d, Idade = %d, Conjuge = NULL\n\n", solteira ->cpf, solteira->idade);

separar (pessoa1, pessoa2);

printf("Apos a Separação:\n");
printf("Pessoa 1: CPF = %1d, Idede = %d, Conjuge = NULL\n", pessoa1->cpf, pessoa1->idade);
printf("Pessoa 2: CPF = %1d, Idede = %d, Conjuge = NULL\n\n", pessoa2->cpf, pessoa1->idade);

casar(pessoa2, solteira);

printf("Apos o Casamento:\n");
printf("Pessoa 2: CPF = %1d, Idede = %d, Conjuge = CPF = %1d\n", pessoa2->cpf, pessoa2->idade, pessoa2->conjuge->cpf);
printf("Pessoa Solteira: CPF = %1d, Idede = %d, Conjuge = CPF = %1d\n", solteira->cpf, solteira->idade, solteira->conjuge->cpf);

free(pessoa1);
free(pessoa2);
free(solteira);

return 0;

}
