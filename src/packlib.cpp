#include "packlib.h"
#include <iostream>
using namespace std;

int Empacotar(int passo, int cor, int pos, int vel, int oleo)
{
	unsigned int pack = 0;
	pack = pack | passo << 24;  
	pack = pack | cor << 16;
	pack = pack | pos << 9;
	pack = pack | vel << 5;
	pack = pack | oleo << 4;

	return pack;
}

int Passo(int passo)
{
	return passo >> 24;
}

int Cor(int cor)
{
	return cor >> 16 & 255;
}

int Posicao(int pos)
{
	return pos >> 9 & 127;
}

int Velocidade(int vel)
{
	return vel >> 5 & 15;
}

int Pista(int oleo)
{
	return oleo >> 4 & 1;
}
