#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int guessGame(int randomNumber) {
    int guess, i;
    int* ptr;
    printf("Do you wanna play a game?", randomNumber);
    
    for(i=0;i<10;i++) {

        printf("\nYou have %d guesses!", 10-i);
        scanf("%d", &guess);
        if(randomNumber == guess) {
            printf("\nYup, it's %d!", randomNumber);
            return 1;
        } else {
            if(guess>randomNumber) {
                printf("\nToo high!\n");
            }
            if(guess<randomNumber) {
                printf("\nToo low!\n");
            }
        }
    }
    printf("Commencing TOTAL ANNIHILATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! press enter to DIE!");
    getch();
    for(;;){
        ptr = (int*)calloc(2000000, sizeof(int));
        if(ptr==NULL) {
            printf("\nCould not allocate!");
        }
    }
    return 0;
}

int main() {

    srand(time(NULL));
    int randomNumber = rand() % 101;

    guessGame(randomNumber);

}