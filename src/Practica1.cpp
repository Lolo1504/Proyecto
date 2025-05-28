//============================================================================
// Name        : Practica1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "PruebaUsuario.h"
#include <cmath>
#include <string>
#include "PruebaCuentaBancaria.h"
#include "PruebaPatinete.h"
#include "PruebasSistemas.h"
#include "PruebasGestorUsuario.h"
#include "PruebaEstacion.h"
#include "Usuario.h"
#include <fstream>

int menu(string nombreSistema) {
	int opcion;
	do {
		cout << endl<<endl;
		cout << " -------- " << nombreSistema << " --------" << endl <<endl;
		cout << " 1. Mostrar todos los usuarios          " << endl;
		cout << " 2. Buscar y mostrar un usuario         " << endl;
		cout << " 3. Mostrar todos patinetes             " << endl;
		cout << " 4. Mostrar estaciones con sus patinetes" << endl;
		cout << " 5. Buscar y mostrar una estación       " << endl;
		cout << " 6. Reparar patinetes estación          " << endl;
		cout << " 7. Alquilar/devolver                   " << endl;
		cout << " 8. Estación con mayor nº de patines alquilados" << endl;
		cout << " 9. Buscar patinetes extraviados        " << endl;

		cout << " 0. Finalizar. " << endl;
		cout << " Opción: ";
		cout<<"_";
		cin>>opcion;
		cin.ignore();
		cout<<endl;

	} while ((opcion < 0) || (opcion > 10));
	return opcion;
}

int main() {
	/*
	// TODO Crear un objeto dinámico de la clase Sistema
	Sistema *s = new Sistema("Sistema de Patinetes");

	//los datos se cargan automáticamente.
	// TODO no olvidar hacer new
	bool salir = false;
	int opcion;
	string nombreSistema;
	string idPatinete, idEstacion, marca, modelo,DNI;
	Usuario *usu;

	while (!salir) {

		opcion = menu(nombreSistema);
		switch (opcion) {
		case 1:
			s->mostrarUsuarios();
			break;
		case 2:
			cout<< "Introduce el DNI del usuario: ";
			cin>>DNI;
			cin.ignore();
			s->buscarUsuario(DNI,usu);
			usu->Mostrar();
			break;
		case 3:
			s->mostrarPatinetes();
			break;
		case 4:
			s->mostrarEstaciones();
			break;
		case 5:
			cout << "Introduce el id de la estacion: ";
			cin >> idEstacion;
			s->mostrarEstacion(idEstacion);
			break;
		case 6:
			cout<<"Introduce el id de la estacion que desea que repare sus patinetes: ";
			cin>>idEstacion;
			s->repararPatinetesEstacion(idEstacion);
			break;
		case 7:
			s->alquilarDevolverPatinetes();
			break;
		case 8:
			s->maxAlquiladosEstacion();
			break;
		case 9:
			s->buscarPatinetesExtraviados();
			break;
		case 0:
			salir = true;
			break;
		default:
			break;
		}
	}


	delete s;
	*/
	PruebaUsuario();
	PruebaCuentaBancaria();
	pruebaEstacion();
	PruebaPatinete();
	PruebasGestor();
	//PruebasSistema();
	return 0;
}
