#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
	Canli super;
	void (*c_yokedici)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekKurucu(char, int, int, int);
char* BocekGorunum(const Canli);
void BocekYokEdici(const Bocek);

#endif