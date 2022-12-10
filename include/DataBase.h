#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "ConfiguracionModelDB.h"
#include "Usuario.h"
#include "Rol.h"
#include <vector>
#include "Empleado.h"

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
	void actualizarEmpleados(vector<Empleado>);

	void cargarRoles();
	void agregarRol(Rol);
	void actualizarRoles(vector<Rol>);

	bool existeUsuario(string);
	bool existeEmpleado(string);
	void actualizarUsuario(Usuario);
	void eliminarUsuario(int);
	Usuario getUsuarioPorDocumento(string);
	
	vector<Rol>listaRolesDisponibles();
	vector<Usuario> listaUsuarios();
	vector<Empleado> listaEmpleados();

private:
	DataBase();

	const enum tipoConexion {
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