#ifndef GESTIONEMPLEADOS_H
#define GESTIONEMPLEADOS_H

#include <iostream>
#include "DataBase.h"
#include "UiConsola.h"
#include <vector>
#include "Empleado.h"
#include "Fecha.h"
#include <string>

class GestionEmpleados {

public:

	void menuEmpleados();
	void crearEmpleados();
	void listarEmpleados();
	void editarEmpleado();
	void eliminarEmpleado();

private:
	UiConsola& uiConsola = UiConsola::getIntancia();
	bool existeEmpleado(string);
	void mostrarEmpleado(Empleado);
	DataBase& db = DataBase::getInstancia();
	vector<Empleado> empleados;

};


#endif