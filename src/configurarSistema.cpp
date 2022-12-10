#include <iostream>

#include "Definiciones.h"
#include "GestionEmpleados.h"
#include "GestionRoles.h"
#include "Usuario.h"

using namespace std;


UiConsola& uiConsola = UiConsola::getIntancia();
DataBase& db = DataBase::getInstancia();
GestionRoles gestionRoles;
GestionEmpleados gestionEmpleados;

bool configurarSistema() {
	ConfiguracionModelDB nuevaConfig;
	string nombre, nit;
	bool crearEmpleados;
	uiConsola.imprimir("Bienvenido", UiConsola::CENTER);
	uiConsola.imprimir("-----------------------", UiConsola::CENTER);
	uiConsola.imprimirInfo("Configuracion del Sistema", UiConsola::CENTER);
	uiConsola.espacio();
	uiConsola.leer(nombre, "Nombre de la empresa: ", UiConsola::CENTER);
	uiConsola.leer(nit, "Nit: ", UiConsola::CENTER);
	nuevaConfig = ConfiguracionModelDB(nombre, nit, true);
	try {
		if (!crearUsuarioAdministrador()) throw "No se pudo crear el administrador";
		gestionRoles.menuRoles();
		uiConsola.borrarPantalla();
		uiConsola.leerDesicion(crearEmpleados, "Desea agregar empleados");
		if (crearEmpleados) {
			gestionEmpleados.menuEmpleados();
		}
		uiConsola.borrarPantalla();
		uiConsola.espacio();
		uiConsola.barraProgreso(100, 100);
		uiConsola.imprimirHecho("* Guardado exitosamente *", UiConsola::CENTER);
		db.setConfiguracionSistema(nuevaConfig);
		Sleep(400);
		return true;
	}
	catch (const char* error) {
		uiConsola.imprimirError(error, UiConsola::CENTER);
	}

	return false;
}


bool crearUsuarioAdministrador() {

	string nombre, apellido, documento, telefono, contrasenna;

	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Perfil Administrador", UiConsola::CENTER);
	uiConsola.leer(nombre, "Nombre: ", UiConsola::CENTER);
	uiConsola.leer(apellido, "Apellido: ", UiConsola::CENTER);
	uiConsola.leer(documento, "Documento: ", UiConsola::CENTER);
	uiConsola.leer(telefono, "Telefono: ", UiConsola::CENTER);
	uiConsola.leer(contrasenna, "Contrasena: ", UiConsola::CENTER);

	try
	{
		return db.escribirUsuario(Usuario(nombre, apellido, telefono, documento, contrasenna, true));
	}
	catch (...)
	{
		return false;
	
	}
}
	
