/*
 * Usuario.cpp
 *
 *  Created on: 10 feb 2025
 *      Author: Manuel
 */

#include "Usuario.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

//Constructor por defecto
Usuario::Usuario() {
	NombreCompleto= " ";
	Telefono= " ";
	Edad = 0;
	CuentaB = nullptr;
	DNI=" ";
	Email="";
}
//Constructor parametrizado
Usuario::Usuario(string NombreCompleto,string Telefono, int Edad, string NumeroCuenta,float Saldo,string DNI,string Email)
	{
	this->NombreCompleto=NombreCompleto;
	this->Telefono=Telefono;
	this->Edad=Edad;
	CuentaB=new CuentaBancaria(NumeroCuenta,Saldo);
	this->DNI =DNI;
	this-> Email=Email;
	}
Usuario::Usuario(const Usuario &OtroUsuario)
	{
	this->NombreCompleto=OtroUsuario.NombreCompleto;
	this->Telefono=OtroUsuario.Telefono;
	this->Edad=OtroUsuario.Edad;
	CuentaB= new CuentaBancaria(*OtroUsuario.CuentaB);
	this->DNI= OtroUsuario.DNI;
	this->Email=OtroUsuario.Email;
	}

//Gets
string Usuario::GetNombreCompleto() const
	{
	return NombreCompleto;
	}
void Usuario::GetNombreCompleto(string &NombreCompleto) const
	{
		NombreCompleto=this->NombreCompleto;
	}
string Usuario::GetTelefono() const
	{
	return Telefono;
	}
int Usuario::GetEdad() const
	{
	return Edad;
	}

float Usuario::ConsultarSaldo()const
	{
	return CuentaB->GetSaldo();
	}
string Usuario::ConsultarNumeroCuenta()const
	{
	return CuentaB->GetNumeroCuenta();
	}
string Usuario::GetDNI()
	{
	return DNI;
	}
string Usuario::GetEmail()
	{
	return Email;
	}
//Sets
void Usuario::SetNombreCompleto(string NombreCompleto)
{
	this->NombreCompleto=NombreCompleto;
}
void Usuario::SetTelefono(string Telefono)
	{
	this->Telefono=Telefono;
	}
void Usuario::SetEdad(int Edad)
	{
		this->Edad=Edad;
	}
void Usuario::CrearCuentaB(string NumeroCuenta,float Saldo)
	{
	if(CuentaB==nullptr)
		CuentaB=new CuentaBancaria(NumeroCuenta,Saldo);
	}
void Usuario::IngresarSaldo(float Saldo)
	{
	CuentaB->IngresarSaldo(Saldo);
	}
void Usuario::RetirarSaldo (float Saldo)
	{
	CuentaB->RetirarSaldo(Saldo);
	}
void Usuario::SetDNI(string DNI)
	{
	this->DNI=DNI;
	}
void Usuario::SetEmail(string Email)
	{
	this->Email=Email;
	}

//Mostrar
void Usuario::Mostrar()
	{
	cout <<"Nombre de la criatura: "<< GetNombreCompleto() <<endl<< "Telefono: " << GetTelefono() <<endl << "Edad del bicho: "<<GetEdad()  <<endl << "DNI: "<<GetDNI()<<endl<< "Email: " << GetEmail()<<endl;
	CuentaB->Mostrar();
	}

//Cadena

string Usuario::PasarACadena()
	{
	string cadena, cadena2;
	cadena = to_string(GetEdad());
	cadena2= to_string(ConsultarSaldo());
	return  "Nombre: " + GetNombreCompleto() +" Telefono: " + GetTelefono() +" Edad: "+cadena + " DNI: " + GetDNI()+ " Email: " + GetEmail()+ " Numero de cuenta: " + ConsultarNumeroCuenta()+ " Saldo: "+ cadena2 ;
	}

//Desctrcutor
Usuario::~Usuario() {
	delete CuentaB;
}

