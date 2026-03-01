#include <stdio.h>
#include <stdbool.h>

char board[3][3]; // Oyun tahtası

// Tahta durumunu ekrana yazdır
void tahta_yazdir() {
    printf("\nTahta Durumu:\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Tahta durumunu sıfırla
void tahta_sifirla() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Oyuncunun hamlesini al
void oyuncu_hamlesi_al(char oyuncu) {
    int satir, sutun;
    printf("Oyuncu %c icin satir ve sutun girin (0-2 araliginda): ", oyuncu);
    scanf("%d %d", &satir, &sutun);

    // Geçersiz hamle kontrolü
    while (satir < 0 || satir > 2 || sutun < 0 || sutun > 2 || board[satir][sutun] != ' ') {
        printf("Gecersiz hamle, lutfen tekrar girin: ");
        scanf("%d %d", &satir, &sutun);
    }

    // Tahtaya hamleyi yerleştir
    board[satir][sutun] = oyuncu;
}

// Oyunun kazananını kontrol et
bool kazanan_kontrol(char oyuncu) {
    // Satır ve sütun kontrolü
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == oyuncu && board[i][1] == oyuncu && board[i][2] == oyuncu) return true;
        if (board[0][i] == oyuncu && board[1][i] == oyuncu && board[2][i] == oyuncu) return true;
    }
    // Köşegen kontrolü
    if (board[0][0] == oyuncu && board[1][1] == oyuncu && board[2][2] == oyuncu) return true;
    if (board[0][2] == oyuncu && board[1][1] == oyuncu && board[2][0] == oyuncu) return true;
    return false;
}

int main() {
    char devam;
    do {
        tahta_sifirla();
        char mevcut_oyuncu = 'X';
        bool oyun_devam = true;

        // Oyun döngüsü
        while (oyun_devam) {
            tahta_yazdir();
            oyuncu_hamlesi_al(mevcut_oyuncu);
            if (kazanan_kontrol(mevcut_oyuncu)) {
                printf("Oyuncu %c kazandi!\n", mevcut_oyuncu);
                oyun_devam = false;
            } else if (mevcut_oyuncu == 'X') {
                mevcut_oyuncu = 'O';
            } else {
                mevcut_oyuncu = 'X';
            }
        }

        tahta_yazdir();
        printf("Tekrar oynamak ister misiniz? (E/H): ");
        scanf(" %c", &devam); // Boşluk karakteri scanf buffer'ını temizler

    } while (devam == 'E' || devam == 'e');

    printf("Oyunu kapatiyorsunuz. İyi günler!\n");

    return 0;
}
