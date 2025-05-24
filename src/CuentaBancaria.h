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
	 // PRE: -
	 // POST: Crea una cuenta bancaria vacía
	 // DESC: Inicializa número de cuenta y saldo a valores por defecto
	 // Complejidad: O(1)
	 CuentaBancaria();
	 // PRE: NumeroCuenta debe ser string válido, Saldo debe ser float válido
	 // POST: Crea una cuenta con los valores proporcionados
	 // DESC: Inicializa la cuenta con número y saldo específicos
	 // Complejidad: O(1)
	 CuentaBancaria(string NumeroCuenta, float Saldo);
	 // PRE: aCuentaBancaria debe ser una cuenta válida
	 // POST: Crea una copia exacta de la cuenta
	 // DESC: Copia el número de cuenta y saldo
	 // Complejidad: O(1)
	 CuentaBancaria(const CuentaBancaria &aCuentaBancaria);
	 // PRE: -
	 // POST: Devuelve el número de cuenta
	 // DESC: Getter para NumeroCuenta
	 // Complejidad: O(1)
	 string GetNumeroCuenta();
	 // PRE: -
	 // POST: Devuelve el saldo actual
	 // DESC: Getter para Saldo
	 // Complejidad: O(1)
	 float GetSaldo();
	 // PRE: NumeroCuenta debe ser string válido
	 // POST: Asigna el número de cuenta
	 // DESC: Setter para NumeroCuenta
	 // Complejidad: O(1)
	 void SetNumeroCuenta(string NumeroCuenta);
	 // PRE: Saldo debe ser float positivo
	 // POST: Incrementa el saldo actual
	 // DESC: Suma la cantidad al saldo existente
	 // Complejidad: O(1)
	 void IngresarSaldo(float Saldo);
	 // PRE: Saldo debe ser float positivo
	 // POST: Reduce el saldo si hay fondos suficientes
	 // DESC: Resta la cantidad si el saldo es suficiente, devuelve mensaje de estado
	 // Complejidad: O(1)
	 string RetirarSaldo(float Saldo);
	 // PRE: -
	 // POST: Muestra por consola los datos de la cuenta
	 // DESC: Imprime número de cuenta y saldo actual
	 // Complejidad: O(1)
	 void Mostrar();
	 // PRE: -
	 // POST: Libera los recursos de la cuenta
	 // DESC: No hay recursos dinámicos que liberar
	 // Complejidad: O(1)
	 virtual ~CuentaBancaria();
 };
 
 #endif /* CUENTABANCARIA_H_ */
 
