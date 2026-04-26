#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int tahta[3][3];
int bosX, bosY;

void tahtayiCiz(){
    printf("\n*-------*-------*-------*\n");
    for(int i=0;i<3;i++){
        printf("\n|       |       |       |\n");
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] == 0){
                printf("|       ");
            }
            else{
                printf("|   %d   ", tahta[i][j]);
            }
        }
        printf("|\n");
        printf("|       |       |       |\n");
        printf("+-------+-------+-------+\n");
    }
}
