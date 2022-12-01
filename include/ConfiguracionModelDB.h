#ifndef CONFIGURACIONMODELDB_H
#define CONFIGURACIONMODELDB_H

#include <iostream>

using namespace std;

class ConfiguracionModelDB
{

public:
	string getNombreNegocio();
	string getNIT();
	bool getEstado();
	
	void setNIT();
	void setNombreNegocio();
	
	void setNIT(string);
	void setNombreNegocio(string);

	void setEstado();
	void setEstado(bool);

	ConfiguracionModelDB(string, string, bool);
	ConfiguracionModelDB();
private:
	string nombreNegocio;
	string NIT;
	bool estado;
};

#endif
