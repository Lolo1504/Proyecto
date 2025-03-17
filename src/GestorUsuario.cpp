/*
 * GestorUsuario.cpp
 *
 *  Created on: 17 mar 2025
 *      Author: Manuel
 */

#include "GestorUsuario.h"

GestorUsuario::GestorUsuario() {
	lUsuario=new ListaDPI<Usuario*>;
	contador=0;
}
GestorUsuario::GestorUsuario(const GestorUsuario &OtroGestor)
	{
	this->lUsuario=new ListaDPI<Usuario*>;
	OtroGestor.lUsuario->moverPrimero();
	Usuario *u=nullptr;
	Usuario *Copia=nullptr;
	while(!OtroGestor.lUsuario->alFinal())
	{
		u=OtroGestor.lUsuario->consultar();
		Copia=new Usuario(*u);
		lUsuario->insertar(Copia);
		OtroGestor.lUsuario->avanzar();
	}
	this->contador=OtroGestor.contador;
	}
void GestorUsuario::Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email)
	{
	bool enc =false;
	bool posicion=false;
	lUsuario->moverPrimero();
	Usuario *u=nullptr;
	while(!lUsuario->alFinal()&& !enc && !posicion)
		{
		u=lUsuario->consultar();
		if(u->GetDNI()==DNI)
			{
			enc=true;
			}
		else
		{
		if(u->GetDNI()>DNI)
			{
			posicion=true;
			}
		else
			{
			lUsuario->avanzar();
			}
		}
		}
		if(posicion){
		u=new Usuario(NombreCompleto,Telefono,Edad,NumeroCuenta,saldo,DNI,Email);
		lUsuario->insertar(u);
		contador++;
		}
		}
int GestorUsuario::NumElementos()
	{
	return contador;
	}
void GestorUsuario::Mostrar()
	{
	Usuario *u=nullptr;
	lUsuario->enPrimero();
	while(lUsuario->alFinal())
	{	u=lUsuario->consultar();
		cout<<"DNI: "<<u->GetDNI()<<" Nombre: "<< u->GetNombreCompleto()<<" Telefono: "<<u->GetTelefono()<< "Edad: "<< u->GetEdad()<<"Email: "<<u->GetEmail()<<"NumeroCuenta: "<<u->GetNumeroCuenta()<<"Saldo de la cuenta: "<<u->GetSaldo() <<endl;
		lUsuario->avanzar();
	}

	}
GestorUsuario::~GestorUsuario() {
	Usuario *u=nullptr;
	lUsuario->moverPrimero();
	while(!lUsuario->estaVacia())
		{
		u=lUsuario->consultar();
		delete u;
		lUsuario->eliminar();
		contador--;

		}
	delete lUsuario;
}

