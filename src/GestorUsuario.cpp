/*
 * GestorUsuario.cpp
 *
 *  Created on: 17 mar 2025
 *      Author: Manuel
 */

#include "GestorUsuario.h"
#include <fstream>
//#if defined(LISTA)
GestorUsuario::GestorUsuario() {
	lUsuario=new ListaDPI<Usuario*>;
	contador=0;
}
GestorUsuario::GestorUsuario(const GestorUsuario &OtroGestor)
	{
	this->lUsuario=new ListaDPI<Usuario*>;
	OtroGestor.lUsuario->moverPrimero();
	Usuario *u=nullptr;

	while(!OtroGestor.lUsuario->alFinal())
	{
		u=OtroGestor.lUsuario->consultar();

		lUsuario->insertar(new Usuario(*u));
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
	if(lUsuario->estaVacia())
		{
		u=new Usuario(NombreCompleto,Telefono,Edad,NumeroCuenta,saldo,DNI,Email);
				lUsuario->insertar(u);
				contador++;
		}
	else
	{
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
		if(posicion || !enc){
		u=new Usuario(NombreCompleto,Telefono,Edad,NumeroCuenta,saldo,DNI,Email);
		lUsuario->insertar(u);
		contador++;
		}
	}
		}
int GestorUsuario::NumElementos()
	{
	return contador;
	}
void GestorUsuario::Mostrar()
	{
	Usuario *u=nullptr;
	lUsuario->moverPrimero();
	while(!lUsuario->alFinal())
	{	lUsuario->consultar(u);
	u->Mostrar();
		lUsuario->avanzar();
	}
	}
bool GestorUsuario::Buscar(string DNI, Usuario *&usu)
	{
	bool enc=false;
	lUsuario->moverPrimero();
	while(!lUsuario->alFinal()&& !enc)
		{
		if(lUsuario->consultar()->GetDNI()==DNI)
			{
			enc=true;
			usu=lUsuario->consultar();
			}
		lUsuario->avanzar();
		}

	return enc;
	}
GestorUsuario::~GestorUsuario() {
	Usuario *u=nullptr;
	lUsuario->moverPrimero();
	while(!lUsuario->estaVacia())
		{
		u=lUsuario->consultar();
		delete u;
		lUsuario->eliminar();
		}
	contador=0;
	delete lUsuario;
}


void GestorUsuario::Eliminar(string DNI) {
	Usuario *u=nullptr;
	lUsuario->moverPrimero();
	while(!lUsuario->alFinal())
		{
		if(lUsuario->consultar()->GetDNI()==DNI)
			{
			u=lUsuario->consultar();
			ofstream archivo("ficheros/sistema.log", ios::app);
				if(!archivo){
					cout << "No se pudo abrir el archivo sistema.log" << endl;
				}
				archivo << "Eliminando usuario: " << u->GetNombreCompleto() << endl;
			lUsuario->eliminar();
			delete u;
			contador--;
			break;
			}
		lUsuario->avanzar();
		}
}
#else
GestorUsuario::GestorUsuario()
	{
	aUsuarios=new BSTree <KeyValue<string,Usuario*>>;
	contador=0;
	}
void GestorUsuario::copiarArbol(BSTree<KeyValue<string,Usuario*>> *otro)
	{
	KeyValue<string,Usuario*> par;
	Usuario *u=nullptr;
	if(!otro->estaVacio())
		{
		par=otro->getDato();
		u=par.getValue();
		Usuario *Uc=new Usuario(*u);
		KeyValue<string,Usuario*> parCopia(par.getKey(),Uc);
		aUsuarios->insertar(parCopia);
		if(otro->getIzq()!=nullptr)
			{
			copiarArbol(otro->getIzq());
			}
		if(otro->getDer()!=nullptr)
			{
			copiarArbol(otro->getDer());
			}
		}
	}
GestorUsuario::GestorUsuario(const GestorUsuario &OtroGestor)
	{
	aUsuarios=new BSTree<KeyValue<string,Usuario*>>;
	contador=OtroGestor.contador;
	copiarArbol(OtroGestor.aUsuarios);
	}
void GestorUsuario::Insertar(string NombreCompleto, string Telefono, int Edad, string NumeroCuenta,float saldo, string DNI, string Email)
	{
	Usuario *u=new Usuario(NombreCompleto,Telefono,Edad,NumeroCuenta,saldo,DNI,Email);
	aUsuarios->insertar(KeyValue<string,Usuario*> (DNI,u));
	contador++;
	}

bool GestorUsuario::Buscar(string DNI, Usuario *&usu) {
	return MoverseBuscar(aUsuarios, DNI, usu);
}

bool GestorUsuario::MoverseBuscar(BSTree<KeyValue<string,Usuario*>> *a, string DNI, Usuario *&usu) {
	if(a == nullptr || a->estaVacio())
	{
		return false;
	}
	else
	{
		KeyValue<string,Usuario*> par = a->getDato();
		if(par.getKey() == DNI)
		{
			usu = par.getValue();
			return true;
		}
		else if(DNI < par.getKey())
		{
			return MoverseBuscar(a->getIzq(), DNI, usu);
		}
		else
		{
			return MoverseBuscar(a->getDer(), DNI, usu);
		}
	}
}


int GestorUsuario::NumElementos()
	{
	return contador;
	}

void GestorUsuario::Eliminar(string DNI) {
	cout << "Eliminando usuario con DNI: " << DNI << endl;
	KeyValue<string,Usuario*> par;
	Usuario *u=nullptr;
	par=KeyValue<string,Usuario*>(DNI,u);
	//Imprimir en el archivo "sistema.log" el DNI del usuario que se elimina, si no existe el archivo se crea
	ofstream archivo("ficheros/sistema.log", ios::app);
	if(!archivo){
		cout << "No se pudo abrir el archivo sistema.log" << endl;
	}
	Buscar(DNI, u);
	archivo << "Eliminando usuario: " << u->GetNombreCompleto() << endl;
	archivo.close();
	aUsuarios->eliminar(par);
	contador--;
	}

void GestorUsuario::Mostrar() {
	if(aUsuarios == nullptr || aUsuarios->estaVacio())
	{
		cout << "No hay usuarios en el sistema" << endl;
	}
	else
	{
		KeyValue<string,Usuario*> par;
		MostrarInorden(aUsuarios);
		cout << "Profundidad del árbol: " << Profundidad(aUsuarios) << endl;
	}
}

void GestorUsuario::MostrarInorden(BSTree<KeyValue<string, Usuario*> > *a) {
	if(a == nullptr || a->estaVacio())
	{
		return;
	}
	else
	{
		BSTree<KeyValue<string, Usuario*> > *der = a->getDer();
		BSTree<KeyValue<string, Usuario*> > *izq = a->getIzq();
		if(izq != nullptr)
		{
			MostrarInorden(izq);
		}
		MostrarInorden(a->getIzq());
		KeyValue<string,Usuario*> par = a->getDato();
		Usuario *u = par.getValue();
		u->Mostrar();
		if(der != nullptr)
		{
			MostrarInorden(der);
		}

	}
}

int GestorUsuario::Profundidad(BSTree<KeyValue<string, Usuario*> > *a) {
	if(a == nullptr || a->estaVacio())
	{
		return 0;
	}
	else
	{
		int profundidadIzq = Profundidad(a->getIzq());
		int profundidadDer = Profundidad(a->getDer());
		return 1 + max(profundidadIzq, profundidadDer);
	}
}

void GestorUsuario::RecorrerArbol(BSTree<KeyValue<string, Usuario*> > *a, ofstream &archivo) {
	if(a == nullptr || a->estaVacio())
	{
		return;
	}
	else
	{
		BSTree<KeyValue<string, Usuario*> > *der = a->getDer();
		BSTree<KeyValue<string, Usuario*> > *izq = a->getIzq();
		if(izq != nullptr)
		{
			RecorrerArbol(izq, archivo);
		}

		KeyValue<string,Usuario*> par = a->getDato();
		Usuario *u = par.getValue();
		u->UsuarioAFichero(archivo);

		if(der != nullptr)
		{
			RecorrerArbol(der, archivo);
		}
	}
}

void GestorUsuario::ActualizarArchivo() {
	ofstream archivo("ficheros/usuarios.csv", ios::trunc);
	if(!archivo) {
		cout << "No se pudo abrir el archivo usuarios.csv" << endl;
		return;
	}
	archivo << "NOMBRE COMPLETO;DNI;CORREO;TELÉFONO;EDAD;N.CUENTA;SALDO" << endl;
	RecorrerArbol(aUsuarios, archivo);
	archivo.close();
}

GestorUsuario::~GestorUsuario()
{
	ActualizarArchivo();
	cout << "Destructor de GestorUsuario llamado" << endl;
}
#endif
