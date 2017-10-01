/*
Assigned by:
Nir_Shmueli #304844095
Yosef_(sefi)_Piscon #300508348
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void showMenuEx2();
void mainExe1(); 
void mainExe2();
void horse();

int main()
{
	int select;
	do
	{
		printf("---MAIN MENU---\n(1) exe 1\n(2) exe 2\n(3) horse\n(0)exit\n----->Enter your choice: ");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			flushall();
			mainExe1();
			break;
		case 2: mainExe2();
			break;
		case 3: horse();
			break;
		case 0:printf("BYE.\n");
			break;
		}
	}while(select);
	system("pause");
	return 0;
}

void mainExe1()
{
	char expression[MaxStack];
	stack s1 , s2;
	create_stack (&s1);
	create_stack (&s2);
	printf("\n----EXE 2-----\nPlease enter a string expression to evaluate --> (%d max size)\n\n",MaxStack);
	gets(expression);
	printf("\n\nOutput table for given string is: \n\n");
	printf ("|Operation | Operand1 | Operand2  | Result |\n");
	printf("--------------------------------------------\n");
	if(!selector(expression,&s1,&s2))
		printf("\n): wrong input :(\n");
	printf("\nEnter any key to back to main menu\n");
	system("pause");
}
void mainExe2()
{
	int input,temp1,temp2 ,i ;
	list p1, p2,p3;
	init_list(&p1);
	init_list(&p2);
	init_list(&p3);
	printf("The polynomials P1, P2, P3 were initialized\n");
	showMenuEx2();
	do{
		printf("\n-----> Enter your choice: ");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("-->Enter the factor: \n");
			scanf("%d",&temp1);
			printf("-->Enter the power: \n");
			scanf("%d",&temp2);
			insertElement(&p1 , temp1,temp2);
			printf("* element was added to P1 *\n");
			break;
		case 11:
			for(i=0;i<3 ;i++)
			{
				printf("-->Enter the factor: \n");
				scanf("%d",&temp1);
				printf("-->Enter the power: \n");
				scanf("%d",&temp2);
				insertElement(&p1 , temp1,temp2);
			}
			printf("* elements was added to P1 *\nP1:");
			printPoly(&p1);
			printf("\n");
			break;
		case 2:
			printf("-->Enter the factor: \n");
			scanf("%d",&temp1);
			printf("-->Enter the power: \n");
			scanf("%d",&temp2);
			insertElement(&p2 , temp1,temp2);
			printf("* element was added to P2 *");
			break;
		case 12:
			for(i=0;i<3 ;i++)
			{
				printf("-->Enter the factor: \n");
				scanf("%d",&temp1);
				printf("-->Enter the power: \n");
				scanf("%d",&temp2);
				insertElement(&p2 , temp1,temp2);
			}
			printf("* elements was added to P2 *\nP2:");
			printPoly(&p2);
			printf("\n");
			break;
		case -1:
			resetPoly(&p1);
			printf("#P1 was re-initialized\n");
			break;
		case -2:
			resetPoly(&p2);
			printf("#P2 was re-initialized\n");
			break;
		case 3:
			printf("P1: ");
			printPoly(&p1);
			printf("\n");
			printf("P2: ");
			printPoly(&p2);
			printf("\n");
			break;
		case 4:
			p3=connectingPolynomials(&p1, &p2);
			printf(">> P1 + P2= ");
			printPoly(&p3);
			resetPoly(&p3);
			printf("\n");
			break;
		case 5:
			p3=subtractionPolynomials(&p1,&p2);
			printf(">> P1 - P2= ");
			printPoly(&p3);
			resetPoly(&p3);
			printf("\n");
			break;
		case 6: 
			printf("-->Enter c:\n");
			scanf("%d",&temp1);
			p3=multiplyingWithNumber(&p1, temp1);
			printf(">> %d * P1 = ",temp1);
			printPoly(&p3);
			resetPoly(&p3);
			printf("\n");
			break;
		case 7:
			printf("the biggest power is %d\n ", biggestPower(&p1));
			break;
		case 8:
			p3 = multiplyingTwoPoly(&p1,&p2);
			printf(">> P1 * P2 = ");
			printPoly(&p3);
			resetPoly(&p3);
			printf("\n");
			break;
		case 0: 
			freeList(&p1);
			freeList(&p2);
			freeList(&p3);
			break;
		case 100:
			showMenuEx2();
			break;
		}
	}while(input);
}

void showMenuEx2()
{
	printf("\n~-~-~-~-~-~-EXE 2: MENU~-~-~-~-~-~-\n");
	printf("\SET\n-----------\n");
	printf("(1) add element to P1\t(11) add 3 element in a row to P1\n(2) add element to P2\t(12) add 3 element in a row to P2\n(-1) reset P1\n(-2) reset P2\n(3) print P1 and P2\n");
	printf("\nDO & PRINT\n-----------\n");
	printf("(4) P1 + P2\n(5) P1 - P2\n(6) c * P1\n(7) P1 biggest power\n(8) BONUS - P1 * P2\n-----------\n(0)EXIT (back to main menu)\n(100) show this menu again\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
}

void horse()
{
printf("     >>\.						\n");
printf("     /_  )`.					\n");
printf("    /  _)`^)`.   _.---._		\n");
printf("   (_,' \  `^-)        `.		\n");
printf("         |              |		\n");
printf("         \              / |		\n");
printf("        / \  /.___.'\  (\ (_	\n");
printf("       < , ||     \ |`. \`-'	\n");
printf("        \\ ()      )|  )/		\n");
printf("        |_>|>     /_] //		\n");
printf("          /_]        /_]		\n");
//free(horse);
}
