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
	cout<<"INICIO PRUEBAS DE USUARIO"<<endl;
	//En esta priera prueba creamos un usuario con el constructor por defecto y usaremos los metodos de set y get para
	//comporbar su funcionamiento
	Usuario user1;
	string NombreCompleto ;

	user1.SetNombreCompleto("Juan Jose Galindo Cotano");
	user1.SetTelefono("+34 699 99 25 24");//Aclaracion, el numero de telefono es inventado, aun asi no se si pertenece a alguien o no
	user1.SetEdad(21);
	user1.SetDNI("7909028Z");
	user1.SetEmail("Galingod@gmail.com");
	user1.CrearCuentaB("Jgalcot123",0);
	if(user1.GetNombreCompleto() !="Juan Jose Galindo Cotano")
		{
		cerr<< "Error no esta galindo"<<endl;
		}
	user1.GetNombreCompleto(NombreCompleto);
	if( NombreCompleto!="Juan Jose Galindo Cotano")
		{
		cerr<< "Error no esta galindo"<<endl;
		}
	if(user1.GetDNI()!="7909028Z")
		cerr<<"Error en el dni "<<endl;
	if(user1.GetEdad()!=21)
		cerr<<"Error en la edad no devuelve el valor esperado"<<endl;
	if(user1.GetEmail()!="Galingod@gmail.com")
		cerr<<"Error en la consulta del gmail no devuelve el valor esperado "<<endl;
	if(user1.GetTelefono()!="+34 699 99 25 24")
		cerr<<"Error en la consulta del telefono"<<endl;
	if(user1.ConsultarSaldo()!=0)
		cerr<<"Error en la consulta del saldo"<<endl;
	if(user1.ConsultarNumeroCuenta()!="Jgalcot123")
		cerr<<"Error en la consulta del numero de cuenta"<<endl;


	user1.Mostrar();

	user1.IngresarSaldo(1000);
	if(user1.ConsultarSaldo()!=1000)
		{
		cerr<<"Error a la hora de insertar saldo"<<endl;
		}
	user1.RetirarSaldo(1000);
	if (user1.ConsultarSaldo()!=0)
		{
		cerr <<"Error a la hora de retirar saldo"<<endl;
		}

		cout <<user1.PasarACadena()<<endl;


		//Aqui probaremos el constrcutor parametrizado y lo mostraremos para asegurarnos que se a creado correcamente
		Usuario user2("Alberto Chamizo ","685 60 86 61", 21,"PrommiseFC",10000,"099809890F","Albertoch@gmail.com");
		user2.Mostrar();
		//Acontinuacion probaremos el constructor por copia y lo mostraremos deberia contener la misma informacion que el usuario 2
	   cout <<"Prueba del constructor por copia, la informacion del usuario 2 y el 3 deberia ser la misma"<<endl;
	   Usuario user3(user2);
	   user3.Mostrar();

	   cout<<"FIN PRUEBAS DE USUARIOS"<<endl;
	}
