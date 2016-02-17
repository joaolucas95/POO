#include "Interface.h"
#include <fstream>
#include <iostream>

void preenche_lateral(Consola c);
void prepara_janela();
vector <string> recupera_fich(string nome_fich);

Interface::Interface(Jogo * j){
	jogo = j;
	nL = 16;
	nC = 21;
	sLin =0;
	sCol = 0;
}
void Interface::set_Lin(int novo_Lin){
	nL = novo_Lin;
}
void Interface::set_Col(int novo_Col){
	nC = novo_Col;
}
bool Interface::EstaNoEcra(int lin, int col){
	if(lin >= sLin && lin < sLin + nL && col >= sCol && col < sCol + nC)
		return true;
	else
		return false;
}
void Interface::imprimeTudo(){
	for(int i=sLin; i<sLin+nL; i++){
		for(int j=sCol; j<sCol+nC; j++){
			desenhaCelula(i,j);
		}
	}
}
void Interface::desenhaCelula(int i, int j){
	vector<Unidade*> v = jogo->getUnid(i, j);
	Unidade* s = NULL;
	if(v.size() > 0){
		s = v[0];
		int linEcra = (i-sLin)*3; //+ margem
		int colEcra = (j-sCol)*3; //+ margem
		if(jogo->getUnidPop(i, j) == 0)
			consola.setBackgroundColor(consola.AMARELO);
		if(jogo->getUnidPop(i, j) == 1)
			consola.setBackgroundColor(consola.AZUL_CLARO);
		if(jogo->getUnidPop(i, j) == 2)
			consola.setBackgroundColor(consola.VERDE);
		if(jogo->getUnidPop(i, j) == 3)
			consola.setBackgroundColor(consola.CYAN_CLARO);
		if(jogo->getUnidPop(i, j) == 4)
			consola.setBackgroundColor(consola.COR_DE_ROSA);
		consola.gotoxy(colEcra, linEcra);
		cout << "Uni";
		consola.gotoxy(colEcra, linEcra+1);
		cout << s->getNome();
		consola.gotoxy(colEcra, linEcra+2);
		if(s->getSaude() >= 10)
			cout << (char) 3 << s->getSaude();
		else
			cout << ' ' << (char) 3 << s->getSaude();
		consola.setBackgroundColor(consola.BRANCO_CLARO);
	}
	vector<Edificio*> v1 = jogo->getEdi(i, j);
	Edificio* s1 = NULL;
	if(v1.size() > 0){
		s1 = v1[0];
		int linEcra = (i-sLin)*3; //+ margem
		int colEcra = (j-sCol)*3; //+ margem
		if(jogo->getEdiPop(i, j) == 0)
			consola.setBackgroundColor(consola.AMARELO);
		if(jogo->getEdiPop(i, j) == 1)
			consola.setBackgroundColor(consola.AZUL_CLARO);
		if(jogo->getEdiPop(i, j) == 2)
			consola.setBackgroundColor(consola.VERDE);
		if(jogo->getEdiPop(i, j) == 3)
			consola.setBackgroundColor(consola.CYAN_CLARO);
		if(jogo->getEdiPop(i, j) == 4)
			consola.setBackgroundColor(consola.COR_DE_ROSA);
		consola.gotoxy(colEcra, linEcra);
		cout << "Est";
		consola.gotoxy(colEcra, linEcra+1);
		cout << s1->getNome();
		consola.gotoxy(colEcra, linEcra+2);
		if(s1->getEstado_Conserv() >= 100)
			cout << s1->getEstado_Conserv();
		else{
			if(s1->getEstado_Conserv() >= 10)
				cout << " " << s1->getEstado_Conserv();
			else
				cout << "  " << s1->getEstado_Conserv();
		}
		consola.setBackgroundColor(consola.BRANCO_CLARO);
	}
	vector<Fontes*> v2 = jogo->getFont(i, j);
	Fontes* s2 = NULL;
	if(v2.size() > 0){
		s2 = v2[0];
		int linEcra = (i-sLin)*3; //+ margem
		int colEcra = (j-sCol)*3; //+ margem
		if(s2->getTipo() == "flo")
			consola.setBackgroundColor(consola.VERDE_CLARO);
		if(s2->getTipo() == "min")
			consola.setBackgroundColor(consola.AMARELO_CLARO);
		if(s2->getTipo() == "ped")
			consola.setBackgroundColor(consola.CINZENTO);
		consola.gotoxy(colEcra, linEcra);
		cout << "TER";
		consola.gotoxy(colEcra, linEcra+1);
		cout << s2->getNome();

		consola.gotoxy(colEcra, linEcra+2);
		if(s2->getTipo() == "min"){
			if(s2->getOuro() >= 10)
				cout << "0" << s2->getOuro();
			else
				cout << "0" << s2->getOuro();
		}
		if(s2->getTipo() == "flo"){
			if(s2->getMadeira() >= 10)
				cout << "0" << s2->getMadeira();
			else
				cout << "0" << s2->getMadeira();
		}if(s2->getTipo() == "ped"){
			if(s2->getPedra() >= 10)
				cout << "0" << s2->getPedra();
			else
				cout << "00" << s2->getPedra();
		}
		consola.setBackgroundColor(consola.BRANCO_CLARO);
	}
}
void Interface::cmd_mostra(string populacao){
	int qual = jogo->pesquisaPop(populacao);
	if (qual == -1)
		return;
	else{
		int aux = 2;
		consola.gotoxy(x_ecra-16, aux++);
		cout << "POPULACAO " << populacao << ":";
		consola.gotoxy(x_ecra-16, aux+2);
		cout << "Ouro: " << jogo->populacoes[qual].getRecurso("ouro");
		consola.gotoxy(x_ecra-16, aux++);
		cout << "Madeira: " << jogo->populacoes[qual].getRecurso("madeira");
		consola.gotoxy(x_ecra-16, aux++);
		cout << "Pedra: " << jogo->populacoes[qual].getRecurso("pedra");
		consola.gotoxy(x_ecra-16, aux++);
		vector <Unidade*> v1 = jogo->populacoes[qual].pesquisaUnid();
		for(unsigned int i=0; i<v1.size(); i++){
			consola.gotoxy(x_ecra-16, aux++);
			cout << v1[i]->getNome();
		}
		vector <Edificio*> v2 = jogo->populacoes[qual].pesquisaEdi();
		for(unsigned int i=0; i<v2.size(); i++){
			consola.gotoxy(x_ecra-16, aux++);
			cout << v2[i]->getNome();
		}
	}
	consola.getch();
}

void Interface::lerComando(){
	string linha, comando;
	bool flg = 0;
	do{	
	getline(cin, linha);
	if(linha.empty())
		return;
	istringstream iss(linha);
	iss >> comando;
	if(comando == "pop")
	{
		string pop_pertenc;
		iss >> pop_pertenc;
		jogo->addPopulacao(pop_pertenc);
		return;
	}
	if(comando == "setu")
	{
		string tipo, pop_pertenc;
		int x, y;
		iss >> pop_pertenc >> tipo >> y >> x;
		if (tipo == "camp")
			jogo->addCamponesPop(pop_pertenc, x, y);
		if (tipo == "sold")
			jogo->addSoldadoPop(pop_pertenc, x, y);
		if (tipo == "cv")
			jogo->addCamp_CavaloPop(pop_pertenc, x, y);
		if(tipo == "cav")
			jogo->addCavaleiroPop(pop_pertenc, x, y);
		if(tipo == "gho")
			jogo->addFantasmaPop(pop_pertenc, x, y);
		return;
	}
	
	if(comando == "load")
	{
		vector <string> comandos;
		string file_name;

		iss >> file_name;
		comandos = recupera_fich(file_name);
		
		for (unsigned int i=0; i<comandos.size();i++){
			lerComando(comandos[i]);
		}
		return;
	}

	if(comando == "sete")
	{
		string tipo, pop_pertenc;
		int x, y;
		iss >> pop_pertenc >> tipo >> x >> y;
		if(tipo == "cas")
			jogo->addCasteloPop(pop_pertenc, x, y);
		if(tipo == "quar")
			jogo->addQuartelPop(pop_pertenc, x, y);
		if(tipo == "est")
			jogo->addEstabuloPop(pop_pertenc, x, y);
		if(tipo == "quin")
			jogo->addQuintaPop(pop_pertenc, x, y);
		return;
	}
	if(comando == "setf")
	{
		string tipo;
		int x, y;
		iss >> tipo >> x >> y;
		if(tipo == "min")
			jogo->addMina(x, y);
		if(tipo == "ped")
			jogo->addPedreira(x, y);
		if(tipo == "flo")
			jogo->addFloresta(x, y);
		return;
	}
	if(comando == "go")
	{
		string id;
		int x, y;
		iss >> id >> y >> x;
		jogo->alteraUnid1(id, x, y);
		return;
	}

	if(comando == "goto")
	{
		string id;
		int x, y;
		iss >> id >> y >> x;
		jogo->alteraUnid(id, x, y);
		return;
	}
	if(comando == "scroll"){
		while(1){
			char tecla = consola.getch();
			if (tecla == 'c') break;
			if ( (tecla != consola.ESQUERDA) && (tecla != consola.DIREITA) &&  (tecla != consola.CIMA)     && (tecla != consola.BAIXO) )
				continue;
			
			if (tecla == consola.ESQUERDA) sCol--;
			if (tecla == consola.DIREITA) sCol++;
			if (tecla == consola.CIMA) sLin--;
			if (tecla == consola.BAIXO) sLin++;
			system ("color f0");
			consola.clrscr();
			prepara_janela();
			imprimeTudo();
		}
		return;
	}
	if(comando == "mostra")
	{
		string populacao;
		iss >> populacao;
		cmd_mostra(populacao);
		return;
	}
	if(comando == "sel")
	{
		string id;
		iss >> id;
		seleciona(id);
		return;
	}
	if(comando == "deambula")
	{
		string id;
		iss >> id;
		deambula(id);
		return;
	}
	if(comando == "conserta")
	{
		string id, ide;
		iss >> id >> ide;
		if(id[0] == 'P')
			jogo->conserta(id, ide);
		return;
	}
	if(comando == "ataca")
	{
		string id, idvitima;
		iss >> id >> idvitima;
		if(idvitima[0] == 'G') break;
		if(idvitima[0] == 'S' || idvitima[0] == 'K' || idvitima[0] == 'P' || idvitima[0] == 'B')
			jogo->ataca(id, idvitima);
		else
			jogo->atacaEdi(id, idvitima);
		return;
	}
	if(comando == "mina")
	{
		string id, idfonte;
		iss >> id >> idfonte;
		jogo->mina(id, idfonte);
		return;
	}
	if(comando == "mku")
	{
		string oque;
		iss >> oque;
		jogo->makeUnid(oque);
		return;
	}
	if(comando == "mke"){
		string id, oque;
		int linha, coluna;
		iss >> id >> oque >> linha >> coluna;
		jogo->makeEdi(id, oque, linha, coluna);
		return;
	}
	if(comando == "ouro")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daOuro(nome, n);
		return;
	}
	if(comando == "pedra")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daPedra(nome, n);
		return;
	}
	if(comando == "madeira")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daMadeira(nome, n);
		return;
	}
	if(comando == "next")
		flg = 1;
	if(comando == "sair")
		exit(EXIT_SUCCESS);
	}while(flg == 0);
}
void Interface::lerComando(string comando)
{
	istringstream iss(comando);
	iss >> comando;
	if(comando == "pop")
	{
		string pop_pertenc;
		iss >> pop_pertenc;
		jogo->addPopulacao(pop_pertenc);
		return;
	}
	if(comando == "setu")
	{
		string tipo, pop_pertenc;
		int x, y;
		iss >> pop_pertenc >> tipo >> y >> x;
		if (tipo == "camp")
			jogo->addCamponesPop(pop_pertenc, x, y);
		if (tipo == "sold")
			jogo->addSoldadoPop(pop_pertenc, x, y);
		if (tipo == "cv")
			jogo->addCamp_CavaloPop(pop_pertenc, x, y);
		if(tipo == "cav")
			jogo->addCavaleiroPop(pop_pertenc, x, y);
		if(tipo == "gho")
			jogo->addFantasmaPop(pop_pertenc, x, y);
		return;
	}
	
	if(comando == "load")
	{
		vector <string> comandos;
		string file_name;

		iss >> file_name;
		comandos = recupera_fich(file_name);
		
		for (unsigned int i=0; i<comandos.size();i++){
			lerComando(comandos[i]);
		}
		return;
	}

	if(comando == "sete")
	{
		string tipo, pop_pertenc;
		int x, y;
		iss >> pop_pertenc >> tipo >> x >> y;
		if(tipo == "cas")
			jogo->addCasteloPop(pop_pertenc, x, y);
		if(tipo == "quar")
			jogo->addQuartelPop(pop_pertenc, x, y);
		if(tipo == "est")
			jogo->addEstabuloPop(pop_pertenc, x, y);
		if(tipo == "quin")
			jogo->addQuintaPop(pop_pertenc, x, y);
		return;
	}
	if(comando == "setf")
	{
		string tipo;
		int x, y;
		iss >> tipo >> x >> y;
		if(tipo == "min")
			jogo->addMina(x, y);
		if(tipo == "ped")
			jogo->addPedreira(x, y);
		if(tipo == "flo")
			jogo->addFloresta(x, y);
		return;
	}
	if(comando == "go")
	{
		string id;
		int x, y;
		iss >> id >> y >> x;
		jogo->alteraUnid1(id, x, y);
		return;
	}

	if(comando == "goto")
	{
		string id;
		int x, y;
		iss >> id >> y >> x;
		jogo->alteraUnid(id, x, y);
		return;
	}
	if(comando == "scroll"){
		while(1){
			char tecla = consola.getch();
			if (tecla == 'c') break;
			if ( (tecla != consola.ESQUERDA) && (tecla != consola.DIREITA) &&  (tecla != consola.CIMA)     && (tecla != consola.BAIXO) )
				continue;
			
			if (tecla == consola.ESQUERDA) sCol--;
			if (tecla == consola.DIREITA) sCol++;
			if (tecla == consola.CIMA) sLin--;
			if (tecla == consola.BAIXO) sLin++;
			system ("color f0");
			consola.clrscr();
			prepara_janela();
			imprimeTudo();
		}
		return;
	}
	if(comando == "mostra")
	{
		string populacao;
		iss >> populacao;
		cmd_mostra(populacao);
		return;
	}
	if(comando == "sel")
	{
		string id;
		iss >> id;
		seleciona(id);
		return;
	}
	if(comando == "deambula")
	{
		string id;
		iss >> id;
		deambula(id);
		return;
	}
	if(comando == "conserta")
	{
		string id, ide;
		iss >> id >> ide;
		if(id[0] == 'P')
			jogo->conserta(id, ide);
		return;
	}
	if(comando == "ataca")
	{
		string id, idvitima;
		iss >> id >> idvitima;
		if(idvitima[0] == 'G') return;
		if(idvitima[0] == 'S' || idvitima[0] == 'K' || idvitima[0] == 'P' || idvitima[0] == 'B')
			jogo->ataca(id, idvitima);
		else
			jogo->atacaEdi(id, idvitima);
		return;
	}
	if(comando == "mina")
	{
		string id, idfonte;
		iss >> id >> idfonte;
		jogo->mina(id, idfonte);
		return;
	}
	if(comando == "mku")
	{
		string oque;
		iss >> oque;
		jogo->makeUnid(oque);
		return;
	}
	if(comando == "mke"){
		string id, oque;
		int linha, coluna;
		iss >> id >> oque >> linha >> coluna;
		jogo->makeEdi(id, oque, linha, coluna);
		return;
	}
	if(comando == "ouro")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daOuro(nome, n);
		return;
	}
	if(comando == "pedra")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daPedra(nome, n);
		return;
	}
	if(comando == "madeira")
	{
		string nome;
		int n;
		iss >> nome >> n;
		jogo->daMadeira(nome, n);
		return;
	}
	if(comando == "next")
		return;
	if(comando == "sair")
		exit(EXIT_SUCCESS);
}

void Interface::mexeUnid(){
	jogo->mexeUnid();
}
// funçao usada no lercomando()
vector <string> recupera_fich(string nome_fich){
	vector <string> comandos;
	comandos.empty();
	ifstream fich(nome_fich);
	string linha;
	int i=0;
	comandos.empty();

	while (fich.peek() != EOF) {
		getline(fich, linha);
		//comandos[i]=(linha);
		comandos.push_back(linha);
		i++;
	}
	fich.close();
	return comandos;
}

void prepara_janela (){
	Consola c;
	c.setScreenSize(y_ecra,x_ecra);

	for (int j = 0;j<y_ecra;j++){
		for (int i = 0;i<x_ecra-1;i++)
		{
			if (i==x_ecra-17)
				cout << "#";
			else
				cout << " ";
		}
		cout << endl;
	}
	
	c.gotoxy(0,y_ecra-2);
	for (int i = 0;i<x_ecra-16;i++)
		cout << "#";
	c.setTextColor(c.VERMELHO);
		
	//preenche_lateral(c);

	c.gotoxy(0,y_ecra-1);
	cout << " >> ";
}
void preenche_lateral(Consola c){
	c.gotoxy(x_ecra-15,1);
	cout << "Populacao ";  // adicionar o campo da class com << o nome da pop
	c.gotoxy(x_ecra-15,2);
	cout << "Madeira: ";  // adicionar o campo da class com << ...
	c.gotoxy(x_ecra-15,3);
	cout << "Ferro: ";  //  adicionar o campo da class com << ...
	c.gotoxy(x_ecra-15,4);
	cout << "Ouro: ";  //  adicionar o campo da class com << ...
	c.gotoxy(x_ecra-15,5);
	cout << "N soldados: ";
}

void Interface::seleciona(string id){
	int aux = 2;
	for(unsigned int i=0; i<jogo->populacoes.size(); i++){
		vector <Unidade*> vp = jogo->populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(id == vp[j]->getNome())
			{
				sLin = vp[j]->getX() - (nL/2);
				sCol = vp[j]->getY() - (nC/2);
				system ("color f0");
				consola.clrscr();
				prepara_janela();
				imprimeTudo();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Nome: " << vp[j]->getNome();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Saude: " << vp[j]->getSaude();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Coordenadas:";
				consola.gotoxy(x_ecra-16, aux++);
				cout << "(" << vp[j]->getX() << "/" << vp[j]->getY() << ")";
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Coord_destino:";
				consola.gotoxy(x_ecra-16, aux++);
				cout << "(" << vp[j]->getX_des() << "/" << vp[j]->getY_des() << ")";
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Ataca: " << vp[j]->getAtaca();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Ataca Edi: " << vp[j]->getAtacaEdi();
				consola.getch();
				return;
			}
		}
		vector <Edificio*> vp1 = jogo->populacoes[i].pesquisaEdi();
		for(unsigned int j=0; j<vp1.size(); j++){
			if(id == vp1[j]->getNome())
			{
				sLin = vp1[j]->getX() - (nL/2);
				sCol = vp1[j]->getY() - (nC/2);
				system ("color f0");
				consola.clrscr();
				prepara_janela();
				imprimeTudo();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Nome: " << vp1[j]->getNome();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Estado: " << vp1[j]->getEstado_Conserv();
				consola.gotoxy(x_ecra-16, aux++);
				cout << "Coordenadas:";
				consola.gotoxy(x_ecra-16, aux++);
				cout << "(" << vp1[j]->getX() << "/" << vp1[j]->getY() << ")";
				consola.getch();
				return;
			}
		}
	}
}
void Interface::deambula(string id){
	for(unsigned int i=0; i<jogo->populacoes.size(); i++){
		vector <Unidade*> vp = jogo->populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(id == vp[j]->getNome())
			{
				srand((unsigned int)time(NULL));
				int x_ale = rand() % nC;
				int y_ale = rand() % nL;
				vp[j]->setX_des(x_ale);
				vp[j]->setY_des(y_ale);
				vp[j]->setDeambula(1);
				vp[j]->setAtaca(0); vp[j]->setConserta(0); vp[j]->setAtacaEdi(0); vp[j]->setMina(0);
				return;
			}
		}
	}
}
void Interface::deambula(){
	for(unsigned int i=0; i<jogo->populacoes.size(); i++){
		vector <Unidade*> vp = jogo->populacoes[i].pesquisaUnid();
		for(unsigned int j=0; j<vp.size(); j++){
			if(vp[j]->getDeambula())
			{
				deambula(vp[j]->getNome());
			}
		}
	}
}

