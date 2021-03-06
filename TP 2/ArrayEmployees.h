typedef struct
{
    int id;
    char lastName[51];
    char name[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

////////////////////////////////////////////////////////////////////////////////////
/////////////////////       menu    ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Shows the main menu for the ABM program.
*
*/
void menu(void);

////////////////////////////////////////////////////////////////////////////////////
//////////////////        modifyMenu         ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Shows the modify menu of the ABM program and displays the info of the employee that matchs the provided ID.
*
*\param Employee employeeList[] received structure vector
*\param int ID integer number representing the ID of a registered employee
*
*/
void modifyMenu(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
/////////////////////       listingMenu     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Shows the listing menu of the ABM program.
*
*/
void listingMenu(void);

////////////////////////////////////////////////////////////////////////////////////
/////////////////////       listingMenuB    ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Shows the listing sub menu of the ABM program.
*
*/

void listingMenuB(void);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       initEmployees      //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Initializes received structure vector, assigning a value to ID and isEmpty variables.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size
*
*/
void initEmployees(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////      findEmployeeById      ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Scans the provided structure vector for a matching ID number, provided by the user.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*\param int ID provided ID number.
*\return index -1 if ID provided didn't match, i if ID matches with a registered employee
*
*/
int findEmployeeById(Employee* , int, int);

////////////////////////////////////////////////////////////////////////////////////
///////////////////////       infoInput      ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Ask the user to input info to add an employee, calling the addEmployees function and checking everything is ok afterwards.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*
*/
void infoInput(Employee*, int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       addEmployees      ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Adds an employee, with the user inputs as it's data, changing it's "isEmpty" state to 0.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*\param int id provided employee id (calculated automatically from the initialized array "isEmpty" value)
*\param char name[] provided name string
*\param char lastName[] provided last name string
*\param float salary provided salary
*\param int sector provided sector
*\return -1 if there's not enough space, 0 if everything is ok.
*
*/
int addEmployees(Employee*, int, int, char [], char [], float, int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       modifyEmployee    ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Modifies the data of an employee whose ID is provided by the user.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*
*/
void modifyEmployee(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       removeEmployee      /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Removes an employee whose ID is provided by the user, changing it's "isEmpty" state to 1.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*\return 0 if ok, -1 if there is an error.
*
*/
int removeEmployee(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       listEmployee     ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Lists employees based on the option the user choice.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*
*/
void listEmployee(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       sortEmployeeByName    ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Lists employees alphabetically and by sector, in a ascending or descending way, defined by the provided "order" variable.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*\param int order 1 ascending, 2 descending
*\return 0 if ok, -1 if there is an error
*
*/
int sortEmployeeByName(Employee* , int, int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       averageSalaryListing    /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Lists the total salaries, average salaries and employees whose salary is above the average salary.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*
*/
void averageSalaryListing(Employee* , int);

////////////////////////////////////////////////////////////////////////////////////
////////////////////       printEmployees     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Prints registered employees and its info.
*
*\param Employee employeeList[] received structure vector.
*\param int CANT structure vector size.
*
*/
int printEmployees(Employee* , int);
