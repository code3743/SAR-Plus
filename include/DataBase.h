#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "ConfiguracionModelDB.h"
#include "Empleado.h"
#include "Usuario.h"
#include "Rol.h"

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

	bool escribirUsuario(Usuario);
	void cargarUsuariosAdministracion();

	void agreagarEmpleado(Empleado);
	void cargarEmpleados();

	void cargarRoles();
	void agregarRol(Rol);

	bool existeUsuario(string);
	bool existeEmpleado(string);

	Usuario getUsuarioPorDocumento(string);

	vector<Rol>listaRolesDisponibles();
	vector<Usuario> listaUsuarios();
	vector<Empleado> listaEmpleados();

private:
	DataBase();

	enum tipoConexion {
		Leer, Escribir, SobreEscribir
	};


	bool establecerConexionDB(string, ifstream&, int);
	bool establecerConexionDB(string, ofstream&, int);
	void cerrarConexionDB(ifstream&);
	void cerrarConexionDB(ofstream&);

	string rutaEmpleados = "./db/empleados.csv";
	string rutuaUsers = "./db/users.csv";
	string rutaConfiguraciones = "./db/config.csv";
	string rutaRoles = "./db/roles.csv";

	ConfiguracionModelDB configuracionInicial;
	vector<Rol> rolesDisponibles;
	vector<Usuario> usuariosAdministradores;
	vector<Empleado> empleados;
};

#endif