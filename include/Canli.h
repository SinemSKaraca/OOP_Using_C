#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>

struct CANLI {
	char tur;
	int deger;
	int x;
	int y;
	// Soyut sinif benzetimi
	char*(*gorunum)(); // Bunun icini cocuk siniflarda dolduracagiz
	void (*yokedici)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli CanliKurucu(char, int, int, int);
void CanliYokEdici(const Canli);

#endif