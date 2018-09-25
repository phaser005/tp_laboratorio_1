#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define CANT 1000

int main()
{
    Employee employeeList[CANT];
    int flag = 0;
    int exit = 0;
    char option = 'x';

    initEmployees(employeeList, CANT);

    do
    {
        system("cls");
        menu();

        printf("\nType Your Option: ");
        option = getch();

        switch(option)
        {
        case '1': //ADD//
            addEmployees(employeeList, CANT);
            flag = 1;
            break;
        case '2': //MODIFY//
            if(flag==0)
            {
                printf("\n\nADD AN EMPLOYEE FIRST\n");
                system("pause");
            }else{
            modifyEmployee(employeeList, CANT);
            }
            break;
        case '3':
            if(flag==0)
            {
                printf("\n\nADD AN EMPLOYEE FIRST\n");
                system("pause");
            }else{
            removeEmployee(employeeList, CANT);
            }
            break;
        case '4':
            if(flag==0)
            {
                printf("\n\nADD AN EMPLOYEE FIRST\n");
                system("pause");
            }else{
            listEmployee(employeeList, CANT);
            }
            break;
        case '5':
            exit = 1;
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
        break;
        }

    }
    while(exit == 0);

    return 0;
}
