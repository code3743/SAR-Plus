#ifndef PANELADMINISTRATIVO_H
#define PANELADMINISTRATIVO_H

#include "GestionEmpleados.h"
#include "GestionRoles.h"

class PanelAdministrativo: public GestionEmpleados, GestionRoles {
public:
	PanelAdministrativo();
	
	void listaEmpleados();
	void buscarEmpleado();
	void agregarEmpleado();
	void generarExtractoMensualEmpleado();
	
	void generarTotalNominas();
	void indiceDeProductividad();

};

#endif