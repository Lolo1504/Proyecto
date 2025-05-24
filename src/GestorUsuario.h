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
#include <iostream>
#if defined(LISTA)
class GestorUsuario {
private:
	ListaDPI<Usuario *> *lUsuario;
	int contador;
public:
	// PRE: -
	// POST: Crea un gestor vacío con contador a 0
	// DESC: Inicializa la lista de usuarios
	// Complejidad: O(1)
	GestorUsuario();
	// PRE: OtroGestor debe ser un gestor válido
	// POST: Crea una copia exacta del gestor
	// DESC: Realiza una copia profunda de todos los usuarios
	// Complejidad: O(n)
	GestorUsuario(const GestorUsuario &OtroGestor);
	// PRE: Todos los parámetros deben estar correctamente inicializados
	// POST: Añade un nuevo usuario manteniendo el orden por DNI
	// DESC: Inserta el usuario en la posición correcta según DNI
	// Complejidad: O(n)
	void Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email);
	// PRE: DNI debe ser un string válido
	// POST: Devuelve true si encuentra el usuario y lo asigna al parámetro
	// DESC: Busca linealmente un usuario por DNI
	// Complejidad: O(n)
	bool Buscar(string DNI, Usuario *&usu);
	// PRE: -
	// POST: Devuelve el contador de usuarios
	// DESC: Getter para el atributo contador
	// Complejidad: O(1)
	int  NumElementos();
	// PRE: DNI debe ser un string válido
	// POST: Elimina el usuario con el DNI especificado
	// DESC: Busca y elimina un usuario de la lista
	// Complejidad: O(n)
	void Eliminar(string DNI);
	// PRE: -
	// POST: Muestra por consola todos los usuarios
	// DESC: Recorre la lista mostrando cada usuario
	// Complejidad: O(n)
	void Mostrar();

	virtual ~GestorUsuario();
};
#else
class GestorUsuario {
private:
	BSTree<KeyValue<string,Usuario*>> *aUsuarios;
	// PRE: a es un árbol BST válido
	// POST: Muestra los usuarios en orden ascendente por DNI
	// DESC: Recorrido inorden recursivo
	// Complejidad: O(n)
	void MostrarInorden(BSTree<KeyValue<string,Usuario*>> *a);
	// PRE: a es un árbol BST válido, DNI es string válido
	// POST: Devuelve true si encuentra el usuario
	// DESC: Implementa la búsqueda binaria en el BST
	// Complejidad: O(log n) promedio, O(n) peor caso
	bool MoverseBuscar(BSTree<KeyValue<string,Usuario*>> *a, string DNI, Usuario *&usu);
	// PRE: a es un árbol BST válido
	// POST: Devuelve la profundidad del árbol
	// DESC: Calcula recursivamente la profundidad máxima
	// Complejidad: O(n)
	int Profundidad(BSTree<KeyValue<string,Usuario*>> *a);
	int contador;
	// PRE: otro debe ser un árbol BST válido
	// POST: Copia recursiva de todos los nodos
	// DESC: Realiza una copia profunda del árbol
	// Complejidad: O(n)
	void copiarArbol(BSTree<KeyValue<string,Usuario*>> *otro);
public:
	// PRE: -
	// POST: Crea un gestor vacío con contador a 0
	// DESC: Inicializa el árbol BST de usuarios
	// Complejidad: O(1)
	GestorUsuario();
	// PRE: OtroGestor debe ser un gestor válido
	// POST: Crea una copia exacta del gestor
	// DESC: Realiza una copia profunda del árbol BST
	// Complejidad: O(n)
	GestorUsuario(const GestorUsuario &OtroGestor);
	// PRE: -
	// POST: Añade un nuevo usuario al árbol
	// DESC: Crea un nuevo usuario y lo inserta en el BST
	// Complejidad: O(log n) promedio, O(n) peor caso
	void Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email);
	// PRE: DNI debe ser un string válido
	// POST: Devuelve true si encuentra el usuario y lo asigna al parámetro
	// DESC: Busca recursivamente en el árbol BST
	// Complejidad: O(log n) promedio, O(n) peor caso
	bool Buscar(string DNI, Usuario *&usu);
	// PRE: -
	// POST: Devuelve el contador de usuarios
	// DESC: Getter para el atributo contador
	// Complejidad: O(1)
	int  NumElementos();
	// PRE: DNI debe ser un string válido
	// POST: Elimina el usuario con el DNI especificado
	// DESC: Busca y elimina un usuario del árbol BST
	// Complejidad: O(log n) promedio, O(n) peor caso
	void Eliminar(string DNI);
	// PRE: -
	// POST: Muestra todos los usuarios en orden
	// DESC: Recorrido inorden del árbol BST
	// Complejidad: O(n)
	void Mostrar();
	// PRE: -
	// POST: Actualiza el archivo CSV con los usuarios actuales
	// DESC: Sobrescribe el archivo con los usuarios del árbol
	// Complejidad: O(n)
	void ActualizarArchivo();
	// PRE: a es un árbol BST válido, archivo está abierto
	// POST: Escribe los usuarios en el archivo en orden
	// DESC: Recorrido inorden para escritura en archivo
	// Complejidad: O(n)
	void RecorrerArbol(BSTree<KeyValue<string, Usuario*> > *a, ofstream &archivo);
	// PRE: -
	// POST: Libera toda la memoria y actualiza el archivo
	// DESC: Actualiza el archivo y libera el árbol BST
	// Complejidad: O(n)
	virtual ~GestorUsuario();
};
#endif
#endif /* GESTORUSUARIO_H_ */
