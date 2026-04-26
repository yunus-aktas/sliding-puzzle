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




int tasHareketEttir(char yon) {
    int yeniX = bosX;
    int yeniY = bosY;
                                                
    if (yon == 'w' || yon == 'W') yeniX = bosX - 1;
    else if (yon == 's' || yon == 'S') yeniX = bosX + 1;
    else if (yon == 'a' || yon == 'A') yeniY = bosY - 1;
    else if (yon == 'd' || yon == 'D') yeniY = bosY + 1;
    else {
        printf("Gecersiz giris! Lutfen W/A/S/D kullanin.\n");
        return 0;
    }

    if (yeniX < 0 || yeniX > 2 || yeniY < 0 || yeniY > 2) {
        printf("Gecersiz hamle! Sinir disi.\n");
        return 0;
    }

    tahta[bosX][bosY] = tahta[yeniX][yeniY];
    tahta[yeniX][yeniY] = 0;

    bosX = yeniX;
    bosY = yeniY;

    return 1;
}



int oyunBittiMi() {
    int hedef[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] != hedef[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
