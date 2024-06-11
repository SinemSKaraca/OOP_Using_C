#include "Bocek.h"
#include "Canli.h"

Bocek BocekKurucu(char tur, int deger, int x, int y) {
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	// Kalıtım benzetmesi (Alt siniftan nesne üretildiginde Ust siniftan da nesne uretilir)
	this->super = CanliKurucu(tur, deger, x, y);
	this->super->gorunum = &BocekGorunum;
	this->c_yokedici = &BocekYokEdici;
	
	return this;
}

char* BocekGorunum(const Canli this) {
	char* karakter = &this->tur;
	return karakter;
}

void BocekYokEdici(const Bocek this) {
	if(this == NULL) return;
	this->super->yokedici(this->super);
	free(this);
}