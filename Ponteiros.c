/*-Gabriel Felix -David Lukas -Samuel Kevin -Alleck Luka -Victor Lorran -Lucas Costa -Samuel Santana -Karla juliane*/

#include <stdio.h>
#include <stdlib.h>

/*https://www.programiz.com/c-programming/c-dynamic-memory-allocation*/
/* ptr = (float*) calloc(25, sizeof(float)); - Inicia todos os bits com 0 */
/* ptr = (float*) malloc(25 * sizeof(float)); - Não inicia valores */

typedef struct funcionario {
    char nome[16];
    int registro;
    float salario;
} Funcionario;

void lerFuncionario(Funcionario* funcionario) {
    printf("\nNome do funcionario: ");
    scanf("%s", funcionario->nome);
    printf("Numero do funcionario no registro: ");
    scanf("%d", &funcionario->registro);
    printf("Numero do funcionario no registro: ");
    scanf("%f", &funcionario->salario);
}

/*https://www.learn-c.org/en/Linked_lists*/
typedef struct node{
    int value;
    struct node * next;
}node_t;

void push(node_t **head, int val) {

    node_t * new_node;
    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->value = val;
    new_node->next = *head;
    *head = new_node;

}

void printList(node_t *head) {
    node_t *current = head;

    while(current !=NULL){
        printf("\n%d", current->value);
        current = current->next;
    }
}



int main() {
    int opt;
    do{

        scanf("%d", &opt);
        switch(opt) {
        case 1:
            {

                int *ptr, i, *ptr2;
                ptr = (int*) malloc(10 * sizeof(int));

                ptr2 = (int*) calloc(10, sizeof(int));

                if(ptr == NULL || ptr2 == NULL) {
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

                /* Unde-FUCKING-fined BABY!!! --ALLECK

                printf("\n\nPosicoes na memoria para ptr: \n");

                for(i=0;i<10;i++) {
                    printf("[%d]\n", ptr+i);
                }

                printf("\nArray 1 (ptr): \n");

                for(i=0;i<10;i++) {
                    printf("[%d]\t", *(ptr+i));
                }*/
            }
            break;
        case 2:
            {
                /*Para retornar mais de um valor em uma função. -Alleck Luka */
                Funcionario funcionario;
                lerFuncionario(&funcionario);

                printf("Nome: %s, ", funcionario.nome);
                printf("Registro: %d, ", funcionario.registro);
                printf("Salario: %.2fR$", funcionario.salario);

            }
            break;
        case 3:
            {
                /*Referência para listas, pilhas, -Alleck Luka*/
                /*Existe uma sobrecarga associada ao uso de arrays dinamicos, dado que se torna necessario realocar memoria e
                copiar os dados ja existentes novamente. */
                node_t * head = NULL;


                head = (node_t*)malloc(sizeof(node_t));
                if(head==NULL)
                    exit(-1);

                head->value = 10;

                head->next = (node_t*)malloc(sizeof(node_t));
                if(head->next==NULL)
                    exit(-1);

                head->next->value = 11;
                head->next->next = NULL;

                node_t * current = head;

                printf("%d", head->value);
                printf("\n%d", head->next->value);

                printf("Base da funcao para imprimir a lista:");

                while(current !=NULL){
                    printf("\n%d", current->value);
                    current = current->next;
                }

                printf("\n\n");

                push(&head, 10);
                push(&head, 11);
                push(&head, 12);
                push(&head, 13);
                push(&head, 14);

                printList(head);
            }
            break;
        }
    } while(opt!=0);
}
