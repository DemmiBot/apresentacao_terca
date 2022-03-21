/*-Gabriel Felix -David Lukas -Samuel Kevin -Alleck Luka -Victor Lorran -Lucas Costa -Samuel Santana -Karla juliane*/

#include <stdio.h>
#include <stdlib.h>


void readArray(int *arr, int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d: ", i+1);
        printf("Insert N# %d: ", i+1);
        scanf("%d", arr);
        arr++; /*a é um ponteiro para o primeiro indice do vetor, ou seja, é o mesmo que &arr[0]*/
    }
}

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

/*https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list*/
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

int main() {
    int opt2;
    do{

        printf("\n\n");
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
    } while(opt2!=0);
}
