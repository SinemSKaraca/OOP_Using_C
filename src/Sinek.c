#include "Sinek.h"

Sinek SinekKurucu(char tur, int deger, int x, int y) {
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	// Kalıtım benzetmesi (Alt siniftan nesne üretildiginde Ust siniftan da nesne uretilir)
	this->super = BocekKurucu(tur, deger, x, y);
	this->super->super->gorunum = &SinekGorunum;
	this->s_yokedici = &SinekYokEdici;
	
	return this;
}

char* SinekGorunum(const Canli this) {
	char* karakter = &this->tur;
	return karakter;
}

void SinekYokEdici(const Sinek this) {
	if(this == NULL) return;
	this->super->c_yokedici(this->super);
	free(this);
}