#ifndef PIRE_H
#define PIRE_H

#include "Canli.h"
#include "Bocek.h"

struct PIRE {
	Bocek super;
	void (*p_yokedici)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireKurucu(char, int, int, int);
char* PireGorunum(const Canli);
void PireYokEdici(const Pire);

#endif