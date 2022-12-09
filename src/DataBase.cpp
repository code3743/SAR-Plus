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

void DataBase::cargarRoles() {
	ifstream archivoDB;
	if (!establecerConexionDB(rutaRoles, archivoDB, DataBase::Leer))	throw "No se puede establecer conexion";

	string datosTemp;
	string nombre, baseSalario;

	while (getline(archivoDB, datosTemp)) {

		stringstream token(datosTemp);
		getline(token, nombre, ';');
		getline(token, baseSalario, ';');
		
		rolesDisponibles.push_back(Rol(nombre, stoi(baseSalario)));
	}
	cerrarConexionDB(archivoDB);
}



void DataBase::cargarEmpleados() {
	ifstream archivoDB;
	if (!establecerConexionDB(rutaEmpleados, archivoDB, DataBase::Leer))	throw "No se puede establecer conexion";

	string datosTemp;
	string nombre, apellido, documento, telefono, rol, fecha;

	while (getline(archivoDB, datosTemp)) {
		stringstream token(datosTemp);
		getline(token, nombre, ';');
		getline(token, apellido, ';');
		getline(token, documento, ';');
		getline(token, telefono, ';');
		getline(token, rol, ';');
		getline(token, fecha, ';');
		Empleado empleado = Empleado(nombre, apellido, telefono, documento, rol, fecha);
		empleados.push_back(empleado);
	}
	cerrarConexionDB(archivoDB);
}

void DataBase::cargarUsuariosAdministracion() {
	ifstream archivoDB;
	if (!establecerConexionDB(rutuaUsers, archivoDB, DataBase::Leer))	throw "No se puede establecer conexion";
	string datosTemp;
	string nombre, apellido, documento, telefono, contrasenna;
	while (getline(archivoDB, datosTemp)) {
		stringstream token(datosTemp);
		getline(token, nombre, ';');
		getline(token, apellido, ';');
		getline(token, telefono, ';');
		getline(token, documento, ';');
		getline(token, contrasenna, ';');
		
		Usuario user;
		user.setNombre(nombre);
		user.setApellido(apellido);
		user.setTelefono(telefono);
		user.setDocumento(documento);
		user.setContrasenna(contrasenna);

		usuariosAdministradores.push_back(user);
	}
	cerrarConexionDB(archivoDB);
}

void DataBase::agregarRol(Rol nuevoRol) {
	ofstream archivoDB;
	if (!establecerConexionDB(rutaRoles, archivoDB, DataBase::Escribir)) throw "Fue imposible guardar la configuracion";

	archivoDB << nuevoRol.getNombreRol() << ";";
	archivoDB << nuevoRol.getBaseSalarial() << endl;

	rolesDisponibles.push_back(nuevoRol);

	cerrarConexionDB(archivoDB);
}



void DataBase::agreagarEmpleado(Empleado empleado) {
	ofstream archivoDB;
	if (!establecerConexionDB(rutaEmpleados, archivoDB, DataBase::Escribir)) throw "Fue imposible guardar la configuracion";

	archivoDB << empleado.getNombre() << ";";
	archivoDB << empleado.getApellido() << ";";
	archivoDB << empleado.getDocumento() << ";";
	archivoDB << empleado.getTelefono() << ";";
	archivoDB << empleado.getRol() << ";";
	archivoDB << empleado.getFechaVinculacion() << endl;

	empleados.push_back(empleado);

	cerrarConexionDB(archivoDB);
}

vector<Rol> DataBase::listaRolesDisponibles() {
	return rolesDisponibles;
}

vector<Empleado> DataBase::listaEmpleados() {
	return empleados;
}

vector<Usuario> DataBase::listaUsuarios() {
	return usuariosAdministradores;
}



bool DataBase::escribirUsuario(Usuario user) {
	ofstream archivoDB;
	if (!establecerConexionDB(rutuaUsers, archivoDB, DataBase::Escribir))	throw "No se puede establecer conexion";
	archivoDB << user.getNombre() << ";" << user.getApellido() << ";" << user.getTelefono() << ";" << user.getDocumento() << ";" << user.getContrasenna() << endl;
	cerrarConexionDB(archivoDB);
	
	usuariosAdministradores.push_back(user);

	return true;
}

bool DataBase::existeUsuario(string documento) {
	for (int i = 0; i < usuariosAdministradores.size(); i++) {
		if (documento == usuariosAdministradores[i].getDocumento())
			return true;
	}
	return false;
}

bool DataBase::existeEmpleado(string documento) {
	for (int i = 0; i < empleados.size(); i++) {
		if (documento == empleados[i].getDocumento())
			return true;
	}
	return false;
}

Usuario  DataBase::getUsuarioPorDocumento(string documento){
	for (int i = 0; i < usuariosAdministradores.size(); i++) {
		if (documento == usuariosAdministradores[i].getDocumento())
			return usuariosAdministradores[i];
	}
	throw "No se encontro el usuario";
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

