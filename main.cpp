#include <iostream>
#include <string>
#include "UiConsola.h"

using namespace std;

#define menuOpt(opciones)  UiConsola::menuOpciones(opciones,sizeof(opciones)/sizeof(opciones[0]));
#define borrarPantalla()      UiConsola::borrarPantalla();
#define leer(dato, mensaje) UiConsola::leer(dato,mensaje);
#define imprimir(mensaje) UiConsola::imprimir(mensaje);
#define imprimirInfo(mensaje) UiConsola::imprimirInfo(mensaje);
#define imprimirError(mensaje) UiConsola::imprimirError(mensaje);
#define imprimirAlerta(mensaje) UiConsola::imprimirAlerta(mensaje);
#define imprimirHecho(mensaje) UiConsola::imprimirHecho(mensaje);
#define barraProgreso(valorActual, valorMaximo) UiConsola::barraProgreso(valorActual, valorMaximo);

bool init();
void iniciar();
int main()
{

    init();

    return 0;
}

void iniciar(){
    string nombre;
    string apellido;
    string email;
    string documento;
    string nombreNegocio;
    imprimir("Configuraciones");
    imprimirInfo("Configuracion del usuario");
    imprimirInfo("-------------------------");
    leer(nombre, "Nombre: ");
    leer(apellido, "Apellido: ");
    leer(documento, "N. Documento: ");
    imprimirInfo("Configuracion del usuario");
    imprimirInfo("-------------------------");
    leer(nombreNegocio,"Nombre del restaurante: ");
    barraProgreso(100,100);
    imprimirHecho("Usuario creado");

}

bool init(){
    bool inicializado = false;
    int opt = 0;
    string opciones[] = {"Iniciar","Soporte", "Salir"};
    while(opt != 3){
        imprimir("***** Bienvenido ******");
        imprimirInfo("Configuracion del sistema SAR+");
        menuOpt(opciones);
        leer(opt,"Opcion: ");

        switch(opt){
        case 1:
            borrarPantalla();
            iniciar();
            break;
        case 2:
            borrarPantalla();
            break;
        case 3:
            borrarPantalla();
            break;
        default:
            borrarPantalla();
            imprimirError("Opcion Invalida");

            break;
        }
    }
    return false;

}
