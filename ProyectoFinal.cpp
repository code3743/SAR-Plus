#include <iostream>
#include "Definiciones.h"

using namespace std;

int main()
{
	CheckConfig checkConfig;
	Login login;
	
	while (true) {
		if (checkConfig.configuracionCompleta()) {
			login.iniciarSesion();
			break;
		}
		else if (!configurarSistema()) break;
	}
	return 0;
}