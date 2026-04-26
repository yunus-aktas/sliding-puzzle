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




#define MAX_DURUM 500000

typedef struct {
    int tahta[3][3];
    int bosX, bosY;
    char hamleler[500];
    int hamleAdedi;
} Durum;

Durum kuyruk[MAX_DURUM];
int on = 0, arka = 0;

char ziyaretEdilen[MAX_DURUM][10];
int ziyaretSayisi = 0;

void tahtayiStringe(int t[3][3], char *str) {
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            str[k++] = '0' + t[i][j];
    str[k] = '\0';
}

int ziyaretEdildiMi(char *str) {
    int i;
    for (i = 0; i < ziyaretSayisi; i++)
        if (strcmp(ziyaretEdilen[i], str) == 0)
            return 1;
    return 0;
}

void bfsCoz() {
    int i,j;
    on = 0; arka = 0; ziyaretSayisi = 0;

    int yon[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    char yonAdi[4] = {'W','S','A','D'};

    Durum baslangic;
    memcpy(baslangic.tahta, tahta, sizeof(tahta));
    baslangic.bosX = bosX;
    baslangic.bosY = bosY;
    baslangic.hamleler[0] = '\0';
    baslangic.hamleAdedi = 0;
    kuyruk[arka++] = baslangic;

    while (on < arka) {
        Durum simdiki = kuyruk[on++];

        char str[10];
        tahtayiStringe(simdiki.tahta, str);
        if (ziyaretEdildiMi(str)) continue;
        strcpy(ziyaretEdilen[ziyaretSayisi++], str);

        int hedef[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
        int bitti = 1;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (simdiki.tahta[i][j] != hedef[i][j]) bitti = 0;

        if (bitti) {
            printf("\nEn kisa cozum %d hamle:\n", simdiki.hamleAdedi);
            printf("Hamle sirasi: %s\n", simdiki.hamleler);
            return;
        }

        for (i = 0; i < 4; i++) {
            int yeniX = simdiki.bosX + yon[i][0];
            int yeniY = simdiki.bosY + yon[i][1];

            if (yeniX < 0 || yeniX > 2 || yeniY < 0 || yeniY > 2) continue;

            Durum yeni = simdiki;
            yeni.tahta[simdiki.bosX][simdiki.bosY] = yeni.tahta[yeniX][yeniY];
            yeni.tahta[yeniX][yeniY] = 0;
            yeni.bosX = yeniX;
            yeni.bosY = yeniY;

            int uzunluk = strlen(yeni.hamleler);
            yeni.hamleler[uzunluk] = yonAdi[i];
            yeni.hamleler[uzunluk + 1] = '\0';
            yeni.hamleAdedi++;

            if(arka < MAX_DURUM)
                kuyruk[arka++] = yeni;
        }
    }
    printf("Cozum bulunamadi!\n");
}




int main() {
    char yon;
    int hamle = 0;

    printf("=== 3x3 Sliding Puzzle ===\n");
    printf("Kontroller: W = Yukari | S = Asagi | A = Sol | D = Sag\n");
    printf("Cikis icin Q tusuna basin.\n");
    printf("Ipucu icin H tusuna basin.\n");

    tahtayiBaslat();

    while (1) {
        tahtayiCiz();
        printf("Hamle: %d\n", hamle);
        printf("Yon girin: ");
        scanf(" %c", &yon);

        if (yon == 'q' || yon == 'Q') {
            printf("Oyundan cikiliyor...\n");
            break;
        }
        if (yon == 'h' || yon == 'H') {
            printf("En kisa cozum hesaplaniyor...\n");
            bfsCoz();
            continue;
        }
        if (tasHareketEttir(yon)) {
            hamle++;
        }
        if (oyunBittiMi()) {
            tahtayiCiz();
            printf("\nTebrikler! Puzzlei %d hamlede cozdunuz!\n", hamle);
            break;
        }
    }
    return 0;
}
