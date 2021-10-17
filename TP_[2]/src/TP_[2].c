/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Cantos Santiago Felipe
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000


int main()
{

	setbuf(stdout, NULL);

    Employee list[TAM];
    char stay = 's';
    int nextId = 1;
    int flag = 0;

    initEmployees(list, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            addEmployee(list, TAM, nextId, list->name, list->lastName, list->salary, list->sector);
            nextId++;
            flag = 1;
            break;
        case 2:
            if(flag)
            {
                modifyEmployee(list, TAM);
            }
            else
            {
                printf("Primero darse de alta en opción 1\n");
            }
            break;
        case 3:
            if(flag)
            {
                removeEmployee(list, TAM, list->id);
                validateFlag(list, TAM, &flag);
            }
            else
            {
                printf("Primero darse de alta en opción 1\n");
            }
            break;
        case 4:
            if(flag)
            {
                menuInformes(list, TAM);
            }
            else
            {
                printf("Primero darse de alta en opción 1\n");
            }
            break;
        case 5:
            stay = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            fflush(stdin);
            break;
        }

        system("pause");

    }
    while(stay == 's');


    system("pause");

    return EXIT_SUCCESS;
}

