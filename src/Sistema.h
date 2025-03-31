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
	 GestorUsuario *Usuarios;
	 ListaDPI <Patinete *> *lPatinete;
	 ListaDPI<Estacion*> *lEstacion;
 
	 void cargarUsuarios();
	 void cargarEstacion();
	 void cargarPatinetes();
 public:
	 Sistema();
	 Sistema(string nombreSistema);
	 Sistema(const Sistema &other);
 
	 void buscarUsuario(string DNI);
 
	 void mostrarUsuarios();
	 void mostrarPatinetes();
	 void mostrarEstaciones();
 
 
	 void instertarEstacion(string id, string nombre);
	 void insertarPatinete(string id, string marca,string modelo,bool averiado,bool disponible);
 
	 virtual ~Sistema();
 };
 
 #endif /* SISTEMA_H_ */
