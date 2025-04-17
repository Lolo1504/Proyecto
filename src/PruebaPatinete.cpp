/*
 * PruebaPatinete.cpp
 *
 *  Created on: 26 feb 2025
 *      Author: Manuel
 */

#include "PruebaPatinete.h"



void PruebaPatinete()
	{
		Patinete *P1;
		P1=new Patinete;
		Usuario *user1 ;
		user1=new Usuario;
			string NombreCompleto ;
			user1->SetNombreCompleto("Manuel Lagar Frutos");
			user1->SetTelefono("+34 699 99 25 24");
			user1->SetEdad(21);
			user1->SetDNI("98419870F");

		P1->SetID("XLR8");
		P1->SetAveriado(false);
		P1->SetModelo("FaFurius");
		P1->SetMarca("Toyota");
		P1->SetDisponible(true);
		P1->Alquilar(user1);
		cout<< user1->GetNombreCompleto()<<endl;
		P1->Mostrar();
		Patinete *P2;
		P2=new Patinete(*P1);
		P2->Desalquilar();
		P2->Mostrar();
		delete P1;
		delete P2;
		delete user1;
	}

