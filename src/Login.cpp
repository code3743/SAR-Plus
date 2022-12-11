#include "Login.h"



void Login::iniciarSesion(){
	while (true) {
		uiConsola.borrarPantalla();
		uiConsola.espacio();
		uiConsola.imprimirInfo(db.getConfiguraciones().getNombreNegocio(), UiConsola::CENTER);
		uiConsola.imprimirInfo(" S I S T E M A   D E  M A R C A C I O N ", UiConsola::CENTER);
		uiConsola.espacio();
		uiConsola.imprimirAlerta("Escribir Salir o S  para cerrar", UiConsola::TAB);
		uiConsola.espacio();
		uiConsola.leer(documento, "Documento: ", UiConsola::CENTER);

		if (documento == "Salir" || documento == "S" || documento == "s") break;
		if (db.existeUsuario(documento)) {

			uiConsola.leer(contrasenna, "Ingrese la contrasena: ", UiConsola::CENTER);

			if (db.getUsuarioPorDocumento(documento).getContrasenna() == contrasenna) {
				dashBoard.inicio(db.getUsuarioPorDocumento(documento));
			}
			else {
				uiConsola.espacio();
				uiConsola.imprimirError("* Contrasena incorrecta *", UiConsola::CENTER);
				Sleep(600);
			}
		}
		else {
			if(db.existeEmpleado(documento))
			for (int i = 0; i < db.listaEmpleados().size(); i++) {
				if (db.listaEmpleados()[i].getDocumento() == documento) {
                    uiConsola.espacio();
					uiConsola.imprimirInfo("Hora: " + marcacion.ingresarCedula(db.listaEmpleados()[i]), UiConsola::CENTER);
					uiConsola.imprimir("Bienvenido " + db.listaEmpleados()[i].getNombre() + "  " + db.listaEmpleados()[i].getApellido(), UiConsola::CENTER);
					uiConsola.imprimirInfo("Feliz Jornada", UiConsola::CENTER);
					Sleep(800);
				}
			}
			else {
				uiConsola.espacio();
				uiConsola.imprimirError("* No se encontro el Documento, verifiquelo *", UiConsola::CENTER);
				Sleep(600);
			}
		}
	}
}
