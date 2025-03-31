/*
 * PruebasGestorUsuario.cpp
 *
 *  Created on: 31 mar 2025
 *      Author: Manuel
 */
#include "GestorUsuario.h"


void PruebasGestor()
	{
	GestorUsuario *g=new GestorUsuario();

	g->Insertar("Manuel","12313232",12,"23231a",1000,"maricon","maricon");
	g->Insertar("Manuel","12313232",12,"23231a",1000,"amaricon","123");
	g->Insertar("Manuel","12313232",12,"23231a",1000,"bmaricon","123");
	g->Insertar("Manuel","12313232",12,"23231a",1000,"cmaricon","123");


	g->Mostrar();
	GestorUsuario *g1=new GestorUsuario(*g);
	cout << "Prueba constructor por copia Gestor Usuario"<<endl;
	g1->Mostrar();
	delete g1;
	delete g;
	}
