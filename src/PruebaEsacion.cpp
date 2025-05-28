/*
 * PruebaEsacion.cpp
 *
 *  Created on: 13 abr 2025
 *      Author: Manuel
 */
#include "PruebaEstacion.h"


void pruebaEstacion()
	{
	cout<<"INICIO PRUEBAS DE ESTACION"<<endl;
	Estacion *E=new Estacion();
	Patinete *P= new Patinete ("23","toyota","kaskai", false,true);
	Patinete *P1= new Patinete ("20","toyota","kaskai", false,true);
	Patinete *P2= new Patinete ("2","toyota","kaskai", false,true);
	Patinete *P3= new Patinete ("3","toyota","kaskai", true,false);

	E->setId("2");
	if(E->getId()!="2")
		{
		cout<< "Error en el metodo get o set del ID de la Estacion"<<endl;
		}
	E->setDireccion("Almendralejo");
	if(E->getDireccion()!="Almendralejo")
		{
		cout <<"Error en el metodo get o set de la direccion del Estacion"<<endl;
		}
	E->setNumeroAlquilados();
	if(E->getNumeroAlquilados()!=1)
		{
		cout<<"Error en el metodo get o set del numero de alquilados"<<endl;
		}

	//Probamos el metodo de mostrar de la estacion
	E->Mostrar() ;
	//Probamos a agregar patinetes 3 disponibles y 1 averiado
	E->agregarPatinete(P);
	E->agregarPatinete(P1);
	E->agregarPatinete(P2);
	E->agregarPatinete(P3);
	if(E->getNumeroAveriados()!=1)
		{
		cout<<"Error en el metodo get numero averiados deberia devolver 1"<<endl;
		}
	if(E->getNumeroDisponibles()!=3)
		{
		cout<<"Error en el metodo get numero disponibles deberia de devolver 3"<<endl;
		}
	cout<<"Vamos a probar a mostrar la informacion de los patinetes, primero de los disponibles y despues de los averiados"<<endl;

	cout<<"Patinetes Disponibles:"<<endl;
	E->MostrarDisponibles();
	cout<<"Patinetes Averiados: "<<endl;
	E->MostrarAveriados();
	//Probamos el constructor por copia de la estacion
	Estacion *E1=new Estacion(*E);

	//Provamos el metodo buscar patinete que necesita que le pasemos un id
	if (!E->BuscarPatinete("2"))
		{
		cout <<"Error al probar el motodo buscar patinete"<<endl;
		}
	if(!E->ConsultarDisponible())
		{
		cout<<"Error en  el metodo de consultar disponibles"<<endl;
		}
	if(E->RepararPatinetes()!=1)
		{
		cout<<"Erros en el metodo reparar patinetes deberia devolver 1 que es el numero de patinetes que se reparan"<<endl;
		}
	//Vamos a crear un usuario para las siguiente 2 pruabas
	Usuario *u=new Usuario("Juan Jose Galindo Cotano","+34 699 99 25 24",21,"1",100,"7909028Z","Galingod@gmail.com");
	Patinete *PP=nullptr;
	E->alquilarPatinete(u,PP);
	//Para probar que funciona mostraremos a donde apunta el patinete PP y si se encuentra no disponible y tiene el usuario creado es que funciona correctamente
	PP->Mostrar();
	E->Devolver(PP);
	cout<<"Despues de usar el metodo devolver se deberia de mostrar el mismo patinete pero no deberia tener ningun usuario asignado"<<endl;
	PP->Mostrar();
	delete P;
	delete P1;
	delete u;
	delete P2;
	delete P3;
	delete E1;
	delete E;
	cout <<"FIN PRUEBAS DE ESTACION"<<endl;
	}
