/*
 * Sistema.h
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */

 #ifndef SISTEMA_H_
 #define SISTEMA_H_
 #include "GestorUsuario.h"
 #include "Patinete.h"
 #include "Estacion.h"
 #include "Usuario.h"
 class Sistema {
 private:
	 string nombreSistema;
	 GestorUsuario *lUsuarios;
	 ListaDPI <Patinete *> *lPatinete;
	 ListaDPI<Estacion*> *lEstacion;
	 // PRE: El archivo "ficheros/usuarios.csv" debe existir y tener formato correcto
	 // POST: Carga todos los usuarios del archivo al sistema
	 // DESC: Lee el archivo CSV y crea objetos Usuario para cada entrada
	 // Complejidad: O(n)
	 void cargarUsuarios();
	 // PRE: El archivo "ficheros/estaciones.csv" debe existir y tener formato correcto
	 // POST: Carga todas las estaciones del archivo al sistema
	 // DESC: Lee el archivo CSV y crea objetos Estacion para cada entrada
	 // Complejidad: O(n)
	 void cargarEstacion();
	 // PRE: El archivo "ficheros/patinetes.csv" debe existir y tener formato correcto
	 // POST: Carga todos los patinetes del archivo al sistema
	 // DESC: Lee el archivo CSV y crea objetos Patinete para cada entrada
	 // Complejidad: O(n)
	 void cargarPatinetes();
	 // PRE: El archivo "ficheros/distribucionPatinetes.csv" debe existir
	 // POST: Asigna patinetes a estaciones según el archivo
	 // DESC: Lee el archivo y asocia patinetes a estaciones
	 // Complejidad: O(n^2)
	 void distribuirPatinetesEnEstaciones();
	 // PRE: Todos los parámetros deben ser strings válidos
	 // POST: Realiza el proceso completo de alquiler y devolución
	 // DESC: Gestiona el alquiler y devolución con validaciones de saldo y estaciones
	 // Complejidad: O(log n)
	 void alquilarDevolverUnPatinete(string EstacionAlquilar, string DNI, string EstacionDevolver);
 public:
	 // Constructor por defecto
	 // PRE: -
	 // POST: Crea un objeto Sistema con valores por defecto
	 // DESC: Inicializa el sistema con nombre vacío y carga todos los datos
	 // Complejidad: O(1)
	 Sistema();
	 // Constructor parametrizado
	 // PRE: nombreSistema debe ser un string válido
	 // POST: Crea un objeto Sistema con el nombre proporcionado e inicializa todas las estructuras de datos
	 // DESC: Inicializa el sistema, carga usuarios, patinetes, estaciones y distribuye patinetes
	 // Complejidad: O(1)
	 Sistema(string nombreSistema);
	 // Constructor de copia
	 // PRE: other debe ser un objeto Sistema válido
	 // POST: Crea una copia exacta del sistema proporcionado
	 // DESC: Realiza una copia profunda de todas las estructuras de datos
	 // Complejidad: O(1)
	 Sistema(const Sistema &other);
	 // PRE: DNI debe ser un string válido
	 // POST: Devuelve true si encuentra el usuario y lo asigna al parámetro usu
	 // DESC: Busca un usuario en el gestor de usuarios por su DNI
	 // Complejidad: O(log n) con BSTree, O(n) con ListaDPI
	 bool buscarUsuario(string DNI, Usuario *&usu);
	 // PRE: IdPatinete debe ser un string válido
	 // POST: Devuelve true si encuentra el patinete y lo asigna al parámetro p
	 // DESC: Busca linealmente un patinete en la lista por su ID
	 // Complejidad: O(n)
	 bool buscarPatinete(string IdPatinete, Patinete *&p);
	 // PRE: IdEstacion debe ser un string válido
	 // POST: Devuelve true si encuentra la estación y lo asigna al parámetro E
	 // DESC: Busca linealmente una estación en la lista por su ID
	 // Complejidad: O(n)
	 bool buscarEstacion(string IdEstacion,Estacion *&E);
	 // PRE: -
	 // POST: Muestra por consola todos los usuarios y su cantidad
	 // DESC: Utiliza el método Mostrar del GestorUsuario
	 // Complejidad: O(n)
	 void mostrarUsuarios();
	 // PRE: -
	 // POST: Muestra por consola todos los patinetes y su cantidad
	 // DESC: Recorre la lista de patinetes mostrando cada uno
	 // Complejidad: O(n)
	 void mostrarPatinetes();
	 // PRE: -
	 // POST: Muestra por consola todas las estaciones
	 // DESC: Recorre la lista de estaciones mostrando cada una
	 // Complejidad: O(n)
	 void mostrarEstaciones();
	 // PRE: idEstacion debe ser un string válido
	 // POST: Muestra por consola la estación con el ID proporcionado
	 // DESC: Busca y muestra una estación específica
	 // Complejidad: O(n)
	 void mostrarEstacion(string idEstacion);
	 // PRE: -
	 // POST: Muestra la estación con más patinetes alquilados
	 // DESC: Recorre todas las estaciones buscando la que tenga más alquileres
	 // Complejidad: O(n)
	 void maxAlquiladosEstacion();
	 // PRE: idPatinete y idEstacion deben ser strings válidos
	 // POST: Asigna el patinete a la estación especificada
	 // DESC: Busca ambos elementos y realiza la asignación
	 // Complejidad: O(n) donde m=patinetes, p=estaciones
     void agregarPatineteEnEstacion(string idPatinete, string idEstacion);
     // PRE: id y ubicación deben ser strings válidos
     // POST: Añade una nueva estación al final de la lista de estaciones
     // DESC: Crea un nuevo objeto Estacion y lo inserta al final de la lista
     // Complejidad: O(1)
	 void insertarEstacion(string id, string nombre);
	 // PRE: Todos los parámetros deben estar correctamente inicializados
	 // POST: Añade un nuevo patinete a la lista de patinetes
	 // DESC: Crea un nuevo objeto Patinete y lo inserta al principio de la lista
	 // Complejidad: O(1)
	 void insertarPatinete(string id, string marca,string modelo,bool averiado,bool disponible);
	 // PRE: El archivo "ficheros/alquilerPatinetes.csv" debe existir
	 // POST: Ejecuta todos los alquileres especificados en el archivo
	 // DESC: Lee el archivo y procesa cada operación de alquiler/devolución
	 // Complejidad: O(n*log n)
	 void alquilarDevolverPatinetes();
	 // PRE: idEstacion debe ser un string válido
	 // POST: Repara los patinetes averiados en la estación especificada
	 // DESC: Busca la estación y repara sus patinetes averiados
	 // Complejidad: O(n)
	 void repararPatinetesEstacion(string idEstacion);
	 // PRE: -
	 // POST: Encuentra y muestra patinetes que no están en ninguna estación
	 // DESC: Compara todos los patinetes con los asignados a estaciones
	 // Complejidad: O(n^2)
	 void buscarPatinetesExtraviados();
	 // PRE: -
	 // POST: Libera toda la memoria utilizada por el sistema
	 // DESC: Elimina todos los usuarios, patinetes y estaciones
	 // Complejidad: O(n) donde n=usuarios, m=patinetes, p=estaciones
	 virtual ~Sistema();
 };
 
 #endif /* SISTEMA_H_ */
