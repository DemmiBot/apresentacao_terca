/*-Gabriel Felix -David Lukas -Samuel Kevin -Alleck Luka -Victor Lorran -Lucas Costa -Samuel Santana -Karla juliane*/

#include <stdio.h>
#include <stdlib.h>

/*https://www.programiz.com/c-programming/c-dynamic-memory-allocation*/
/* ptr = (float*) calloc(25, sizeof(float)); - Inicia todos os bits com 0 */
/* ptr = (float*) malloc(25 * sizeof(float)); - Não inicia valores */

void scanArray() { /*Jogar valores direto no array: */

}

void printArray() { /*Jogar valores direto no array: */

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

                printf("\nMalloc: Valores nao iniciados\n");

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

            }
            break;
        }
    } while(opt!=0);
}
