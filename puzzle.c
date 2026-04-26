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




int cozulebilirMi() {
    int dizi[8],k = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] != 0) {
                dizi[k++] = tahta[i][j];
            }
        }
    }
    int inversiyon = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (dizi[i] > dizi[j]) {
                inversiyon++;
            }
        }
    }
    return inversiyon % 2 == 0;
}





void tahtayiBaslat(){
    int sayilar[9]={1,2,3,4,5,6,7,8,0};

    srand(time(NULL));
    do {
        for(int i=8;i>0;i--){
        int j,temp;
        j = rand() % (i + 1);
        temp = sayilar[i];
        sayilar[i] = sayilar[j];
        sayilar[j] = temp;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tahta[i][j] = sayilar[i * 3 + j];
            if (tahta[i][j] == 0) {
                bosX = i;
                bosY = j;
            }
        }
    }
    } while (!cozulebilirMi());
}
