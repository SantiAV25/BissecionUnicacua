//
// Created by agred on 13/03/2023.
//

#ifndef REGLAFALSA_REGLAFALSA_H
#define REGLAFALSA_REGLAFALSA_H
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include "Expression.h"
#include "raices.h"

using std::string;
/**
 * @file
 * @brief Metodo de biseccion
 * @author Santiago Agredo <sagredov@unicauca.edu.co>
 */
/**
 *@brief Raices de ecuaciones de una variable
 */
namespace raices {


    /**
     * @brief Metodo de biseccion
     */
    class reglafalsa {
    public:
        /**
         * @brief
         *
         */
        reglafalsa(string funcstr):f(funcstr){

        }

        solucion encontrarRaiz(double xI, double xS, double erp, int n) {



            solucion s; //Instancia de solucion

            //Paso1
            int i = 1;
            //Paso2
            double xAnterior = xS -((f(xS)*(xI-xS))/(f(xI)-f(xS)));
            s.raiz = NAN;

            //Primera Aproximación
            if(f(xI)*f(xAnterior)>0.0f){
                xI = xAnterior;
            }else{
                xS=xAnterior;
            }

            //paso3
            while(i<= n){
                //paso 4 nueva aproximacion
                double  xNueva =  xS -((f(xS)*(xI-xS))/(f(xI)-f(xS)));
                double er = fabs((xNueva-xAnterior)/xNueva) * 100.0f;
                s.aproximaciones.push_back({xAnterior,xNueva,er});
                //paso 5
                if(er < erp){
                    s.raiz = xNueva;
                    return s;
                }
                //paso 6
                ++i;
                //paso 7
                if(f(xI)*f(xNueva)>0.0f){
                    xI = xNueva;
                }else{
                    xS=xNueva;
                }

                xAnterior = xNueva;
            }


            return s;
        }

    private:
        Expression f;
    };
}

#endif //REGLAFALSA_REGLAFALSA_H
