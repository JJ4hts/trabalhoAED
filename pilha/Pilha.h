#ifndef PILHA_H

#define PILHA_H

//#include "tad.cpp"
#include "tad/tad.h"

Pilha* criaPilha();
int vaziaPilha(Pilha* pilha);
Pilha* push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
int buscaPilha(Pilha* pilha, int valor);
int buscaERemove(Pilha* pilha, int valor);
void removePares(Pilha* pilha);
void removeRepetidos(Pilha* pilha);
void destroiPilha(Pilha* pilha);
void printPilhaControle(Pilha* pilha);

#endif // PILHA_H
