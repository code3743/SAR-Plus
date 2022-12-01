#include "CheckConfig.h"
#include "UiConsola.h"

CheckConfig::CheckConfig(DataBase& db):db{ db } {

}


bool CheckConfig::configuracionCompleta() {
	try
	{
		if (db.inicializarConfiguracion()) {
			return db.getConfiguraciones().getEstado();
		}
	}
	catch (const char* error)
	{
		
	}
	return false;
}