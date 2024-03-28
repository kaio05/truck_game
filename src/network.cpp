#include "network.h"
#include "packlib.h"
#include "colors.h"
#include <iostream>
using namespace std;

int network;

void Transmitir(int passo, int cor, int pos, int vel, int oleo)
{
	network = Empacotar(passo, cor, pos, vel, oleo);
	resetColor();
	cout << "Transmitindo dados... " << endl;
	changeColor(black, cor);
	cout << network << endl;
	resetColor();
}

int Receber()
{
	// decomp�e e exibe os dados
	cout << "Frame: " << Passo(network) << " Pos: " << Posicao(network) << " Vel: " << Velocidade(network) << " Oil: ";
	if (Pista(network))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	
	return network;
}

int Processar(int network)
{
	// nova_posi��o = posi��o_atual + velocidade � �leo;
	int nova_posicao = Posicao(network) + Velocidade(network) - Pista(network);
	cout << "Pr�xima posi��o: " << nova_posicao << "\n\n";
	return nova_posicao;
}