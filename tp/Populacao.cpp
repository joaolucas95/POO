#include "Populacao.h"

int Populacao::N_Populacoes = 0;

Populacao::Populacao(string nome0){
	nome = nome0;
	ouro = 300;
	madeira = 300;
	pedra = 300;
	N_Populacoes++;
}

void Populacao::setRecurso(string s, int num){
	if(s == "ouro")
		ouro = ouro + num;
	if(s == "madeira")
		madeira = madeira + num;
	if(s == "pedra")
		pedra = pedra + num;
}
int Populacao::getRecurso(string s){
	if(s == "ouro")
		return ouro;
	if(s == "madeira")
		return madeira;
	if(s == "pedra")
		return pedra;
	return NULL;
}

int Populacao::getN_Populacoes() const{
	return N_Populacoes;
}
string Populacao::getNome() const{
	return nome;
}

void Populacao::addCampones(int lin, int col){
	unidades.push_back(new Campones(lin, col));
}
void Populacao::addSoldado(int lin, int col){
	unidades.push_back(new Soldado(lin, col));
}
bool Populacao::addCavaleiro(int lin, int col){
	for(unsigned int i=0; i<unidades.size();i++)
		if(unidades[i]->getTipo() == "cav")
			return false;
	unidades.push_back(new Cavaleiro(lin, col));
	return true;
}
bool Populacao::addFantasma(int lin, int col){
	for(unsigned int i=0; i<unidades.size();i++)
		if(unidades[i]->getTipo() == "gho")
			return false;
	unidades.push_back(new Fantasma(lin, col));
	return true;
}
void Populacao::addCamp_Cavalo(int lin, int col){
	unidades.push_back(new Camp_Cavalo(lin, col));
}
bool Populacao::addCastelo(int lin, int col){
	for(unsigned int i=0; i<edificios.size();i++)
		if(edificios[i]->getTipo() == "cas")
			return false;
	edificios.push_back(new Castelo(lin, col));
	return true;
}
bool Populacao::addQuartel(int lin, int col){
	for(unsigned int i=0; i<edificios.size();i++)
		if(edificios[i]->getTipo() == "quar")
			return false;
	edificios.push_back(new Quartel(lin, col));
	return true;
}
bool Populacao::addEstabulo(int lin, int col){
	for(unsigned int i=0; i<edificios.size();i++)
		if(edificios[i]->getTipo() == "est")
			return false;
	edificios.push_back(new Estabulo(lin, col));
	return true;
}
void Populacao::addQuinta(int lin, int col){
	edificios.push_back(new Quinta(lin, col));
}

///////////////////////////////////////////////////////////////////
vector <Unidade*> Populacao::getUnid(int x, int y){
	vector <Unidade*> v;
	for(unsigned int i=0; i<unidades.size(); i++)
		if(unidades[i]->getX() == x && unidades[i]->getY() == y)
			v.push_back(unidades[i]);
	return v;
}
vector <Edificio*> Populacao::getEdi(int x, int y){
	vector <Edificio*> v;
	for(unsigned int i=0; i<edificios.size(); i++)
		if(edificios[i]->getX() == x && edificios[i]->getY() == y)
			v.push_back(edificios[i]);
	return v;
}

////////////////////////////////////////////////////////////////
vector <Unidade*> Populacao::pesquisaUnid(){
	vector <Unidade*> v;
	for(unsigned int i=0; i<unidades.size(); i++)
		v.push_back(unidades[i]);
	return v;
}
vector <Edificio*> Populacao::pesquisaEdi(){
	vector <Edificio*> v;
	for(unsigned int i=0; i<edificios.size(); i++)
		v.push_back(edificios[i]);
	return v;
}
void Populacao::apaga(string nome){
	int aux = -1;
	vector <Unidade*> v = pesquisaUnid();
	for(unsigned int i=0; i<unidades.size(); i++)
		if(v[i]->getNome() == nome)
			aux = i;
	if(aux == -1) return;
	delete unidades[aux];
	unidades.erase(unidades.begin() + aux);
}
void Populacao::apagaEdi(string nome){
	int aux = -1;
	vector <Edificio*> v = pesquisaEdi();
	for(unsigned int i=0; i<edificios.size(); i++)
		if(v[i]->getNome() == nome)
			aux = i;
	if(aux == -1) return;
	delete edificios[aux];
	edificios.erase(edificios.begin() + aux);
}