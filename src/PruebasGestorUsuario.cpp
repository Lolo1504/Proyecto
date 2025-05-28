/*
 * PruebasGestorUsuario.cpp
 *
 *  Created on: 31 mar 2025
 *      Author: Manuel
 */
#include "GestorUsuario.h"


void PruebasGestor()
	{
	cout<<"INICIO PRUEBAS GESTOR DE USUARIOS"<<endl;
	GestorUsuario *g=new GestorUsuario();
	//Probamos los metodos insertar
	g->Insertar("Manuel","0890231",12,"23231a",1000,"1","gmail");
	g->Insertar("Carlos","39012740",12,"123221",1000,"2","gmail");
	g->Insertar("Alberto","381092803",12,"31231",1000,"4","gmail");
	g->Insertar("Juanjo","310927309",12,"43241",1000,"3","gmail");
	Usuario *u=nullptr;
	if(g->Buscar("2",u))
		{
		cout<<"Se mostrara el usuario con DNI 2 para demostrar que ha sido encontrado y que ha sido apuntado al puntero con exito"<<endl;
			u->Mostrar();
		}
	else
		cout<<"Error en el metodo Buscar"<<endl;

	if(g->NumElementos()!=4)
		cout <<"Error en el metodo NumElementos"<<endl;
	cout<<"Vamos a mostrar la informacion del gestor y luego borraremos 2 usuarios del gestor y comprobaremos que se han borrado correctamente volviendolo a mostrar"<<endl;
	g->Mostrar();
	g->Eliminar("4");
	g->Eliminar("2");
	cout<<"volvemos a mostrarlo"<<endl;
	g->Mostrar();
	cout<<"Prueba del metodo mostrar, deberia mostrar la informacion de todos los usuarios"<<endl;
	g->Mostrar();
	GestorUsuario *g1=new GestorUsuario(*g);
	cout << "Prueba constructor por copia Gestor Usuario deberia mostrar los mismo datos que el otro gestor"<<endl;
	g1->Mostrar();
	//Para comprobar si el metodo de ActualizarArchivo funciona correctamente comprobar el archivo usuarios.csv, que esta en la carperta ficheros
	delete g1;
	delete g;
	cout<<"FIN PRUEBAS GESTOR DE USUARIOS"<<endl;
	}
