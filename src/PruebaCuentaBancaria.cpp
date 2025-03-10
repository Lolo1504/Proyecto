#include "PruebaCuentaBancaria.h"
using namespace std;
#include <iostream>

void PruebaCuentaBancaria()
	{
	cout << "Inicio Pruebas Cuenta Bancaria"<<endl;
	CuentaBancaria *cB1;
	cB1=new CuentaBancaria();
	cB1 ->IngresarSaldo(100);

	CuentaBancaria *cB2;
	cB2 =new CuentaBancaria("JGalGot23", 10000);
	cB2->Mostrar();

	CuentaBancaria *cB3;
	cB3=new CuentaBancaria(*cB2);

	if (cB2->GetNumeroCuenta()!= "JGalGot23")
		{
		cout << "Error a en el Get numero de cuenta "<<endl;
		}
	if (cB3->GetSaldo()!=10000 )
		{
		cout << "Error en el Get Saldo "<<endl;
		}
	cB1->SetNumeroCuenta("JTrejChasis69");
	if(cB1->GetNumeroCuenta()!="JTrejChasis69")
		{
		 cout <<"Error a la hora de usar el set numero cuenta o get numero cuenta  " <<endl;
		}
	cB1->IngresarSaldo(1500);
	if(cB1->GetSaldo()!= 1600)
		{
			cout << "Error a la hora de usar el ingresar saldo y "<<endl;
		}
	delete cB1;
	delete cB2;
	delete cB3;
	cout << "Fin pruebas Cuenta Bancaria"<<endl;
	}
