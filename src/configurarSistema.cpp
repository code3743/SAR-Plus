#include "Definiciones.h"
#include <iostream>


using namespace std;


UiConsola& uiConsola = UiConsola::getIntancia();

bool configurarSistema() {
	DataBase& db = DataBase::getInstancia();
	ConfiguracionModelDB nuevaConfig;
	string nombre, nit;

	uiConsola.imprimir("Bienvenido", UiConsola::CENTER);
	uiConsola.imprimir("-----------------------", UiConsola::CENTER);
	uiConsola.imprimir("Configuracion del Sistema", UiConsola::CENTER);
	uiConsola.imprimir("", 1);
	uiConsola.imprimirError("* No se pudo establecer *", UiConsola::CENTER);
	//uiConsola.mostrarColoresDisponibles();
	system("pause");
	nuevaConfig = ConfiguracionModelDB(nombre, nit, true);
	try {
		db.setConfiguracionSistema(nuevaConfig);
		/*barraProgreso(100, 100);
		imprimirHecho("Guardado exitosamente");*/
		return true;
	}
	catch (const char* error) {
		/*imprimirError(error);*/
	}

	return false;
}


bool crearUsuarioAdministrador() {
	//borrarPantalla();
	//imprimirInfo("Perfil Administrador");

	return true;
}
