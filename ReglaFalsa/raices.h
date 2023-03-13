//
// Created by agred on 13/03/2023.
//

#ifndef REGLAFALSA_RAICES_H
#define REGLAFALSA_RAICES_H

#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>



using std::vector;
using std::setw;
using std::setprecision;

namespace raices {
/**
     * @brief Aproximacion de una raiz
     */
    struct aproximacion {
        double xAnt; /*!< valor de  la aproximacion*/
        double xNuv;
        double erp; /*!<Error Relativo porcentual*/

    };

/**
 * @brief Solucion de metodo de raices
 */
    struct solucion {
        double raiz = NAN; /*!<Raiz encontrada (NAN  si no se encontro)*/
        vector <aproximacion> aproximaciones;

        /**
         * @brief Determina si la solucion existe
         */
         bool existe(){
            return (!std::isnan(raiz));
         }
         /**
          * @brief function que retonar la cantidad aproximaciones realizadas
          * @return Cantidad Aproximaciones
          */
         int cantAproximaciones(){
             return  aproximaciones.size();
         }

    };

}

#endif //REGLAFALSA_RAICES_H
