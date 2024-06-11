#include "Pire.h"

Pire PireKurucu(char tur, int deger, int x, int y) {
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	// Kalıtım benzetmesi (Alt siniftan nesne üretildiginde Ust siniftan da nesne uretilir)
	this->super = BocekKurucu(tur, deger, x, y);
	this->super->super->gorunum = &PireGorunum;
	this->p_yokedici = &PireYokEdici;
	
	return this;
}

char* PireGorunum(const Canli this) {
	char* karakter = &this->tur;
	return karakter;
}

void PireYokEdici(const Pire this) {
	if(this == NULL) return;
	this->super->c_yokedici(this->super);
	free(this);
}