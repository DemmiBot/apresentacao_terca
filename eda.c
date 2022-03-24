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
#include <time.h>

/*https://www.learn-c.org/en/Linked_lists*/
typedef struct node{
    int value;                  /*Valor guardado em dada posicao*/
    struct node * next;         /*ponteiro para a proxima posicao*/
}node_t;                        /*Nome padrao*/


typedef struct ponto{
	int x, y;
	struct ponto * proximo;
}t_ponto;


void push(node_t **head, int val) {                 /*Ponteiro duplo para alterar o ponteiro de head*/
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
       free(aux); /*aux ainda aponta para o local na memoria, so que o espaco nao esta mais alocado, o sistema operacional pode utilizar-lo*/
    }
    printf("\nHead is NULL!");
}

void printList(node_t *head) {
    node_t *atual = head;
    while(atual !=NULL){
        printf("[%d]", atual->value);
        atual = atual->next;
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
                printf("\nArray arr (lixo de memoria): ");
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

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento do vetor: ");
                printf("\n------------------------------------------------------------------");

                int elemento, j;

                printf("\n\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3\n");

                printf("\nInsira o elemento a ser removido : ");
                scanf("%d", &elemento);


                for(i=0;i<tamanhoArray;i++){
                    if(arr3[i]==elemento){
                        for(j = i+1; j < tamanhoArray; j++) { /*Empurra elementos para a esquerda*/
                            arr3[j-1] = arr3[j];
                        }
                    }
                }

                printf("\n");
                printArray(arr3, tamanhoArray);
                printf(" -Array 3");

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nInsercao de um item no array por posicao: ");
                printf("\n------------------------------------------------------------------");

                int posicao;

                printf("\n\n");
                printArray(arr3, tamanhoArray);

                printf("\n\nInsira a posicao em que deseja inserir o valor: ");
                scanf("%d", &posicao);

                /*Faz os valores serem empurrados para frente*/
                if(posicao>0 && posicao<=tamanhoArray){
                    for(i = tamanhoArray-1; i > posicao-1; i--) {
                        arr3[i] = arr3[i-1];
                    }
                } else {
                    printf("\nPosicao invalida!: ");
                    break;
                }

                printf("\nInsira o valor a ser inserido: ");
                scanf("%d", &arr3[posicao-1]);

                printf("\n");
                printArray(arr3, tamanhoArray);

                /*-Remoção de um elemento NO VETOR;*/

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento no array: ");
                printf("\n------------------------------------------------------------------");

                int vet[5];

                /*criacao do vetor de 5 posicoes com elementos aleatorios*/

                srand(time(NULL));

                for(i=0; i<5; i++){
                    vet[i] = rand() % 10;
                }

                printf("\nVetor: ");
                for(i=0; i<5; i++){
                    printf("%d, ", vet[i]);
                }

                printf("\n");

                printf("Insira a posicao do elemento que deseja remover:");
                scanf("%d", &posicao);

                for(i = 0; i < 5; i++){
                    vet[posicao-1] = -1;
                    printf("%d, ", vet[i]);
                }

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nAcesso de um array: ");
                printf("\n------------------------------------------------------------------");

                int vet2[5];

                printf("\nVetor: ");
                for(i=0; i < 5; i++){
                    vet2[i] = rand() % 10;
                    printf("%d, ", vet2[i]);
                }

                printf("\nInsira o indice a ser buscado:");
                scanf("%d", &elemento);

                printf("\nO Indice %d guarda o elemento %d", elemento, vet2[elemento]);

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nBusca em um array: ");
                printf("\n------------------------------------------------------------------");

                int vet3[10];
                int n=0, x;

                printf("\nVetor: ");

                for(i=0; i<10; i++){
                    vet[i] = rand() % 20;
                    printf("%d, ", vet[i]);
                }

                printf("\nInsira o valor do elemento a ser buscado:");
                scanf("%d", &x);

                for(i=0; i<10; i++){
                    if(vet[i] == x){
                        n=1;
                        printf("\nO elemento %d está no indice %d", x, i);
                    }
                }

                if(n == 0){
                    printf("\nO elemento não está listado no vetor :(");
                }

            }
            break;
        case 2:
            {
                /*1 Criação*/
                int matriz[3][3];

                int i, j, buscar, cont;

                printf ("\n\nMATRIZ IMPRESSA\n");
                for (i=0; i<3; i++){
                    for(j=0; j<3; j++){
                        printf("[%d]", matriz[i][j]);
                    }
                    printf("\n");
                }

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nInsercao de valores em uma Matriz: ");
                printf("\n------------------------------------------------------------------");

                printf ("\nInsira os valores para cada posiçao da matriz: \n");
                for (i=0; i<3; i++){
                    for(j=0; j<3; j++){
                        printf("Posiçao [%d] [%d]: ", i, j);
                        scanf("%d", &matriz [i][j]);
                    }
                }
                /* Impressão da Matriz*/
                printf ("\n\nMATRIZ IMPRESSA\n");
                for (i=0; i<3; i++){
                    for(j=0; j<3; j++){
                        printf("[%d]", matriz[i][j]);
                    }
                    printf("\n");
                }

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento da matriz por valor: ");
                printf("\n------------------------------------------------------------------");

                printf("\nInsira valor a ser removido (todos os valores iguais serao removidos!): ");
                scanf("%d", &buscar);

                for(j=0; j<3; j++){
                    for(i=0; i<3; i++){
                        if(buscar==matriz[i][j]){
                            printf("\nPosicao [%d][%d], deletando... Pronto!", i, j, matriz [i][j]);
                            matriz[i][j] = 0;
                        }
                    }
                }

                printf ("\n\nMATRIZ IMPRESSA\n");
                for (i=0; i<3; i++){
                    printf("(%d)  ", i);
                    for(j=0; j<3; j++){
                        printf("[%d]", matriz[i][j]);
                    }
                    printf("\n");
                }
                printf("\n     (0)(1)(2)");

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nRemocao de um elemento da matriz por indice: ");
                printf("\n------------------------------------------------------------------");

                printf("\nInsira a linha do elemento a ser removido: ");
                scanf("%d", &i);
                printf("\nInsira a coluna do elemento a ser removido: ");
                scanf("%d", &j);

                printf("%d", matriz[i][j]);

                matriz[i][j] = 0;

                printf ("\n\nMATRIZ IMPRESSA\n");
                for (i=0; i<3; i++){
                    for(j=0; j<3; j++){
                        printf("[%d]", matriz[i][j]);
                    }
                    printf("\n");
                }

                printf("\n\n\n------------------------------------------------------------------");
                printf("\nAcessando um Elemento na Matriz: ");
                printf("\n------------------------------------------------------------------");

                printf("\n Acessando o valor da Linha 1 - Coluna 2: %d", matriz [0][1]);

                /*7 Buscar NA  MATRIZ*/
                printf("\n\n\n------------------------------------------------------------------");
                printf("\nBuscar na Matriz: ");
                printf("\n------------------------------------------------------------------");

                printf("\n\n Digite o valor a ser procurado na Matriz: ");
                scanf("%d", &buscar);

                for(j=0; j<3; j++){
                    for(i=0; i<3; i++){
                        if(buscar==matriz[i][j]){
                            cont=1;
                            printf("\nPosicao [%d][%d] = %d", i, j, matriz [i][j]);
                        }
                    }
                }
                if(cont==0){
                    printf ("\n\n O valor %d não foi encontrado na Matriz",buscar);
                }

            }
            break;

        case 3:
            {
                int opt2;
                do{
                    printf("\n\n1: Alocacao dinamica\n2: Manipulacao de vetores, retorno de mais de um valor\n3: Referencia para listas e pilhas\n4: malloc() e strings\n5: Lista encadeada\n0: Anterior\n\nEscolha:");
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

                            node_t* head = NULL;                            /*Inicia a lista*/

                            head = (node_t*)malloc(sizeof(node_t));         /*Lembrando que malloc retorna um ponteiro void, que vira node_t */

                            if(head==NULL)                                  /*Sempre checar*/
                                exit(-1);

                            head->value = 10;                               /*Isso é feito com funcoes, exemplo cru*/

                            head->next = (node_t*)malloc(sizeof(node_t));

                            if(head->next==NULL)
                                exit(-1);

                            head->next->value = 11;
                            head->next->next = NULL;

                            node_t * atual = head;

                            printf("Lista: [%d] [%d]", head->value, head->next->value);

                            printf("\nBase da funcao para imprimir a lista encadeada: \nLista: ");

                            while(atual !=NULL){
                                printf("[%d]", atual->value);
                                atual = atual->next;
                            }

                            pop(&head);
                            pop(&head);

                            int numero;

                            printf("\n\nInserindo valores com o metodo push: \n");
                            do{
                                printf("Digite um numero: ");
                                scanf("%d", &numero);
                                push(&head, numero);
                                printf("Deseja inserir outro ?: (Y=1, N=0): ");
                                scanf("%d", &numero);
                            } while(numero!=0);

                            printf("\nLista: ");
                            printList(head);

                            pop(&head);
                            printf("\nLista: ");
                            printList(head);

                            freeList(head);
                            if(head == NULL) {
                                printf("\nHead is NULL!");
                            }

                            free(head);

                        }
                        break;
                    case 4:
                        {
                            /*Exemplo de alocacao dinamica com string*/
                            char *n[50];
                            int tamArray, i, tam;

                            printf("Quantos nomes? ");
                            scanf("%d", &tamArray);

                            char *nome[tamArray];
                            for (i = 0; i < tamArray; i++)
                            {
                                fflush(stdin);
                                printf("Digite seu nome: ");
                                gets(n);
                                tam = strlen(n);
                                nome[i] = malloc((tam + 1) *sizeof(char));

                                printf("MALLOC((%d)*sizeof(char))\n", tam+1); /* Ilustrativo */

                                if(nome[i]==NULL){
                                    printf("NOT ALLOCATED!");
                                    exit(-1);
                                }
                                strcpy(nome[i], n);
                            }
                            free(n);

                            for (i = 0; i <tamArray; i++)
                            {
                                printf("\n%s", nome[i]);
                            }


                            for(i=0;i<tamArray;i++){
                                printf("\nfreeing(nome[%d])...",i);
                                free(nome[i]);
                                printf(" DONE!");
                            }

                            /*printf("\nTeste: Imprimir nome[%d] APOS FREE() ",i);
                            for (i = 0; i <tamArray; i++)
                            {
                                printf("\n%s", nome[i]);
                            }*/

                        }
                        break;
                    case 5:
                        {
                            /*Mais alocacao :)*/

                        	t_ponto * ini_ponto;
                            t_ponto * proximo_ponto;
                            int resp;

                            ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
                            if (ini_ponto == NULL)
                            {
                                exit(1);
                            }
                            proximo_ponto = ini_ponto;

                            while (1)
                            {
                                printf("Informe o valor de X: ");
                                scanf("%d", &proximo_ponto->x);
                                printf("Informe o valor de Y: ");
                                scanf("%d", &proximo_ponto->y);
                                printf("Deseja continuar ? <1> SIM <2> NAO: ");
                                scanf("%d", &resp);
                                if (resp==1)
                                {
                                    proximo_ponto->proximo = (t_ponto *)malloc(sizeof(t_ponto));
                                    proximo_ponto = proximo_ponto->proximo;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            printf("\n");
                            proximo_ponto->proximo=NULL;
                            proximo_ponto=ini_ponto;
                            while (proximo_ponto != NULL)
                            {
                                printf("X = %d, Y = %d\n", proximo_ponto->x, proximo_ponto->y);
                                proximo_ponto=proximo_ponto->proximo;
                            }
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






/*Feynman techique - Richard Feynman*/
