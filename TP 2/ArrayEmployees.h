typedef struct
{
    int id;
    char lastName[51];
    char name[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void menu(void);
void modifyMenu(Employee* , int);
void listingMenu(void);
void listingMenuB(void);

void initEmployees(Employee* , int);

int findEmployeeById(Employee* , int, int);

void infoInput(Employee*, int);
int addEmployees(Employee*, int, int, char [], char [], float, int);
void modifyEmployee(Employee* , int);
int removeEmployee(Employee* , int);
void listEmployee(Employee* , int);

int sortEmployeeByName(Employee* , int, int);
void averageSalaryListing(Employee* , int);
int printEmployees(Employee* , int);
