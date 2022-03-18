/*Gabriel Felix - David Lukas - Samuel Kevin - Alleck Luka - Victor Lorran - Lucas Costa */
#include <stdio.h>

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

void populateArray(int arr[], int size) {
    int i;
    for(i=0;i<size;i++) {
        arr[i] = i+1;
    }
}

/*https://stackoverflow.com/questions/5630478/printing-arrays-in-separate-function-in-c*/
void printArray(int arr[], int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
}

void printArrayFloat(float arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%.2f ", arr[i]);
    }
}
/*void print2DArray(int *a, int rows, int columns){
    int i, j;
    for(i=0;i<rows*columns;i++){
        printf("\t%d", a[i]);
        if(!((i+1)%(columns)))
            printf("\n");
    }
}*/

int arrayIsEqual(int *array1, int arraySize1, int *array2, int arraySize2) {
    int i;
    if(arraySize1 != arraySize2)
        return 0;

    for(i=0;i<arraySize1;i++) {
        if(array1[i] != array2[i])
            return 0;
    }
    return 1;
}

int main() {

    int opt;
    do {
        printf("\n\nMENU: Ex1, (0 PARA SAIR) \n\n");
        scanf("%d", &opt);
        switch(opt) {
        case 1:
            {

                /*-Criação de um vetor; -Inicialização de um vetor;*/

                int arr[10]; /*Criacao do vetor*/
                printf("Array arr (lixo de memoria): ");
                printArray(arr, 10); /* VETOR NÃO INICIADO*/
                printf("\n");

                arr[10] = 12; /* UNDEFINED, qualquer coisa pode ocorrer, até a ilusão de funcionar */
                printf("%d\n\n", arr[10]);

                int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; /*Hardcode*/

                printf("Array arr2: ");
                printArray(arr2, 10);
                printf("\n");

                int i;
                for(i=0;i<10;i++) {
                    arr[i] = -i;
                }

                printf("Array arr: ");
                printArray(arr, 10);

                /*-Remoção de um vetor / Elemento;*/


                /*-Inserção de um elemento NO VETOR;*/
                /*-Remoção de um elemento NO VETOR;*/
                /*-Acesso de um VETOR;*/
                /*-Buscar no Vetor;*/


            }
            break;
        }

    } while (opt != 0);




}
