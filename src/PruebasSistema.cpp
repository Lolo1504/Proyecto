/*
 * PruebasSistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */
#include "PruebasSistemas.h"
void Pruebas()
	{
	string NombreSistema;
	NombreSistema="Prueba";
	Sistema *S1;
	S1=new Sistema(NombreSistema);

	S1->mostrarUsuario();
	delete S1;

	}


