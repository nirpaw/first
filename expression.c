#include <stdio.h>
#include "header.h"

void create_stack (stack *ps){
	ps->top = -1;
}

int push (char x, stack *ps){
	if (ps->top < MaxStack-1){
		ps->top++;
        ps->items[ps->top] = x;
        return 1;
	}
	return 0;
}

int pop (stack *ps, char *px){
	if (ps->top >= 0){
		*px = ps->items[ps->top];
        ps->top--;
        return 1;
	}
	return 0;
}

int stack_top (stack *ps, char *px){
	if (ps->top >= 0){
		*px = ps->items[ps->top];
        return 1;
	}
	return 0;
}

int stack_is_empty (stack *ps){
	return ps->top == -1;
}

int stack_is_full (stack *ps){
	return ps->top == MaxStack-1;
}

void printFunction(char operation, char operand_1 , char operand_2 , char result){
	printf("| %c\t   |  %c\t      |  %c\t  |  %c     |\n" ,operation, operand_2, operand_1, result);
}

int selector(char expression[], stack *s1, stack *s2)
{
	int i, rank_temp, rank_top;
	char temp, top, operation, operand1,operand2, result = 'Z';
	for(i = 0; expression[i] != '\0'; i++)
	{
		temp = expression[i];	
		if(temp >= '0' && temp <= '9' || temp >= 'A' && temp <= 'H')
		{
			push(temp, s1);
			continue;
		}
		else 
			rank_temp=rankOperations(temp); // also check if the char is acceptable
		if(temp==' ')
			continue;
		if (!rank_temp)
			return 0;
		if(stack_is_empty(s2)){
				push(temp, s2);
				continue;
		}
		else
		{
			stack_top(s2 , &top);
			rank_top=rankOperations(top);
			if(rank_temp==3 && rank_top==3 ) // BONUS
				push(temp, s2);
			else if(rank_temp>rank_top)
				push(temp, s2);
			else
			{
				do{
					//Popping values from the stacks to print
					pop(s2, &operation);
					pop(s1, &operand1);
					pop(s1, &operand2);
					printFunction(operation,operand1,operand2,result);
					printf("--------------------------------------------\n");
					push(result--, s1);
					stack_top(s2, &top);
					rank_top=rankOperations(top);
				}while((rank_temp<=rank_top) && (!stack_is_empty(s2)));
				push(temp, s2);
			}
		}
	}
	
	while(!stack_is_empty(s2))
	{
		pop(s2, &operation);
		pop(s1, &operand1);
		pop(s1, &operand2);
		printFunction(operation, operand1, operand2, result);
		printf("--------------------------------------------\n");
		if(!stack_is_empty(s2))
			push(result--, s1);
	}
	return 1;
}

int rankOperations(char ch)
{
	if(ch=='^')
		return 3;
	if(ch=='*'||ch=='/')
		return 2;
	if(ch=='+'||ch=='-')
		return 1;
	return 0;  // wrong input flag
}

