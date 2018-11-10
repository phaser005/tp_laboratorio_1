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
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* filePointer;
    int returnValue = 0;

    filePointer = fopen(path, "r+");
    if(filePointer == NULL)
    {
        printf("\nCouldn't open archive\n");
        system("pause");
        returnValue = -1;
    }else{
        printf("\nText file was opened in Read - Write Mode\n");
        system("pause");
    }
    returnValue = parser_EmployeeFromText(filePointer,pArrayListEmployee);

    free(filePointer);
    return returnValue;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* filePointer;
    int status = 0;

    filePointer = fopen(path, "rb+");
    if(filePointer == NULL)
    {
        printf("\nCouldn't open archive\n");
        system("pause");
        status = -1;
    }else{
        printf("\nText file was opened in Read - Write Mode\n");
        status = parser_EmployeeFromBinary(filePointer,pArrayListEmployee);
        system("pause");
    }
    free(filePointer);
    return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int returnValue = 1;
    char id[8];
    char name[128];
    char workTime[8];
    char salary[8];

    getString(id, "TYPE ID: ","LENGTH ERROR" ,1,40);
    getString(name, "TYPE NAME: ","LENGTH ERROR" ,1,128);
    getString(workTime, "TYPE WORKTIME: ","LENGTH ERROR" ,1,40);
    getString(salary, "TYPE SALARY: ","LENGTH ERROR" ,1,40);

    newEmployee = employee_newParametros(id, name, workTime, salary);
    if(newEmployee!=NULL)
    {
        ll_add(pArrayListEmployee, newEmployee);
    }else if(newEmployee==NULL)
    {
        returnValue = -1;
    }

    return returnValue;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int IDAUX;
    int check = -1;
    int option = -1;
    int flag = 0;
    int status = 1;
    Employee* indexPointer;
    getInt(&IDAUX, "Type ID of the employee you want to modify: ", "ERROR", 0, 9999999);
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        indexPointer = (Employee*)ll_get(pArrayListEmployee, i);
        if(indexPointer->id == IDAUX)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        do{
            system("cls");
            printf("**      This employee will be modified \n");
            printf("\nId: %d    Name: %s    Worked Time: %d    Salary: %.1f\n", indexPointer->id, indexPointer->nombre, indexPointer->horasTrabajadas, indexPointer->sueldo);
            option = modify_menu();
            switch(option)
            {
                case 1:   //MODIFY NAME
                    do{
                    system("cls");
                    check = getString((indexPointer->nombre), "Type new name: (Max 128): ", "[ERROR] Out of range\n", 1, 128);
                    }while(check!=1);
                    break;
                case 2:   //MODIFY WORKED TIME
                    do{
                    system("cls");
                    check = getInt(&(indexPointer->horasTrabajadas), "Type new worked time: (Max 9999999): ", "[ERROR] Out of range\n", 1, 9999999);
                    }while(check!=1);
                    break;
                case 3:   //MODIFY SALARY
                    do{
                    system("cls");
                    check = getFloat(&(indexPointer->sueldo), "Type new salary: (Max 9999999): ", "[ERROR] Out of range\n", 1, 9999999);
                    }while(check!=1);
                    break;
                case 4:
                    option = 0;
                    break;
            }
        }while( option != 0);
    }else
    {
        printf("ID nonexistant\n");
        status = -1;
    }

    return status;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int IDAUX;
    int i;
    char option ='0';
    int flag = 0;
    int status = 1;

    Employee* indexPointer;
    getInt(&IDAUX, "Type ID of the employee you want to delete: ", "ERROR", 0, 9999999);
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        indexPointer = (Employee*)ll_get(pArrayListEmployee, i);
        if(indexPointer->id == IDAUX)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("This employee will be deleted: \n");
        printf("\nId: %d    Name: %s    Worked Time: %d    Salary: %.1f\n\n", indexPointer->id, indexPointer->nombre, indexPointer->horasTrabajadas, indexPointer->sueldo);
        getChar(&option, "are you sure? [Y] [N]\n", "Not a character");
        option = toupper(option);
        if(option=='Y')
        {
            ll_remove(pArrayListEmployee, i);
            printf("\nThe employee has been removed!");
            free(indexPointer);
        }else if(option=='N')
        {
            printf("\nOperation Canceled");
            status = -1;
        }
    }
    return status;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* indexPointer;
    int idAux;
    char nombreAux[128];
    int horasTrabajadasAux;
    float sueldoAux;

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        indexPointer = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getNombre(indexPointer, nombreAux);
        employee_getId(indexPointer, &idAux);
        employee_getHorasTrabajadas(indexPointer, &horasTrabajadasAux);
        employee_getSueldo(indexPointer, &sueldoAux);

        printf("\n//id: %d //nombre: %s //horasTrabajadas: %d //sueldo: %.2f", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
    }
    printf("\n");
    system("pause");
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option = 0;
    do{
        option = sort_menu();
        switch(option)
        {
            case 1://SORT BY NAME
                printf("SORTED BY NAME\n");
                ll_sort(pArrayListEmployee, employee_SortByName, 1);
                system("pause");
                break;
            case 2://SORT BY SALARY
                printf("SORTED BY SALARY\n");
                ll_sort(pArrayListEmployee, employee_SortBySalary, 1);
                system("pause");
                break;
            case 3://SORT BY WORKED TIME
                printf("SORTED BY WORKED TIME\n");
                ll_sort(pArrayListEmployee, employee_SortByWorkedTime, 1);
                system("pause");
                break;
            case 4://SORT BY ID
                printf("SORTED BY ID\n");
                ll_sort(pArrayListEmployee, employee_SortByID, 1);
                system("pause");
                break;
            case 5:
                option = 0;
                break;
        }
    }while( option != 0);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* newFilePointer;
    Employee* employeePointer;
    int returnValue = 0;
    int written_lengh = 0;
    int toWrite_lengh, i;
    char firstLine[] = "id,nombre,horasTrabajadas,sueldo\n";

    if(pArrayListEmployee == NULL)
    {
        printf("Invalid Linked List Pointer");
        returnValue = -1;
    }else if(pArrayListEmployee!=NULL)//WRITING PART
    {
        newFilePointer = fopen(path, "w+");
        if(newFilePointer == NULL)
        {
            printf("\nCouldn't create archive\n");
            system("pause");
            returnValue = -2;
        }else{
            printf("\nFile %s is ready to write\n", path);

            toWrite_lengh = strlen(firstLine);
            written_lengh = fwrite(firstLine,1,(sizeof(char)* toWrite_lengh),newFilePointer);

            if(written_lengh == toWrite_lengh)
            {
                printf("Titles written. Now we will write the employees info to the file\n\n");
                system("pause");
                for(i = 0; i<ll_len(pArrayListEmployee); i++)
                {
                    employeePointer = (Employee*)ll_get(pArrayListEmployee, i);
                    written_lengh = fprintf(newFilePointer,"%d,%s,%d,%.0f\n",employeePointer->id,employeePointer->nombre,employeePointer->horasTrabajadas,employeePointer->sueldo);
                }
                if((i = ll_len(pArrayListEmployee)))
                {
                    printf("\nInfo was saved suscessfully\n");
                }
            }else if(written_lengh != toWrite_lengh)
            {
                printf("Titles were not written correctly");
                system("pause");
                returnValue = -3;
            }
        }
    }

    free(newFilePointer);
    return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* newFilePointer;
    Employee* employeePointer;
    int returnValue = 0;
    int written_lengh = 0;
    int i;

    if(pArrayListEmployee == NULL)
    {
        printf("Invalid Linked List Pointer");
        returnValue = -1;
    }else if(pArrayListEmployee!=NULL)//WRITING PART
    {
        newFilePointer = fopen(path, "wb+");
        if(newFilePointer == NULL)
        {
            printf("\nCouldn't create archive\n");
            system("pause");
            returnValue = -2;
        }else{
            printf("\nFile %s is ready to write\n", path);

            for(i = 0; i<ll_len(pArrayListEmployee); i++)
            {

                employeePointer = (Employee*)ll_get(pArrayListEmployee, i);
                written_lengh = fwrite(employeePointer,sizeof(Employee),1,newFilePointer);
                printf("SAVED DATA:\n");
                printf("\n//id: %d //nombre: %s //horasTrabajadas: %d //sueldo: %.2f", employeePointer->id, employeePointer->nombre, employeePointer->horasTrabajadas, employeePointer->sueldo);
                if(written_lengh!=1)
                {
                    printf("Error Saving Data to file.");
                    returnValue = -3;
                    break;
                }
            }
        }
    }
    free(newFilePointer);
    return returnValue;
}


int menu(void)
{
    int option = -1;
    system("cls");
    printf("****************************************MENU******************************************\n");
    printf("**    [1]   **  Cargar los datos de los empleados desde el archivo data.csv (TEXT).\n");
    printf("**    [2]   **  Cargar los datos de los empleados desde el archivo data.bin (BINARY).\n");
    printf("**    [3]   **  Alta de empleado.\n");
    printf("**    [4]   **  Modificar datos de empleado.\n");
    printf("**    [5]   **  Baja de empleado.\n");
    printf("**    [6]   **  Listar empleados.\n");
    printf("**    [7]   **  Ordenar empleados.\n");
    printf("**    [8]   **  Guardar los datos de los empleados en el archivo data.csv (TEXT).\n");
    printf("**    [9]   **  Guardar los datos de los empleados en el archivo data.bin (BINARY).\n");
    printf("***************************************************************************************\n");
    printf("**    [10]  **  Salir\n");
    printf("***************************************************************************************\n");
    printf("** TYPE YOUR OPTION **\n");
    scanf("%d",&option);
    fflush(stdin);
    return option;
}

int modify_menu(void)
{
    int option;
    printf("\n");
    printf("***************************  What do you want to do?  *********************************\n");
    printf("**\n");
    printf("**    [1]   **          Modify Name\n");
    printf("**    [2]   **          Modify Worked Time\n");
    printf("**    [3]   **          Modify Salary\n");
    printf("**\n");
    printf("***************************************************************************************\n");
    printf("**    [4]   **          Salir\n");
    printf("***************************************************************************************\n");
    printf("** TYPE YOUR OPTION **\n");
    scanf("%d",&option);
    fflush(stdin);
    return option;
}

int sort_menu(void)
{
    int option;
    system("cls");
    printf("Select your order method\n");
    printf("[1]     By Name (Ascendent)\n");
    printf("[2]     By Salary (Ascendent)\n");
    printf("[3]     By Worked Time (Ascendent)\n");
    printf("[4]     By ID (Ascendent)\n");
    printf("[5]   Exit\n");
    scanf("%d",&option);
    fflush(stdin);
    return option;
}
