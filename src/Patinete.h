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
	 //Constructores
	 Patinete();
	 Patinete(string ID, string Marca, string Modelo, bool Averiado,bool Disponible);
	 Patinete(const Patinete &OtroPatinete);
	 //Metodos gets
	 string GetID() const;
	 string GetMarca();
	 string GetModelo();
	 bool GetAveriado();
	 bool GetDisponible();
	 string GetDNI();
	 string GetNombreCompleto() const;
	 //Metodos Sets
	 void SetID(string ID);
	 void SetMarca(string Marca);
	 void SetModelo(string Modelo);
	 void SetAveriado(bool Averiado);
	 void SetDisponible(bool Disponible);
	 void Alquilar(Usuario* user );
	 void Desalquilar();
	 void Mostrar();
	 bool operator ==(const Patinete &OtroPatinete) ;
	 virtual ~Patinete();
 };
 
 #endif /* PATINETE_H_ */
 
