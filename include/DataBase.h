#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConfiguracionModelDB.h"



using namespace std;

class DataBase
{
public:
	static DataBase& getInstancia();
	DataBase(const DataBase&) = delete;
	DataBase& operator = (const DataBase&) = delete;

	ConfiguracionModelDB getConfiguraciones();
	void setConfiguracionSistema(ConfiguracionModelDB);
	bool inicializarConfiguracion();
	void guardarProducto();
	void consultarProducto();


private:
	DataBase();

    enum tipoConexion {
		Leer, Escribir, SobreEscribir
	};


	bool establecerConexionDB(string, ifstream&, int);
	void cerrarConexionDB(ifstream&);
	bool establecerConexionDB(string, ofstream&, int);
	void cerrarConexionDB(ofstream&);
	string rutaEmpleadosDB = "./db/administracion.csv";
	string rutaConfiguraciones = "./db/config.csv";

	ConfiguracionModelDB configuracionInicial;
};

#endif
