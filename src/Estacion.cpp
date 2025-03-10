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

Estacion::~Estacion() {
	delete PatineteAveriado;
	delete PatineteDisponible;
}

