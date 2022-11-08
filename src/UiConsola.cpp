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
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::imprimirError(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 4);
    if(mensaje != "")
        cout<<mensaje<<endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::imprimirAlerta(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 6);
    if(mensaje != "")
        cout<<mensaje<<endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::imprimirHecho(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 10);
    if(mensaje != "")
        cout<<mensaje<<endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::imprimirInfo(string mensaje){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 3);
    if(mensaje != "")
        cout<<mensaje<<endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::barraProgreso(int valorActual, int valorMaximo){
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    int porcentaje = 0;
    int porcentajeBarra = 0;
    if(valorActual <= valorMaximo){
     porcentaje = (valorActual * 100) / valorMaximo;
     porcentajeBarra = (porcentaje * 20 )/ 100;
     cout<<"| ";
     for(int i=1; i<= porcentajeBarra; i++){
        cout<<"=";
        Sleep(170);
     }
     SetConsoleTextAttribute(hConsole, 8);
     for(int i = porcentajeBarra; i< 20; i++){
        cout<<"=";
        Sleep(150);
     }
    SetConsoleTextAttribute(hConsole, 13);
     cout<<" "<<porcentaje<<" %"<<" |"<<endl;
    }
    else imprimirError("El valor actual supera el 100%");
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::leer(int& valor, string mensaje){
    cout<<mensaje;
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    cin>>valor;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::leer(double& valor, string mensaje){
    cout<<mensaje;
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    cin>>valor;
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::leer(string& valor, string mensaje){
    cout<<mensaje;
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    fflush(stdin);
    getline(cin, valor);
    SetConsoleTextAttribute(hConsole, 7);
}
