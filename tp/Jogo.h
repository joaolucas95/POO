#ifndef JOGO_H
#define JOGO_H

#include "Unidade.h"
#include "Edificio.h"
#include "Populacao.h"
#include "Font_recurso.h"
class Jogo{
public:
	vector <Populacao> populacoes;
	vector <Fontes*> f_recursos;
	void addPopulacao(string nome); //adiciona um jogador ao jogo
	int pesquisaPop(string nome); //procura um jogador

	vector <Unidade*> getUnid(int lin, int col);
	int getUnidPop(int lin, int col);
	vector <Edificio*> getEdi(int lin, int col);
	int getEdiPop(int lin, int col);
	vector <Fontes*> getFont(int lin, int col);
	
	bool addCamponesPop(string nome, int lin, int col);
	bool addSoldadoPop(string nome, int lin, int col); //retorna a posicao da populacao no vetor
	bool addCavaleiroPop(string nome, int lin, int col);
	bool addCamp_CavaloPop(string nome, int lin, int col);
	bool addFantasmaPop(string nome, int lin, int col);

	bool addCasteloPop(string nome, int lin, int col);
	bool addQuartelPop(string nome, int lin, int col);
	bool addEstabuloPop(string nome, int lin, int col);
	bool addQuintaPop(string nome, int lin, int col);

	void addMina(int lin, int col);
	void addPedreira(int lin, int col);
	void addFloresta(int lin, int col);

	vector <Unidade*> pesquisaUnid();
	vector <Edificio*> pesquisaEdi();
	vector <Fontes*> pesquisaFont();

	void alteraUnid(string id, int novo_x, int novo_y);
	void alteraUnid1(string id, int novo_x, int novo_y);
	void mexeUnid();
	void ataca(string id, string idvitima);
	void atacaEdi(string id, string idvitima);
	void conserta(string id, string ide);
	void mina(string id, string idfonte);
	void contra_ataca(string idvitima, string id);
	void verifAtaca();
	void verifAtacaEdi();
	void verifMina();
	void verifConserta();
	void verifConstroi();
	void verifMorto();
	void makeUnid(string oque);
	void makeEdi(string id, string oque, int linha, int coluna);

	void daOuro(string nome, int n);
	void daPedra(string nome, int n);
	void daMadeira(string nome, int n);

	bool celulaOcupada(int lin, int col);
	void apagaFont(string nome);
	void special();
};

#endif JOGO_H




