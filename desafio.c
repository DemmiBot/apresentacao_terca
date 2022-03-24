#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int guessGame(int randomNumber) {
    int guess;
    printf("TESTE %d\n", randomNumber);
    scanf("%d", &guess);
    if(randomNumber == guess) {
        printf("Yup, it's %d!", randomNumber);
        return 0;
    } else {
        if(guess>randomNumber) {
            printf("Too high!\n");
            return 1;
        }
        if(guess<randomNumber) {
            printf("Too low!\n");
            return 1;
        }
    }
}

int main() {

    srand(time(NULL));
    int randomNumber = rand() % 101;
    int guess, i=0;

    do{
        i++;
    }while(guessGame(randomNumber)&&i<3);

}