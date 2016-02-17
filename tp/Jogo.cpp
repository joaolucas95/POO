#include "Jogo.h"
void Jogo::addPopulacao(string nome){
		populacoes.push_back(Populacao(nome));
}
int Jogo::pesquisaPop(string nome){
	for (unsigned int i=0; i<populacoes.size(); i++){
		if (populacoes[i].getNome() == nome)
			return i;
	}
	return -1;
}


////////////////////////////////////////////////////////////////////////////////
vector<Unidade*> Jogo::getUnid(int lin, int col){
	vector <Unidade*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].getUnid(lin, col);
		for(unsigned int j=0; j<vp.size(); j++)
			v.push_back(vp[j]);
	}
	return v;
}
int Jogo::getUnidPop(int lin, int col){
	vector <Unidade*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].getUnid(lin, col);
		if(vp.size() > 0)
			return i;
	}
	return NULL;
}
int Jogo::getEdiPop(int lin, int col){
	vector <Edificio*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].getEdi(lin, col);
		if(vp.size() > 0)
			return i;
	}
	return NULL;
}
vector<Edificio*> Jogo::getEdi(int lin, int col){
	vector <Edificio*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].getEdi(lin, col);
		for(unsigned int j=0; j<vp.size(); j++)
			v.push_back(vp[j]);
	}
	return v;
}
vector <Fontes*> Jogo::getFont(int lin, int col){
	vector <Fontes*> v;
	for(unsigned int i=0; i<f_recursos.size(); i++)
		if(f_recursos[i]->getX() == lin && f_recursos[i]->getY() == col)
			v.push_back(f_recursos[i]);
	return v;
}

/////////////////////////////////////////////////////////////////////////////
bool Jogo::addCamponesPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	populacoes[qual].addCampones(lin, col);
	return true;
}
bool Jogo::addSoldadoPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	populacoes[qual].addSoldado(lin, col);
	return true;
}
bool Jogo::addCavaleiroPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	populacoes[qual].addCavaleiro(lin, col);
	return true;
}
bool Jogo::addCamp_CavaloPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	populacoes[qual].addCamp_Cavalo(lin, col);
	return true;
}
bool Jogo::addFantasmaPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	populacoes[qual].addFantasma(lin, col);
	return true;
}

bool Jogo::addCasteloPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	if(celulaOcupada(lin, col))
		return false;
	populacoes[qual].addCastelo(lin, col);
	return true;
}
bool Jogo::addQuartelPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	if(celulaOcupada(lin, col))
		return false;
	populacoes[qual].addQuartel(lin, col);
	return true;
}
bool Jogo::addEstabuloPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	if(celulaOcupada(lin, col))
		return false;
	populacoes[qual].addEstabulo(lin, col);
	return true;
}
bool Jogo::addQuintaPop(string nome, int lin, int col){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return false;
	if(celulaOcupada(lin, col))
		return false;
	populacoes[qual].addQuinta(lin, col);
	return true;
}

void Jogo::addMina(int lin, int col){
	if(celulaOcupada(lin, col))
		return;
	f_recursos.push_back(new Mina(lin, col));
}
void Jogo::addPedreira(int lin, int col){
	if(celulaOcupada(lin, col))
		return;
	f_recursos.push_back(new Pedreira(lin, col));
}
void Jogo::addFloresta(int lin, int col){
	if(celulaOcupada(lin, col))
		return;
	f_recursos.push_back(new Floresta(lin, col));
}
////////////////////////////////////////////////////////////////////
vector <Unidade*> Jogo::pesquisaUnid(){
	vector <Unidade*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++)
			v.push_back(vp[j]);
	}
	return v;
}
vector <Edificio*> Jogo::pesquisaEdi(){
	vector <Edificio*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].pesquisaEdi();
		for(unsigned int j=0; j<vp.size(); j++)
			v.push_back(vp[j]);
	}
	return v;
}
vector <Fontes*> Jogo::pesquisaFont(){
	vector <Fontes*> v;
	for(unsigned int i=0; i<f_recursos.size(); i++)
		v.push_back(f_recursos[i]);
	return v;
}
bool Jogo::celulaOcupada(int lin, int col){
	vector <Edificio*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].getEdi(lin, col);
		for(unsigned int j=0; j<vp.size(); j++)
			v.push_back(vp[j]);
	}
	vector <Fontes*> v2;
	vector <Fontes*> vp2 = getFont(lin, col);
	for(unsigned int i=0; i<vp2.size(); i++)
		v2.push_back(vp2[i]);
	if(v.size() > 0 || v2.size() > 0)
		return 1;
	else
		return 0;
}
//////////////////////////////////////////////////////////////////////
void Jogo::alteraUnid(string id, int novo_x, int novo_y){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(id == vp[j]->getNome())
			{
				vp[j]->setX_des(novo_x);
				vp[j]->setY_des(novo_y);
				return;
			}
		}
	}
}
void Jogo::alteraUnid1(string id, int novo_x, int novo_y){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(id == vp[j]->getNome())
			{
				vp[j]->setX_des(novo_x+vp[j]->getX());
				vp[j]->setY_des(novo_y+vp[j]->getY());
				return;
			}
		}
	}
}
void Jogo::mexeUnid(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getX() > vp[j]->getX_des())
				vp[j]->setX(vp[j]->getX()-1);
			if(vp[j]->getX() < vp[j]->getX_des())
				vp[j]->setX(vp[j]->getX()+1);
			if(vp[j]->getY() > vp[j]->getY_des())
				vp[j]->setY(vp[j]->getY()-1);
			if(vp[j]->getY() < vp[j]->getY_des())
				vp[j]->setY(vp[j]->getY()+1);
		}
	}
}
void Jogo::ataca(string id, string idvitima){
	Unidade *atac = NULL, *def = NULL;
	int pop_atac, pop_def;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id){
				atac = vp[j];
				pop_atac = i;
			}
		}
	}
	if(atac == NULL) return;
	if(atac->getfAtaque() == 0) return;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == idvitima){
				def = vp[j];
				pop_def = i;
			}
		}
	}
	if(def == NULL || def->getTipo() == "gho") return;
	if(pop_atac == pop_def) return;
	atac->setAtaca(1);
	atac->setAtacaEdi(0); atac->setConserta(0); atac->setDeambula(0);
	atac->setInimigo(def->getNome());
	if(atac->getX() != def->getX() || atac->getY() != def->getY()){
		atac->setX_des(def->getX());
		atac->setY_des(def->getY());
		return;
	}
	else{
		for(unsigned int i=0; i<populacoes.size(); i++){
			vector <Unidade*> vp = populacoes[i].pesquisaUnid();
			for(unsigned int j=0; j<vp.size(); j++){
				if(vp[j]->getNome() == idvitima){
					vp[j]->setSaude(vp[j]->getSaude() - (atac->getfAtaque() - (int)(atac->getfAtaque()*vp[j]->getfDefesa()*0.01)));
					if(idvitima[0] == 'S' || idvitima[0] == 'K')
						contra_ataca(idvitima, id);
					if(vp[j]->getfAtaque() == 0){
						vector <Edificio*> p = populacoes[i].pesquisaEdi();
						for(unsigned int l=0; l<p.size(); l++){
							if(p[l]->getTipo() == "cas"){
								vp[j]->setX_des(p[l]->getX());
								vp[j]->setY_des(p[l]->getY());
							}
						}
					}
				}
			}
		}
	}
}
void Jogo::atacaEdi(string id, string idvitima){
	Unidade *atac = NULL;
	Edificio *def = NULL;
	int pop_atac, pop_def;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id){
				atac = vp[j];
				pop_atac = i;
			}
		}
	}
	if(atac == NULL) return;
	if(atac->getfAtaque() == 0) return;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].pesquisaEdi();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == idvitima){
				def = vp[j];
				pop_def = i;
			}
		}
	}
	if(def == NULL) return;
	if(pop_atac == pop_def) return;
	atac->setAtacaEdi(1);
	atac->setAtaca(0); atac->setConserta(0); atac->setDeambula(0);
	atac->setInimigo(def->getNome());
	if(atac->getX() != def->getX() || atac->getY() != def->getY()){
		atac->setX_des(def->getX());
		atac->setY_des(def->getY());
		return;
	}
	else{
		for(unsigned int i=0; i<populacoes.size(); i++){
			vector <Edificio*> vp = populacoes[i].pesquisaEdi();
			for(unsigned int j=0; j<vp.size(); j++){
				if(vp[j]->getNome() == idvitima){
					vp[j]->setEstado_Conserv(vp[j]->getEstado_Conserv() - 10);
				}
			}
		}
	}
}
void Jogo::conserta(string id, string ide){
	Unidade *camp = NULL;
	Edificio *edi = NULL;
	int pop_atac, pop_def;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id){
				camp= vp[j];
				pop_atac = i;
			}
		}
	}
	if(camp == NULL) return;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp = populacoes[i].pesquisaEdi();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == ide){
				edi = vp[j];
				pop_def = i;
			}
		}
	}
	if(edi == NULL) return;
	if(pop_atac != pop_def) return;
	camp->setConserta(1);
	camp->setDeambula(0);
	camp->setInimigo(edi->getNome());
	if(camp->getX() != edi->getX() || camp->getY() != edi->getY()){
		camp->setX_des(edi->getX());
		camp->setY_des(edi->getY());
		return;
	}
	else{
		for(unsigned int i=0; i<populacoes.size(); i++){
			vector <Edificio*> vp = populacoes[i].pesquisaEdi();
			for(unsigned int j=0; j<vp.size(); j++){
				if(vp[j]->getNome() == ide){
					if(edi->getTipo() == "cas" && edi->getEstado_Conserv() == 200){
						camp->setConserta(false); return;
					}
					if(edi->getTipo() == "quar" && edi->getEstado_Conserv() == 100){
						camp->setConserta(false); return;
					}
					if(edi->getTipo() == "est" && edi->getEstado_Conserv() == 120){
						camp->setConserta(false); return;
					}
					if(edi->getTipo() == "quin" && edi->getEstado_Conserv() == 80){
						camp->setConserta(false); return;
					}
					vp[j]->setEstado_Conserv(vp[j]->getEstado_Conserv() + 1);
				}
			}
		}
	}
}
void Jogo::contra_ataca(string id, string idvitima){
	Unidade *atac = NULL, *def = NULL;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id){
				atac = vp[j];
			}
		}
	}
	if(atac == NULL) return;
	if(atac->getfAtaque() == 0) return;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == idvitima){
				def = vp[j];
			}
		}
	}
	if(def == NULL) return;
	atac->setAtaca(1);
	atac->setInimigo(def->getNome());
	if(atac->getX() != def->getX() || atac->getY() != def->getY()){
		atac->setX_des(def->getX());
		atac->setY_des(def->getY());
		return;
	}
	else{
		for(unsigned int i=0; i<populacoes.size(); i++){
			vector <Unidade*> vp = populacoes[i].pesquisaUnid();
			for(unsigned int j=0; j<vp.size(); j++){
				if(vp[j]->getNome() == idvitima){
					vp[j]->setSaude(vp[j]->getSaude() - (atac->getfAtaque() - (int)(atac->getfAtaque()*vp[j]->getfDefesa()*0.01)));
				}
			}
		}
	}
}
void Jogo::verifAtacaEdi(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getAtacaEdi()){
				atacaEdi(vp[j]->getNome(), vp[j]->getInimigo());
			}
		}
	}
}
void Jogo::verifConserta(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getConserta()){
				conserta(vp[j]->getNome(), vp[j]->getInimigo());
			}
		}
	}
}
void Jogo::verifConstroi(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getConstroi()){
				makeEdi(vp[j]->getNome(), vp[j]->getInimigo(), vp[j]->getX_des(), vp[j]->getY_des());
			}
		}
	}
}
void Jogo::verifAtaca(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getAtaca()){
				ataca(vp[j]->getNome(), vp[j]->getInimigo());
			}
		}
	}
}
void Jogo::verifMina(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getMina()){
				mina(vp[j]->getNome(), vp[j]->getInimigo());
			}
		}
	}
}
void Jogo::verifMorto(){
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getSaude() <= 0){
				populacoes[i].apaga(vp[j]->getNome());
			}
		}
	}
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Edificio*> vp1 = populacoes[i].pesquisaEdi();
		for(unsigned int j=0; j<vp1.size(); j++){
			if(vp1[j]->getEstado_Conserv() <= 0){
				populacoes[i].apagaEdi(vp1[j]->getNome());
			}
		}
	}
	vector <Fontes*> vp2 = pesquisaFont();
		for(unsigned int j=0; j<vp2.size(); j++){
			if(vp2[j]->getTipo() == "flo")
				if(vp2[j]->getMadeira() <= 0)
					apagaFont(vp2[j]->getNome());
			if(vp2[j]->getTipo() == "min")
				if(vp2[j]->getOuro() <= 0)
					apagaFont(vp2[j]->getNome());
			if(vp2[j]->getTipo() == "ped")
				if(vp2[j]->getPedra() <= 0)
					apagaFont(vp2[j]->getNome());
		}
}
void Jogo::mina(string id, string idfonte){
	Unidade *uni = NULL;
	Fontes *font = NULL;
	Edificio *cast = NULL;
	int pop_pertence;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector <Unidade*> vp = populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id){
				uni = vp[j];
				pop_pertence = i;
			}
		}
	}
	if(uni == NULL) return;
	if(uni->getCapCarga() == 0) return;
	
	vector<Fontes*> vp = pesquisaFont();
	for(unsigned int j=0; j<vp.size(); j++){
		if(vp[j]->getNome() == idfonte){
			font = vp[j];
		}
	}
	if(font == NULL) return;
	vector<Edificio*> p = populacoes[pop_pertence].pesquisaEdi();
	for(unsigned int l=0; l<p.size(); l++)
		if(p[l]->getTipo() == "cas")
			cast = p[l];
	uni->setMina(1);
	uni->setConserta(0); uni->setDeambula(0);
	uni->setInimigo(font->getNome());
	if((uni->getX() != font->getX() || uni->getY() != font->getY()) && uni->getCarga() != uni->getCapCarga()){
		uni->setX_des(font->getX());
		uni->setY_des(font->getY());
		return;
	}
	else{
		if(uni->getCarga() == uni->getCapCarga()){
			if(cast != NULL){
			if(uni->getX() == cast->getX() && uni->getY() == cast->getY()){
				uni->setCarga(0);
				if(font->getTipo() == "flo")
					populacoes[pop_pertence].setRecurso("madeira", uni->getCapCarga());
				if(font->getTipo() == "min")
					populacoes[pop_pertence].setRecurso("ouro", uni->getCapCarga());
				if(font->getTipo() == "ped")
					populacoes[pop_pertence].setRecurso("ouro", uni->getCapCarga());
			}
			else{
				uni->setX_des(cast->getX());
				uni->setY_des(cast->getY());
			}
			}
		}
		else{
		for(unsigned int i=0; i<populacoes.size(); i++){
			vector <Unidade*> vp = populacoes[i].pesquisaUnid();
			for(unsigned int j=0; j<vp.size(); j++){
				if(vp[j]->getNome() == id){
					vp[j]->setCarga(vp[j]->getCarga() + 1);
					if(font->getTipo() == "flo")
						font->setMadeira(font->getMadeira() - 1);
					if(font->getTipo() == "min")
						font->setOuro(font->getOuro() - 1);
					if(font->getTipo() == "ped")
						font->setPedra(font->getPedra() - 1);
				}
			}
		}
	}
	}
}


void Jogo::makeUnid(string oque){
	if(populacoes.size() == 0)
		return;
	if(oque == "camp"){
		if(populacoes[0].getRecurso("madeira") >= 10 && populacoes[0].getRecurso("ouro") >= 5){
			vector<Edificio*> v = populacoes[0].pesquisaEdi();
			for(unsigned int i=0; i<v.size(); i++){
				if("cas" == v[i]->getTipo()){
					populacoes[0].addCampones(v[i]->getX(), v[i]->getY());
					populacoes[0].setRecurso("madeira", -10);
					populacoes[0].setRecurso("ouro", -5);
				}
			}
		}
	}
	if(oque == "sold"){
		if(populacoes[0].getRecurso("madeira") >= 10 && populacoes[0].getRecurso("ouro") >= 10){
			vector<Edificio*> v = populacoes[0].pesquisaEdi();
			for(unsigned int i=0; i<v.size(); i++){
				if("quar" == v[i]->getTipo()){
					populacoes[0].addSoldado(v[i]->getX(), v[i]->getY());
					populacoes[0].setRecurso("madeira", -10);
					populacoes[0].setRecurso("ouro", -10);
				}
			}
		}
	}
	if(oque == "cav"){
		if(populacoes[0].getRecurso("madeira") >= 20 && populacoes[0].getRecurso("pedra") >= 5 && populacoes[0].getRecurso("ouro") >= 10){
			vector<Edificio*> v = populacoes[0].pesquisaEdi();
			for(unsigned int i=0; i<v.size(); i++){
				if("est" == v[i]->getTipo()){
					populacoes[0].addCavaleiro(v[i]->getX(), v[i]->getY());
					populacoes[0].setRecurso("madeira", -20);
					populacoes[0].setRecurso("pedra", -5);
					populacoes[0].setRecurso("ouro", -10);
				}
			}
		}
	}
	if(oque == "cv"){
		if(populacoes[0].getRecurso("madeira") >= 20 && populacoes[0].getRecurso("pedra") >= 5 && populacoes[0].getRecurso("ouro") >= 5){
			vector<Edificio*> v = populacoes[0].pesquisaEdi();
			for(unsigned int i=0; i<v.size(); i++){
				if("cas" == v[i]->getTipo()){
					populacoes[0].addCamp_Cavalo(v[i]->getX(), v[i]->getY());
					populacoes[0].setRecurso("madeira", -20);
					populacoes[0].setRecurso("pedra", -5);
					populacoes[0].setRecurso("ouro", -5);
				}
			}
		}
	}
	if(oque == "gho"){
		if(populacoes[0].getRecurso("madeira") >= 30 && populacoes[0].getRecurso("pedra") >= 20 && populacoes[0].getRecurso("ouro") >= 20){
			vector<Edificio*> v = populacoes[0].pesquisaEdi();
			for(unsigned int i=0; i<v.size(); i++){
				if("cas" == v[i]->getTipo()){
					populacoes[0].addFantasma(v[i]->getX(), v[i]->getY());
					populacoes[0].setRecurso("madeira", -30);
					populacoes[0].setRecurso("pedra", -20);
					populacoes[0].setRecurso("ouro", -20);
				}
			}
		}
	}
}
void Jogo::makeEdi(string id, string oque, int linha, int coluna){
	if(id[0] != 'P') return;
	Unidade *aux = NULL;
	int qual = -1;
	if(populacoes.size() == 0) return;
	if(celulaOcupada(linha, coluna)) return;
	if(oque != "cas" && oque != "quin" && oque != "quar" && oque != "est")
		return;
	vector<Unidade*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector<Unidade*> vp = pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getNome() == id && vp[j]->getTipo() == "camp"){
				qual = i;
				aux = vp[j];
			}
		}
	}
	if(qual == -1) return;
	aux->setConstroi(1);
	aux->setInimigo(oque);
	if(aux->getX() != linha || aux->getY() != coluna){
		aux->setX_des(linha);
		aux->setY_des(coluna);
		return;
	}
	if(oque == "cas"){
		if(populacoes[qual].getRecurso("ouro") >= 20 && populacoes[qual].getRecurso("madeira") >= 20 && populacoes[qual].getRecurso("pedra") >= 30){
			populacoes[qual].addCastelo(linha, coluna);
			populacoes[qual].setRecurso("ouro", -20);
			populacoes[qual].setRecurso("madeira", -20);
			populacoes[qual].setRecurso("pedra", -30);
			return;
		}
	}
	if(oque == "quar"){
		if(populacoes[qual].getRecurso("ouro") >= 30 && populacoes[qual].getRecurso("madeira") >= 10 && populacoes[qual].getRecurso("pedra") >= 30){
			populacoes[qual].addQuartel(linha, coluna);
			populacoes[qual].setRecurso("ouro", -30);
			populacoes[qual].setRecurso("madeira", -10);
			populacoes[qual].setRecurso("pedra", -30);
			return;
		}
	}
	if(oque == "est"){
		if(populacoes[qual].getRecurso("ouro") >= 0 && populacoes[qual].getRecurso("madeira") >= 40 && populacoes[qual].getRecurso("pedra") >= 20){
			populacoes[qual].addEstabulo(linha, coluna);
			populacoes[qual].setRecurso("madeira", -40);
			populacoes[qual].setRecurso("pedra", -20);
			return;
		}
	}
	if(oque == "quin"){
		if(populacoes[qual].getRecurso("ouro") >= 30 && populacoes[qual].getRecurso("madeira") >= 30 && populacoes[qual].getRecurso("pedra") >= 0){
			populacoes[qual].addCastelo(linha, coluna);
			populacoes[qual].setRecurso("ouro", -30);
			populacoes[qual].setRecurso("madeira", -30);
		}
	}
}

void Jogo::daOuro(string nome, int n){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return;
	else
		populacoes[qual].setRecurso("ouro", n);
}
void Jogo::daPedra(string nome, int n){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return;
	else
		populacoes[qual].setRecurso("pedra", n);
}
void Jogo::daMadeira(string nome, int n){
	int qual = pesquisaPop(nome);
	if (qual == -1)
		return;
	else
		populacoes[qual].setRecurso("madeira", n);
}
void Jogo::apagaFont(string nome){
	int aux = -1;
	vector <Fontes*> v = pesquisaFont();
	for(unsigned int i=0; i<f_recursos.size(); i++)
		if(v[i]->getNome() == nome)
			aux = i;
	if(aux == -1) return;
	delete f_recursos[aux];
	f_recursos.erase(f_recursos.begin() + aux);
}
void Jogo::special(){
	vector <Unidade*> aux;
	vector<Unidade*> v;
	for(unsigned int i=0; i<populacoes.size(); i++){
		vector<Unidade*> vp = pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getTipo() == "gho"){
				aux = populacoes[i].getUnid(vp[j]->getX(), vp[j]->getY());
				if(aux.size() > 0)
					aux[0]->setSaude(90);
			}
		}
	}
}