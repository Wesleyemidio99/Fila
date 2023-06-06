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
    int pegaValor, op = 0, valor = 0;

    criar(&pf);

    do{
        printf("Digite 1 - Enfileira / 2 - Desinfileirar / -1 para sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                do{
                    printf("entre com o valor para enfileirar ou -1 para sair\n");
                    scanf("%d",&valor);

                    if(valor == -1){
                        printf("Saindo...\n");
                    }
                    else{
                        if(!enfileirar(&pf,valor)){
                            printf("Erro ao enfileirar\n");
                        }
                    }
                }while(valor != -1);
                break ;

            case 2:
                do{
                    printf("Digite 1 para desinfileirar e -1 para sair\n");
                    scanf("%d",&valor);

                    if(valor == 1) {
                        if (desinfileirar(&pf, &pegaValor)) {
                            printf("retirado %d do inicio da Fila!\n", pegaValor);
                        }
                        else {
                            printf("Saindo...\n");
                        }
                    }
                }while(valor!= -1);
                break;
             }
    }while(op!=-1);

    return 0;
}
