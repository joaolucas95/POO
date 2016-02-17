#ifndef INTERFACE_H
#define INTERFACE_H
#define y_ecra 50
#define x_ecra 80
#include "Jogo.h"
#include "Consola.h"
#include <time.h>

class Interface{
	int sLin, sCol, nL, nC;
	Jogo * jogo;
	Consola consola;
public:
	Interface(Jogo * j);
	void set_Lin(int novo_Lin);
	void set_Col(int novo_Col);
	bool EstaNoEcra(int lin, int col);
	void imprimeTudo();
	void cmd_mostra(string populacao);
	void desenhaCelula(int i, int j);
	void seleciona(string id);
	void deambula(string id);
	void deambula();

	void lerComando();
	void lerComando(string comando);
	
	void mexeUnid();
};

void preenche_lateral(Consola c);
void prepara_janela();

#endif INTERFACE_H