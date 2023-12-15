#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *prox;
}node;


int main() {
    
    int opt, valor, ant;
    node *lista = NULL;
    
    do{
        
        printf("\n \t0- Sair\n \t1- Inserir Início\n \t2 - Inserir Fim\n \t3- Inserir Meio\n \t4- Imprimir\n");
        scanf("%d", &opt);
        
        switch(opt){
            case 1:
                printf("Digite um valor!\n");
                scanf("%d", &valor);
                
                inserir_no_inicio(&lista, valor);
                break;
            case 2: 
                printf("Digite um valor!\n");
                scanf("%d", &valor);
                
                inserir_no_fim(&lista, valor);
                break;
            case 3:
                printf("Digite um valor e o valor de referencia!\n");
                scanf("%d %d", &valor, &ant);
                
                inserir_no_meio(&lista, valor, ant);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opt != 0){
                    printf("Opcao invalida!\n");
                }
                    
        }
        
    }while( opt != 0);

    return 0;
}

//Inserir no início
void inserir_no_inicio(node **lista, int num){
    node *novo = malloc(sizeof(node));
    
    if (novo){
        novo->valor = num;
        novo->prox = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

//Inserir no fim
void inserir_no_fim(node **lista, int num){
    node *aux, *novo = malloc(sizeof(node));
    
    if (novo){
        novo->valor = num;
        novo->prox = NULL;
        
        //É o primeiro?
        if(*lista == NULL){
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

//Inserir no meio
void inserir_no_meio(node **lista, int num, int ant){
    node *aux, *novo = malloc(sizeof(node));
    
    if(novo){
        novo->valor = num;
        //é o primeiro?
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            // 8  9  7
            // ant = 9
            //enquanto valor != 9 && prox != NULL
            while(aux->valor != ant && aux->prox != NULL){
                aux = aux->prox;
            }
            //valor novo = 11 aponta para 7 e agora 9 ap9nta para 11
            //8 9 11 7
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

//printar lista
void imprimir(node *node){
    printf("\n \tLista: ");
    while(node != NULL){
        printf("%d ",node->valor);
        node = node->prox;
    }
    printf("\n\n");
}

