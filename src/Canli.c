#include "Canli.h"

Canli CanliKurucu(char tur, int deger, int x, int y) {
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));
	this->tur = tur;
	this->deger = deger;
	this->x = x;
	this->y = y;
	this->yokedici = &CanliYokEdici;
	
	return this;
}

void CanliYokEdici(const Canli this) {
	if(this == NULL) return;
	free(this);
}