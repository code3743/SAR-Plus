#include "PanelAdministrativo.h"


void PanelAdministrativo::inicio(Usuario user) {
		if (user.esAdmin()) {
			menuAdministrativo(user);
		}
		else {
			menuAdministrador(user);
		}	
}

void PanelAdministrativo::menuAdministrativo(Usuario user) {

	string opciones[] = { "Gestion Administrativa", "Gestion Gerencial", "Gestion de Empleados","Perfil","Salir"};
	int opt;

	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.espacio();
		uiConsola.imprimir("B I E N V E N I D O", UiConsola::CENTER);
		uiConsola.imprimir("S i s t e m a   d e   G e s t i o n   I n t e r n o", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.imprimir("Usuario: " + user.getNombre() + " " + user.getApellido(), UiConsola::TAB);
		uiConsola.imprimirInfo("Adminsitrador Global", UiConsola::TAB);
		uiConsola.espacio();

		uiConsola.menuOpciones(opciones, 5);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
		switch (opt)
		{
		case 1:
			menuGestionAdministrativa();
			break;
		case 2:
			menuGestionGerenciales();
			break;
		case 3:
			menuGestionEmpleados();
			break;
		case 4:
			perfilAdministrativo(user);
			break;
		case 5:
			return;
		default:
			uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}
	}
	
}

void PanelAdministrativo::menuAdministrador(Usuario user) {
	string opciones[] = {"Gestion Gerencial", "Gestion de Empleados", "Perfil", "Salir"};
	int opt;

	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.espacio();
		uiConsola.imprimir("B I E N V E N I D O", UiConsola::CENTER);
		uiConsola.imprimir("S i s t e m a   d e   G e s t i o n   I n t e r n o", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.imprimir("Usuario: " + user.getNombre() + " " + user.getApellido(), UiConsola::TAB);
		uiConsola.imprimirInfo("Adminsitrador", UiConsola::TAB);
		uiConsola.espacio();
		uiConsola.menuOpciones(opciones, 4);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
		switch (opt)
		{
		case 1:
			menuGestionGerenciales();
			break;
		case 2:
			menuGestionEmpleados();
			break;
		case 3:
			perfilAdministrativo(user);
			break;
		case 4:
			return;
		default:
			uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}
	}
}

void PanelAdministrativo::menuGestionAdministrativa() {
	string nombre, apellido, documento, telefono, contrasenna;
	bool esAdmin = false;
	int indexUsuario;
	string opciones[] = { "Lista de Administradores","Agregrar Administrador","Eliminar Administrador", "Atras"};
	int opt;
	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.imprimirInfo("Menu Administrativo", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.menuOpciones(opciones, 4);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
		switch (opt) {
		case 1:
			uiConsola.borrarPantalla();
			uiConsola.imprimirInfo("Lista de Administradores", UiConsola::CENTER);
			uiConsola.espacio();
			for (int i = 0; i < db.listaUsuarios().size(); i++) {
				uiConsola.imprimir(to_string(i + 1) + ". " + db.listaUsuarios()[i].getNombre()
					+ " - " + db.listaUsuarios()[i].getDocumento() + " - " + 
					(db.listaUsuarios()[i].esAdmin() ? "Administrador Global" : "Administrador"), UiConsola::TAB);
			}
			uiConsola.espacio();
			system("pause");
			break;
		case 2:
			uiConsola.borrarPantalla();
			uiConsola.imprimirInfo("Agregar Administrador", UiConsola::CENTER);
			uiConsola.espacio();
			uiConsola.leer(nombre, "Nombre: ", UiConsola::CENTER);
			uiConsola.leer(apellido, "Apellido: ", UiConsola::CENTER);
			uiConsola.leer(documento, "Documento: ", UiConsola::CENTER);
			uiConsola.leer(telefono, "Telefono: ", UiConsola::CENTER);
			uiConsola.leer(contrasenna, "Contrasena: ", UiConsola::CENTER);
			uiConsola.leerDesicion(esAdmin, "Todos los permisos?");
			if (db.existeUsuario(documento)) {
				uiConsola.espacio();
				uiConsola.imprimirError("* El Documiento ya esta registrado *", UiConsola::CENTER);
			}
			else {
				db.escribirUsuario(Usuario(nombre, apellido, telefono, documento, contrasenna, esAdmin));
				uiConsola.espacio();
				uiConsola.imprimirHecho("* Usuario Creado *", UiConsola::CENTER);
			}
			Sleep(600);
			break;
		case 3:
			uiConsola.borrarPantalla();
			uiConsola.imprimirInfo("Perfil Eliminar", UiConsola::CENTER);
			uiConsola.espacio();
			uiConsola.leer(indexUsuario, "Numero Usuario: ", UiConsola::TAB);
			if (indexUsuario > 0 && indexUsuario <= db.listaUsuarios().size()) {
				uiConsola.borrarPantalla();
				mostrarInformacionUsuario(db.listaUsuarios()[indexUsuario - 1]);
				bool eliminar;
				uiConsola.leerDesicion(eliminar, "Eliminar el Usuario?");
				if (eliminar) {
					db.eliminarUsuario(indexUsuario);
					uiConsola.espacio();
					uiConsola.imprimirHecho("* Usuario Eliminado *", UiConsola::CENTER);
				}
				else {
					uiConsola.espacio();
					uiConsola.imprimirAlerta("*Operacion Cancelada*", UiConsola::CENTER);
				}
				
			}
			else {
				uiConsola.espacio();
				uiConsola.imprimirError("* El Usuario no existe *", UiConsola::CENTER);
			}
			Sleep(600);
			break;
		case 4:
			return;
		default:
			uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}

	}
}

void PanelAdministrativo::menuGestionGerenciales() {
	setRoles(db.listaRolesDisponibles());
	string opciones[] = { "Nivel de Productividad","Crear Rol","Lista Roles","Editar Rol" , "Atras"};
	int opt;
	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.imprimirInfo("Opciones Gerenciales", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.menuOpciones(opciones, 5);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);

		switch (opt)
		{
		case 1:
		
			break;
		case 2:
			crearRol();
			break;
		case 3:
			listaRoles();
			break;
		case 4:
			editarRol();
			break;
		case 5:
			db.actualizarRoles(getRoles());
			return;
		default:uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}
	}
}
void PanelAdministrativo::menuGestionEmpleados(){
	string opciones[] = { "Crear Empleado","Lista Empleados", "Editar Empleado", "Atras" };
	int opt;
	
	setEmpleados(db.listaEmpleados());
	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.imprimirInfo("Control de Empleados", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.menuOpciones(opciones, 4);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
		switch (opt)
		{
		case 1:
			crearEmpleados();
			break;
		case 2:
			listarEmpleados();
			break;
		case 3:
			editarEmpleado();
			break;
		case 4:
			db.actualizarEmpleados(getEmpleados());
			return;
		default:uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}
	}
}

void PanelAdministrativo::perfilAdministrativo(Usuario user) {

	string opciones[] = {"Cambiar contrasenna","Atras"};
	string contrasenna, nuevaContrasenna;
	int opt;
	while (true) {
		uiConsola.borrarPantalla();
		mostrarInformacionUsuario(user);
		uiConsola.menuOpciones(opciones, 2);
		uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
		switch (opt)
		{
		case 1:
			uiConsola.borrarPantalla();
			uiConsola.imprimirInfo("Cambiar Contrasenna", UiConsola::CENTER);
			uiConsola.leer(contrasenna, "Contrasenna Actual: ", UiConsola::TAB);
			if (contrasenna == user.getContrasenna()) {
				uiConsola.leer(nuevaContrasenna, "Contrasenna Nueva: ", UiConsola::TAB);
				user.setContrasenna(nuevaContrasenna);
				db.actualizarUsuario(user);
				uiConsola.imprimirHecho("* Contrasenna Actualizada *", UiConsola::CENTER);
			}
			else {
				uiConsola.espacio();
				uiConsola.imprimirError("* Contrasenna Incorrecta *", UiConsola::CENTER);
			}
			Sleep(600);
			break;
		case 2:
			return;
		default:
			uiConsola.espacio();
			uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
			Sleep(600);
			break;
		}

	}

}


void PanelAdministrativo::mostrarInformacionUsuario(Usuario user) {
	uiConsola.espacio();
	uiConsola.imprimirInfo("Perfil", UiConsola::CENTER);
	uiConsola.imprimir("Nombre: " + user.getNombre(), UiConsola::TAB);
	uiConsola.imprimir("Apellido: " + user.getApellido(), UiConsola::TAB);
	uiConsola.imprimir("Documeto: " + user.getDocumento(), UiConsola::TAB);
	uiConsola.imprimir("Telefono:  " + user.getTelefono(), UiConsola::TAB);
	uiConsola.espacio();
}


