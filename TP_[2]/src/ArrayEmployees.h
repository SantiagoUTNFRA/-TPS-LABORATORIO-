/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Cantos Santiago Felipe
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

/**
 * @struct Employee
 * @brief This structure is for represent Employee ABM list
 *
 */
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif /* ARRAYEMPLOYEES_H_ */


/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
 *
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len);   //2.1 Función initEmployees

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);   //2.2 Función addEmployees

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id en returns the index position in array
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id);   //2.3 Función findEmployeeById

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return  int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);   //2.4 Función removeEmployee

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);   //2.5 Función sortEmployees

/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length);   //2.6 Función printEmployees





//MY FUNCTIONS



/**
 * @fn int sortEmployeesSalary(Employee*, int)
 * @brief Sort the elements in the array of employees, the argument salary order indicate HIGHER or LOWER
 *
 * @param list *Employee
 * @param len int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployeesSalary(Employee* list, int len);

/**
 * @fn int modifyEmployee(Employee*, int)
 * @brief Show a menu to the employee for his data modification
 *
 * @param list *Employee
 * @param len int
 * @return  Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len);

/**
 * @fn int searchFree(Employee*, int)
 * @brief find a place with index 0 or 1
 *
 * @param list *Employee
 * @param len int
 * @return indice int free index - (0)[if there is no place]
 */
int searchFree(Employee* list, int len);

/**
 * @fn void printEmployee(Employee)
 * @brief print the content of a vector employees
 * @param oneEmployee
 */
void printEmployee(Employee oneEmployee);

/**
 * @fn int menuModify()
 * @brief Display a menu, leads to data modification options
 *
 * @return opcion int
 */
int menuModify();

/**
 * @fn int menuInformes(Employee*, int)
 * @brief Display a menu, leads to report sorting options
 *
 * @param list *Employee
 * @param len int
 * @return int Return (-1) if Error - (0) if Ok
 */
int menuInformes(Employee* list, int len);

/**
 * @fn int menu()
 * @brief Display a menu of ABM options
 *
 * @return int Return (-1) if Error - (0) if Ok
 */
int menu();

/**
 * @fn int validateFlag(Employee*, int, int*)
 * @brief Validate access to other cases
 *
 * @param list *Employee
 * @param len int
 * @param flag *int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int validateFlag(Employee* list, int len, int* flag);

/**
 * @fn int validateStringTidy(char*)
 * @brief Visually relocate upper and lower case
 *
 * @param string *Employee
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int validateStringTidy(char* string);

/**
 * @fn int onlyString(char*)
 * @brief Validate that no numbers or symbols are entered
 *
 * @param string *Employee
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int onlyString(char* str);



// GET FUNCTION


/**
 * @fn int getInteger(int*, char*, char*, int, int)
 * @brief Sort integers and validate with min and max
 *
 * @param integer *int
 * @param message[] char
 * @param messageError[] char
 * @param min int
 * @param max int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getInteger(int* integer, char* message, char* messageError, int min, int max);

/**
 * @fn int getFloat(float*, char*, char*, float, float)
 * @brief Sort floats and validate with min and max
 *
 * @param flotante *int
 * @param message[] char
 * @param messageError[] char
 * @param min int
 * @param max int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getFloat(float* flotante, char* message, char* messageError, float min, float max);

/**
 * @fn int getString(char*, char*, char*, int)
 * @brief Validate entry of numbers and symbols
 *
 * @param string *Employee
 * @param message[] char
 * @param messageError[] char
 * @param max int
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int getString(char* string, char* message, char* messageError, int max);

/**
 * @fn int getCharacter(char*, char*)
 * @brief Get a character and validate range
 *
 * @param character[] char
 * @param message[] char
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int getCharacter(char* character, char* message);

/**
 * @fn int getCriterio(int*)
 * @brief Sort ascending or descending
 *
 * @param criterio
 * @return int Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int getCriterio(int* criterio);

