/*
 * PruebaEsacion.cpp
 *
 *  Created on: 13 abr 2025
 *      Author: Manuel
 */
#include "PruebaEstacion.h"


void pruebaEstacion()
	{

	Estacion *E=new Estacion("2","almendralejo");
	Patinete *P= new Patinete ("23","toyota","kaskai", false,true);
	Patinete *P1= new Patinete ("20","toyota","kaskai", false,true);
	Patinete *P2= new Patinete ("2","toyota","kaskai", false,true);
	Patinete *P3= new Patinete ("3","toyota","kaskai", true,false);

	E->Mostrar() ;
	E->agregarPatinete(P);
	E->agregarPatinete(P1);
	Estacion *E1=new Estacion(*E);
	E->agregarPatinete(P2);
	E->agregarPatinete(P3);
	/*if (E->BuscarPatinete("2")==true)
		E->MostrarDisponibles();

	else
		cout <<"Error al probar el motodo buscar patinete"<<endl;*/
	E->Mostrar() ;
	E1->Mostrar();
	E->MostrarAveriados();
	delete P;
	delete P1;
	delete P2;
	delete P3;
	delete E1;
	delete E;
	}
