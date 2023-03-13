//
// Created by agred on 13/03/2023.
//

#ifndef REGLAFALSA_RAICES_H
#define REGLAFALSA_RAICES_H

#include <cfloat>
#include <cmath>
#include <vector>
#include <string>


using std::vector;

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

    };

}

#endif //REGLAFALSA_RAICES_H
