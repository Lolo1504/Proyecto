/*
 * PruebasSistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */
#include "PruebasSistemas.h"
void PruebasSistema()
	{
	cout<<"INICIO PRUEBAS SISTEMA"<<endl;
	//Prueba de la clase Sistema
	//Prueba 1: Sistema por defecto
	//IMPORTANTE: Este realizada la ampliacion que modifica el fichero usuario.csv, cada que se quiera ejecutar las pruebas habra que
	// volver a implementar el fichero usuario.cvs original , ya que al modificar ciertos datos no sale la salida esperada
	Sistema *s=new Sistema();
	Usuario *u=nullptr;
	Estacion *e=nullptr;
	Patinete *p=nullptr;
	//Lo primero es mostrar todos los patinetes usuario y estaciones que hemos cargado en el sistema
	s->mostrarUsuarios();
	s->mostrarEstaciones();
	s->mostrarPatinetes();
	s->insertarEstacion("09","Solana");
	s->insertarPatinete("2323","toyota","x45",false,true);

	if(s->buscarUsuario("36519149R",u))
	{
	cout<<"Mostramos el usuario encontrado "<<endl;
	u->Mostrar();
	}
	else
		cout<<"Error al buscar el usuario"<<endl;

	if(s->buscarEstacion("09",e))
		{
		cout <<"Mostramos la Estacion que hemos buscado"<<endl;
		e->Mostrar();
		}
	else
		cout<<"Error en el metodo de buscar estacion"<<endl;

	if(s->buscarPatinete("2323",p))
		{
		cout<<"Mostramos el patinete que hemos buscado"<<endl;
		p->Mostrar();
		}
	else
		cout<<"Error en el metodo buscar Patinete"<<endl;

	s->agregarPatineteEnEstacion("2323","09");

	s->alquilarDevolverPatinetes();
	cout<<"Vamos a probar el metodo de reparar patinetes es una estacion"<<endl;
	s->repararPatinetesEstacion("3014");
	cout<<"Vamos a probar el metodo Patinetes extraviados"<<endl;

	s->buscarPatinetesExtraviados();
	cout<<"Vamos a probar el metodo de la estacion que mas patinetes a alquilado"<<endl;
	s->maxAlquiladosEstacion();
	cout << "Prueba constructor por copia"<<endl;
	Sistema *s1= new Sistema(*s);
	//Al mostrar los usuario deberia mostrar los mismos
	//s1->mostrarUsuarios();
	delete s;
	delete s1;
	cout<<"FIN DE LAS PRUEBAS DEL SISTEMA"<<endl;
	}


