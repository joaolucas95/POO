#include <sstream>
#include <iostream>
#include <iomanip>
#include "Jogo.h"
#include "Interface.h"



using namespace std;



void main(){
	Consola c;
	int novo_lin, novo_col;
	while(1){
		system ("color f0");
		c.clrscr();
		prepara_janela();
		string linha, comando;
		getline(cin, linha);
		istringstream iss(linha);
		iss >> comando;
		if(comando == "mkgame"){
			iss >> novo_lin >> novo_col;
			break;
		}
	}
	Jogo *j = new Jogo;
	Interface b(j);
	b.set_Lin(novo_lin);
	b.set_Col(novo_col);
	while(1){
		system ("color f0");
		c.clrscr();
		prepara_janela();
		b.imprimeTudo();
		b.mexeUnid();
		b.deambula();
		j->verifAtaca();
		j->verifAtacaEdi();
		j->verifMina();
		j->verifConserta();
		j->verifConstroi();
		j->special();
		j->verifMorto();
		c.gotoxy(0,y_ecra-1);
		cout << " >> ";
		b.lerComando();
	}
}


