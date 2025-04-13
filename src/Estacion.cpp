/*
 * Estacion.cpp
 *
 *  Created on: 10 mar 2025
 *      Author: Manuel
 */

 #include "Estacion.h"

 Estacion::Estacion() {
		 this->identificador ="";
		 this->direccion="";
		 this->NumDisponibles=0;
		 this ->NumAveriados=0;
		 this->nAlquilados=0;
		 this->PatineteDisponible=new Cola<Patinete*>;
		 this->PatineteAveriado = new Cola<Patinete*>;
 }
 
 Estacion::Estacion(string Id, string direccion)
	 {
		 this->identificador=Id;
		 this->direccion=direccion;
		 this->NumDisponibles=0;
		 this->NumAveriados=0;
		 this->nAlquilados=0;
		 this->PatineteDisponible=new Cola<Patinete*>;
		 this->PatineteAveriado = new Cola<Patinete*>;
	 }
 Estacion::Estacion(const Estacion &OtraEstacion)
	 {
		 this ->identificador=OtraEstacion.identificador;
		 this->direccion=OtraEstacion.direccion;
		 this->nAlquilados=OtraEstacion.nAlquilados;
		 this ->NumDisponibles=OtraEstacion.NumDisponibles;
		 this->NumAveriados=OtraEstacion.NumAveriados;
		 this->PatineteDisponible= new Cola<Patinete*>;
		 Cola <Patinete *> *Aux= new Cola<Patinete *>;
		 Patinete *p=nullptr;
		 while(!OtraEstacion.PatineteDisponible->estaVacia())
			 {
			 p=OtraEstacion.PatineteDisponible->getPrimero();
			 PatineteDisponible->encolar(p);
			 Aux->encolar(p);
			 OtraEstacion.PatineteDisponible->desencolar();
			 }
		 while(!Aux->estaVacia())
			 {
			 OtraEstacion.PatineteDisponible->encolar(Aux->getPrimero());
			 Aux->desencolar();
 
			 }
 
		 this->PatineteAveriado=	new Cola<Patinete *>;
 
 
		 while(!OtraEstacion.PatineteAveriado->estaVacia())
			 {
			 p=OtraEstacion.PatineteAveriado->getPrimero();
			 PatineteAveriado->encolar(p);
			 Aux->encolar(p);
			 OtraEstacion.PatineteAveriado->desencolar();
			 }
		 while(!Aux->estaVacia())
			 {
			 OtraEstacion.PatineteAveriado->encolar(Aux->getPrimero());
			 Aux->desencolar();
 
			 }
		 delete Aux;
 
	 }
 void Estacion::setId(string Id)
 	 {
	 identificador=Id;
 	 }
 void Estacion::setDireccion(string Direccion)
 	 	 {
 		 direccion=Direccion;
 	 	 }
 int Estacion::getNumeroAlquilados()
	 { return this->nAlquilados; }

 int Estacion::getNumeroDisponibles()
	 { return this->NumDisponibles; }

 int Estacion::getNumeroAveriados()
	 { return this->NumAveriados; }
 string Estacion::getId()
	 {
	 return this->identificador;
	 }
 string Estacion::getDireccion()
 	 {
	 return this->direccion;
 	 }

bool Estacion::ConsultarDisponible() {
	 return this->NumDisponibles>0;
 }

 bool Estacion::BuscarPatinete(string idPatinete) {
	 bool encontrado = false;
	 Cola<Patinete*> *Aux = new Cola<Patinete*>;
	 Patinete *p;
	 while (!PatineteDisponible->estaVacia()) {
		 p = PatineteDisponible->getPrimero();
		 Aux->encolar(p);
		 if (p->GetID() == idPatinete) {
			 encontrado = true;
		 }
		 PatineteDisponible->desencolar();
	 }
	 while (!Aux->estaVacia()) {
		 PatineteDisponible->encolar(Aux->getPrimero());
		 Aux->desencolar();
	 }
	 if (!encontrado) {
		 while (!PatineteAveriado->estaVacia()) {
			 p = PatineteAveriado->getPrimero();
			 Aux->encolar(p);
			 if (p->GetID() == idPatinete) {
				 encontrado = true;
			 }
			 PatineteAveriado->desencolar();
		 }
		 while (!Aux->estaVacia()) {
			 PatineteAveriado->encolar(Aux->getPrimero());
			 Aux->desencolar();
		 }
	 }
	 delete Aux;
	 return encontrado;
 }


 void Estacion::agregarPatinete(Patinete *p)
	 {
	 if(p->GetAveriado())
		 {

		 PatineteAveriado->encolar(p);

		 this->NumAveriados++;
		 }
	 else
	 {

		 PatineteDisponible->encolar(p);
		 this->NumDisponibles++;
	 }

	 }
 void Estacion::MostrarAveriados()
	 {
	 Cola<Patinete*> *Aux=new Cola<Patinete*>;
	 Patinete *p;
	 while(!PatineteAveriado->estaVacia()){
		 p=PatineteAveriado->getPrimero();
 
		 Aux->encolar(p);
		 PatineteAveriado->desencolar();
		 p->Mostrar();
	 }
	 while(!Aux->estaVacia())
		 {
		 PatineteAveriado->encolar(Aux->getPrimero());
		 Aux->desencolar();
		 }

	 cout << "Hay "<< getNumeroAveriados()<< " patinetes averiados" <<endl;
	 delete Aux;
	 }
 
 void Estacion::Mostrar()
	 {
	 cout << "La estacion con id: "<<this->identificador;
	 cout << " Direccion: "<<this->direccion;
	 cout << " Numero de patinetes disponibles: "<<this->NumDisponibles;
	 cout << " Numero de patinetes averiados: "<<this->NumAveriados<<endl;

	 }
 


void Estacion::MostrarDisponibles() {
	 Cola<Patinete*> *Aux=new Cola<Patinete*>;
	 Patinete *p;
	 while(!PatineteDisponible->estaVacia()){
		 p=PatineteDisponible->getPrimero();

		 Aux->encolar(p);
		 PatineteDisponible->desencolar();
		 p->Mostrar();
	 }
	 while(!Aux->estaVacia())
		 {
		 PatineteDisponible->encolar(Aux->getPrimero());
		 Aux->desencolar();
		 }

	 cout << "Hay "<<getNumeroDisponibles()<<" patinetes disponibles" <<endl;
	 delete Aux;
}

Patinete Estacion::alquilarPatinete() {
	if (ConsultarDisponible()) {
		Patinete *p = PatineteDisponible->getPrimero();
		PatineteDisponible->desencolar();
		p->SetDisponible(false);
		this->NumDisponibles--;
		return *p;
	} else {
		cout << "No hay patinetes disponibles en la estacion." << endl;
		return Patinete(); // Retorna un patinete vacío o nulo
	}
}


void Estacion::RepararPatinetes() {
	Cola<Patinete*> *Aux=new Cola<Patinete*>;
	Patinete *p;
	while(!PatineteAveriado->estaVacia()){
		p=PatineteAveriado->getPrimero();
		Aux->encolar(p);
		PatineteAveriado->desencolar();
		p->SetAveriado(false);
		p->SetDisponible(true);
		this->NumDisponibles++;
		this->NumAveriados--;
	}
	while(!Aux->estaVacia())
		 {
		 PatineteDisponible->encolar(Aux->getPrimero());
		 Aux->desencolar();
		 }
	delete Aux;
}

 Estacion::~Estacion() {
	 delete PatineteAveriado;
	 delete PatineteDisponible;
 }
 
 
