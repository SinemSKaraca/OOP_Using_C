#include "Populasyon.h"
#include <stdio.h>
#include <stdlib.h>

int bitkiAdet(char* dosyaAdi) {
	FILE *dosya;
    int sayi;
	int bitkiSayisi = 0;

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

    while(fscanf(dosya, "%d", &sayi) != EOF) {
        if(sayi > 0 && sayi < 10) {
			bitkiSayisi++;
		}
    }

    fclose(dosya);
	//printf("bitki.: %d", bitkiSayisi);
	return bitkiSayisi;
}

int bocekAdet(char* dosyaAdi) {
	FILE *dosya;
    int sayi;
	int bocekSayisi = 0;

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

    while(fscanf(dosya, "%d", &sayi) != EOF) {
        if(sayi > 9 && sayi < 21) {
			bocekSayisi++;
		}
    }

    fclose(dosya);
	//printf("bocek.: %d", bocekSayisi);
	return bocekSayisi;
}

int sinekAdet(char* dosyaAdi) {
	FILE *dosya;
    int sayi;
	int sinekSayisi = 0;

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

    while(fscanf(dosya, "%d", &sayi) != EOF) {
		if(sayi > 20 && sayi < 51) {
			sinekSayisi++;
		}
    }

    fclose(dosya);
	//printf("sinek.: %d", sinekSayisi);
	return sinekSayisi;
}

int pireAdet(char* dosyaAdi) {
	FILE *dosya;
    int sayi;
	int pireSayisi = 0;

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

    while(fscanf(dosya, "%d", &sayi) != EOF) {
        if(sayi > 51 && sayi < 100) {
			pireSayisi++;
		}
    }

    fclose(dosya);
	//printf("pire.: %d", pireSayisi);
	return pireSayisi;
}

