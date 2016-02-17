#include <sstream>
#include <iomanip>
#include <iostream>
#include "Unidade.h"

using namespace std;

Unidade::Unidade(int coordX, int coordY){
	x = x_des = coordX;
	y = y_des = coordY;
	deambula = 0;
	ataca = 0;
	atacaEdi = 0;
	mina = 0;
	carga = 0;
	inimigo = "nada";
}
int Unidade::getX() const{
	return x;
}
int Unidade::getY() const{
	return y;
}
int Unidade::getX_des() const{
	return x_des;
}
int Unidade::getY_des() const{
	return y_des;
}
string Unidade::getNome() const{
	return nome;
}
int Unidade::getSaude() const{
	return saude;
}
bool Unidade::getDeambula() const{
	if(deambula)
		return true;
	else
		return false;
}
bool Unidade::getAtaca() const{
	if(ataca)
		return true;
	else
		return false;
}
bool Unidade::getAtacaEdi() const{
	if(atacaEdi)
		return true;
	else
		return false;
}
bool Unidade::getMina() const{
	if(mina)
		return true;
	else
		return false;
}
bool Unidade::getConserta() const{
	if(conserta)
		return true;
	else
		return false;
}
bool Unidade::getConstroi() const{
	if(constroi)
		return true;
	else
		return false;
}
int Unidade::getfAtaque() const{
	return f_ataque;
}
int Unidade::getfDefesa() const{
	return f_defesa;
}
int Unidade::getCapCarga() const{
	return cap_carga;
}
void Unidade::setX(int num){
	x = num;
}
void Unidade::setY(int num){
	y = num;
}
void Unidade::setX_des(int num){
	x_des = num;
}
void Unidade::setY_des(int num){
	y_des = num;
}
void Unidade::setNome(string s){
	nome = s;
}
void Unidade::setSaude(int num){
	saude = num;
}
void Unidade::setDeambula(int num){
	if(num)
		deambula = 1;
	else
		deambula = 0;
}
void Unidade::setAtaca(int num){
	if(num){
		ataca = true;
	}
	else
		ataca = false;
}
void Unidade::setAtacaEdi(int num){
	if(num){
		atacaEdi = true;
	}
	else
		atacaEdi = false;
}
void Unidade::setMina(int num){
	if(num){
		mina = true;
	}
	else
		mina = false;
}
void Unidade::setConserta(int num){
	if(num){
		conserta = true;
	}
	else
		conserta = false;
}
void Unidade::setConstroi(int num){
	if(num){
		constroi= true;
	}
	else
		constroi = false;
}
int Unidade::getCarga() const{
	return carga;
}
void Unidade::setCarga(int num){
	carga = num;
}
void Unidade::setForcas(int fataque, int fdefesa){
	f_ataque = fataque;
	f_defesa = fdefesa;
}
void Unidade::setCapCarga(int num){
	cap_carga = num;
}
void Unidade::setTipo(string s){
	tipo = s;
}
string Unidade::getTipo() const{
	return tipo;
}
string Unidade::getInimigo() const{
	return inimigo;
}
void Unidade::setInimigo(string s){
	inimigo = s;
}
/////////////////////////////////////////////////
int Soldado::n_Soldados = 0;

Soldado::Soldado(int coordX, int coordY): Unidade(coordX, coordY){
	setSaude(40);
	setForcas(5, 20);
	setCapCarga(0);
	setTipo("sold");
	ostringstream oss;
	oss << "S" << setw(2) << setfill('0') << n_Soldados++;
	setNome(oss.str());
}
int Soldado::getN_Soldados() const{
	return n_Soldados;
}
int Soldado::getCustoM() const{
	return custoM;
}
int Soldado::getCustoO() const{
	return custoO;
}
int Soldado::getCustoP() const{
	return custoP;
}
/////////////////////////////////////
int Campones::n_Camponeses = 0;

Campones::Campones(int coordX, int coordY): Unidade(coordX, coordY){
	setSaude(20);
	setForcas(0, 0);
	setCapCarga(5);
	constroi = 0;
	setTipo("camp");
	ostringstream oss;
	oss << "P" << setw(2) << setfill('0') << n_Camponeses++;
	setNome(oss.str());
}
int Campones::getN_Camponeses() const{
	return n_Camponeses;
}
int Campones::getCustoM() const{
	return custoM;
}
int Campones::getCustoO() const{
	return custoO;
}
int Campones::getCustoP() const{
	return custoP;
}
///////////////////////////////////////
int Cavaleiro::n_Cavaleiros = 0;

Cavaleiro::Cavaleiro(int coordX, int coordY): Unidade(coordX, coordY){
	setSaude(60);
	setForcas(8, 40);
	setCapCarga(0);
	setTipo("cav");
	ostringstream oss;
	oss << "K" << setw(2) << setfill('0') << n_Cavaleiros++;
	setNome(oss.str());
}
int Cavaleiro::getN_Cavaleiros() const{
	return n_Cavaleiros;
}
int Cavaleiro::getCustoM() const{
	return custoM;
}
int Cavaleiro::getCustoO() const{
	return custoO;
}
int Cavaleiro::getCustoP() const{
	return custoP;
}
///////////////////////////////////////////////
int Camp_Cavalo::n_CampCavalo = 0;

Camp_Cavalo::Camp_Cavalo(int coordX, int coordY): Unidade(coordX, coordY){
	setSaude(40);
	setForcas(0, 0);
	setCapCarga(10);
	setTipo("cv");
	ostringstream oss;
	oss << "B" << setw(2) << setfill('0') << n_CampCavalo++;
	setNome(oss.str());
}
int Camp_Cavalo::getN_CampCavalo() const{
	return n_CampCavalo;
}
int Camp_Cavalo::getCustoM() const{
	return custoM;
}
int Camp_Cavalo::getCustoO() const{
	return custoO;
}
int Camp_Cavalo::getCustoP() const{
	return custoP;
}
///////////////////////////////////////////////
int Fantasma::n_Fantasmas = 0;

Fantasma::Fantasma(int coordX, int coordY): Unidade(coordX, coordY){
	setSaude(99);
	setForcas(0, 0);
	setCapCarga(0);
	setTipo("gho");
	setDeambula(1);
	ostringstream oss;
	oss << "G" << setw(2) << setfill('0') << n_Fantasmas++;
	setNome(oss.str());
}
int Fantasma::getCustoM() const{
	return custoM;
}
int Fantasma::getCustoO() const{
	return custoO;
}
int Fantasma::getCustoP() const{
	return custoP;
}

