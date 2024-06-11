#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
	// Kalıtım benzetmesi
	Canli super;
	void (*b_yokedici)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiKurucu(char, int, int, int);
char* BitkiGorunum(const Canli);
void BitkiYokEdici(const Bitki);

#endif