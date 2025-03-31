/*
 * PruebaUsuario.cpp
 *
 *  Created on: 10 feb 2025
 *      Author: Manuel
 */

#include "PruebaUsuario.h"
#include <iostream>
#include <string>
using namespace std;


void PruebaUsuario()
	{
	Usuario user1;
	string NombreCompleto ;
	user1.SetNombreCompleto("Juan Jose Galindo Cotano");
	user1.SetTelefono("+34 699 99 25 24");
	user1.SetEdad(21);
	user1.CrearCuentaB("Jgalcot123",20);
	if(user1.GetNombreCompleto() !="Juan Jose Galindo Cotano")
		{
		cerr<< "Error no esta galindo"<<endl;
		}

	user1.GetNombreCompleto(NombreCompleto);
	if( NombreCompleto!="Juan Jose Galindo Cotano")
		{
		cerr<< "Error no esta galindo"<<endl;
		}


	user1.Mostrar();

	user1.IngresarSaldo(1000);

	cout <<user1.PasarACadena()<<endl;
	   Usuario user2("Alberto Chamizo ","685 60 86 61", 21,"PrommiseFC",10000,"099809890F","Albertoch@gmail.com");


	}
