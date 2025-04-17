/*
 * PruebasSistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */
#include "PruebasSistemas.h"
void PruebasSistema()
	{
	//Prueba de la clase Sistema
	//Prueba 1: Sistema por defecto
	Sistema *s=new Sistema();
	s->mostrarUsuarios();
	Usuario *u=nullptr;
	s->buscarUsuario("36519149R",u);
	u->Mostrar();
	s->mostrarPatinetes();
	s->mostrarEstaciones();
	s->alquilarDevolverPatinetes();

	//cout << "Prueba constructor por copia"<<endl;
	//Sistema *s1= new Sistema(*s);
	//s1->mostrarUsuarios();
	delete s;
	//delete s1;
	}


