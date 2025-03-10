/*
 * Usuario.h
 *
 *  Created on: 10 feb 2025
 *      Author: Manuel
 */


#ifndef USUARIO_H_
#define USUARIO_H_
using namespace std;
#include "CuentaBancaria.h"
#include <string>
#include <fstream>


class Usuario {
private:
	string NombreCompleto;
	string Telefono;
	int Edad;
	CuentaBancaria *CuentaB;
	string DNI;
	string Email;

public:


	Usuario();
	Usuario(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta, float Saldo, string DNI,string Email);
	Usuario(const Usuario &OtroUsuario);
	//Gets
	string GetNombreCompleto() const;
	void GetNombreCompleto(string &NombreCompleto)const;
	string GetTelefono()const;
	int GetEdad()const;
	string GetNumeroCuenta();
	float GetSaldo();
	string GetDNI();
	string GetEmail();
	//Sets
	void SetNombreCompleto(string NombreCompleto);
	void SetTelefono(string Telefono);
	void SetEdad(int Edad);
	void SetNumeroCuenta(string NumeroCuenta);
	void IngresarSaldo(float Saldo);
	void RetirarSaldo (float Saldo);
	void SetDNI(string DNI);
	void SetEmail(string Email);
	void IngresarSaldo(int Saldo);
	//mostrar
	void Mostrar();
	//PasarAcadena
	string PasarACadena();


	//Desctructor
	~Usuario();
};

#endif /* USUARIO_H_ */
