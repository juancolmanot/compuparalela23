//
// solver.h versión juan
//

#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

void dens_step(unsigned int n, float* x, float* x0, float* u, float* v, float diff, float dt);
void vel_step(unsigned int n, float* u, float* v, float* u0, float* v0, float visc, float dt);

#endif /* SOLVER_H_INCLUDED */

/*
============================================================================

El protocolo ifndef previene la doble inclusión del encabezado en el código
principal .c. 

============================================================================

La idea de declarar ambas funciones simplemente permite limpiar el código central.

============================================================================

Las variables declaradas para las funciones son las siguientes y sus características son:
    - unsigned int n: tamaño de la grilla, almacenada en un entero sin signo, puesto que es un entero
      siempre positivo, por lo que se ahorra el espacio de memoria para el signo.
    - float* (...): puntero hacia x para empezar a almacenar las diferentes cantidades
      en la grilla, es una dirección de memoria donde se almacenará un arreglo de 
      (n+1)*(n+1) elementos.
    - float (...): almacena memoria de punto flotante.
*/