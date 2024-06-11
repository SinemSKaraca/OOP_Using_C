#include "Bitki.h"

Bitki BitkiKurucu(char tur, int deger, int x, int y) {
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	// Kalıtım benzetmesi (Alt siniftan nesne üretildiginde Ust siniftan da nesne uretilir)
	this->super = CanliKurucu(tur, deger, x, y);
	this->super->gorunum = &BitkiGorunum;
	this->b_yokedici = &BitkiYokEdici;
	
	return this;
}

char* BitkiGorunum(const Canli this) {
	char* karakter = &this->tur;
	return karakter;
}

void BitkiYokEdici(const Bitki this) {
	if(this == NULL) return;
	this->super->yokedici(this->super);
	free(this);
}