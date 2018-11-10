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

Employee* employee_new()
{
    Employee* new_employee;
    new_employee = calloc(1, sizeof(Employee));
    return new_employee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr)
{
    Employee* new_employee = NULL;
    int id, horasTrabajadas;
    int check_1, check_2, check_3, check_4;
    float salario;
    new_employee = employee_new();
    if(new_employee!=NULL)
    {
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        salario = atof(salaryStr);

        check_1 = employee_setId(new_employee, id);
        if(check_1 != 0)
            {
                printf("Error. ID\n");
                system("pause");
            }

        check_2 = employee_setNombre(new_employee, nombreStr);
        if(check_2 != 0)
            {
                printf("Error. Name\n");
                system("pause");
            }

        check_3 = employee_setHorasTrabajadas(new_employee, horasTrabajadas);
        if(check_3 != 0)
            {
                printf("Error. Worked Time\n");
                system("pause");
            }

        check_4 = employee_setSueldo(new_employee, salario);
        if(check_4 != 0)
            {
                printf("Error. Salary\n");
                system("pause");
            }
    }

    return new_employee;
}

int employee_setId(Employee* this,int id)
{
    int returnValue = 0;

    if(id>0 && this!=NULL)
    {
        this->id = id;
    }else{
        returnValue = -1;
    }
    return returnValue;
}

int employee_getId(Employee* this,int* id)
{
    int returnValue = 0;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
    }else{
        returnValue = -1;
    }

    return returnValue;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int returnValue = 0;
    if(this!= NULL && nombre!=NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
    }else{
        returnValue = -1;
    }
    return returnValue;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int returnValue = 0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
    }else{
        returnValue = -1;
    }
    return returnValue;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int returnValue = 0;

    if(horasTrabajadas>0 && this!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
    }else{
        returnValue = -1;
    }

    return returnValue;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int returnValue = 0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }else{
        returnValue = -1;
    }
    return returnValue;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int returnValue = 0;

    if(sueldo>0 && this!=NULL)
    {
        this->sueldo = sueldo;
    }else{
        returnValue = -1;
    }

    return returnValue;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int returnValue = 0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
    }else{
        returnValue = -1;
    }
    return returnValue;
}

int employee_SortByName(void* employeeA, void* employeeB)
{
    int returnValue = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employeeAuxA = employeeA;
        employeeAuxB = employeeB;
        returnValue = strcmp( employeeAuxA->nombre, employeeAuxB->nombre);
    }
    return returnValue;
}

int employee_SortBySalary(void* employeeA, void* employeeB)
{
    int returnValue = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employeeAuxA = employeeA;
        employeeAuxB = employeeB;
        if(employeeAuxA->sueldo > employeeAuxB->sueldo)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}

int employee_SortByWorkedTime(void* employeeA, void* employeeB)
{
    int returnValue = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employeeAuxA = employeeA;
        employeeAuxB = employeeB;
        if(employeeAuxA->horasTrabajadas > employeeAuxB->horasTrabajadas)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}

int employee_SortByID(void* employeeA, void* employeeB)
{
    int returnValue = 0;
    Employee* employeeAuxA;
    Employee* employeeAuxB;

    if(employeeA != NULL && employeeB != NULL)
    {
        employeeAuxA = employeeA;
        employeeAuxB = employeeB;
        if(employeeAuxA->id > employeeAuxB->id)
        {
            returnValue = 1;
        }
    }
    return returnValue;
}
