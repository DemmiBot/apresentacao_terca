/*
    Apresentacao sobre vetores, matrizes, ponteiros e lista encadeada
    Grupo 1:
    -Gabriel Felix
    -David Lukas
    -Samuel Kevin
    -Alleck Luka
    -Victor Lorran
    -Lucas Costa
    -Samuel Santana
    -Karla juliane
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*https://www.learn-c.org/en/Linked_lists*/
typedef struct node{
    int value;                  /*Valor guardado em dada posicao*/
    struct node * next;         /*ponteiro para a proxima posicao*/
}node_t;                        /*Nome padrao*/

void push(node_t **head, int val) {
    node_t * new_node;                              /*Cria e*/
    new_node = (node_t *)malloc(sizeof(node_t));    /*Aloca novo node*/
    new_node->value = val;                          /*Novo node recebe valor passado pela funcao*/
    new_node->next = *head;                         /*next recebe a posicao na memoria do head anterior*/
    *head = new_node;                               /*ponteiro do head aponta agora para
                                                    new node, efetivamente tornando new_node o novo head.*/
}

int pop(node_t **head) {
    int retval = -1;                /*variavel para retornar valor removido*/
    node_t* next_node= NULL;

    if(*head==NULL){
        printf("\nList is empty!");
        return -1;
    }

    next_node = (*head)->next;      /*armazena o proximo node*/
    retval = (*head)->value;        /*valor retornado*/
    free(*head);
    *head = next_node;              /*novo head*/
    return retval;
}

void freeList(node_t* head) {
   node_t* aux;
   while (head != NULL)
    {
       aux = head;
       head = head->next;
       free(aux);
    }
}

void printList(node_t *head) {
    node_t *current = head;
    while(current !=NULL){
        printf("[%d]", current->value);
        current = current->next;
    }
}

/*https://stackoverflow.com/questions/5630478/printing-arrays-in-separate-function-in-c*/
void printArray(int* arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("[%d]", arr[i]);
    }
}

/*https://beginnersbook.com/2014/01/c-passing-array-to-function-example/*/
void readArray(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d: ", i+1);
        printf("Insert N# %d: ", i+1);
        scanf("%d", arr);
        arr++; /*a é um ponteiro para o primeiro indice do vetor, ou seja, é o mesmo que &arr[0]*/
    }
}


int main(){
    int opt;
    do{
        printf("Selecione o exemplo: \n\n[1]Vetores \n[2]Matrizes \n[3]Ponteiros, Alocacao e exemplos\n[0]Finalizar Programa\n\nEscolha: ");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            {
                /*-Criação de um vetor; -Inicialização de um vetor;*/

                printf("------------------------------------------------------------------");
                printf("\nInicializar vetor e testes: ");
                printf("\n------------------------------------------------------------------");

                int arr[10]; /*Criacao do vetor*/
                printf("Array arr (lixo de memoria): ");
                printArray(arr, 10);
                printf("\n");

                arr[10] = 12; /* UNDEFINED, qualquer coisa pode ocorrer, até a ilusão de funcionar */
                printf("\nAcessando valor fora do vetor: %d\n\n", arr[10]);

                int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; /*Hardcode*/

                printf("Array arr2: ");
                printArray(arr2, 10);

                int i, tamanhoArray;
                printf("\n\n\n------------------------------------------------------------------");
                printf("\nConstruir array com input: ");
                printf("\n------------------------------------------------------------------");

                printf("\n\nInsira o tamanho do array: ");
                scanf("%d", &tamanhoArray);
                int arr3[tamanhoArray];

                for(i=0;i<tamanhoArray;i++) {
                    printf("Insira valor %d: ", i+1);
                    scanf("%d", &arr3[i]);
                }

                printf("\nArray arr3: ");
                printArray(arr3, tamanhoArray);

                /*-Remoção de um vetor / (por?) Elemento;*/

                int pos;

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento do vetor: ");
                printf("\n------------------------------------------------------------------");

                printf("\n\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3\n");

                printf("\nInsira a posicao do item a ser removido (1, 2, 3, 4..): ");
                scanf("%d", &pos);

                if(pos>0 && pos<=tamanhoArray){
                    for(i = pos; i < tamanhoArray; i++) {
                        arr3[i-1] = arr3[i];
                    }
                } else {
                    printf("\nPosicao invalida!: ");
                    break;
                }

                printf("\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3");

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nInsercao de um item no array por posicao: ");
                printf("\n------------------------------------------------------------------");

                printf("\n\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3");

                printf("\n\nInsira a posicao em que deseja inserir o valor: ");
                scanf("%d", &pos);

                /*Faz os valores serem empurrados para frente*/
                if(pos>0 && pos<=tamanhoArray){
                    for(i = tamanhoArray-1; i > pos-1; i--) {
                        arr3[i] = arr3[i-1];
                    }
                } else {
                    printf("\nPosicao invalida!: ");
                    break;
                }

                printf("\nInsira o valor a ser inserido: ");
                scanf("%d", &arr3[pos-1]);

                printf("\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3");


                /*-Remoção de um elemento NO VETOR;*/

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento no array: ");
                printf("\n------------------------------------------------------------------");

                /*-Acesso de um VETOR;*/

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nAcesso de um array: ");
                printf("\n------------------------------------------------------------------");

                /*-Buscar no Vetor;*/

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nBusca em um array: ");
                printf("\n------------------------------------------------------------------");
            }
            break;
        case 2:
            {

            }
            break;

        case 3:
            {
                int opt2;
                do{
                    printf("\n\n1: Alocacao dinamica\n2: Manipulacao de vetores, retorno de mais de um valor\n3: Referencia para listas e pilhas\n0: Anterior\n\nEscolha:");
                    scanf("%d", &opt2);
                    switch(opt2) {
                    case 1:
                        {
                            /*https://www.programiz.com/c-programming/c-dynamic-memory-allocation*/
                            int *ptr, i, *ptr2;
                            ptr = (int*) malloc(10 * sizeof(int));
                            ptr2 = (int*) calloc(10, sizeof(int));

                            if(ptr == NULL || ptr2 == NULL) {                           /*Sempre verificar alocacao*/
                                printf("Erro! memoria nao alocada!.");
                                exit(0);
                            }

                            printf("\nMalloc: Valores nao iniciados: \n");
                            for(i=0;i<10;i++) {
                                printf("[%d]\t", *(ptr+i));
                            }

                            printf("\n\nCalloc: Todos os bits iniciados como 0\n");
                            for(i=0;i<10;i++) {
                                printf("[%d]\t\t", *(ptr2+i));
                            }

                            printf("\n\nPosicoes na memoria para ptr: \n");
                            for(i=0;i<10;i++) {
                                printf("[%d]\n", ptr+i);
                            }

                            printf("\n\nPosicoes na memoria para ptr2: \n");
                            for(i=0;i<10;i++) {
                                printf("[%d]\n", ptr2+i);
                            }

                            printf("\n\nInsira valores para o primeiro array: ");
                            for(i=0;i<10;i++) {
                                printf("ptr+%d: ", i);
                                scanf("%d", ptr+i);
                            }

                            printf("\nArray 1 (ptr): \n");
                            for(i=0;i<10;i++) {
                                printf("[%d]\t", *(ptr+i));
                            }

                            int novoTamanhoArray;
                            printf("\n\nAumentar o array ptr (Tem 10 espacos): ");
                            printf("\nInsira a quantidade de espacos novos: ");
                            scanf("%d", &novoTamanhoArray);
                            ptr = (int *)realloc(ptr, (10+novoTamanhoArray)*sizeof(int));

                            if(ptr == NULL || ptr2 == NULL) {
                                printf("Erro! memoria nao alocada!.");
                                exit(0);
                            }

                            for(i=10;i<10+novoTamanhoArray;i++) {
                                printf("ptr+%d: ", i);
                                scanf("%d", ptr+i);
                            }

                            printf("\nArray 1 (ptr): \n");

                            for(i=0;i<10+novoTamanhoArray;i++) {
                                printf("[%d]\t", *(ptr+i));
                            }

                            free(ptr);
                            free(ptr2);
                        }
                        break;
                    case 2:
                        {
                            /*Para retornar mais de um valor em uma função. -Alleck Luka */
                            int retornar[4], i;
                            readArray(retornar, 4);

                            for(i=0;i<4;i++) {
                                printf("[%d]", retornar[i]);
                            }
                        }
                        break;
                    case 3:
                        {
                            /*Referência para listas, pilhas, -Alleck Luka*/
                            /*Existe uma sobrecarga associada ao uso de arrays dinamicos, dado que se torna necessario realocar memoria e
                            copiar os dados ja existentes novamente. */

                            /*
                            typedef struct node{
                                int value;
                                struct node * next;
                            }node_t;
                            */

                            node_t* head = NULL; /*Inicia a lista*/

                            head = (node_t*)malloc(sizeof(node_t)); /*Lembrando que malloc retorna um ponteiro void, que vira node_t */
                            if(head==NULL)
                                exit(-1);

                            head->value = 10;

                            head->next = (node_t*)malloc(sizeof(node_t));
                            if(head->next==NULL)
                                exit(-1);

                            head->next->value = 11;
                            head->next->next = NULL;

                            node_t * curr = head;

                            printf("Lista: ");
                            printf("[%d]", head->value);
                            printf("[%d]", head->next->value);

                            printf("\nBase da funcao para imprimir a lista encadeada: \nLista: ");

                            while(curr !=NULL){
                                printf("[%d]", curr->value);
                                curr = curr->next;
                            }

                            pop(&head);
                            pop(&head);

                            int n;

                            printf("\n\nInserindo valores com o metodo push: \n");
                            do{
                                printf("Digite um numero: ");
                                scanf("%d", &n);
                                push(&head, n);
                                printf("Deseja inserir outro ?: (Y=1, N=0): ");
                                scanf("%d", &n);
                            } while(n!=0);

                            printf("\nLista: ");
                            printList(head);

                            pop(&head);
                            printf("\nLista: ");
                            printList(head);

                            freeList(head);
                            free(head);
                        }
                        break;
                    }
                printf("\n\n");
                } while(opt2!=0);
            }
            break;
        }
        printf("\n\n\n");
    }while(opt!=0);
}

/*int arrayIsEqual(int *array1, int arraySize1, int *array2, int arraySize2) {
    int i;
    if(arraySize1 != arraySize2)
        return 0;

    for(i=0;i<arraySize1;i++) {
        if(array1[i] != array2[i])
            return 0;
    }
    return 1;
}*/
