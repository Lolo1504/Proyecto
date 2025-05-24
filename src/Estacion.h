/*
 * Estacion.h
 *
 *  Created on: 10 mar 2025
 *      Author: Manuel
 */

 #ifndef ESTACION_H_
 #define ESTACION_H_
 #include "Cola.h"
 #include "Patinete.h"
 using namespace std;
 #include <iostream>
 #include <string>
 
 class Estacion {
 private:
	 string identificador;
	 string direccion;
	 int NumDisponibles;
	 int NumAveriados;
	 int nAlquilados;
	 Cola <Patinete*> *PatineteDisponible;
	 Cola <Patinete*> *PatineteAveriado;
 
 public:
	 // PRE: -
	 // POST: Crea una estación vacía
	 // DESC: Inicializa todos los atributos con valores por defecto
	 // Complejidad: O(1)
	 Estacion();
	 // PRE: Id y direccion deben ser strings válidos
	 // POST: Crea una estación con los datos proporcionados
	 // DESC: Inicializa la estación con los parámetros dados
	 // Complejidad: O(1)
	 Estacion(string Id, string direccion);
	 // PRE: OtraEstacion debe ser una estación válida
	 // POST: Crea una copia exacta de la estación
	 // DESC: Realiza una copia profunda de las colas de patinetes
	 // Complejidad: O(n)
	 Estacion(const Estacion &OtraEstacion);
	 // PRE: Id debe ser un string válido
	 // POST: Asigna el identificador de la estación
	 // DESC: Setter para el atributo identificador
	 // Complejidad: O(1)
	 void setId(string Id);
	 // PRE: Direccion debe ser un string válido
	 // POST: Asigna la dirección de la estación
	 // DESC: Setter para el atributo direccion
	 // Complejidad: O(1)
	 void setDireccion(string Direccion);
	 // PRE: -
	 // POST: Incrementa en 1 el contador de alquilados
	 // DESC: Aumenta el número de patinetes alquilados
	 // Complejidad: O(1)
	 void setNumeroAlquilados();
	 // PRE: -
	 // POST: Devuelve el identificador de la estación
	 // DESC: Getter para identificador
	 // Complejidad: O(1)
	 string getId();
	 // PRE: -
	 // POST: Devuelve la dirección de la estación
	 // DESC: Getter para direccion
	 // Complejidad: O(1)
	 string getDireccion();
	 // PRE: -
	 // POST: Devuelve el número de patinetes disponibles
	 // DESC: Getter para NumDisponibles
	 // Complejidad: O(1)
	 int getNumeroDisponibles();
	 // PRE: -
	 // POST: Devuelve el número de patinetes averiados
	 // DESC: Getter para NumAveriados
	 // Complejidad: O(1)
	 int getNumeroAveriados();
	 // PRE: -
	 // POST: Devuelve el número de patinetes alquilados
	 // DESC: Getter para nAlquilados
	 // Complejidad: O(1)
	 int getNumeroAlquilados();
	 // PRE: -
	 // POST: Devuelve true si hay patinetes disponibles
	 // DESC: Comprueba si hay patinetes disponibles
	 // Complejidad: O(1)
	 bool ConsultarDisponible();
	 // PRE: p debe ser un puntero a Patinete válido
	 // POST: Añade el patinete a la cola correspondiente
	 // DESC: Agrega el patinete a la cola de disponibles o averiados según su estado
	 // Complejidad: O(1)
	 void agregarPatinete(Patinete *p);
	 // PRE: -
	 // POST: Muestra por consola los patinetes disponibles
	 // DESC: Recorre y muestra los patinetes disponibles
	 // Complejidad: O(n)
	 void MostrarDisponibles();
	 // PRE: -
	 // POST: Muestra por consola los patinetes averiados
	 // DESC: Recorre y muestra los patinetes averiados
	 // Complejidad: O(n)
	 void MostrarAveriados();
	 // PRE: -
	 // POST: Muestra los datos principales de la estación
	 // DESC: Imprime información resumida de la estación
	 // Complejidad: O(1)
	 void Mostrar();
	 // PRE: -
	 // POST: Repara todos los patinetes averiados
	 // DESC: Marca todos los patinetes averiados como reparados y los mueve a disponibles
	 // Complejidad: O(n)
	 int RepararPatinetes();
	 // PRE: idPatinete debe ser un string válido
	 // POST: Devuelve true si el patinete está en la estación
	 // DESC: Busca un patinete en ambas colas (disponibles y averiados)
	 // Complejidad: O(n)
	 bool BuscarPatinete(string idPatinete);
	 // PRE: usu debe ser un puntero a Usuario válido
	 // POST: Asigna un patinete disponible al usuario
	 // DESC: Extrae un patinete de la cola de disponibles y lo asigna al usuario
	 // Complejidad: O(1)
	 void alquilarPatinete( Usuario *&usu,Patinete *&P);
	 // PRE: P debe ser un puntero a Patinete válido
	 // POST: Devuelve el patinete a la estación
	 // DESC: Desvincula el patinete del usuario y lo vuelve a agregar a la estación
	 // Complejidad: O(1)
	 void Devolver(Patinete *&P);
	 // PRE: -
	 // POST: Libera la memoria de las colas de patinetes
	 // DESC: Elimina las colas de patinetes disponibles y averiados
	 // Complejidad: O(1)
	  ~Estacion();
 };
 
 #endif /* ESTACION_H_ */
 
