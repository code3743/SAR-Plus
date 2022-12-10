#ifndef PANELADMINISTRATIVO_H
#define PANELADMINISTRATIVO_H

#include "DataBase.h"
#include "GestionEmpleados.h"
#include "GestionRoles.h"
#include "UiConsola.h"
#include "Usuario.h"

class PanelAdministrativo: public GestionEmpleados, GestionRoles {
public:

	void inicio(Usuario);
	

	void generarExtractoMensualEmpleado();
	void generarTotalNominas();
	void indiceDeProductividad();

private:

	void menuAdministrativo(Usuario);
	void menuAdministrador(Usuario);

	void menuGestionAdministrativa();
	void menuGestionEmpleados();
	void menuGestionGerenciales();
	void perfilAdministrativo(Usuario);
	void mostrarInformacionUsuario(Usuario);

	UiConsola& uiConsola = UiConsola::getIntancia();
	DataBase& db = DataBase::getInstancia();
};

#endif