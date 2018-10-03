#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"


void initEmployees(Employee* employeeList, int CANT)
{
    for(int i=0; i<CANT; i++)
    {
        employeeList[i].id = i+1;
        employeeList[i].isEmpty = 1;
    }
}


void menu(void)
{
    printf("[1] ADD EMPLOYEE\n");
    printf("[2] MODIFY EMPLOYEE DATA\n");
    printf("[3] REMOVE EMPLOYEE\n");
    printf("[4] LIST\n\n");
    printf("[5] EXIT\n");
}


void modifyMenu(Employee* employeeList, int ID)
{
    printf("/////MODIFY MENU/////\n");
    printf("\nTHIS EMPLOYEE'S INFO WILL BE MODIFIED\n");
    printf("LASTNAME [%s]    NAME [%s]    SALARY [%.2f]    SECTOR [%d]\n", employeeList[ID].lastName, employeeList[ID].name, employeeList[ID].salary, employeeList[ID].sector);
    printf("\n/////////////////////////\n");
    printf("[1] MODIFY NAME\n");
    printf("[2] MODIFY LAST NAME\n");
    printf("[3] MODIFY SALARY\n");
    printf("[4] MODIFY SECTOR\n\n");
    printf("[5] EXIT\n");
}


void listingMenu(void)
{
    printf("/////LISTING MENU/////\n");
    printf("[1] ALPHABETICALLY ORDERED EMPLOYEE LIST\n");
    printf("[2] TOTAL AND AVERAGE EMPLOYEE'S SALARY AND SALARY ABOVE AVERAGE'S EMPLOYEES \n");
    printf("[3] EXIT\n");
}


void listingMenuB(void)
{
    printf("/////LISTING MENU/////\n");
    printf("[1] ASCENDENT\n");
    printf("[2] DESCENDENT\n");
    printf("[3] EXIT\n");
}


int findEmployeeById(Employee* employeeList, int CANT, int ID)
{
    int index = -1;

    for(int i=0; i<CANT; i++)
    {
        if(employeeList[i].id == ID && employeeList[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


void infoInput(Employee* employeeList, int CANT)
{
    Employee newEmployee;
    system("cls");
    int check;
    do{
        system("cls");
        check = getString(newEmployee.lastName, "Type Last Name (Max Length 50): ", "[ERROR] Last Name too long or too short\n", 1, 51);
        }while(check!=1);

    do{
        system("cls");
        check = getString(newEmployee.name, "Type Name (Max Length 50): ", "[ERROR] Name too long or too short\n", 1, 51);
        }while(check!=1);

    do{
        system("cls");
        check = getFloat(&newEmployee.salary, "Type Salary: ", "[ERROR] Not a valid number\n", 1, 9999999);
        }while(check!=1);

    do{
        system("cls");
        check = getInt(&newEmployee.sector, "Type Sector (1 - 5): ", "[ERROR] Not a valid number\n", 1, 5);
        }while(check!=1);

    for (int i=0; i<CANT; i++)
    {
        if(employeeList[i].isEmpty==1)
        {
            newEmployee.id = i+1;
            break;
        }else{
            newEmployee.id = -1;
        }
    }


    check = addEmployees(employeeList, CANT, newEmployee.id, newEmployee.name, newEmployee.lastName, newEmployee.salary, newEmployee.sector);
    if(check == 0)
    {
        printf("/////SAVED DATA/////\n");
        printf("ID [%d]   LASTNAME [%s]   NAME [%s]   SALARY [%.2f]   SECTOR [%d]\n", newEmployee.id, newEmployee.lastName, newEmployee.name, newEmployee.salary, newEmployee.sector);

        system("pause");
    }else if(check == -1)
    {
        printf("ERROR");
        system("pause");
    }
}


int addEmployees(Employee* employeeList, int CANT, int id, char name[], char lastName[], float salary, int sector)
{
    int status;
    for(int i=0; i<CANT; i++)
    {
        if(employeeList[i].isEmpty == 1)
        {

            employeeList[i].id = id;
            strcpy(employeeList[i].name, name);
            strcpy(employeeList[i].lastName, lastName);
            employeeList[i].salary = salary;
            employeeList[i].sector = sector;
            employeeList[i].isEmpty = 0;

            status = 0;
            break;
        }else{
            status = -1;
        }
    }
    return status;
}


int removeEmployee(Employee* employeeList, int CANT)
{
    system("cls");
    int status;
    int check = -1;
    int ID, IDAux;
    char optionYN;
    do{ check = getInt(&IDAux, "Type ID of employee(1 - 100): ", "[ERROR] Not a Valid ID\n", 1, 100);
    }while(check!=1);

    ID = findEmployeeById(employeeList, CANT, IDAux);

    if(ID != -1)
    {
        do
        {
            system("cls");
            printf("\nTHIS EMPLOYEE WILL BE DELETED\n");
            printf("LASTNAME [%s]    NAME [%s]    SALARY [%.2f]    SECTOR [%d]\n", employeeList[ID].lastName, employeeList[ID].name, employeeList[ID].salary, employeeList[ID].sector);
            printf("\nARE YOU SURE? Y/N: ");
            optionYN = toupper(getch());
        }while(!(optionYN == 'Y' || optionYN == 'N'));

        if(optionYN == 'Y')
        {
            employeeList[ID].isEmpty = 1;
            printf("\nEMPLOYEE HAS BEEN SUSCESSFULLY DELETED!\n");
            system("pause");
            status = 0;
        }else if(optionYN == 'N')
        {
            printf("\nOPERATION CANCELED\n");
            system("pause");
        }
    }
    else
    {
        printf("\nID NOT FOUND!\n");
        status = -1;
        system("pause");
    }
    return status;
}


void modifyEmployee(Employee* employeeList, int CANT)
{
    system("cls");
    int check = -1;
    int ID;
    int IDAux;
    do{ check = getInt(&IDAux, "Type ID of employee(1 - 100): ", "[ERROR] Not a Valid ID\n", 1, 100);
    }while(check!=1);

    ID = findEmployeeById(employeeList, CANT, IDAux);

    if(ID != -1)
    {
        int exit = 0;
        char option;
        do
        {
            system("cls");
            modifyMenu(employeeList, ID);

            printf("\nType Your Option: ");
            option = getch();

            switch(option)
            {

                case '1': //MODIFY NAME//
                    do{
                        system("cls");
                        check = getString(employeeList[ID].name, "Type New Name (Max Length 50): ", "[ERROR] Name too long or too short", 1, 51);
                    }while(check!=1);
                    break;
                case '2': //MODIFY LAST NAME//
                    do{ system("cls");
                        check = getString(employeeList[ID].lastName, "Type New Last Name (Max Length 50): ", "[ERROR] Name too long or too short", 1, 51);
                    }while(check!=1);
                    break;
                case '3': //MODIFY SALARY//
                    do{
                        system("cls");
                        check = getFloat(&employeeList[ID].salary, "Type New Salary: ", "[ERROR] Number out of Valid Range\n", 1, 9999999);
                    }while(check!=1);
                    break;
                case '4': //MODIFY SECTOR//
                    do{
                        system("cls");
                        check = getInt(&employeeList[ID].sector, "Type New Sector (1 - 5): ", "[ERROR] Not a valid number\n", 1, 5);
                    }while(check!=1);
                    break;
                case '5':
                    exit = 1;
                    break;
                default:
                    printf("Incorrect Input\n");
                    system("pause");
                    break;
            }
        }while(exit==0);
    }else
    {
        printf("\nID NOT FOUND!\n");
        system("pause");
    }
}


void listEmployee(Employee* employeeList, int CANT)
{
    int exit = 0;
    char option;
    int exitB = 0;
    char optionB;
    int status;

    do
    {
        system("cls");
        listingMenu();

        printf("\nType Your Option: ");
        option = getch();

            switch(option)
            {
                case '1': //LISTING 1//////////////////////////////////////
                    do
                    {
                        system("cls");
                        listingMenuB();

                        printf("\nType Your Option: ");
                        optionB = getch();

                        switch(optionB)
                        {
                            case '1': //ASCENDENT/////////////////////////
                                sortEmployeeByName(employeeList, CANT, 1);
                                status = printEmployees(employeeList, CANT);
                                if(status!=0)
                                {
                                    printf("ERROR PRINTING EMPLOYEES");
                                }
                                system("pause");
                                break;
                            case '2': //DESCENDENT///////////////////////
                                sortEmployeeByName(employeeList, CANT, 2);
                                status = printEmployees(employeeList, CANT);
                                if(status!=0)
                                {
                                    printf("ERROR PRINTING EMPLOYEES");
                                }
                                system("pause");
                                break;
                            case '3':
                                exitB = 1;
                                break;
                            default:
                            printf("Incorrect Input\n");
                            system("pause");
                            break;
                        }
                    }while(exitB==0);
                    break;
                case '2': //LISTING 2//
                    averageSalaryListing(employeeList, CANT);
                    system("pause");
                    break;
                case '3':
                    exit = 1;
                    break;
                default:
                    printf("Incorrect Input\n");
                    system("pause");
                    break;
            }
        }while(exit==0);
}


int sortEmployeeByName(Employee* employeeList, int CANT, int order)
{
    int status;
    Employee aux;
    if(order==1)
    {
        for(int i=0; i<CANT-1; i++)
        {
            for(int j=i+1; j<CANT; j++)
            {
                if((strcmp(employeeList[i].lastName, employeeList[j].lastName)>0) && employeeList[i].isEmpty==0 && employeeList[j].isEmpty==0)
                {
                    aux = employeeList[j];
                    employeeList[j] = employeeList[i];
                    employeeList[i] = aux;
                    status = 0;
                }else if((strcmp(employeeList[i].lastName, employeeList[j].lastName)==0) && employeeList[i].isEmpty==0 && employeeList[j].isEmpty==0)
                {
                    if(employeeList[i].sector > employeeList[j].sector)
                    {
                        aux = employeeList[j];
                        employeeList[j] = employeeList[i];
                        employeeList[i] = aux;
                        status = 0;
                    }
                }else{status = 1;}
            }
        }
    }else if(order==2)
    {
        for(int i=0; i<CANT-1; i++)
        {
            for(int j=i+1; j<CANT; j++)
            {
                if((strcmp(employeeList[i].lastName, employeeList[j].lastName)<0) && employeeList[i].isEmpty==0 && employeeList[j].isEmpty==0)
                {
                    aux = employeeList[j];
                    employeeList[j] = employeeList[i];
                    employeeList[i] = aux;
                    status = 0;
                }else if((strcmp(employeeList[i].lastName, employeeList[j].lastName)==0) && employeeList[i].isEmpty==0 && employeeList[j].isEmpty==0)
                {
                    if(employeeList[i].sector < employeeList[j].sector)
                    {
                        aux = employeeList[j];
                        employeeList[j] = employeeList[i];
                        employeeList[i] = aux;
                        status = 0;
                    }
                }{status = 1;}
            }
        }
    }
    return status;
}


void averageSalaryListing(Employee* employeeList, int CANT)
{
    float total = 0;
    int count = 0;
    float average = 0;
    int aboveAverage = 0;
    for(int i=0; i<CANT; i++)
    {
        if(employeeList[i].isEmpty==0)
        {
        total = total + employeeList[i].salary;
        count++;
        }
    }

    average = (float) total / count;
    for(int i=0; i<CANT; i++)
    {
        if(employeeList[i].isEmpty==0)
        {
            if(employeeList[i].salary>average)
            {
                aboveAverage++;
            }
        }
    }
    printf("\nTOTAL SALARIES: %.2f\n", total);
    printf("\nAVERAGE SALARY: %.2f\n", average);
    printf("\nABOVE AVERAGE SALARY EMPLOYEES: %d\n", aboveAverage);
}


int printEmployees(Employee* employeeList, int CANT)
{
    int status;
    printf("\n--------------------------------------------------------------\n");
    printf("\n---------------------------REGISTRY---------------------------\n");
    for(int i=0; i<CANT; i++)
    {
        if(employeeList[i].isEmpty==0)
        {
            printf("ID[%d]   LASTNAME[%s]    NAME[%s]    SALARY[%.2f]    SECTOR[%d]\n", employeeList[i].id, employeeList[i].lastName, employeeList[i].name, employeeList[i].salary, employeeList[i].sector);
            status = 0;
        }
    }

    return status;
}

