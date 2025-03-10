/*
 * CuentaBancaria.cpp
 *
 *  Created on: 17 feb 2025
 *      Author: Manuel
 */
using namespace std;
#include <iostream>
#include "CuentaBancaria.h"
#include <string>
//Constructor por defecto
CuentaBancaria::CuentaBancaria() {
	NumeroCuenta="";
	 Saldo=0;
}
//Constructor parametrizado
CuentaBancaria::CuentaBancaria(string NumeroCuenta, float Saldo )
	{
	this->NumeroCuenta=NumeroCuenta;
	this->Saldo=Saldo;
	}
//Constructor por copia
CuentaBancaria::CuentaBancaria(const CuentaBancaria &aCuentaBancaria)
	{
	this->NumeroCuenta=aCuentaBancaria.NumeroCuenta;
	this->Saldo=aCuentaBancaria.Saldo;
	}
//Gets
string CuentaBancaria::GetNumeroCuenta()
	{
	return NumeroCuenta;
	}
float CuentaBancaria::GetSaldo()
	{
	return Saldo;
	}
//Sets
void CuentaBancaria::SetNumeroCuenta(string NumeroCuenta)
	{
	this->NumeroCuenta=NumeroCuenta;
	}

void CuentaBancaria::IngresarSaldo(float Saldo)
	{
	this->Saldo=this->Saldo+Saldo;
	}

string CuentaBancaria::RetirarSaldo(float Saldo)
	{string mensaje;
	if(GetSaldo()>=Saldo)
	{
		this->Saldo=GetSaldo()-Saldo;
		mensaje="Retirada de dinero completa";
	}
	else
		{
		mensaje = "El saldo que se quiere retirar es superiro al que hay en la cuenta";
		}
	return mensaje;
	}
void CuentaBancaria::Mostrar()
	{
	cout<< "Numero de cuenta: "<< GetNumeroCuenta() <<endl << "Saldo: "<<GetSaldo() <<endl;
	}
CuentaBancaria::~CuentaBancaria() {

}

