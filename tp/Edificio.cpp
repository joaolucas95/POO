#include <sstream>
#include <iomanip>
#include <iostream>
#include "Edificio.h"

using namespace std;

Edificio::Edificio(int coordX, int coordY){
	x = coordX;
	y = coordY;
}

int Edificio::getX() const{
	return x;
}
int Edificio::getY() const{
	return y;
}
string Edificio::getNome() const{
	return nome;
}
int Edificio::getEstado_Conserv() const{
	return estado_conserv;
}

void Edificio::setNome(string s){
	nome = s;
}
void Edificio::setEstado_Conserv(int num){
	 estado_conserv = num;
}
void Edificio::setTipo(string s){
	tipo = s;
}
string Edificio::getTipo() const{
	return tipo;
}
///////////////////////////////
int Castelo::n_Castelos = 0;

Castelo::Castelo(int coordX, int coordY): Edificio(coordX, coordY){
	setEstado_Conserv(200);
	setTipo("cas");
	ostringstream oss;
	oss << "C" << setw(2) << setfill('0') << n_Castelos++;
	setNome(oss.str());
}
int Castelo::getN_Castelos() const{
	return n_Castelos;
}

///////////////////////////////
int Quartel::n_Quarteis = 0;

Quartel::Quartel(int coordX, int coordY): Edificio(coordX, coordY){
	setEstado_Conserv(100);
	setTipo("quar");
	ostringstream oss;
	oss << "Q" << setw(2) << setfill('0') << n_Quarteis++;
	setNome(oss.str());
}
int Quartel::getN_Quarteis() const{
	return n_Quarteis;
}

///////////////////////////////
int Estabulo::n_Estabulos = 0;

Estabulo::Estabulo(int coordX, int coordY): Edificio(coordX, coordY){
	setEstado_Conserv(120);
	setTipo("est");
	ostringstream oss;
	oss << "E" << setw(2) << setfill('0') << n_Estabulos++;
	setNome(oss.str());
}
int Estabulo::getN_Estabulos() const{
	return n_Estabulos;
}

///////////////////////////////
int Quinta::n_Quintas = 0;

Quinta::Quinta(int coordX, int coordY): Edificio(coordX, coordY){
	setEstado_Conserv(80);
	setTipo("quin");
	ostringstream oss;
	oss << "F" << setw(2) << setfill('0') << n_Quintas++;
	setNome(oss.str());
}
int Quinta::getN_Quintas() const{
	return n_Quintas;
}