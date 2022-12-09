#include "GestionEmpleados.h"

void GestionEmpleados::menuEmpleados() {

		int opt = 0;
		string opciones[] = { "Crear Empleado","Lista Empleados", "Editar Empleado", "Eliminar Empleado", "Finalizar" };

		while (true) {
			uiConsola.borrarPantalla();
			uiConsola.imprimir("Creacion de empledos", UiConsola::CENTER);
			uiConsola.espacio();
			uiConsola.menuOpciones(opciones, 5);
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
				eliminarEmpleado();
				break;
			case 5:
				for (int i = 0; i < empleados.size(); i++) {
					db.agreagarEmpleado(empleados[i]);
				}
				uiConsola.borrarPantalla();
				return;
			default:
				uiConsola.imprimirError("Opcion invalida", UiConsola::CENTER);
				Sleep(600);
				break;
			}
		}
	
}

void GestionEmpleados::crearEmpleados(){
	bool guardar;
	string nombre, apellido, documento, telefono;
	int indexRol;
	Empleado empleado;
	Fecha fechaVinculacion;
	int dia, mes, anio;

	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Agregar Empleado", UiConsola::CENTER);
	uiConsola.espacio();
	uiConsola.leer(nombre, "Nombre: ", UiConsola::TAB);
	uiConsola.leer(apellido, "Apellido: ", UiConsola::TAB);
	uiConsola.leer(documento, "Documento: ", UiConsola::TAB);
	if (existeEmpleado(documento)) {
		uiConsola.imprimirError("* Ya se encuentra registrado un empleado con ese documento * ", UiConsola::CENTER);
		Sleep(600);
		return;
	}

	uiConsola.leer(telefono, "Telefono: ", UiConsola::TAB);
	uiConsola.imprimirInfo("Eliga un rol", UiConsola::TAB);
	uiConsola.espacio();

	for (int i = 0; i < db.listaRolesDisponibles().size(); i++) {
		uiConsola.imprimir(to_string(i +1)+ ". " + db.listaRolesDisponibles()[i].getNombreRol(), UiConsola::TAB);
	}

	while (true) {
		uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);
		if (indexRol > 0 && indexRol <= db.listaRolesDisponibles().size()) break;
		else uiConsola.imprimirError("* Rol no valido *", UiConsola::TAB);
	}

	uiConsola.imprimirInfo("Fecha de vinculacion", UiConsola::TAB);
	uiConsola.leer(dia, "Dia: ", UiConsola::TAB);
	uiConsola.leer(mes, "Mes: ", UiConsola::TAB);
	uiConsola.leer(anio, "Año: ", UiConsola::TAB);

	fechaVinculacion = Fecha(dia, mes, anio);
	
	empleado.setNombre(nombre);
	empleado.setApellido(apellido);
	empleado.setDocumento(documento);
	empleado.setTelefono(telefono);
	empleado.setRol(db.listaRolesDisponibles()[indexRol - 1].getNombreRol());
	empleado.setFechaVinculacion(fechaVinculacion);
	uiConsola.borrarPantalla();
	mostrarEmpleado(empleado);
	uiConsola.leerDesicion(guardar, "Guardar");
	if (guardar) {
		uiConsola.espacio();
		empleados.push_back(empleado);
		uiConsola.imprimirHecho("* Empleado Agregado *", UiConsola::CENTER);
	}
	else {
		uiConsola.espacio();
		uiConsola.imprimirAlerta("* Operacion Cancelada *", UiConsola::CENTER);
	}
	Sleep(600);
}


bool GestionEmpleados::existeEmpleado(string documento) {
	for (int i = 0; i < empleados.size(); i++) {
		if (documento == empleados[i].getDocumento()) return true;
	}
	return false;
}

void GestionEmpleados::mostrarEmpleado(Empleado empleado) {
	uiConsola.espacio();
	uiConsola.imprimir("Nombre: " + empleado.getNombre(), UiConsola::TAB);
	uiConsola.imprimir("Apellido: " + empleado.getApellido(), UiConsola::TAB);
	uiConsola.imprimir("Documento: " + empleado.getDocumento(), UiConsola::TAB);
	uiConsola.imprimir("Telefono: " + empleado.getTelefono(), UiConsola::TAB);
	uiConsola.imprimir("Rol: " + empleado.getRol(), UiConsola::TAB);
	uiConsola.imprimir("Fecha Vinculacion: " + empleado.getFechaVinculacion(), UiConsola::TAB);
	uiConsola.espacio();
}

void GestionEmpleados::listarEmpleados(){
	
	uiConsola.borrarPantalla();

	uiConsola.imprimirInfo("Lista de empleados", UiConsola::CENTER);
	uiConsola.imprimirInfo("Nombre - Documento", UiConsola::CENTER);
	uiConsola.espacio();
	for (int i = 0; i < empleados.size(); i++) {
		uiConsola.imprimir(to_string(i + 1) + ". " + empleados[i].getNombre() + " - " + empleados[i].getDocumento(), UiConsola::TAB);
	}
	system("pause");
}

void GestionEmpleados::editarEmpleado(){
	int indexEmpleado;
	
	string opcionesEditar[] = {"Editar Nombre", "Editar Apellido", "Editar Documento","Editar Telefono","Editar Rol","Editar Fecha de Vinculacion", "Finalizar"};
	
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Editar Empleado", UiConsola::CENTER);
	uiConsola.espacio();
	uiConsola.leer(indexEmpleado, "Numero de Empleado: ", UiConsola::TAB);
	if (indexEmpleado > 0 && indexEmpleado <= empleados.size()) {
		int opt;
		string nombre, apellido, documento, rol, telefono;
		int dia, mes, anio;
		int indexRol;
		Fecha nuevaFecha;
		while (true) {
			uiConsola.borrarPantalla();
			mostrarEmpleado(empleados[indexEmpleado - 1]);
			uiConsola.menuOpciones(opcionesEditar, 7);
			uiConsola.leer(opt, "Opcion: ", UiConsola::TAB);
			switch (opt)
			{
			case 1:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar Nombre", UiConsola::TAB);
				uiConsola.leer(nombre, "Nuevo Nombre: ", UiConsola::TAB);
				empleados[indexEmpleado - 1].setNombre(nombre);
				uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				Sleep(600);
				break;
			case 2:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar Apellido", UiConsola::TAB);
				uiConsola.leer(apellido, "Nuevo Apellido: ", UiConsola::TAB);
				empleados[indexEmpleado - 1].setApellido(apellido);
				uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				Sleep(600);
				break;
			case 3:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar	Documento", UiConsola::TAB);
				uiConsola.leer(documento, "Nuevo documento: ", UiConsola::TAB);
				if (existeEmpleado(documento)) {
					uiConsola.imprimirError("* El documento ya existe *", UiConsola::CENTER);
					break;
				}
				empleados[indexEmpleado - 1].setDocumento(documento);
				uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				Sleep(600);
				break;
			case 4:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar Telefono", UiConsola::TAB);
				uiConsola.leer(telefono, "Nuevo Telefono: ", UiConsola::TAB);
				empleados[indexEmpleado - 1].setTelefono(telefono);
				uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				Sleep(600);
				break;
			case 5:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar Rol", UiConsola::TAB);
				for (int i = 0; i < db.listaRolesDisponibles().size(); i++) {
					uiConsola.imprimir(to_string(i + 1) + ". " + db.listaRolesDisponibles()[i].getNombreRol(), UiConsola::TAB);
				}
				uiConsola.leer(indexRol, "Numero Rol: ", UiConsola::TAB);

				if (indexRol > 0 && indexRol <= db.listaRolesDisponibles().size()) {
					empleados[indexEmpleado - 1].setRol(db.listaRolesDisponibles()[indexRol - 1].getNombreRol());
					uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				}else uiConsola.imprimirError("* Rol no dispinible *", UiConsola::CENTER);
				
				Sleep(600);
				break;
			case 6:
				uiConsola.borrarPantalla();
				uiConsola.imprimirInfo("Editar Fecha", UiConsola::TAB);
				uiConsola.leer(dia, "Dia: ", UiConsola::TAB);
				uiConsola.leer(mes, "Mes: ", UiConsola::TAB);
				uiConsola.leer(anio, "Año: ", UiConsola::TAB);
				nuevaFecha = Fecha(dia, mes, anio);
				empleados[indexEmpleado - 1].setFechaVinculacion(nuevaFecha);
				uiConsola.imprimirHecho("* Empleado actualizado *", UiConsola::TAB);
				Sleep(600);
				break;
			case 7:
				return;
			default:
				uiConsola.imprimirError("* Opcion invalida *", UiConsola::CENTER);
				break;
			}
		}
	}
	else uiConsola.imprimirError("* El empleado no existe *", UiConsola::CENTER);
	Sleep(600);
}

void GestionEmpleados::eliminarEmpleado(){
	bool confirmacion;
	int indexEmpleado;
	uiConsola.borrarPantalla();
	uiConsola.imprimirInfo("Borrar Empleado", UiConsola::CENTER);
	uiConsola.espacio();
	uiConsola.leer(indexEmpleado, "Numero de Empleado: ", UiConsola::TAB);
	if (indexEmpleado > 0 && indexEmpleado <= empleados.size()) {
		mostrarEmpleado(empleados[indexEmpleado - 1]);
		uiConsola.leerDesicion(confirmacion, "¿Eliminar Empleado?");
		if (confirmacion) {
			empleados.erase(empleados.begin() + (indexEmpleado - 1));
			uiConsola.imprimirHecho("* Empleado Eliminado *", UiConsola::CENTER);
		}
		else uiConsola.imprimirAlerta("* Operacion Cancelada *", UiConsola::CENTER);

	}else uiConsola.imprimirError("* El empleado no existe *", UiConsola::CENTER);

	Sleep(600);

}