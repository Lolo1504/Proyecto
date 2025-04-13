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
 
	 void cargarUsuarios();
	 void cargarEstacion();
	 void cargarPatinetes();
	 void distribuirPatinetesEnEstaciones();
	 void alquilarDevolverUnPatinete(string EstacionAlquilar, string DNI, string EstacionDevolver);
 public:
	 Sistema();
	 Sistema(string nombreSistema);
	 Sistema(const Sistema &other);
 
	 bool buscarUsuario(string DNI, Usuario *&usu);
	 bool buscarPatinete(string IdPatinete, Patinete *&p);

	 void mostrarUsuarios();
	 void mostrarPatinetes();
	 void mostrarEstaciones();
	 void mostrarEstacion(string idEstacion);
	 void maxAlquiladosEstacion();
     void agregarPatineteEnEstacion(string idPatinete, string idEstacion);
	 void insertarEstacion(string id, string nombre);
	 void insertarPatinete(string id, string marca,string modelo,bool averiado,bool disponible);
	 void alquilarDevolverPatinetes();
	 void repararPatinetesEstacion(string idEstacion);
	 void buscarPatinetesExtraviados();
 
	 virtual ~Sistema();
 };
 
 #endif /* SISTEMA_H_ */
