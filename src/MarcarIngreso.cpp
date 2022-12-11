#include "MarcarIngreso.h"


string MarcarIngreso::ingresarCedula(Empleado empleado) {
    /*

    guardar hora y registrarlo a la base de datos

    */


	return obtenerFechaHoraActual();
}

string MarcarIngreso::obtenerFechaHoraActual(){

    char tiempo[100];
    time_t ahora = time(nullptr);
    auto tiempoInfo = localtime(&ahora);

    strftime(tiempo, 100, "%Y-%m-%d %H:%M:%S", tiempoInfo);
    return tiempo;
}
