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
#include "Usuario.h"
#include <fstream>
const int TAM=242;
//
typedef Usuario* Tvector [TAM];
void leerFichero(Tvector &v)
	{
	ifstream fEnt;
	string linea,NombreCompleto,DNI,Correo,telefono,edad,numCuenta,saldo;
	int cont =0;
	fEnt.open("ficheros/usuarios.csv");
	if(fEnt.is_open())
		{
			getline(fEnt,linea);

			while(!fEnt.eof())
			{


				getline(fEnt,NombreCompleto,';');
				if(!fEnt.eof())
				{
				getline(fEnt,DNI,';');
				getline(fEnt,Correo,';');
				getline(fEnt,telefono,';');
				getline(fEnt,edad,';');
				getline(fEnt,numCuenta,';');
				getline(fEnt,saldo);

				Usuario *u=new Usuario(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);
				v[cont]=u;
				cont++;
				}
			}
			fEnt.close();
		}
	else
		cout<< "No se pudo abrir el fichero"<<endl;
	}
void MostrarVector(Tvector v)
	{
	for(int i=0; i<TAM;i++)
		{
		v[i]->Mostrar();
		}
	}
void MayorEdad(Tvector v,int edad)
	{
		ofstream f;
		f.open("ficheros/MayorEdad.csv",ios::trunc);
		string Cadena[7];
		if(f.is_open())
		{
		for(int i=0;i<TAM;i++)
			{
				if(v[i]->GetEdad()>edad)
					{
					Cadena[0]=v[i]->GetNombreCompleto();
					Cadena[1]=v[i]->GetDNI();
					Cadena[2]=v[i]->GetEmail();
					Cadena[3]=v[i]->GetTelefono();
					Cadena[4]=to_string(v[i]->GetEdad());
					Cadena[5]=v[i]->ConsultarNumeroCuenta();
					Cadena[6]=to_string((int)v[i]->ConsultarSaldo());
					f<<Cadena[0]<<';'<< Cadena[1]<<';'<< Cadena[2]<<';'<< Cadena[3]<<';'<< Cadena[4]<<';'<< Cadena[5]<<';'<< Cadena[6]<<'\n';
					}

			}
		cout<<"Fichero escrito"<<endl;
		f.close();
		}
		else
			cout << "Error al abrir el fichero"<<endl;
	}
void mostrarInverso(ifstream &fInv)
	{
	string linea;
	getline(fInv,linea);
	if(!fInv.eof())
		{
		mostrarInverso(fInv);
		cout<<linea<<endl;
		}

	}
void Inverso()
	{
		ifstream fInv;
		fInv.open("ficheros/MayorEdad.csv");
		if(fInv.is_open())
			{
			mostrarInverso(fInv);
			fInv.close();
			}
		else
			cout <<"Error al abrir el fichero"<<endl;
	}
void BorrarVector(Tvector &v)
	{
	for(int i=0;i<TAM;i++)
		{
			delete v[i];
		}
	cout << "Borrado Correctamente"<<endl;
	}


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
	// TODO Crear un objeto dinámico de la clase Sistema
	Sistema *s = new Sistema("Sistema de Patinetes");
	//los datos se cargan automáticamente.
	// TODO no olvidar hacer new
	bool salir = false;
	int opcion;
	string nombreSistema;
	string idPatinete, idEstacion, marca, modelo;

	while (!salir) {

		opcion = menu(nombreSistema);
		switch (opcion) {
		case 1:
			s->mostrarUsuarios();
			break;
		case 2:
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

			break;
		case 7:

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

	// TODO no olvidar el delete al puntero
	delete s;
	return 0;
}
