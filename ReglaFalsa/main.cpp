#include <cmath>
#include <iostream>
#include <string>
#include "biseccion.h"
#include "reglafalsa.h"
#include "raices.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setprecision;
using raices::biseccion;
using raices::solucion;
using raices::aproximacion;
using raices::reglafalsa;
void caso_1();

int main() {
    caso_1();
    return 0;
}

void caso_1(){
    string funcstr = "e^(~x) - ln(x)";
    double xInf,xSup,erp;
    int n;

    biseccion b(funcstr);
    xInf = 1.0f;
    xSup = 1.5f;
    erp = 1.0f;
    n = 20;

    solucion solucionBiseccion = b.encontrarRaiz(xInf,xSup,erp,n);
    if(std::isnan(solucionBiseccion.raiz)){
        cout<<"Raiz no Econtrada en el intervalo"
            <<xInf<<","<<xSup<<endl;
    }else{
        cout <<"Raiz:" <<solucionBiseccion.raiz<< endl;
        cout<<"Aproximaciones"<<endl;
        cout << setw(15) <<"Valor Inical"
            << setw(15)<<"Valor Final"
            << setw(15)<<"ERP"
            <<endl;
        for (auto &a: solucionBiseccion.aproximaciones) {
            cout<< setw(15)<< setprecision(8) << a.xAnt  <<setw(15) << setprecision(8) << a.xNuv << setw(15) << setprecision(8) << a.erp<<endl;
        }

        cout<<"Numero de aproximaciones:"<< solucionBiseccion.cantAproximaciones()<<endl;
    }

    cout<<"==========================================================="<<endl;
    reglafalsa fr(funcstr);

    solucion solucionReglaFalsa = fr.encontrarRaiz(xInf,xSup,erp,n);
    if(std::isnan(solucionReglaFalsa.raiz)){
        cout<<"Raiz no Econtrada en el intervalo"
            <<xInf<<","<<xSup<<endl;
    }else{
        cout <<"Raiz:" <<solucionReglaFalsa.raiz<< endl;
        cout<<"Aproximaciones"<<endl;
        for (auto &a: solucionReglaFalsa.aproximaciones) {
            cout<< a.xAnt  << "  "<< a.xNuv << "  " << a.erp<<endl;
        }

        cout<<"Numero de aproximaciones:"<< solucionReglaFalsa.cantAproximaciones()<<endl;
    }


}

