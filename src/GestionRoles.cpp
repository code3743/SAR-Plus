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

GestionRoles::~GestionRoles() {
	rolesDisponibles.clear();
}

void GestionRoles::crearRol() {
	string nombreRol;
	int baseSalarial;

	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Crear Rol", UiConsola::CENTER);
	uiConsola.leer(nombreRol, "Nombre de Rol: ", UiConsola::TAB);
	uiConsola.leer(baseSalarial, "Base Salarial: ", UiConsola::TAB);
	if (!existeRol(nombreRol)) {
		rolesDisponibles.push_back(Rol(nombreRol, baseSalarial));
		uiConsola.imprimirHecho("* Rol creado *", UiConsola::CENTER);
	}
	else uiConsola.imprimirError("* EL Rol ya existe *", UiConsola::CENTER);

	Sleep(600);
}
void GestionRoles::listaRoles() {
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Roles", UiConsola::TAB);
	if (rolesDisponibles.size() > 0) {
		for (int i = 0; i < rolesDisponibles.size(); i++) {
			uiConsola.imprimir(to_string(i + 1) + ". " + rolesDisponibles[i].getNombreRol() + " - " + to_string(rolesDisponibles[i].getBaseSalarial()), UiConsola::TAB);
		}
		system("pause");
	}
	else {
		uiConsola.imprimirAlerta("No hay roles creados", UiConsola::CENTER);
		Sleep(600);
	}
}

void GestionRoles::setRoles(vector<Rol> roles) {
	rolesDisponibles.clear();
	this->rolesDisponibles = roles;
}

vector<Rol> GestionRoles::getRoles() {

	return rolesDisponibles;
}

void GestionRoles::editarRol() {
	string nombreRol;
	int baseSalarial;
	int indexRol;
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Editar Roles", UiConsola::CENTER);
	
	for (int i = 0; i < rolesDisponibles.size(); i++) {
		uiConsola.imprimir(to_string(i + 1) + ". " + rolesDisponibles[i].getNombreRol() + " - " + to_string(rolesDisponibles[i].getBaseSalarial()), UiConsola::TAB);
	}

	uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);
	if (indexRol > 0 && indexRol <= rolesDisponibles.size()) {
		uiConsola.leer(nombreRol, "nuevo Nombre: ", UiConsola::TAB);
		uiConsola.leer(baseSalarial, "nuevo Base Salarial: ", UiConsola::TAB);
		if (!existeRol(nombreRol)) {
			rolesDisponibles[indexRol - 1].setNombreRol(nombreRol);
			rolesDisponibles[indexRol - 1].setBaseSalarial(baseSalarial);
			uiConsola.imprimirHecho("* Rol editado *", UiConsola::CENTER);
		}
		else uiConsola.imprimirError("* Nombre de rol en uso *", UiConsola::CENTER);
	}
	else uiConsola.imprimirError("Rol no valido", UiConsola::CENTER);
	Sleep(600);
}

void GestionRoles::eliminarRol() {
	int indexRol;
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Eliminar Roles", UiConsola::CENTER);

	for (int i = 0; i < rolesDisponibles.size(); i++) {
		uiConsola.imprimir(to_string(i + 1) + ". " + rolesDisponibles[i].getNombreRol() + " - " + to_string(rolesDisponibles[i].getBaseSalarial()), UiConsola::TAB);
	}

	uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);
	if (indexRol > 0 && indexRol <= rolesDisponibles.size()) {
		rolesDisponibles.erase(rolesDisponibles.begin() + (indexRol - 1));
		uiConsola.imprimirHecho("* Rol eliminado *", UiConsola::CENTER);
	}
	else uiConsola.imprimirError("Rol no valido", UiConsola::CENTER);
	Sleep(600);
}

bool GestionRoles::existeRol(string nombreRol) {
	for (int i = 0; i < rolesDisponibles.size(); i++) {
		if (rolesDisponibles[i].getNombreRol() == nombreRol) return true;
	}
	return false;
}

bool GestionRoles::finalizarConfigRoles() {
	if (rolesDisponibles.size()> 0) {
		for (int i = 0; i < rolesDisponibles.size(); i++) {
			db.agregarRol(rolesDisponibles[i]);
		}
		return true;
	}

	uiConsola.imprimirAlerta("* Debe crear por lo menos un rol *", UiConsola::CENTER);
	Sleep(600);
	return false;
}