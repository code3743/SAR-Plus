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

protected:

	void crearEmpleados();
	void listarEmpleados();
	void editarEmpleado();
	void eliminarEmpleado();
	void setEmpleados(vector<Empleado>);
	vector<Empleado> getEmpleados();

private:
	UiConsola& uiConsola = UiConsola::getIntancia();
	DataBase& db = DataBase::getInstancia();
	vector<Empleado> empleados;
	
	bool existeEmpleado(string);
	void mostrarEmpleado(Empleado);

};


#endif