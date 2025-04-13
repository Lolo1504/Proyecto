/*
 * Patinete.cpp
 *
 *  Created on: 24 feb 2025
 *      Author: Manuel
 */

 #include "Patinete.h"
 using namespace std;
 #include <string>
 #include <iostream>
 Patinete::Patinete() {
	 ID=" ";
	 Marca=" ";
	 Modelo=" ";
	 Averiado=false;
	 Disponible=true;
	 UsuarioActual=nullptr;
 }
 Patinete::Patinete(string ID,string Marca,string Modelo, bool Averiado, bool Disponible)
	 {
	 this->ID=ID;
	 this->Marca=Marca;
	 this->Modelo=Modelo;
	 this->Averiado=Averiado;
	 this->Disponible=Disponible;
	 this->UsuarioActual=nullptr;
	 }
 Patinete::Patinete(const Patinete &OtroPatinete)
	 {
		 this->ID=OtroPatinete.ID;
		 this->Marca=OtroPatinete.Marca;
		 this->Modelo=OtroPatinete.Modelo;
		 this->Averiado=OtroPatinete.Averiado;
		 this->Disponible=OtroPatinete.Disponible;
		 this->UsuarioActual=OtroPatinete.UsuarioActual;
	 }
	 //Metodos Gets
 string Patinete::GetID()const
	 {
	 return ID;
	 }
 string Patinete::GetMarca()
	 {
	 return Marca;
	 }
 string Patinete::GetModelo()
	 {
	 return Modelo;
	 }
 bool Patinete::GetAveriado()
	 {
	 return Averiado;
	 }
 bool Patinete::GetDisponible()
	 {
	 return Disponible;
	 }
 //Metodos Sets
 void  Patinete::SetID(string ID)
	 {
	 this->ID=ID;
	 }
 void Patinete::SetMarca(string Marca)
	 {
	 this->Marca=Marca;
	 }
 void Patinete::SetModelo(string Modelo)
	 {
	 this->Modelo=Modelo;
	 }
 void Patinete::SetAveriado(bool Averiado)
	 {
	 this->Averiado=Averiado;
	 }
 void Patinete::SetDisponible(bool Disponible)
	 {
	 this->Disponible=Disponible;
	 }
 void Patinete::Alquilar(Usuario* user )
	 {
		 this->UsuarioActual=user;
		 SetDisponible(false);
	 }
 void Patinete::Mostrar()
	 {
	 string Averiado=" No esta averiado";
	 if(GetAveriado())
		 Averiado="Esta averiado";
	 if(!GetDisponible())
	 {
		 cout<<"ID: "<<GetID()<<endl <<"Marca: "<<GetMarca()<<endl<<
				 "Modelo: "<<GetModelo()<<endl<<"Averiado:"<<Averiado<<endl<<
				 "Disponible: "<<"No esta Disponible"<<endl;
	 }
	 else
		 {
		 cout<<"ID:" <<GetID()<<endl <<"Marca:"<<GetMarca()<<endl<<"Modelo: " <<GetModelo()<<endl<< "Averiado: "<<Averiado<<endl<<"Disponible: "
						 <<"Esta Disponible"<<endl;
		 }
	 }
 bool Patinete::operator ==(const Patinete &OtroPatinete)
		 {
			 return GetID()==OtroPatinete.GetID();
		 }
 Patinete::~Patinete() {
 
 }
 
 
