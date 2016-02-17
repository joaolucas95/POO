#ifndef UNIDADE_H
#define UNIDADE_H

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Unidade{
	int x, y;
	int x_des, y_des;
	string nome, tipo, inimigo;
	int saude, carga;
	bool deambula, ataca, atacaEdi, mina, conserta, constroi;
	int f_ataque, f_defesa, cap_carga;
public:
	Unidade(int coordX, int coordY);
	~Unidade(){}
	int getX() const;
	int getY() const;
	int getX_des() const;
	int getY_des() const;
	bool getDeambula() const;
	bool getAtaca() const;
	bool getAtacaEdi() const;
	bool getMina() const;
	bool getConserta() const;
	bool getConstroi() const;
	int getfAtaque() const;
	int getfDefesa() const;
	int getCapCarga() const;
	int getCarga() const;
	void setCarga(int num);
	void setX(int num);
	void setY(int num);
	void setX_des(int num);
	void setY_des(int num);
	void setForcas(int fataque, int fdefesa);
	void setCapCarga(int num);
	string getNome() const;
	int getSaude() const;
	void setSaude(int num);
	void setNome(string s);
	void setDeambula(int num);
	void setAtaca(int num);
	void setAtacaEdi(int num);
	void setMina(int num);
	void setConserta(int num);
	void setConstroi(int num);
	void setTipo(string s);
	string getTipo() const;
	string getInimigo() const;
	void setInimigo(string s);
};

class Campones: public Unidade{
	static const int custoM = 10, custoP = 0, custoO = 5;
	static int n_Camponeses;
	bool constroi;
public:
	Campones(int coordX, int coordY);
	~Campones(){}
	int getN_Camponeses() const;
	int getCustoM() const;
	int getCustoP() const;
	int getCustoO() const;
};

class Soldado: public Unidade{
	static const int custoM = 10, custoP = 0, custoO = 10;
	static int n_Soldados;
public:
	Soldado(int coordX, int coordY);
	~Soldado(){}
	int getN_Soldados() const;
	int getCustoM() const;
	int getCustoP() const;
	int getCustoO() const;
};

class Cavaleiro: public Unidade{
	static const int custoM = 20, custoP = 5, custoO = 10;
	static int n_Cavaleiros;
public:
	Cavaleiro(int coordX, int coordY);
	~Cavaleiro(){}
	int getN_Cavaleiros() const;
	int getCustoM() const;
	int getCustoP() const;
	int getCustoO() const;
};

class Camp_Cavalo: public Unidade{
	static const int custoM = 20, custoP = 5, custoO = 5;
	static int n_CampCavalo;
public:
	Camp_Cavalo(int coordX, int coordY);
	~Camp_Cavalo(){}
	int getN_CampCavalo() const;
	int getCustoM() const;
	int getCustoP() const;
	int getCustoO() const;
};
class Fantasma: public Unidade{
	static const int custoM = 30, custoP = 20, custoO = 20;
	static int n_Fantasmas;
public:
	Fantasma(int coordX, int coordY);
	~Fantasma(){}
	int getCustoM() const;
	int getCustoP() const;
	int getCustoO() const;
};

#endif UNIDADE_H