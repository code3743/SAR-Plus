#include <iostream>
#include "Definiciones.h"

using namespace std;



int main()
{	
	CheckConfig checkConfig = CheckConfig(DataBase::getInstancia());
	while (true) {
		if (checkConfig.configuracionCompleta()) {

			//Marcar ingreso
			//Ingresar cedula
			cout << "Configurado";
			break;
		}
		else {
			if (!configurarSistema()) break;
		}
	}
	
	return 0;
}


