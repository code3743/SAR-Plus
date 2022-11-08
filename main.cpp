#include <iostream>
#include <string>
#include "UiConsola.h"


using namespace std;



int main()
{
    // UiConsola::barraProgreso(80, 120);

    /*
    UiConsola::imprimirError("Inutil");
    UiConsola::imprimirHecho("Inutil");
    UiConsola::imprimirInfo("Inutil");
    UiConsola::imprimirAlerta("Inutil");
    */
    int i = 0;
    string mensaje = "";
    UiConsola::leer(i,"Valor de i: ");
    UiConsola::leer(mensaje, "Ingrese el mensaje: ");
    UiConsola::imprimir(mensaje);

    return 0;
}
