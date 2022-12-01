#include "DataBase.h"


DataBase::DataBase() {

}


DataBase& DataBase::getInstancia() {
	static DataBase db;
	return db;
}


void DataBase::setConfiguracionSistema(ConfiguracionModelDB config) {
	ofstream archivoDB;
	if (!establecerConexionDB(rutaConfiguraciones, archivoDB, DataBase::SobreEscribir)) throw "Fue imposible guardar la configuracion";
	
	archivoDB << config.getNombreNegocio() << ";";
	archivoDB << config.getNIT() << ";";
	archivoDB << config.getEstado() << endl;

	configuracionInicial = config;
	cerrarConexionDB(archivoDB);
}

ConfiguracionModelDB DataBase::getConfiguraciones() {
	return configuracionInicial;
}

bool DataBase::inicializarConfiguracion() {
	ifstream archivoDB;
	if (!establecerConexionDB(rutaConfiguraciones, archivoDB, DataBase::Leer))	throw "No se puede establecer conexion";
	
	string datosTemp;

	string nombre, nit, estado;

	while (getline(archivoDB, datosTemp)) {

		stringstream token(datosTemp);

		getline(token, nombre, ';');
		getline(token, nit, ';');
		getline(token, estado, ';');
	}
	cerrarConexionDB(archivoDB);
	configuracionInicial = ConfiguracionModelDB(nombre, nit, (estado == "1"));
	return true;
}

bool DataBase::establecerConexionDB(string rutaDB, ifstream& archivoDB, int tipoConexion) {
	switch (tipoConexion)
	{
	case 0:
		archivoDB = ifstream(rutaDB, ios::in);
		break;
	case 1:
		archivoDB = ifstream(rutaDB, ios::app);
		break;
	case 2:
		archivoDB = ifstream(rutaDB, ios::out);
		break;
	default:
		archivoDB = ifstream(rutaDB, ios::in);
		break;
	}
	return archivoDB.is_open();
}
bool DataBase::establecerConexionDB(string rutaDB, ofstream& archivoDB, int tipoConexion) {
	switch (tipoConexion)
	{
	case 0:
		archivoDB = ofstream(rutaDB, ios::in);
		break;
	case 1:
		archivoDB = ofstream(rutaDB, ios::app);
		break;
	case 2:
		archivoDB = ofstream(rutaDB, ios::out);
		break;
	default:
		archivoDB = ofstream(rutaDB, ios::in);
		break;
	}
	return archivoDB.is_open();
}

void DataBase::cerrarConexionDB(ofstream& archivoDB) {
	archivoDB.close();
}
void DataBase::cerrarConexionDB(ifstream& archivoDB) {
	archivoDB.close();
}