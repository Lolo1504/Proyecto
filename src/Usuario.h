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
	 //Constructor por defecto
	 //PRE: -
	 //POST: Crea un objeto Usuario con valores por defecto
	 //DESC: Inicializa todos los atributos con valores vacíos o cero
	 //Complejidad: O(1)
	 Usuario();
	 //Constructor parametrizado
	 //PRE: Todos los parámetros deben estar correctamente inicializados
	 //POST: Crea un objeto Usuario con los valores proporcionados
	 //DESC: Asigna los valores de los parámetros a los atributos y crea una nueva CuentaBancaria
	 //Complejidad: O(1)
	 Usuario(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta, float Saldo, string DNI,string Email);
	 //Constructor de copia
	 //PRE: OtroUsuario debe ser un objeto Usuario válido
	 //POST: Crea un nuevo objeto Usuario copia del proporcionado
	 //DESC: Realiza una copia profunda de todos los atributos, incluyendo la CuentaBancaria
	 //Complejidad: O(1)
	 Usuario(const Usuario &OtroUsuario);
	 //PRE: -
	 //POST: Devuelve el nombre completo
	 //DESC: Método getter para el atributo NombreCompleto
	 //Complejidad: O(1)
	 string GetNombreCompleto() const;
	 //PRE: NombreCompleto debe ser una variable string válida
	 //POST: Asigna el nombre completo al parámetro proporcionado
	 //DESC: Método getter alternativo para el atributo NombreCompleto
	 //Complejidad: O(1)
	 void GetNombreCompleto(string &NombreCompleto)const;
	 //PRE: -
	 //POST: Devuelve el teléfono
	 //DESC: Método getter para el atributo Telefono
	 //Complejidad: O(1)
	 string GetTelefono()const;
	 //PRE: -
	 //POST: Devuelve la edad
	 //DESC: Método getter para el atributo Edad
	 //Complejidad: O(1)
	 int GetEdad()const;
	 //PRE: -
	 //POST: Devuelve el saldo de la cuenta
	 //DESC: Consulta el saldo a través del objeto CuentaBancaria
	 //Complejidad: O(1)
	 float ConsultarSaldo() const;
	 //PRE: -
	 //POST: Devuelve el número de cuenta
	 //DESC: Consulta el número de cuenta a través del objeto CuentaBancaria
	 //Complejidad: O(1)
	 string ConsultarNumeroCuenta()const;
	 //PRE: -
	 //POST: Devuelve el DNI
	 //DESC: Método getter para el atributo DNI
	 //Complejidad: O(1)
	 string GetDNI();
	 //PRE: -
	 //POST: Devuelve el email
	 //DESC: Método getter para el atributo Email
	 //Complejidad: O(1)
	 string GetEmail();
	 //Sets
	 //PRE: NombreCompleto debe ser un string válido
	 //POST: Establece el nombre completo
	 //DESC: Método setter para el atributo NombreCompleto
	 //Complejidad: O(1)
	 void SetNombreCompleto(string NombreCompleto);
	 //PRE: Telefono debe ser un string válido
	 //POST: Establece el teléfono
	 //DESC: Método setter para el atributo Telefono
	 //Complejidad: O(1)
	 void SetTelefono(string Telefono);
	 //PRE: Edad debe ser un entero positivo
	 //POST: Establece la edad
	 //DESC: Método setter para el atributo Edad
	 //Complejidad: O(1)
	 void SetEdad(int Edad);
	 //PRE: NumeroCuenta debe ser un string válido, Saldo debe ser un float válido
	 //POST: Crea una nueva cuenta bancaria si no existe
	 //DESC: Inicializa el objeto CuentaBancaria si es nullptr
	 //Complejidad: O(1)
	 void CrearCuentaB(string NumeroCuenta,float Saldo);
	 //PRE: Saldo debe ser positivo
	 //POST: Incrementa el saldo de la cuenta
	 //DESC: Llama al método IngresarSaldo de CuentaBancaria
	 //Complejidad: O(1)
	 void IngresarSaldo(float Saldo);
	 //PRE: Saldo debe ser positivo y <= saldo actual
	 //POST: Reduce el saldo de la cuenta
	 //DESC: Llama al método RetirarSaldo de CuentaBancaria
	 //Complejidad: O(1)
	 void RetirarSaldo (float Saldo);
	 //PRE: DNI debe ser un string válido
	 //POST: Establece el DNI
	 //DESC: Método setter para el atributo DNI
	 //Complejidad: O(1)
	 void SetDNI(string DNI);
	 //PRE: Email debe ser un string válido
	 //POST: Establece el email
	 //DESC: Método setter para el atributo Email
	 //Complejidad: O(1)
	 void SetEmail(string Email);
	 //PRE: -
	 //POST: Muestra por consola los datos del usuario
	 //DESC: Imprime toda la información del usuario y su cuenta bancaria
	 //Complejidad: O(1)
	 void Mostrar();
	 //PRE: -
	 //POST: Devuelve un string con todos los datos del usuario
	 //DESC: Convierte todos los atributos a un string concatenado
	 //Complejidad: O(1)
	 void UsuarioAFichero(ofstream &archivo);
	 //PRE: archivo debe estar abierto para escritura
	 //POST: Escribe los datos del usuario en el archivo
	 //DESC: Guarda los datos del usuario en formato CSV en el archivo proporcionado
	 //Complejidad: O(1)
	 string PasarACadena();
 
 
	 //Desctructor
	 //PRE: -
	 //POST: Libera la memoria de la cuenta bancaria
	 //DESC: Elimina el objeto CuentaBancaria si existe
	 //Complejidad: O(1)
	 ~Usuario();
 };
 
 #endif /* USUARIO_H_ */
 
