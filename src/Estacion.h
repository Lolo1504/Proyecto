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
	 Estacion();
	 Estacion(string Id, string direccion);
	 Estacion(const Estacion &OtraEstacion);
	 void setId(string Id);
	 void setDireccion(string Direccion);
	 string getId();
	 string getDireccion();
	 int getNumeroDisponibles();
	 int getNumeroAveriados();
	 int getNumeroAlquilados();
	 bool ConsultarDisponible();
	 void agregarPatinete(Patinete *p);
	 void MostrarDisponibles();
	 void MostrarAveriados();
	 void Mostrar();
	 void RepararPatinetes();
	 bool BuscarPatinete(string idPatinete);
	 Patinete alquilarPatinete();
	  ~Estacion();
 };
 
 #endif /* ESTACION_H_ */
 
