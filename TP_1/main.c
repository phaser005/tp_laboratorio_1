#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    char seguir='s';
    char option='x';
    float numero1=0, numero2=0;
    float R_SUMA, R_RESTA, R_MULTIPLICACION, R_DIVISION, FACTORIAL_A, FACTORIAL_B;

    while(seguir=='s')
    {
        system("cls");
        menu_A(numero1, numero2);
        option = getch();

        switch(option)
        {
            case '1':
                printf("\nIngrese el primer operando: ");
                scanf("%f", &numero1);
                break;
            case '2':
                printf("\nIngrese el segundo operando: ");
                scanf("%f", &numero2);
                break;
            case '3':
                R_SUMA = suma(numero1, numero2);
                R_RESTA = resta(numero1, numero2);
                if(numero2!=0)
                {
                    R_MULTIPLICACION = multiplicacion(numero1, numero2);
                }
                R_DIVISION = division(numero1, numero2);
                FACTORIAL_A = factorial(numero1);
                FACTORIAL_B = factorial(numero2);
                printf("\nSe han realizado las operaciones.\n");
                system("pause");
                break;
            case '4':
                system("cls");
                menu_B(R_SUMA,R_RESTA, R_DIVISION, R_MULTIPLICACION, FACTORIAL_A, FACTORIAL_B, numero1, numero2);
                system("pause");
                break;
            case '5':
                seguir = 'n';
                break;
        }//SWITCH TERMINATE

    }//WHILE TERMINATE

    return 0;
}//MAIN TERMINATE
