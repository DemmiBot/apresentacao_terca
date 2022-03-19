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

void populateArray(int arr[], int size, int startingPoint) {
    int i;
    for(i=0;i<size;i++) {
        arr[i] = i+startingPoint;
    }
}


/*https://stackoverflow.com/questions/5630478/printing-arrays-in-separate-function-in-c*/
void printArray(int arr[], int size) {
    int i;
    for(i=0;i<size;i++) {
        printf("[%d]", arr[i]);
    }
}

/* void printArrayFloat(float arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%.2f ", arr[i]);
    }
} */

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
        }

    } while (opt != 0);

}
