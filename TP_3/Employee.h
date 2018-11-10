#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

////////////////////////////////////////////////////////////////////////////////////
////////////////////////        employee_new     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Creates a new employee and initializes it's camps
*
*\return a pointer to an Employee type
*
*/
Employee* employee_new();

////////////////////////////////////////////////////////////////////////////////////
//////////////        employee_newParametros     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Transform and assign the received parameters to a new employee
*
*\param idStr pointer to string type
*\param nombreStr pointer to string type
*\param horasTrabajadasStr pointer to string type
*\param salaryStr pointer to string type
*\return a pointer to an Employee type or NULL if there was an invalid data
*
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);
//void employee_delete();

////////////////////////////////////////////////////////////////////////////////////
//////////////////////        employee_setId     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sets the received variable to a new employee.
*
*\param this pointer to an employee type
*\param id data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_setId(Employee* this,int id);

////////////////////////////////////////////////////////////////////////////////////
//////////////////////        employee_getId     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets the ID of a specific employee.
*
*\param this pointer to an employee type
*\param id data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_getId(Employee* this,int* id);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        employee_setNombre     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sets the received variable to a new employee.
*
*\param this pointer to an employee type
*\param nombre pointer to the data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_setNombre(Employee* this,char* nombre);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        employee_getNombre     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets the Name of a specific employee.
*
*\param this pointer to an employee type
*\param nombre pointer to the data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_getNombre(Employee* this,char* nombre);

////////////////////////////////////////////////////////////////////////////////////
/////////        employee_setHorasTrabajadas     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sets the received variable to a new employee.
*
*\param this pointer to an employee type
*\param horasTrabajadas pointer to the data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

////////////////////////////////////////////////////////////////////////////////////
/////////        employee_getHorasTrabajadas     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets the workedtime value of a specific employee.
*
*\param this pointer to an employee type
*\param horasTrabajadas pointer to the data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        employee_setSueldo     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sets the received variable to a new employee.
*
*\param this pointer to an employee type
*\param sueldo data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_setSueldo(Employee* this,float sueldo);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        employee_getSueldo     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Gets the salary variable of a specific employee
*
*\param this pointer to an employee type
*\param sueldo data to set to the employee
*\return 0 if everything is ok, -1 if the input didn't meet the valid criteria or the pointers are NULL
*
*/
int employee_getSueldo(Employee* this,float* sueldo);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        employee_SortByName     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sort the employees of the linked list by name
*
*\param employeeA pointer to an employee type
*\param employeeA pointer to an employee type
*\return 0 if everything is OK, -1 if the employee pointers are NULL
*
*/
int employee_SortByName(void* employeeA, void* employeeB);

////////////////////////////////////////////////////////////////////////////////////
///////////////        employee_SortBySalary     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sort the employees of the linked list by salary
*
*\param employeeA pointer to an employee type
*\param employeeA pointer to an employee type
*\return 0 if everything is OK, 1 if the received parameters meet the desired criteria, -1 if the employee pointers are NULL
*
*/
int employee_SortBySalary(void* employeeA, void* employeeB);

////////////////////////////////////////////////////////////////////////////////////
///////////        employee_SortByWorkedTime     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sort the employees of the linked list by worked time
*
*\param employeeA pointer to an employee type
*\param employeeA pointer to an employee type
*\return 0 if everything is OK, 1 if the received parameters meet the desired criteria, -1 if the employee pointers are NULL
*
*/
int employee_SortByWorkedTime(void* employeeA, void* employeeB);

////////////////////////////////////////////////////////////////////////////////////
///////////////////        employee_SortByID     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Sort the employees of the linked list by ID
*
*\param employeeA pointer to an employee type
*\param employeeA pointer to an employee type
*\return 0 if everything is OK, 1 if the received parameters meet the desired criteria, -1 if the employee pointers are NULL
*
*/
int employee_SortByID(void* employeeA, void* employeeB);

#endif // employee_H_INCLUDED
