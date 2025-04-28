/*
 * GestorUsuario.h
 *
 *  Created on: 17 mar 2025
 *      Author: Manuel
 */

#ifndef GESTORUSUARIO_H_
#define GESTORUSUARIO_H_
//#define LISTA
#include "BSTree.h"
#include "KeyValue.h"
#include "Lista.h"
#include "Usuario.h"
#if defined(LISTA)
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
	void Eliminar(string DNI);
	void Mostrar();

	virtual ~GestorUsuario();
};
#else
class GestorUsuario {
private:
	BSTree<KeyValue<string,Usuario*>> *aUsuarios;
	int contador;

void copiarArbol(BSTree<KeyValue<string,Usuario*>> *otro);
public:
	GestorUsuario();
	GestorUsuario(const GestorUsuario &OtroGestor);

	void Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email);
	bool Buscar(string DNI, Usuario *&usu);
	int  NumElementos();
	void Eliminar(string DNI);
	void Mostrar();

	virtual ~GestorUsuario();
};
#endif
#endif /* GESTORUSUARIO_H_ */
