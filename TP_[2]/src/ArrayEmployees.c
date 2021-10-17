/*
 * ArrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Cantos Santiago Felipe
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }

        todoOk = 0;
    }


    return todoOk;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;
    int indice;

    if(list != NULL && name != NULL && lastName != NULL && len > 0)
    {
        indice = searchFree(list, len);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("\n");

            list[indice].id = id;

            getString(name, "Ingrese nombre: ", "Nombre demasiado largo, reingrese: ", 20);
            strcpy(list[indice].name, name);

            getString(lastName, "Ingrese apellido: ", "Apellido demasiado largo, reingrese: ", 20);
            strcpy(list[indice].lastName, lastName);

            getFloat(&salary, "Ingrese su salario (10000 hasta 100000): ", "Error, reingrese su salario (10000 hasta 100000): ", 10000, 100000);
            list[indice].salary = salary;

            getInteger(&sector, "Ingrese su sector (1 hasta 9): ", "Error, reingrese su sector (1 hasta 9): ", 1, 9);
            list[indice].sector = sector;


            list[indice].isEmpty = 0;

            printf("Alta exitosa!\n");
            todoOk = 0;
        }

    }

    return todoOk;
}


int findEmployeeById(Employee list[], int len, int id)
{
    int indice = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if((list[i].isEmpty) && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int removeEmployee(Employee list[], int len, int id)
{
    int todoOk = -1;
    char confirma;
    int indice;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    ***Baja Empleado***\n");

        getInteger(&id, "Ingrese id: ", "Ingrese id valido: ", 1, 1000000000);

        indice = findEmployeeById(list, len, id);

        if(indice != -1)
        {
            printEmployee(list[indice]);
            getCharacter(&confirma, "\nConfirma baja?: ");
            if(confirma == 's')
            {
                list[indice].isEmpty = 1;
                todoOk = 0;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("\nSe ha cancelado la baja");
            }

        }
        else
        {
            printf("No existe empleado con id: %d\n", id);
        }
    }
    return todoOk;
}


int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;
    Employee auxEmployee;

    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order)
                {
                    if((strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector > list[j].sector) || (strcmp(list[i].lastName, list[j].lastName) > 0 ))
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                        todoOk = 1;
                    }
                }
                else if((strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector < list[j].sector) || (strcmp(list[i].lastName, list[j].lastName) < 0 ))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                    todoOk = 0;
                }
            }
        }
    }

    return todoOk;
}


int printEmployees(Employee* list, int length)
{
    int todoOk = -1;
    int flag = 1;

    if(list != NULL && length > 0)
    {
        system("cls");

        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("-   Id             Name                      LastName                       Salary                   Sector -\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
                flag = 0;
                printf("\n");
            }

        }
        if(flag)
        {
            printf("No hay empleados para mostrar\n");
        }
        printf("\n\n");
        todoOk = 0;
    }

    return todoOk;
}


//FUNCIONES PROPIAS


int modifyEmployee(Employee list[], int len)
{
    int todoOk = -1;
    int id;
    int indice;
    char confirma;



    if(list != NULL && len > 0)
    {
        system("cls");

        printf("------------------------------------------------\n");
        printf("-                ***MODIFICAR***               -\n");
        printf("------------------------------------------------\n");
        printf("\t1. Ingrese id: \n");
        scanf("%d", &id);

        indice = findEmployeeById(list, len, id);

        if(indice == -1)
        {
            printf("No existe una persona con id: %d\n", id);
        }
        else
        {
            printf("\n\n");
            printEmployee(list[indice]);

            getCharacter(&confirma, "\n\nEsta seguro que desea modificar?: ");

        }
        if(confirma == 's')
        {
            switch(menuModify())
            {
            case 1:
                getString(list[indice].name, "Ingrese nombre: ", "Nombre demasiado largo, reingrese: ", 20);
                break;
            case 2:
                getString(list[indice].lastName, "Ingrese apellido: ", "Apellido demasiado largo, reingrese: ", 20);
                break;
            case 3:
                getFloat(&list[indice].salary, "Ingrese su salario (10000 hasta 100000): ", "Error, reingrese su salario (10000 hasta 100000): ", 10000, 100000);
                break;
            case 4:
                getInteger(&list[indice].sector, "Ingrese su sector (1 hasta 9): ", "Error, reingrese su sector (1 hasta 9): ", 1, 9);
                break;
            default:
                printf("No existe esta opcion\n");
                break;
            }
            printf("\nCambios realizados exitosamente\n");
            todoOk = 0;
        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }
    }

    return todoOk;
}


int searchFree(Employee list[], int len)
{
    int indice = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


void printEmployee(Employee oneEmployee)
{
    printf("    %-4d          %-20s         %-20s         $%-6.2f                 %3d", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}


int menuModify()
{
    int opcion;

    system("cls");
    printf("------------------------------------------------\n");
    printf("-                ***MODIFICAR***               -\n");
    printf("------------------------------------------------\n");
    printf("\t1). Nombre\n");
    printf("\t2). Apellido\n");
    printf("\t3). Salario\n");
    printf("\t4). Sector\n");
    printf("\t5). Salir\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int menu()
{
    int opcion;

    system("cls");
    printf("-------------------------------------------------\n");
    printf("-                ***ABM EMPRESAS***             -\n");
    printf("-------------------------------------------------\n");
    printf("\t1). Alta empleado\n");
    printf("\t2). Modificar empleado\n");
    printf("\t3). Baja empleado\n");
    printf("\t4). Informar empleados\n");
    printf("\t5). Salir\n");

    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(Employee* list, int len)
{
    int todoOk = -1;
    int opcion;
    int criterio;


    if(list != NULL && len > 0)
    {
        system("cls");
        printf("------------------------------------------------\n");
        printf("-                ***INFORMES***                -\n");
        printf("------------------------------------------------\n");
        printf("\t1). Ordenar alfabéticamente por Apellido y Sector\n");
        printf("\t2). Mostrar salario promedio \n");
        printf("\t3). Volver al menú\n");
        printf("\nIngrese opcion: ");
        printf("\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\n");
            getInteger(&criterio, "Ordenar ascendente opcion: 1\nOrdenar descendente opcion: 0\n", "Ingrese una opcion correcta\n", 0, 1);
            sortEmployees(list, len, criterio);
            printEmployees(list, len);
            break;
        case 2:
            sortEmployeesSalary(list, len);
            break;
        case 3:
            printf(" ");
            break;
        default:
            printf("Ingrese opción valida");
            break;
        }

        todoOk = 0;
    }
    return todoOk;
}


int sortEmployeesSalary(Employee* list, int len)
{
    int todoOk = -1;
    float accumSalary = 0;
    int accountant = 0;
    int accountantEmployee = 0;
    float average;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty)
            {
                accumSalary += list[i].salary;
                accountant++;
            }
        }
        if(accountant != 0)
        {
            average = accumSalary / accountant;
        }


        for(int i = 0; i < len; i++)
        {
            if(list[i].salary > average && (!list[i].isEmpty))
            {
                accountantEmployee++;
            }
        }

        system("cls");
        printf("\n1) El total de todos los salarios es: $%.2f", accumSalary);
        printf("\n2) El promedio de los salarios es: $%.2f", average);
        printf("\n3) La cantidad de empleados que superan el salario promedio es/son: %d\n", accountantEmployee);
        printf("\n");


        todoOk = 0;
    }
    return todoOk;
}

int validateFlag(Employee* list, int len, int* flag)
{
    int todoOk = 0;
    if(list != NULL && len > 0 && flag != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty)
            {
                *flag = 0;
            }
            else
            {
                *flag = 1;
                break;
            }
        }
    }

    return todoOk;
}


//FUNCTIONS, GET


int getCriterio(int* criterio)
{
    int todoOk = 0;

    if(criterio != NULL)
    {
        printf("Elija como ordenar (1 = ascendente) (0 = descendente)\n");
        scanf("%d", criterio);

        todoOk = 1;
    }

    return todoOk;
}


int getInteger(int* integer, char* mesagge, char* mesaggeError, int min, int max)
{
    int todoOk = -1;
    int numeroIngresado;

    if(integer != NULL && mesagge != NULL && mesaggeError != NULL && min < max)
    {
        printf("%s", mesagge);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mesaggeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *integer = numeroIngresado;
        todoOk = 0;
    }

    return todoOk;
}


int getFloat(float* flotante, char* message, char* messageError, float min, float max)
{
    int todoOk = -1;
    float numeroIngresado;

    if(flotante != NULL && message != NULL && messageError != NULL && min < max)
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%f", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", messageError);
            fflush(stdin);
            scanf("%f", &numeroIngresado);
        }

        *flotante = numeroIngresado;
        todoOk = 0;
    }

    return todoOk;
}


int getString(char* string, char* message, char* messageError, int max)
{
    int todoOk = -1;
    char auxCad[256];

    if(string != NULL && message != NULL && messageError != NULL && max > 0)
    {
        printf("%s", message);
        fflush(stdin);
        gets(auxCad);

        onlyString(auxCad);

        while(strlen(auxCad) > max)
        {
            printf("%s", messageError);
            fflush(stdin);
            gets(auxCad);

            onlyString(auxCad);
        }
        validateStringTidy(auxCad);

        strcpy(string, auxCad);
        todoOk = 0;
    }

    return todoOk;
}


int getCharacter(char* character, char* message)
{
    int todoOk = -1;

    if(character != NULL && message != NULL)
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%c", character);
        todoOk = 0;
    }

    return todoOk;
}


int validateStringTidy(char* string)
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);

        while( string[i] != '\0')
        {
            if( string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }
            i++;
        }

        todoOk = 1;
    }

    return todoOk;
}


int onlyString(char* string)
{
    int todoOk = 0;
    int i=0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if( string[i] != ' ' )
            {
                if( (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') )
                {
                    todoOk = 1;
                    while(todoOk)
                    {
                        printf("Error, no se permiten numeros o simbolos. Reingrese: ");
                        fflush(stdin);
                        gets(string);
                        i = 0;
                        todoOk = 0;
                    }
                }
            }
            i++;
        }
    }

    return todoOk;
}

