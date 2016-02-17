#ifndef POPULACAO_H
#define POPULACAO_H

#include "Unidade.h"
#include "Edificio.h"
#include <vector>
class Populacao{
	int ouro, madeira, pedra;
	string nome; //nome da populacao
	static int N_Populacoes; //numero de jogadores
	
	vector <Unidade*> unidades;
	vector <Edificio*> edificios;
public:
	Populacao(string nome0);
	~Populacao(){}

	void setRecurso(string s, int num);
	int getRecurso(string s);

	int getN_Populacoes() const; //retorna numero de populacoes existentes no jogo
	string getNome() const; //retorna nome da populaca

	void addCampones(int lin, int col);
	void addSoldado(int lin, int col); //acrescenta um soldado 'a populacao (insere no final do vetor soldados)
	bool addCavaleiro(int lin, int col);
	bool addFantasma(int lin, int col);
	void addCamp_Cavalo(int lin, int col);
	bool addCastelo(int lin, int col); //caso ainda nao tenha, acrescenta castelo 'a populacao
	bool addQuartel(int lin, int col);
	bool addEstabulo(int lin, int col);
	void addQuinta(int lin, int col);

	vector <Unidade*> getUnid(int x, int y);
	vector <Edificio*> getEdi(int x, int y);

	vector <Unidade*> pesquisaUnid();
	vector <Edificio*> pesquisaEdi();

	void apaga(string id);
	void apagaEdi(string id);
};

#endif POPULACAO_H