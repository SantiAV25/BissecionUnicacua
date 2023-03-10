//
// Created by agred on 10/03/2023.
//

#ifndef BISECCION_SAGREDOV_BISECCION_H
#define BISECCION_SAGREDOV_BISECCION_H
#include <cfloat>
#include <cmath>

#include <string>
#include "Expression.h"

using std::string;
/**
 * @file
 * @brief Metodo de biseccion
 * @author Santiago Agredo <sagredov@unicauca.edu.co>
 */
/**
 *@brief Raices de ecuaciones de una variable
 */
namespace raices{
    /**
     * @brief Metodo de biseccion
     */
    class  biseccion{
    public:
        /**
         * @brief
         *
         */
        biseccion(string funcstr):f(funcstr){

        }
        /**
         * @brief Encuentra la raiz en un intervalo dado
         * @param xA Extremo inferior del intervalo
         * @param Xb Extremo Superiro del intervalo
         * @param erp Error Relativo Porcentual
         * @param n  Maximo de interaciones
         * @return Valor de la raiz,NAN si no se logra encontrar
         */

        double encontrarRaiz(double xA, double xB, double erp, int n){

            //Paso1
            int i = 1;
            //Paso2
            double xAnterior = (xA + xB)/2.0f;

            //Primera Aproximación
            if(f(xA)*f(xAnterior)>0.0f){
                xA = xAnterior;
            }else{
                xB=xAnterior;
            }

            //paso3
            while(i<= n){
                //paso 4 nueva aproximacion
                double  xNueva = (xA + xB)/2.0f;
                double er = fabs((xNueva-xAnterior)/xNueva) * 100.0f;
                //paso 5
                if(er < erp){
                    return xNueva;
                }
                //paso 6
                ++i;
                //paso 7
                if(f(xA)*f(xNueva)>0.0f){
                    xA = xNueva;
                }else{
                    xB=xNueva;
                }

                xAnterior = xNueva;
            }


            return NAN;

        }

    private:
        Expression f;
    };
};
#endif //BISECCION_SAGREDOV_BISECCION_H
