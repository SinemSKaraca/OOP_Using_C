#ifndef SINEK_H
#define SINEK_H

#include "Canli.h"
#include "Bocek.h"

struct SINEK {
	Bocek super;
	void (*s_yokedici)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekKurucu(char, int, int, int);
char* SinekGorunum(const Canli);
void SinekYokEdici(const Sinek);

#endif