#include "UiConsola.h"

using namespace std;

void UiConsola::borrarPantalla(){
        system("cls");
        imprimir("");
}

void UiConsola::imprimir(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 7);
    if(mensaje != "")
        cout<<mensaje<<endl;
}


void UiConsola::imprimirPersonalizado(int color, string mensaje, bool saltoLinea){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, color);
    if(mensaje != "")
        cout<<mensaje<<((saltoLinea) ? " \n" : " ");
}

void UiConsola::imprimirError(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 4);
    if(mensaje != "")
        cout<<mensaje<<endl;
}

void UiConsola::imprimirAlerta(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 14);
    if(mensaje != "")
        cout<<mensaje<<endl;
}

void UiConsola::imprimirHecho(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 10);
    if(mensaje != "")
        cout<<mensaje<<endl;
}

void UiConsola::imprimirInfo(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 3);
    if(mensaje != "")
        cout<<mensaje<<endl;
}

void UiConsola::barraCargando(float totalPorcentaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);

}

