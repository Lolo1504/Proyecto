/*
 * PruebaPatinete.cpp
 *
 *  Created on: 26 feb 2025
 *      Author: Manuel
 */

#include "PruebaPatinete.h"



void PruebaPatinete()
	{
	cout<<"INICIO PRUEBAS PATINETES"<<endl;
		Patinete *P1;
		P1=new Patinete;
		// Nos creamos un usuario para probar despues el metodo de alquilar
		Usuario *user1 ;
		user1=new Usuario;
			string NombreCompleto ;
			user1->SetNombreCompleto("Manuel Lagar Frutos");
			user1->SetTelefono("+34 699 99 25 24");
			user1->SetEdad(21);
			user1->SetDNI("98419870F");
		// A continuacion probamos los metodos sets de patinete
		P1->SetID("XLR8");
		if(P1->GetID()!="XLR8")
			{
			cout<<"Errors en el metodo get o set del ID"<<endl;
			}
		P1->SetAveriado(false);
		if(P1->GetAveriado())
			{
			cout <<"Error en el metodo get o set de averiado"<<endl;
			}

		P1->SetModelo("FaFurius");
		if(P1->GetModelo()!="FaFurius")
			{
			cout<<"Error en el metodo get o set de Modelo"<<endl;
			}
		P1->SetMarca("Toyota");
		if(P1->GetMarca()!="Toyota")
			{
			cout<<"Erros en el metodo get o set de la marca"<<endl;
			}
		P1->SetDisponible(true);
		if(!P1->GetDisponible())
			{
			cout <<"Error en el metodo get o set de disponible"<<endl;
			}

		//Probamos el metodo alquilar a un usuario
		P1->Alquilar(user1);

		cout<< user1->GetNombreCompleto()<<endl;

		// Probamos el metodo motrar un patinete y comprobamos que tiene un usuario alquilado
		P1->Mostrar();


		// Probamos el constructor por copia , haciendo una copia de P1
		Patinete *P2=new Patinete(*P1);

		if(!P2->operator ==(*P1))
			{
			cout<< "Error a la hora de hacer uso del constructor por copia o de la operacion == "<<endl;
			}
		//Desalquilamos el patinete y lo mostramos para comprobar si se encuentra disponible
		P2->Desalquilar();
		P2->Mostrar();
		delete P1;
		delete P2;
		delete user1;
		cout <<"FIN PRUEBAS PATINETES"<<endl;
	}

