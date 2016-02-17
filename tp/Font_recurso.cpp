#include "Font_recurso.h"

int Fontes::n_Fontes= 0;

Fontes::Fontes(int coordX, int coordY){
	x = coordX;
	y = coordY;
	ostringstream oss;
	oss << "W" << setw(2) << setfill('0') << n_Fontes++;
	setNome(oss.str());
}
int Fontes::getX() const{
	return x;
}
int Fontes::getY() const{
	return y;
}
string Fontes::getNome() const{
	return nome;
}
void Fontes::setTipo(string s){
	tipo = s;
}
string Fontes::getTipo() const{
	return tipo;
}
void Fontes::setOuro(int num){
	ouro = num;
}
int Fontes::getOuro() const{
	return ouro;
}
void Fontes::setPedra(int num){
	pedra = num;
}
int Fontes::getPedra() const{
	return pedra;
}
void Fontes::setMadeira(int num){
	madeira = num;
}
int Fontes::getMadeira() const{
	return madeira;
}
void Fontes::setNome(string s){
	nome = s;
}

Mina::Mina(int coordX, int coordY): Fontes(coordX, coordY){
	setOuro(50);
	setTipo("min");
}
Pedreira::Pedreira(int coordX, int coordY): Fontes(coordX, coordY){
	setPedra(50);
	setTipo("ped");
}
Floresta::Floresta(int coordX, int coordY): Fontes(coordX, coordY){
	setMadeira(50);
	setTipo("flo");
}