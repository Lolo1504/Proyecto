/*
 * Sistema.cpp
 *
 *  Created on: 24 mar 2025
 *      Author: Manuel
 */

 #include "Sistema.h"



 Sistema::Sistema(string nombreSistema) {
 this->nombreSistema=nombreSistema;
 this->lUsuarios= new GestorUsuario;
 this->lEstacion=new ListaDPI<Estacion*>;
 this->lPatinete=new ListaDPI<Patinete*>;
 cargarUsuarios();
 cargarPatinetes();
 cargarEstacion();
 distribuirPatinetesEnEstaciones();
 }
 
 Sistema::Sistema() {
	 this->nombreSistema="";
	 this->lUsuarios= new GestorUsuario;
	 cargarUsuarios();
	 this->lPatinete=new ListaDPI<Patinete*>;
	 cargarPatinetes();
	 this->lEstacion=new ListaDPI<Estacion*>;
	 cargarEstacion();
	 distribuirPatinetesEnEstaciones();
 }
 
 Sistema::Sistema(const Sistema &other)
	 {
	 this->nombreSistema=other.nombreSistema;

	 this->lUsuarios=new GestorUsuario(*other.lUsuarios);
	 if(other.lPatinete!=nullptr)
		 {
		 this->lPatinete=new ListaDPI<Patinete*>;
		 other.lPatinete->moverPrimero();
		 while(!other.lPatinete->alFinal())
			 {
			 Patinete *P=other.lPatinete->consultar();
			 this->lPatinete->insertar(new Patinete(*P));
			 other.lPatinete->avanzar();
			 }
		 }
	 else
		 {
		 this->lPatinete=nullptr;
		 }
	 if(other.lEstacion!=nullptr)
		 {
		 this->lEstacion=new ListaDPI<Estacion*>;
		 other.lEstacion->moverPrimero();
		 while(!other.lEstacion->alFinal())
			 {
			 Estacion *E=other.lEstacion->consultar();
			 this->lEstacion->insertar(new Estacion(*E));
			 other.lEstacion->avanzar();
			 }
		 }
 
	 else
		 {
		 this->lEstacion=nullptr;
		 }
	 }
 
 void Sistema::cargarUsuarios()
	 {
	 ifstream fEnt;
		 string linea,NombreCompleto,DNI,Correo,telefono,edad,numCuenta,saldo;
 
		 fEnt.open("ficheros/usuarios.csv");
		 if(fEnt.is_open())
			 {
				 getline(fEnt,linea);
 
				 while(!fEnt.eof())
				 {
 
 
					 getline(fEnt,NombreCompleto,';');
					 if(!fEnt.eof())
					 {
					 getline(fEnt,DNI,';');
					 getline(fEnt,Correo,';');
					 getline(fEnt,telefono,';');
					 getline(fEnt,edad,';');
					 getline(fEnt,numCuenta,';');
					 getline(fEnt,saldo);
 
					 lUsuarios->Insertar(NombreCompleto,telefono,stoi(edad),numCuenta,stof(saldo),DNI,Correo);
 
					 }
				 }
				 fEnt.close();
			 }
		 else
			 cout<< "No se pudo abrir el fichero"<<endl;

		 cout << "Usuarios cargados correctamente." << endl;
		 }
 
 
 void Sistema::insertarPatinete(string id,string marca,string modelo,bool averiado,bool disponible)
	 {
	 Patinete *P;
	 P=new Patinete(id,marca,modelo,averiado,disponible);
	 lPatinete->moverPrimero();
	 lPatinete->insertar(P);
	 }
 
 
 void Sistema::insertarEstacion(string id, string ubicacion)
	 {
	 Estacion *E;
	 E=new Estacion(id,ubicacion);
	 lEstacion->enUltimo();
	 lEstacion->insertar(E);
	 }
 
 void Sistema::cargarPatinetes()
	 {
	 ifstream fEnt;
		 string linea,id,marca,modelo,averiado,disponible;
		 bool Averiado,Disponible;
		 fEnt.open("ficheros/patinetes.csv");
		 if(fEnt.is_open())
			 {
				 getline(fEnt,linea);
				 while(!fEnt.eof())
				 {
					 getline(fEnt,id,';');
					 if(!fEnt.eof())
					 {
					 getline(fEnt,marca,';');
					 getline(fEnt,modelo,';');
					 getline(fEnt,averiado,';');
					 getline(fEnt,disponible);
					 Averiado=(averiado=="Si");
					 Disponible=(disponible=="Si");
 
					 insertarPatinete(id,marca,modelo,Averiado,Disponible);
					 }
				 }
				 fEnt.close();
			 }
		 else
			 cout<< "No se pudo abrir el fichero"<<endl;
		 }
 
 void Sistema::cargarEstacion()
	 {
	 ifstream fEnt;
		 string linea,id,ubicacion;

		 fEnt.open("ficheros/estaciones.csv");
		 if(fEnt.is_open())
			 {
				 getline(fEnt,linea);
 
				 while(!fEnt.eof())
				 {
					 getline(fEnt,id,';');
					 if(!fEnt.eof())
					 {
					 getline(fEnt,ubicacion);
					 insertarEstacion(id,ubicacion);
					 }
				 }
				 fEnt.close();
			 }
		 else
			 cout<< "No se pudo abrir el fichero"<<endl;
		 }
 
 
 
 bool Sistema::buscarUsuario(string DNI, Usuario *&usu)
	 {
	 bool enc;
	enc =lUsuarios->Buscar(DNI,usu);
	 return enc;
	 }
 bool Sistema::buscarPatinete(string IdPatinete,Patinete *&p)
 	 {
	 bool enc =false;
	 lPatinete->moverPrimero();
	 while(!lPatinete->alFinal()&& !enc)
	 	 {
		 if(lPatinete->consultar()->GetID()==IdPatinete)
		 	 {
			 p=lPatinete->consultar();
			 enc=true;
		 	 }
		 lPatinete->avanzar();
	 	 }
	 return enc;
 	 }
 bool Sistema::buscarEstacion(string IdEstacion,Estacion*&E)
 	 {
	 bool enc=false;
	 lEstacion->moverPrimero();
	 while(!lEstacion->alFinal()&& !enc)
	 	 {
		 if(lEstacion->consultar()->getId()==IdEstacion)
		 	 {
			 E=lEstacion->consultar();
			 enc=true;
		 	 }
		 lEstacion->avanzar();
	 	 }
	 return enc;
 	 }
 void Sistema::mostrarUsuarios(){
	 this->lUsuarios->Mostrar();
	cout<<"Hay "<<  this->lUsuarios->NumElementos()<<" Usuarios"<<endl;
 }
 
 void Sistema::mostrarPatinetes(){
	 Patinete *P=nullptr;
	 int nPatinetes=0;
	 lPatinete->moverPrimero();
	 while(!lPatinete->alFinal())
		 {
		 P=lPatinete->consultar();
		 P->Mostrar();
		 lPatinete->avanzar();
		 nPatinetes++;
		 }
	 cout<<"Hay "<<nPatinetes<<" Patinetes"<<endl;
 }
 
 void Sistema::mostrarEstacion(string idEstacion){
	 Estacion *E=nullptr;
	 lEstacion->moverPrimero();
	 while(!lEstacion->alFinal())
		 {
		 E=lEstacion->consultar();
		 if(E->getId()==idEstacion)
			 {
			 E->Mostrar();
			 break;
			 }
		 lEstacion->avanzar();
		 }
 }

 void Sistema::maxAlquiladosEstacion(){
	 Estacion *Max=nullptr;
	 Estacion *E=nullptr;
	 lEstacion->moverPrimero();
	 int max=0;
	 string idEstacion;
	 while(!lEstacion->alFinal())
		 {
		 E=lEstacion->consultar();
		 if(E->getNumeroAlquilados()>max)
			 {
			 max=E->getNumeroAlquilados();
			 Max=E;
			 }
		 lEstacion->avanzar();
		 }
	 if(Max!=nullptr)
		 {
		 Max->Mostrar();
		 cout<< "Ha alquilado: "<<max;
		 }
 }

 void Sistema::mostrarEstaciones(){
	 lEstacion->moverPrimero();
	 while(!lEstacion->alFinal())
		 {
		 lEstacion->consultar()->Mostrar();
		 lEstacion->avanzar();
		 }
 }

void Sistema::distribuirPatinetesEnEstaciones() {
	ifstream fEnt;
	string linea, idEstacion, idPatinete;
	fEnt.open("ficheros/distribucionPatinetes.csv");
	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, idPatinete, ';');
			if (!fEnt.eof()) {
				getline(fEnt, idEstacion);
				agregarPatineteEnEstacion(idPatinete, idEstacion);
			}
		}
		fEnt.close();
	} else {
		cout << "No se pudo abrir el fichero" << endl;
	}
}

void Sistema::alquilarDevolverUnPatinete(string EstacionAlquilar, string DNI,
		string EstacionDevolver) {
	Usuario *usu = nullptr;
	Patinete *P = nullptr;
	Estacion *EAlquilar = nullptr;
	Estacion *EDevolver=nullptr;
	if(buscarUsuario(DNI, usu)){
		if(usu->ConsultarSaldo() >= 10.0){
					if(buscarEstacion(EstacionAlquilar,EAlquilar))
						{EAlquilar->alquilarPatinete(usu,P);
						if(P!=nullptr)
						{
							usu->RetirarSaldo(10.0);
							cout << "Patinete alquilado con éxito. Saldo restante: " << usu->ConsultarSaldo() << endl;
							EAlquilar->setNumeroAlquilados();
								if (!buscarEstacion(EstacionDevolver,EDevolver)) {
												P->Mostrar();
												cout << "Patinete no devuelto, estación de devolucion no encontrada." << endl;
												if(usu->ConsultarSaldo() < 110.0)
													{
														cout << "Usuario con saldo insuficiente, será eliminado." << endl;
														P->Desalquilar();
														this->lUsuarios->Eliminar(DNI);
													}
												else
													{
														usu->RetirarSaldo(110.0);
														cout << "Usuario multado con 110€ por no devolver el patinete." << endl;
													}
												}
											else
												{
												EDevolver->Devolver(P);
												cout << "Patinete devuelto"<<endl;
												}
							}
						else
							cout<<"No hay patinetes disponibles en la estacion" <<endl;


			}
			else
				cout << "Estación  de alquiler no encontrada." << endl;

		}
		else
		{
			cout << "No tienes saldo suficiente para alquilar un patinete." << endl;
		}
	}

	else
		{
		cout << "Usuario no encontrado." << endl;
		}
}

void Sistema::alquilarDevolverPatinetes() {
	ifstream fEnt;
		string linea, idEstacionS, DNI,idEstacionD;
		fEnt.open("ficheros/alquilerPatinetes.csv");
		if (fEnt.is_open()) {
			getline(fEnt, linea);
			while (!fEnt.eof()) {
				getline(fEnt, idEstacionS, ';');
				if (!fEnt.eof()) {
					getline(fEnt,DNI,';');
					getline(fEnt, idEstacionD);
					alquilarDevolverUnPatinete(idEstacionS,DNI, idEstacionD);
				}
			}
			fEnt.close();
		} else {
			cout << "No se pudo abrir el fichero" << endl;
		}

}

void Sistema::repararPatinetesEstacion(string idEstacion) {
	Estacion *E = nullptr;
	if(buscarEstacion(idEstacion,E))
		{
		cout<<"Han sido reparados: " <<E->RepararPatinetes()<<" patientes"<<endl;

		}

}

void Sistema::buscarPatinetesExtraviados() {
	Patinete *P1 = nullptr;
	Estacion *E = nullptr;
	bool encontrado = false;
	lPatinete->moverPrimero();
	while (!lPatinete->alFinal()) {
		P1 = lPatinete->consultar();
		encontrado = false;
		lEstacion->moverPrimero();
		while (!lEstacion->alFinal() && !encontrado) {
			E = lEstacion->consultar();
			if (!E->BuscarPatinete(P1->GetID())) {
				lEstacion->avanzar();
			}
			else {
				encontrado = true;
			}
		}
		if(!encontrado) {
		cout<<"El patinete perdido es: "<<endl;
		P1->Mostrar();
		//Imprimir en el archivo "sistema.log" el nombre del patinete perdido, si no existe el archivo se crea
		ofstream archivo("ficheros/sistema.log", ios::app);
		if(archivo.is_open())
			{
			archivo << "Patinete perdido: " << P1->GetModelo() << endl;
			archivo.close();
			}
		else
			{
			cout << "No se pudo abrir el archivo sistema.log" << endl;
			}

		lPatinete->eliminar();
		}else {
			lPatinete->avanzar();
		}
	}
}

 Sistema::~Sistema() {
	 delete lUsuarios;
	 Patinete *P = nullptr;
	 if (lPatinete!=nullptr)
		 {
		 lPatinete->moverPrimero();
		 while(!lPatinete->estaVacia())
			 {
			 P = lPatinete->consultar();
			 delete P;
			 lPatinete->eliminar();
			 }
		 }
	 delete lPatinete;
	 Estacion *E = nullptr;
	 if (lEstacion!=nullptr)
		 {
		 lEstacion->moverPrimero();
		 while(!lEstacion->estaVacia())
			 {
			 E = lEstacion->consultar();
			 delete E;
			 lEstacion->eliminar();
			 }
		 }
	 delete lEstacion;
}

void Sistema::agregarPatineteEnEstacion(string idPatinete, string idEstacion) {
	Patinete *P = nullptr;
	Estacion *E = nullptr;
	if(buscarPatinete(idPatinete,P))
	{
		if(buscarEstacion(idEstacion,E))
			{
			E->agregarPatinete(P);
			}
		else
			cout<<"Estacion no encontrada"<<endl;

	}
	else
		cout<<"Patinete no encontrado"<<endl;
}
