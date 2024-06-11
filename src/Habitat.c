#include "Habitat.h"
#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Populasyon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

int elemanSayisi = 0;
int satirSayisi = 0;

// Private Benzetimi
int elemanSayisiBul(char* dosyaAdi) {
	FILE *dosya;
    int sayi;

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

    while(fscanf(dosya, "%d", &sayi) != EOF) {
        elemanSayisi++;
    }

    fclose(dosya);
	//printf("elemanlar: %d\n", elemanSayisi);
	return elemanSayisi;
}

// Private Benzetimi
int satirSayisiBul(char* dosyaAdi) {
	FILE *dosya;
    char karakter;
	elemanSayisi = elemanSayisiBul(dosyaAdi);

    dosya = fopen(dosyaAdi, "r");

    if(dosya == NULL) {
        printf("DOSYA ACMA HATASI!\n");
    }

	char satir[20000];
    int satirSayisi = 0;
	while(fgets(satir, sizeof(satir), dosya) != NULL) {
        // Satırın içinde sayısal bir karakter var mı kontrol et
        int i;
        int sayi_var_mi = 0;
        for(i = 0; satir[i] != '\0'; i++) {
            if (isdigit(satir[i])) {
                sayi_var_mi = 1;
                break;
            }
        }
        if(sayi_var_mi) {
            satirSayisi++;
        }
    }

    fclose(dosya);
	//printf("elemanlar: %d\n", satirSayisi);
	return satirSayisi;
}


void habitat(char* dosyaAdi) {
	FILE *fp; // file_pointer (dosyanin baslangic adresini tutar)
	int eleman;
	
	fp = fopen(dosyaAdi, "r"); // Dosya okuma modunda acildi
	
	if(fp == NULL) {
		printf("DOSYA ACMA HATASI!\n");
		exit(1);
	}
	
	satirSayisi = satirSayisiBul(dosyaAdi);
    int bitkiSayisi = bitkiAdet(dosyaAdi);
    int sinekSayisi = sinekAdet(dosyaAdi);
    int pireSayisi = pireAdet(dosyaAdi);
    int bocekSayisi = bocekAdet(dosyaAdi) + pireSayisi + sinekSayisi;
	//printf("bitki..%d, bocek..%d, sinek..%d, pire..%d", bitkiSayisi, bocekSayisi, sinekSayisi, pireSayisi);
	
	Canli* canlilar = (Canli*)malloc(elemanSayisi * sizeof(struct CANLI));
	Bitki* bitkiler = (Bitki*)malloc(bitkiSayisi * sizeof(struct BITKI));
	Bocek* bocekler = (Bocek*)malloc(bocekSayisi * sizeof(struct BOCEK));
	Sinek* sinekler = (Sinek*)malloc(sinekSayisi * sizeof(struct SINEK));
	Pire* pireler = (Pire*)malloc(sinekSayisi * sizeof(struct PIRE));
	int i = 0; // canlilar dizisinin indexi
	int bi = 0; int bo = 0; int si = 0; int pi = 0;
	int i_eleman = 0;
	int konum_x = 0; // satir (dosyanın satir indexi)
	int konum_y = 0; // sutun (Satirdaki elemanin indexi)

	// Dosyadan sayilar okunur
	while(fscanf(fp, "%d", &eleman) != EOF) {
		if(eleman > 0 && eleman < 10) {
			// Bitki nesnesi olustur
			Bitki b = BitkiKurucu('B', eleman, konum_x, konum_y);
			canlilar[i] = b->super;
			if(bi != bitkiSayisi) {
				bitkiler[bi] = b;
				bi++;
			}
			//printf("%d.%c.%d bitki", i, canlilar[i]->tur, eleman);
		}
			
		else if(eleman > 9 && eleman < 21) {
			// Bocek nesnesi olustur
			Bocek c = BocekKurucu('C', eleman, konum_x, konum_y);
			canlilar[i] = c->super;
			if(bi != bocekSayisi) {
				bocekler[bo] = c;
				bo++;
			}
			//printf("%d.%c.%d bocek", i, canlilar[i]->tur, eleman);
		}
		
		else if(eleman > 20 && eleman < 51) {
			// Sinek nesnesi olustur
			Sinek s = SinekKurucu('S', eleman, konum_x, konum_y);
			canlilar[i] = s->super->super;
			if(si != sinekSayisi) {
				sinekler[si] = s;
				bocekler[bo] = s->super;
				bo++;
				si++;
			}
			//printf("%d.%c.%d sinek", i, canlilar[i]->tur, eleman);
		}
		
		else {
			// Pire nesnesi olustur
			Pire p = PireKurucu('P', eleman, konum_x, konum_y);
			canlilar[i] = p->super->super;
			if(pi != pireSayisi) {
				pireler[pi] = p;
				bocekler[bo] = p->super;
				bo++;
				pi++;
			}
			//printf("%d.%c.%d pire", i, canlilar[i]->tur, eleman);
		}
		konum_y++;
		i++;
		
		// Eğer bir satır sonuna gelinmişse
		if (fgetc(fp) == '\n') {
			//printf("\n");
			konum_x++;
			konum_y = 0;
		}
	}
	fclose(fp); 
	ekosistem(canlilar);
	// yok etme işlemleri burada olacak!!!!!
	for(int i = elemanSayisi - 1; i >= 0; i--) {
		free(canlilar[i]);
	}
	
	for(int i = bitkiSayisi - 1; i >= 0; i--) {
		bitkiler[i]->b_yokedici;
		free(bitkiler[i]);
	}
	
	for(int i = bitkiSayisi - 1; i >= 0; i--) {
		bitkiler[i]->b_yokedici;
		free(bitkiler[i]);
	}
		
	for(int i = bocekSayisi - 1; i >= 0; i--) {
		bocekler[i]->c_yokedici;
		free(bocekler[i]);
	}
		
	for(int i = sinekSayisi - 1; i >= 0; i--) {
		sinekler[i]->s_yokedici;
		free(sinekler[i]);
	}
		
	for(int i = pireSayisi - 1; i >= 0; i--) {
		pireler[i]->p_yokedici;
		free(pireler[i]);
	}
	
	free(canlilar); 
	free(bitkiler);
	free(bocekler);
	free(sinekler);
	free(pireler);
}

//Canlılar arası besin piramidi
Canli* ekosistem(Canli* _canlilar) {
	int i = 0;
	int j = 1;
	int basla = 0;
	//printf("\nelemanSayisi..: %d", elemanSayisi);
	//printf("\nsatirSayisi..: %d\n", satirSayisi);
	int son_x = satirSayisi - 1;
	int son_y = elemanSayisi / satirSayisi - 1;
	while(i != elemanSayisi && j != elemanSayisi+1) {
		int k = 0;
		int t = 0;
		char yaz;
		// Ekrana yazma
		while(k != elemanSayisi) {
			if(t % (elemanSayisi / satirSayisi) == 0) {
				printf("\n");
			}
			if(_canlilar[k]->tur == 'B') {
				yaz = *BitkiGorunum(_canlilar[k]);
				printf("%c ", yaz);
			} 
			else if(_canlilar[k]->tur == 'C') {
				yaz = *BocekGorunum(_canlilar[k]);
				printf("%c ", yaz);
			} 
			else if(_canlilar[k]->tur == 'S') {
				yaz = *SinekGorunum(_canlilar[k]);
				printf("%c ", yaz);
			} 
			else {
				yaz = *PireGorunum(_canlilar[k]);
				printf("%c ", yaz);
			} 
			//printf("%c", _canlilar[k]->tur);
			t++;
			k++;
		}
		//printf("\n--------------------------i: %d, j: %d", i, j);
		if(basla == 0) {
			basla = 1;
			printf("\nDevam Etmek Icin Klavyeden Bir Tusa Basiniz..: \n");
			getch();
		}
		if(j == elemanSayisi) break;
		
		// i j'yi yerse
		if((_canlilar[i]->tur == 'B' && _canlilar[j]->tur == 'P') ||
			(_canlilar[i]->tur == 'C' && _canlilar[j]->tur == 'B')||
			(_canlilar[i]->tur == 'S' && _canlilar[j]->tur == 'P')||
			(_canlilar[i]->tur == 'B' && _canlilar[j]->tur == 'S')||
			(_canlilar[i]->tur == 'S' && _canlilar[j]->tur == 'C')||
			(_canlilar[i]->tur == 'C' && _canlilar[j]->tur == 'P')) {
			// B, P'yi; C, B'yi; S, P'yi; B, S'yi; S, C'yi; C, P'yi yer
			_canlilar[j]->tur = 'X';
			j++;
		}
		// j i'yi yerse
		else if((_canlilar[i]->tur == 'P' && _canlilar[j]->tur == 'B') ||
			(_canlilar[i]->tur == 'B' && _canlilar[j]->tur == 'C')||
			(_canlilar[i]->tur == 'P' && _canlilar[j]->tur == 'S')||
			(_canlilar[i]->tur == 'S' && _canlilar[j]->tur == 'B')||
			(_canlilar[i]->tur == 'C' && _canlilar[j]->tur == 'S')||
			(_canlilar[i]->tur == 'P' && _canlilar[j]->tur == 'C')) {
			_canlilar[i]->tur = 'X';
			i = j;
			j++;
		}
		// Canlılar aynı türdense
		else {
			// Değerlerine bak
			if(_canlilar[i]->deger != _canlilar[j]->deger) {
				if(_canlilar[i]->deger > _canlilar[j]->deger) {
					_canlilar[j]->tur = 'X';
					j++;
				}
				else {
					_canlilar[i]->tur = 'X';
					i = j;
					j++;
				}
			}
			// Bitise olan uzakliklarina bak
			else {	
				int i_uzaklik = pow(son_x - _canlilar[i]->x, 2) + pow(son_y - _canlilar[i]->y, 2);
				int j_uzaklik = pow(son_x - _canlilar[j]->x, 2) + pow(son_y - _canlilar[j]->y, 2);
				
				if(i_uzaklik > j_uzaklik) {
					_canlilar[j]->tur = 'X';
					j++;
				}	
				else {
					_canlilar[i]->tur = 'X';
					i = j;
					j++;
				}
			}
		}
		system("cls");
	}
	system("cls");
	
	for(int i = 0; i < elemanSayisi; i++) { 
		if(_canlilar[i]->tur != 'X') {
			printf("\nKazanan: %c : (%d, %d)\n", _canlilar[i]->tur, _canlilar[i]->x,_canlilar[i]->y);
		}
	}
	return _canlilar;
}
