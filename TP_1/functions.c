#include <stdio.h>

/** \brief Suma dos numeros enteros o flotantes.
*
*\param Dos numeros flotantes.
*\return Entero 0.
*
*/
float suma (float A, float B){
    float resultado;
    resultado = A + B;
    return resultado;
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Resta dos numeros enteros o flotantes.
*
*\param Dos numeros flotantes.
*\return Entero 0.
*
*/
float resta (float A, float B){
    float resultado;
    resultado = A - B;
    return resultado;
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Divide dos numeros enteros o flotantes.
*
*\param Dos numeros flotantes.
*\return resultado.
*
*/
float division (float A, float B){
    float resultado;
    resultado = (float) ((A) / (B));

    return resultado;
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Multiplica dos numeros enteros o flotantes.
*
*\param Dos numeros flotantes.
*\return Entero 0.
*
*/
float multiplicacion (float A, float B){
    float resultado;
    resultado = (float) A * B;

    return resultado;
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Realiza el factoreo de un numero entero.
*
*\param Un numero entero.
*\return Entero 0.
*
*/
float factorial (float A){
    int factorial=1;
    int contador;
    for (contador=1; contador <= A; contador++)
    {
        factorial = factorial * contador;
    }
    return factorial;
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Muestra el menu de opciones con los numeros ingresados.
*
*\param A Numero flotante.
*\param B Numero flotante.
*
*/
void menu_A(float A, float B)
{
    printf("//////////CALCULADORA//////////\n");
    printf("[1]- Ingresar 1er operando (A=%.1f)\n", A);
    printf("[2]- Ingresar 2do operando (B=%.1f)\n", B);
    printf("[3]- Calcular todas las operaciones\n");
        printf("\t a) Calcular la suma (A+B)\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
    printf("[4]- Informar resultados\n");
        printf("\t a) Calcular la suma (A+B)\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
    printf("[5]- Salir\n");
}

/* --------------------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------------------- */

/** \brief Muestra el resultado de las operaciones mencionadas en el menu A.
*
*\param numero1 Operando A
*\param numero2 Operando B
*\param suma resultado de la suma de A+B
*\param resta resultado de la resta de A-B
*\param division resultado de la division de A/B
*\param multiplicacion resultado de la multiplicacion de A*B
*\param factorialA resultado del factorial de A
*\param factorialB resultado del factorial de B
*
*/

void menu_B(float suma, float resta, float division, float multiplicacion, float factorialA, float factorialB, float numero1, float numero2)
{
    printf("A = %.2f \t B = %.2f\n\n", numero1, numero2);
    printf("El resultado de A+B es: %.2f \n\n", suma);
    printf("El resultado de A-B es: %.2f \n\n", resta);
    if(numero2==0)
    {
        printf("No es posible dividir por cero \n\n");
    }else
    {
        printf("El resultado de A/B es: %.2f \n\n", division);
    }
    printf("El resultado de A*B es: %.2f \n\n", multiplicacion);

    if ( (numero1 - (int)numero1 == 0) && numero1>=0 )
    {
        printf("El factorial de A es: %.10f ", factorialA);
    }else
    {
        printf("A es negativo o fraccionario - ");
    }

    if ( (numero2 - (int)numero2 == 0) && numero2>=0 )
    {
        printf("y el factorial de A es: %.10f ", factorialB);
    }else
    {
        printf("B es negativo o fraccionario\n");
    }
}

