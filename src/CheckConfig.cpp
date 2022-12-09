#include "CheckConfig.h"
#include "UiConsola.h"


bool CheckConfig::configuracionCompleta() {
	try
	{
		if (db.inicializarConfiguracion()) {
			if (db.getConfiguraciones().getEstado()) {
				db.cargarEmpleados();
				db.cargarRoles();
				db.cargarUsuariosAdministracion();
				return true;
			}
		}
	}
	catch (const char* error)
	{
		uiConsola.espacio();
		uiConsola.imprimirError("* No se puedo establecer conexion con la Base de Datos *", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.imprimirError("Mesnaje de Error: " +(string)error, UiConsola::CENTER);
		uiConsola.espacio();
		
	}
	return false;
}