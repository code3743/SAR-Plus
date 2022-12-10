#include "GestionRoles.h"


void GestionRoles::menuRoles() {


	string opciones[] = { "Crear Rol","Lista de roles", "Editar rol", "Eliminar Rol", "Finalizar" };
	int opt = 0;
	string nombreRol;
	int baseSalarial;
	int indexRol;
	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.imprimir("Configuracion de roles", UiConsola::CENTER);
		uiConsola.menuOpciones(opciones, 5);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);

		switch (opt)
		{
		case 1:
			crearRol();
			break;
		case 2:
			listaRoles();
			break;
		case 3:
			editarRol();
			break;
		case 4:
			eliminarRol();
			break;
		case 5:
			if (finalizarConfigRoles()) return;
			break;
		default:
			uiConsola.imprimirError("Opcion invalida", UiConsola::CENTER);
			Sleep(600);
			break;
		}
	}
}

void GestionRoles::crearRol() {
	string nombreRol;
	int baseSalarial;

	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Crear Rol", UiConsola::CENTER);
	uiConsola.leer(nombreRol, "Nombre de Rol: ", UiConsola::TAB);
	uiConsola.leer(baseSalarial, "Base Salarial: ", UiConsola::TAB);
	if (roles.crearRol(nombreRol, baseSalarial))
		uiConsola.imprimirHecho("* Rol creado *", UiConsola::CENTER);
	else uiConsola.imprimirError("* EL Rol ya existe *", UiConsola::CENTER);

	Sleep(600);
}
void GestionRoles::listaRoles() {
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Roles", UiConsola::TAB);
	if (roles.totalRoles() > 0) {
		uiConsola.menuOpciones(roles.listadoRoles(), roles.totalRoles());
		system("pause");
	}
	else {
		uiConsola.imprimirAlerta("No hay roles creados", UiConsola::CENTER);
		Sleep(600);
	}
}

void GestionRoles::setRoles(vector<Rol> roles) {
	this->roles = Roles(roles);
}

vector<Rol> GestionRoles::getRoles() {

	return roles.getRoles();
}

void GestionRoles::editarRol() {
	string nombreRol;
	int baseSalarial;
	int indexRol;
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Editar Roles", UiConsola::CENTER);
	uiConsola.menuOpciones(roles.listadoRoles(), roles.totalRoles());
	uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);
	if (indexRol > 0 && indexRol <= roles.totalRoles()) {

		uiConsola.leer(nombreRol, "nuevo Nombre: ", UiConsola::TAB);
		uiConsola.leer(baseSalarial, "nuevo Base Salarial: ", UiConsola::TAB);
		if (roles.editarRol(indexRol - 1, nombreRol, baseSalarial))
			uiConsola.imprimirHecho("* Rol editado *", UiConsola::CENTER);
		else uiConsola.imprimirError("* Nombre de rol en uso *", UiConsola::CENTER);
	}
	else uiConsola.imprimirError("Rol no valido", UiConsola::CENTER);
	Sleep(600);
}

void GestionRoles::eliminarRol() {
	int indexRol;
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Eliminar Roles", UiConsola::CENTER);
	uiConsola.menuOpciones(roles.listadoRoles(), roles.totalRoles());
	uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);
	if (indexRol > 0 && indexRol <= roles.totalRoles()) {
		roles.eliminarRol(indexRol - 1);
		uiConsola.imprimirHecho("* Rol eliminado *", UiConsola::CENTER);
	}
	else uiConsola.imprimirError("Rol no valido", UiConsola::CENTER);
	Sleep(600);
}

bool GestionRoles::finalizarConfigRoles() {
	if (roles.totalRoles() > 0) {
		for (int i = 0; i < roles.totalRoles(); i++) {
			db.agregarRol(roles.getRoles()[i]);
		}
		return true;
	}

	uiConsola.imprimirAlerta("* Debe crear por lo menos un rol *", UiConsola::CENTER);
	Sleep(600);
	return false;
}