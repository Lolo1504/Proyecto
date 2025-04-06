/*
 * GestorUsuario.h
 *
 *  Created on: 17 mar 2025
 *      Author: Manuel
 */

#ifndef GESTORUSUARIO_H_
#define GESTORUSUARIO_H_
#include "Lista.h"
#include "Usuario.h"
class GestorUsuario {
private:
	ListaDPI<Usuario *> *lUsuario;
	int contador;
public:
	GestorUsuario();
	GestorUsuario(const GestorUsuario &OtroGestor);

	void Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email);
	bool Buscar(string DNI, Usuario *&usu);
	int  NumElementos();
	void Mostrar();

	virtual ~GestorUsuario();
};

#endif /* GESTORUSUARIO_H_ */
