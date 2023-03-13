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

            return s;
        }

    private:
        Expression f;
    };
}

#endif //REGLAFALSA_REGLAFALSA_H
