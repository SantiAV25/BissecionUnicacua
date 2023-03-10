#include <iostream>
#include <string>
#include "biseccion.h"

using std::cout;
using std::endl;
using std::string;

using raices::biseccion;
void caso_1();

int main() {
    caso_1();
    return 0;
}

void caso_1(){
    string funcstr = "e^(~x) - ln(x)";
    double xA,xB,erp;
    int n;
    biseccion b(funcstr);
    xA = 1.0f;
    xB = 1.5f;
    erp = 1.0f;
    n = 20;

    cout<<b.encontrarRaiz(xA,xB,erp,n)<<endl;


}
