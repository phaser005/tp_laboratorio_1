#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "Parser.h"
#include "utn.h"
#define ESC 27

/************************************************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = -1;
    LinkedList* EmployeeList = ll_newLinkedList();
    do{
        option = menu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",EmployeeList);
                break;
            case 2:
                controller_loadFromBinary("data.bin",EmployeeList);
                break;
            case 3:
                controller_addEmployee(EmployeeList);
                break;
            case 4:
                controller_editEmployee(EmployeeList);
                break;
            case 5:
                controller_removeEmployee(EmployeeList);
                break;
            case 6:
                controller_ListEmployee(EmployeeList);
                break;
            case 7:
                controller_sortEmployee(EmployeeList);
                break;
            case 8:
                controller_saveAsText("data.csv", EmployeeList);
                break;
            case 9:
                controller_saveAsBinary("data.bin", EmployeeList);
                break;
            case 10:
                option = 0;
                break;
        }
    }while( option != 0);

    ll_deleteLinkedList(EmployeeList);
    return 0;
}
