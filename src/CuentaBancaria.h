/*
 * CuentaBancaria.h
 *
 *  Created on: 17 feb 2025
 *      Author: Manuel
 */

#ifndef CUENTABANCARIA_H_
#define CUENTABANCARIA_H_
#include <string>
using namespace std;
class CuentaBancaria {
private:
	string NumeroCuenta;
	float Saldo;
public:
	CuentaBancaria();
	CuentaBancaria(string NumeroCuenta, float Saldo);
	CuentaBancaria(const CuentaBancaria &aCuentaBancaria);

	string GetNumeroCuenta();
	float GetSaldo();

	void SetNumeroCuenta(string NumeroCuenta);
	void IngresarSaldo(float Saldo);
	string RetirarSaldo(float Saldo);

	void Mostrar();
	virtual ~CuentaBancaria();
};

#endif /* CUENTABANCARIA_H_ */
