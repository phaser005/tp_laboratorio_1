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
void modifyMenu(Employee [], int);
void listingMenu(void);
void listingMenuB(void);

void initEmployees(Employee [], int);

int findEmployeeById(Employee [], int, int);

void addEmployees(Employee [], int);
void modifyEmployee(Employee [], int);
void removeEmployee(Employee [], int);
void listEmployee(Employee [], int);

void sortEmployeeByName(Employee [], int, int);
void averageSalaryListing(Employee [], int);
void printEmployees(Employee [], int);
