#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#ifndef FONT_RECURSO
#define FONT_RECURSO
class Fontes{
	int x, y;
	int ouro, pedra, madeira;
	string nome, tipo;
	static int n_Fontes;
public:
	Fontes(int coordX, int coordY);
	int getX() const;
	int getY() const;
	int getN_Fontes() const;
	string getNome() const;
	void setOuro(int num);
	int getOuro() const;
	void setMadeira(int num);
	int getMadeira() const;
	void setPedra(int num);
	int getPedra() const;
	void setTipo(string s);
	string getTipo() const;
	void setNome(string s);
};
class Mina: public Fontes{
public:
	Mina(int coordX, int coordY);
	
};
class Pedreira: public Fontes{
public:
	Pedreira(int coordX, int coordY);
};
class Floresta: public Fontes{
public:
	Floresta(int coordX, int coordY);
};

#endif FONT_RECURSO