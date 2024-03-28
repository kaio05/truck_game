#include <iostream>
#include <stdlib.h>
#include "colors.h"
#include "network.h"
#include "packlib.h"
using namespace std;

void drawTruck(int, int);
void WhiteSpace(int);


int main() {

	srand(unsigned(time(NULL)));
	// --------------------
	// Inicializa dados:
	// - Posição
	int posA = 0, posB = 0;
	// - Velocidade
	int velA, velB;
	// - Cores
	int corA = yellow, corB = red;
	// - Estado da pista
	int roadA, roadB;
	// --------------------
	int passo = 0;

	do
	{
		// ------------------
		// Limpa tela
		system("CLS");
		changeColor(white, gray);
		cout << "                                                     Truck Racing                                                      \n\n\n";
		// Desenha caminhões
		
		drawTruck(corA, posA);
		drawTruck(corB, posB);
		resetColor();

		// ------------------
		// ------------------------
		// Atualiza velocidade
		velA = (rand() % 10) + 1;
		velB = (rand() % 10) + 1;
		// Atualiza estado da pista
		roadA = rand() % 2;
		roadB = rand() % 2;
		// ------------------------

		// ----------------------------------
		// Transmite, recebe e processa dados
		Transmitir(passo, corA, posA, velA, roadA);
		cout << "Recebendo dados..." << endl;
		changeColor(corA, black);
		int dadosA = Receber();
		resetColor();
		cout << "Processando dados..." << endl;
		changeColor(corA, black);
		posA = Processar(dadosA);
		resetColor();

		Transmitir(passo, corB, posB, velB, roadB);
		cout << "Recebendo dados..." << endl;
		changeColor(corB, black);
		int dadosB = Receber();
		resetColor();
		cout << "Processando dados" << endl;
		changeColor(corB, black);
		// Calcula Próxima posição
		posB = Processar(dadosB);
		resetColor();

		// ----------------------------------
		

		// -------------------------------
		// Aguarda pressionamento de tecla
		system("pause");
		// -------------------------------

		passo = passo + 1;
	} while (posA <= 100 && posB <= 100);
	// --------------------
	// Limpa tela
	system("CLS");
	changeColor(white, gray);
	cout << "                                                     Truck Racing                                                      \n\n\n";
	// Desenha caminhões
	drawTruck(corA, posA);
	drawTruck(corB, posB);
	// Exibe resultados
	changeColor(white, gray);
	cout << "                                                   Corrida Concluída                                                  \n\n\n";
	cout << " Passos ";
	resetColor();
	cout << " " << passo << "\n\n";
	changeColor(black, corA);
	cout << " Posicao ";
	changeColor(corA, black);
	cout << " " << posA << " ";
	changeColor(black, corA);
	cout << " Velocidade Media ";
	changeColor(corA, black);
	cout << " " << float(posA) / passo << "\n\n";

	changeColor(black, corB);
	cout << " Posicao ";
	changeColor(corB, black);
	cout << " " << posB << " ";
	changeColor(black, corB);
	cout << " Velocidade Media ";
	changeColor(corB, black);
	cout << " " << float(posB) / passo << "\n\n";
	
	changeColor(white, gray);
	cout << "                                                                                                                       \n\n\n";
	resetColor();

	system("pause");
	//
}

static void drawTruck(int color, int position) {
	changeColor(color, black);
	WhiteSpace(position);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\x20\xDB\xDB\xDC" << endl;
	WhiteSpace(position);
	cout << "\xDF\xDF" << "00" << "\xDF\xDF\xDF\xDF" << "0" << "\xDF" << endl;

	cout << "---------------------------------------------------------------------------------------------------|-------------------" << endl << "                                                                                                  100" << endl;
	cout << "\n";
}

void WhiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }