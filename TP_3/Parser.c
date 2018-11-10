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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* newEmployeeAux;
    int readQuant;
    int addedCant = 0;
    int check;
    int returnValue = 0;
    char idStr[50],nameStr[50],timeStr[50],salaryStr[50];

    check = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,timeStr,salaryStr);
    if(check==4)
    {
        //printf("\nTitles Readed!\n");

        while(!feof(pFile))
        {
            readQuant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,timeStr,salaryStr);
            if(readQuant == 4)
            {
                newEmployeeAux = employee_newParametros(idStr, nameStr, timeStr, salaryStr);

                ll_add(pArrayListEmployee, newEmployeeAux);
                addedCant++;
                if(feof(pFile))
                {
                    printf("\nThe file has been fully readed\n");
                }
            }else if (readQuant != 4)
            {
                if(!feof(pFile))
                {
                    printf("Couln't read all the parameters!\n");
                    system("pause");
                    break;
                }else
                {
                    printf("The file has been readed fully\n");
                    system("pause");
                    break;
                }
            }

        }
        printf("\n%d Employees has been added\n", addedCant);
        controller_ListEmployee(pArrayListEmployee);
    }else{
        printf("Couln't read the file correctly");
        returnValue = -1;
    }

    return returnValue;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* newEmployeeAux;
    Employee newEmployeeParam;
    int readQuant;
    int addedCant = 0;
    int status = 0;
    char idStr[8],nameStr[128],timeStr[8],salaryStr[8];

    while(!feof(pFile))
    {
        readQuant = fread(&newEmployeeParam, sizeof(Employee), 1, pFile);
        //printf("READED QUANT: %d", readQuant);
        //system("pause");
        if(readQuant == 1)
        {                               //ID
            sprintf(idStr, "%d", newEmployeeParam.id);
                                        //WORKED TIME
            sprintf(timeStr, "%d", newEmployeeParam.horasTrabajadas);
                                        //SALARY
            sprintf(salaryStr, "%0.f", newEmployeeParam.sueldo);
                                        //NAME
            strncpy(nameStr, newEmployeeParam.nombre, sizeof(nameStr));

            //printf("LOADED:\n");
            //printf("\n//id: %d //nombre: %s //horasTrabajadas: %d //sueldo: %.2f\n", newEmployeeParam.id, newEmployeeParam.nombre, newEmployeeParam.horasTrabajadas, newEmployeeParam.sueldo);

            newEmployeeAux = employee_newParametros(idStr, nameStr, timeStr, salaryStr);

            ll_add(pArrayListEmployee, newEmployeeAux);

            //printf("ADDED:\n");
            //printf("\n//id: %d //nombre: %s //horasTrabajadas: %d //sueldo: %.2f\n", newEmployeeAux->id, newEmployeeAux->nombre, newEmployeeAux->horasTrabajadas, newEmployeeAux->sueldo);
            //system("pause");
            addedCant++;
        }else if (readQuant != 1)
        {
            if(!feof(pFile))
            {
                printf("Couln't read all the parameters!\n");
                status = -1;
                system("pause");
                break;
            }else
            {
                printf("\nThe file has been readed fully\n");
                system("pause");
                break;
            }
        }

    }
    controller_ListEmployee(pArrayListEmployee);
    printf("\n%d Employees has been added\n", addedCant);

    return status;
}
