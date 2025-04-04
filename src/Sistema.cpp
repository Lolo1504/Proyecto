/*
 * Sistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */

 #include "Sistema.h"



 Sistema::Sistema(string nombreSistema) {
 this->nombreSistema=nombreSistema;
 this->lUsuarios= new GestorUsuario;
 this->lEstacion=new ListaDPI<Estacion*>;
 this->lPatinete=new ListaDPI<Patinete*>;
 cargarUsuarios();
 }
 
 Sistema::Sistema() {
	 this->nombreSistema="";
	 this->lUsuarios= new GestorUsuario;
	 cargarUsuarios();
	 this->lPatinete=new ListaDPI<Patinete*>;
	 this->lEstacion=new ListaDPI<Estacion*>;
 }
 
 Sistema::Sistema(const Sistema &other)
	 {
	 this->nombreSistema=other.nombreSistema;

	 this->lUsuarios=new GestorUsuario(*other.lUsuarios);
	 if(other.lPatinete!=nullptr)
		 {
		 this->lPatinete=new ListaDPI<Patinete*>;
		 other.lPatinete->moverPrimero();
		 while(!other.lPatinete->alFinal())
			 {
			 Patinete *P=other.lPatinete->consultar();
			 this->lPatinete->insertar(new Patinete(*P));
			 other.lPatinete->avanzar();
			 }
		 }
	 else
		 {
		 this->lPatinete=nullptr;
		 }
	 if(other.lEstacion!=nullptr)
		 {
		 this->lEstacion=new ListaDPI<Estacion*>;
		 other.lEstacion->moverPrimero();
		 while(!other.lEstacion->alFinal())
			 {
			 Estacion *E=other.lEstacion->consultar();
			 this->lEstacion->insertar(new Estacion(*E));
			 other.lEstacion->avanzar();
			 }
		 }
 
	 else
		 {
		 this->lEstacion=nullptr;
		 }
	 }
 
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
 
					 lUsuarios->Insertar(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);
 
					 }
				 }
				 fEnt.close();
			 }
		 else
			 cout<< "No se pudo abrir el fichero"<<endl;
		 }
 
 
 void Sistema::insertarPatinete(string id,string marca,string modelo,bool averiado,bool disponible)
	 {
	 Patinete *P;
	 P=new Patinete(id,marca,modelo,averiado,disponible);
	 lPatinete->enUltimo();
	 lPatinete->insertar(P);
	 }
 
 
 void Sistema::instertarEstacion(string id, string nombre)
	 {
	 Estacion *E;
	 E=new Estacion(id,nombre);
	 lEstacion->enUltimo();
	 lEstacion->insertar(E);
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
 
 void Sistema::cargarEstacion()
	 {
	 ifstream fEnt;
		 string linea,NombreCompleto,DNI,Correo,telefono,edad,numCuenta,saldo;

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
 
					 lUsuarios->Insertar(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);
					 cout<< "----------------------------------"<<endl;
					 cout<< "Usuario: "<<NombreCompleto<<endl;
					 cout<< "DNI: "<<DNI<<endl;
					 cout<< "Correo: "<<Correo<<endl;
					 cout<< "Telefono: "<<telefono<<endl;
					 cout<< "Edad: "<<edad<<endl;
					 cout<< "Numero de cuenta: "<<numCuenta<<endl;
					 cout<< "Saldo: "<<saldo<<endl;
					 cout<< "----------------------------------"<<endl;
					 }
				 }
				 fEnt.close();
			 }
		 else
			 cout<< "No se pudo abrir el fichero"<<endl;
		 }
 
 
 
 void Sistema::buscarUsuario(string DNI)
	 {
	 }
 
 void Sistema::mostrarUsuarios(){
	 this->lUsuarios->Mostrar();
 }
 
 void Sistema::mostrarPatinetes(){
	 Patinete *P=nullptr;
	 lPatinete->moverPrimero();
	 while(!lPatinete->alFinal())
		 {
		 P=lPatinete->consultar();
		 P->Mostrar();
		 lPatinete->avanzar();
		 }
 }
 
 void Sistema::mostrarEstaciones(){
	 Estacion *E=nullptr;
	 lEstacion->moverPrimero();
	 while(!lEstacion->alFinal())
		 {
		 E=lEstacion->consultar();
		 E->Mostrar();
		 lEstacion->avanzar();
		 }
 }
 
 Sistema::~Sistema() {
	 delete lUsuarios;
	 Patinete *P = nullptr;
	 if (lPatinete!=nullptr)
		 {
		 lPatinete->moverPrimero();
		 while(!lPatinete->estaVacia())
			 {
			 P = lPatinete->consultar();
			 delete P;
			 lPatinete->eliminar();
			 }
		 }
	 delete lPatinete;
	 Estacion *E = nullptr;
	 if (lEstacion!=nullptr)
		 {
		 lEstacion->moverPrimero();
		 while(!lEstacion->estaVacia())
			 {
			 E = lEstacion->consultar();
			 delete E;
			 lEstacion->eliminar();
			 }
		 }
	 delete lEstacion;
 }
 
 
