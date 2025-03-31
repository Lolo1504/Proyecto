/*
 * Sistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */

#include "Sistema.h"



Sistema::Sistema(string nombreSistema) {


this->nombreSistema=nombreSistema;
this->Usuario= new GestorUsuario;
/*this->lEstacion=new ListaDPI<Estacion*>;*/
this->lPatinete=new ListaDPI<Patinete*>;
cargarUsuarios();
}

/*Sistema::Sistema(const Sistema &other)
	{
	this->nombreSistema=other.nombreSistema;
		Usuario=new GestorUsuarios(*other.Usuario)
	}*/
void Sistema::cargarUsuarios()
	{
	ifstream fEnt;
		string linea,NombreCompleto,DNI,Correo,telefono,edad,numCuenta,saldo;

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

					Usuario->Insertar(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);

					}
				}
				fEnt.close();
			}
		else
			cout<< "No se pudo abrir el fichero"<<endl;
		}
void Sistema::mostrarUsuario()
	{
	Usuario->Mostrar();
	}
void Sistema::insertarPatinete(string id,string marca,string modelo,bool averiado,bool disponible)
	{
	Patinete *P;
	P=new Patinete(id,marca,modelo,averiado,disponible);
	lPatinete->enUltimo();
	lPatinete->insertar(P);

	}
void Sistema::cargarPatinetes()
	{
	ifstream fEnt;
		string linea,id,marca,modelo,averiado,disponible;
		bool Averiado,Disponible;
		fEnt.open("ficheros/patinetes.csv");
		if(fEnt.is_open())
			{
				getline(fEnt,linea);

				while(!fEnt.eof())
				{


					getline(fEnt,id,';');
					if(!fEnt.eof())
					{
					getline(fEnt,marca,';');
					getline(fEnt,modelo,';');
					getline(fEnt,averiado,';');
					getline(fEnt,disponible,';');
					Averiado=(averiado=="SI");
					Disponible=(disponible=="SI");

					insertarPatinete(id,marca,modelo,Averiado,Disponible);

					}
				}
				fEnt.close();
			}
		else
			cout<< "No se pudo abrir el fichero"<<endl;
		}
/*
void Sistema::cargarEstacion()
	{
	ifstream fEnt;
		string linea,NombreCompleto,DNI,Correo,telefono,edad,numCuenta,saldo;
		int cont =0;
		fEnt.open("ficheros/estaciones.csv");
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

					Usuario->Insertar(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);

					}
				}
				fEnt.close();
			}
		else
			cout<< "No se pudo abrir el fichero"<<endl;
		}*/
Sistema::~Sistema() {
	delete Usuario;
	Patinete *P=nullptr;
	lPatinete->moverPrimero();
	while(!lPatinete->estaVacia())
		{
		P=lPatinete->consultar();
		delete P;
		lPatinete->eliminar();
		}
	delete lPatinete;
}

