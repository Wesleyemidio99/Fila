#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no * prox;
}tno;

typedef struct fila{
    tno * comeco;
    tno * fim;
}tfila;

void criar(tfila * ppf){
    ppf->comeco = NULL;
    ppf->fim = NULL;
}
bool enfileirar(tfila * ppf, int valor){
    tno * novo = (tno *) malloc(sizeof(tno));
    if( novo == NULL){
        return false;
    }
    else{
        if(ppf->comeco == NULL){
            novo->dado = valor;
            novo ->prox = NULL;
            ppf->comeco = novo;
            ppf->fim = novo;
            printf("FilaPF[%d] ",novo->dado);
            return true;
        }
        else{
            novo->dado = valor;
            novo->prox = NULL;
            (ppf->fim)->prox = novo;
            ppf->fim = novo;
            printf("FilaPF[%d] ",novo->dado);
            return true;
        }
    }
}

bool desinfileirar(tfila * ppf, int * pegaValor){
    tno * aux;
    if(ppf->comeco == NULL){
        return false;
    }
    else{
        aux = ppf->comeco;
        *pegaValor = aux->dado;
        ppf->comeco = aux->prox;
        free(aux);
        return true;
    }
}
int main() {
    tfila * pf;
    int pegaValor;

    criar(&pf);

    if(!enfileirar(&pf,1)){
        printf("Erro ao enfileirar\n");
    }
    if(!enfileirar(&pf,2)){
        printf("Erro ao enfileirar\n");
    }

    if(desinfileirar(&pf,&pegaValor)){
        printf("retirado %d do inicio da Fila!\n",pegaValor);
    }
    return 0;
}
