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
#include "Usuario.h"
#include <fstream>
const int TAM=242;
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
					Cadena[5]=v[i]->GetNumeroCuenta();
					Cadena[6]=to_string((int)v[i]->GetSaldo());
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


int main() {/*
	PruebaUsuario();
	PruebaCuentaBancaria();
		Tvector v;
	leerFichero(v);
	MostrarVector(v);
	MayorEdad(v,26);
	Inverso();
	BorrarVector(v);
	Pruebas();*/
	PruebaPatinete();

	return 0;
}
