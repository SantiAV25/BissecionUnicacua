#include <cmath>
#include <iostream>
#include <string>
#include "biseccion.h"

using std::cout;
using std::endl;
using std::string;

using raices::biseccion;
using raices::solucion;
using raices::aproximacion;
void caso_1();

int main() {
    caso_1();
    return 0;
}

void caso_1(){
    string funcstr = "e^(~x) - ln(x)";
    double xA,xB,erp;
    int n;
    solucion s;

    biseccion b(funcstr);
    xA = 1.0f;
    xB = 1.5f;
    erp = 1.0f;
    n = 20;

    s = b.encontrarRaiz(xA,xB,erp,n);
    if(std::isnan(s.raiz)){
        cout<<"Raiz no Econtrada en el intervalo"
        <<xA<<","<<xB<<endl;
    }else{
        cout <<"Raiz:" <<s.raiz<< endl;
        cout<<"Aproximaciones"<<endl;
        for (auto &a: s.aproximaciones) {
            cout<< a.xAnt  << "  "<< a.xNuv << "  " << a.erp<<endl;
        }
    }


}
