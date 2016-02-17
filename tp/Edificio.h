#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Edificio{
	int x, y;
	int estado_conserv;
	string nome, tipo;
public:
	Edificio(int coordX, int coordY);
	~Edificio(){}
	int getX() const;
	int getY() const;
	string getNome() const;
	int getEstado_Conserv() const;
	void setEstado_Conserv(int num);
	void setNome(string s);
	void setTipo(string s);
	string getTipo() const;
};

class Castelo: public Edificio{
	static int n_Castelos;
public:
	Castelo(int coordX, int coordY);
	~Castelo(){}
	int getN_Castelos() const;
};

class Quartel: public Edificio{
	static int n_Quarteis;
public:
	Quartel(int coordX, int coordY);
	~Quartel(){}
	int getN_Quarteis() const;
};

class Estabulo: public Edificio{
	static int n_Estabulos;
public:
	Estabulo(int coordX, int coordY);
	~Estabulo(){}
	int getN_Estabulos() const;
};

class Quinta: public Edificio{
	static int n_Quintas;
public:
	Quinta(int coordX, int coordY);
	~Quinta(){}
	int getN_Quintas() const;
};

#endif EDIFICIO_H