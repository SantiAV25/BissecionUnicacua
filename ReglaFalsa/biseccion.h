//
// Created by agred on 10/03/2023.
//

#ifndef BISECCION_SAGREDOV_BISECCION_H
#define BISECCION_SAGREDOV_BISECCION_H
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
         * @return Solucion que contiene la Raiz y las aproximaciones
         */

        solucion encontrarRaiz(double xA, double xB, double erp, int n){

            solucion s; //Instancia de solucion

            //Paso1
            int i = 1;
            //Paso2
            double xAnterior = (xA + xB)/2.0f;
            s.raiz = NAN;

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
                s.aproximaciones.push_back({xAnterior,xNueva,er});
                //paso 5
                if(er < erp){
                    s.raiz = xNueva;
                    return s;
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


            return s;

        }

    private:
        Expression f;
    };
};
#endif //BISECCION_SAGREDOV_BISECCION_H
