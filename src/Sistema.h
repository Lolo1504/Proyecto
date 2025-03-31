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
class Sistema {
private:
	string nombreSistema;
	GestorUsuario *Usuario;
	ListaDPI <Patinete *> *lPatinete;
	/*ListaDPI<Estacion*> *lEstacion;*/

	void cargarUsuarios();
	/*void cargarEstacion();*/
	void cargarPatinetes();
public:
	Sistema(string nombreSistema);
	Sistema(const Sistema &other);

	void mostrarUsuario();
	void insertarPatinete(string id, string marca,string modelo,bool averiado,bool disponible);
	virtual ~Sistema();
};

#endif /* SISTEMA_H_ */
