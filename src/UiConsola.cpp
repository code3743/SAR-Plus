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

void UiConsola::barraCargando(int valorActual, int valorMaximo){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    int porcentaje = 0;
    if(valorActual <= valorMaximo){
     porcentaje = (valorActual * 100) / valorMaximo;
     //20 caracteres 100 porciento de la barra
     int porcentajeBarra = (porcentaje * 20 )/ 100;
     for(int i=0; i<= porcentajeBarra; i++){
        cout<<"=";
        Sleep(170);
     }
     SetConsoleTextAttribute(hConsole, 8);
     for(int i = porcentajeBarra; i<= 20; i++){
        cout<<"=";
        Sleep(150);
     }
    SetConsoleTextAttribute(hConsole, 13);
     cout<<" "<<porcentaje<<" %"<<endl;
    }
    else imprimirError("El valor actual supera el 100%");

}

