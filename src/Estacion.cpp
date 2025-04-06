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
		 this->PatineteDisponible=new Cola<Patinete*>;
		 this->PatineteAveriado = new Cola<Patinete*>;
 }
 
 Estacion::Estacion(string Id, string direccion)
	 {
		 this->identificador=Id;
		 this->direccion=direccion;
		 this->NumDisponibles=0;
		 this->NumAveriados=0;
		 this->PatineteDisponible=new Cola<Patinete*>;
		 this->PatineteAveriado = new Cola<Patinete*>;
	 }
 Estacion::Estacion(const Estacion &OtraEstacion)
	 {
		 this ->identificador=OtraEstacion.identificador;
		 this->direccion=OtraEstacion.direccion;
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
 void Estacion::agregarPatinete(Patinete *p)
	 {
	 if(p->GetAveriado())
		 {
		 PatineteAveriado->encolar(p);
		 this->NumAveriados++;
		 }
	 else
		 PatineteDisponible->encolar(p);
	 this->NumDisponibles++;
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
	 //Hacer: Usar el metodo Get numPatinetesAveriados para mostrar el numero de patinetes
	 //cout << "Hay "<< <<endl;
	 delete Aux;
	 }
 
 void Estacion::Mostrar()
	 {
	 cout << "La estacion con id: "<<this->identificador;
	 cout << " Direccion: "<<this->direccion;
	 cout << " Numero de patinetes disponibles: "<<this->NumDisponibles;
	 cout << " Numero de patinetes averiados: "<<this->NumAveriados<<endl;
	 }
 
 string Estacion::ConsultarId()
	 {
	 return this->identificador;
	 }

bool Estacion::ConsultarDisponible() {
	 return this->NumDisponibles>0;
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
	 //Hacer: Usar el metodo Get numPatinetesAveriados para mostrar el numero de patinetes
	 //cout << "Hay "<< <<endl;ss
	 delete Aux;
}

Patinete Estacion::alquilarPatinete() {
	if (ConsultarDisponible()) {
		Patinete *p = PatineteDisponible->getPrimero();
		PatineteDisponible->desencolar();
		this->NumDisponibles--;
		return *p;
	} else {
		cout << "No hay patinetes disponibles en la estacion." << endl;
		return Patinete(); // Retorna un patinete vacío o nulo
	}
}

 Estacion::~Estacion() {
	 delete PatineteAveriado;
	 delete PatineteDisponible;
 }
 
 
