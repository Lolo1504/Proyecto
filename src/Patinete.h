/*
 * Patinete.h
 *
 *  Created on: 24 feb 2025
 *      Author: Manuel
 */

 #ifndef PATINETE_H_
 #define PATINETE_H_
 #include <string>
 #include "Usuario.h"
 using namespace std;
 #include <iostream>
 class Patinete {
 private:
	 string ID;
	 string Marca;
	 string Modelo;
	 bool Averiado;
	 bool Disponible;
	 Usuario* UsuarioActual;
 public:
	 // Constructor por defecto
	 // PRE: -
	 // POST: Crea un patinete con valores por defecto
	 // DESC: Inicializa todos los atributos con valores vacíos o false
	 // Complejidad: O(1)
	 Patinete();
	 // Constructor parametrizado
	 // PRE: Todos los parámetros deben estar correctamente inicializados
	 // POST: Crea un patinete con los valores proporcionados
	 // DESC: Asigna los valores de los parámetros a los atributos
	 // Complejidad: O(1)
	 Patinete(string ID, string Marca, string Modelo, bool Averiado,bool Disponible);
	 // Constructor de copia
	 // PRE: OtroPatinete debe ser un objeto Patinete válido
	 // POST: Crea una copia exacta del patinete proporcionado
	 // DESC: Copia todos los atributos del patinete original
	 // Complejidad: O(1)
	 Patinete(const Patinete &OtroPatinete);
	 //Metodos gets
	 // PRE: -
	 // POST: Devuelve el ID del patinete
	 // DESC: Getter para el atributo ID
	 // Complejidad: O(1)
	 string GetID() const;
	 // PRE: -
	 // POST: Devuelve la marca del patinete
	 // DESC: Getter para el atributo Marca
	 // Complejidad: O(1)
	 string GetMarca();
	 // PRE: -
	 // POST: Devuelve el modelo del patinete
	 // DESC: Getter para el atributo Modelo
	 // Complejidad: O(1)
	 string GetModelo();
	 // PRE: -
	 // POST: Devuelve true si el patinete está averiado
	 // DESC: Getter para el atributo Averiado
	 // Complejidad: O(1)
	 bool GetAveriado();
	 // PRE: -
	 // POST: Devuelve true si el patinete está disponible
	 // DESC: Getter para el atributo Disponible
	 // Complejidad: O(1)
	 bool GetDisponible();
	 //Metodos Sets
	 // PRE: ID debe ser un string válido
	 // POST: Asigna el ID proporcionado al patinete
	 // DESC: Setter para el atributo ID
	 // Complejidad: O(1)
	 void SetID(string ID);
	 // PRE: Marca debe ser un string válido
	 // POST: Asigna la marca proporcionada al patinete
	 // DESC: Setter para el atributo Marca
	 // Complejidad: O(1)
	 void SetMarca(string Marca);
	 // PRE: Modelo debe ser un string válido
	 // POST: Asigna el modelo proporcionado al patinete
	 // DESC: Setter para el atributo Modelo
	 // Complejidad: O(1)
	 void SetModelo(string Modelo);
	 // PRE: -
	 // POST: Asigna el estado de averiado proporcionado
	 // DESC: Setter para el atributo Averiado
	 // Complejidad: O(1)
	 void SetAveriado(bool Averiado);
	 // PRE: -
	 // POST: Asigna el estado de disponibilidad proporcionado
	 // DESC: Setter para el atributo Disponible
	 // Complejidad: O(1)
	 void SetDisponible(bool Disponible);
	 // PRE: user debe ser un puntero a Usuario válido
	 // POST: Asocia el usuario al patinete y lo marca como no disponible
	 // DESC: Asigna el usuario actual y cambia el estado de disponibilidad
	 // Complejidad: O(1)
	 void Alquilar(Usuario* user );
	 // PRE: -
	 // POST: Desvincula el usuario del patinete y lo marca como disponible
	 // DESC: Elimina la referencia al usuario y cambia el estado de disponibilidad
	 // Complejidad: O(1)
	 void Desalquilar();
	 // PRE: -
	 // POST: Muestra por consola los datos del patinete
	 // DESC: Imprime toda la información del patinete y su usuario si está alquilado
	 // Complejidad: O(1)
	 void Mostrar();
	 // PRE: OtroPatinete debe ser un objeto Patinete válido
	 // POST: Devuelve true si los IDs coinciden
	 // DESC: Compara dos patinetes por su ID
	 // Complejidad: O(1)
	 bool operator ==(const Patinete &OtroPatinete) ;
	 // Destructor
	 // PRE: -
	 // POST: Libera los recursos del patinete
	 // DESC: No hay recursos dinámicos propios que liberar
	 // Complejidad: O(1)
	 virtual ~Patinete();
 };
 
 #endif /* PATINETE_H_ */
 
