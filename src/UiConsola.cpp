#include "UiConsola.h"
#include <string>

#define color(miColor) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), miColor);

using namespace std;

UiConsola::UiConsola() {

}

UiConsola& UiConsola::getIntancia() {
    static UiConsola uiConsola;
    return uiConsola;
}

void UiConsola::borrarPantalla(){
        color(7)
        system("cls");
        saltoLinea = 1;
}

void UiConsola::imprimir(string mensaje, int alineador){
    color(7);
    espaciadores(alineador, mensaje);
    if(mensaje != "")
        cout<<mensaje<<endl;
}

void UiConsola::espaciadores(int alineador, string texto){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.Y= saltoLinea;
    switch(alineador){
    case CENTER:
        dwPos.X = 60 - (texto.length() / 2);
        break;
    case LEFT:
        dwPos.X = 2;
        break;
    case RIGHT:
        dwPos.X = 120 - texto.length();
        break;
    case TAB:
        dwPos.X = 4;
        break;
    }
    saltoLinea++;
    SetConsoleCursorPosition(hcon,dwPos);
}


void UiConsola::imprimirPersonalizado(int color, string mensaje, bool saltoLinea, int alineado){
    espaciadores(alineado, mensaje);
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, color);
    if(mensaje != "")
        cout<<mensaje<<((saltoLinea) ? " \n" : " ");
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::imprimirError(string mensaje, int alineador){
    color(4);
   
    espaciadores(alineador, mensaje);
    if(mensaje != "")
        cout<<mensaje<<endl;
     color(7);
}

void UiConsola::mostrarColoresDisponibles() {
    HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 1; i < 245; i++) cout << SetConsoleTextAttribute(han, i)<< " Numero: " << i << endl;
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
     cout<<" ";
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
     cout<<" "<<porcentaje<<" %"<<endl;
    }
    else imprimirError("El valor actual supera el 100%", 1);
    SetConsoleTextAttribute(hConsole, 7);
}

void UiConsola::leer(int& valor, string mensaje){
    cout<<mensaje;
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, 13);
    cin>>valor;
    SetConsoleTextAttribute(hConsole, 7);

}

void UiConsola::leerDesicion(bool& valor, string mensaje) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int valorTemp;
    cout << mensaje << endl;
    cout << " 1.";
    SetConsoleTextAttribute(hConsole, 10);
    cout << " Si" << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "2.";
    SetConsoleTextAttribute(hConsole, 4);
    cout << " No" << endl;
    cout << "Opcion: ";
    cin >> valorTemp;
    valor = (valorTemp == 1);
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


void UiConsola::menuOpciones(string opciones[], int totalOpciones){


    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    for(int i= 0; i< totalOpciones; i++){
        SetConsoleTextAttribute(hConsole, 13);
        cout<<(i + 1)<<". ";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<opciones[i]<<endl;
    }

}
