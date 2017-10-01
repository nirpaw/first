#include <stdio.h>
#include <stdlib.h>
#include "header.h"

list  multiplyingTwoPoly (list *p1 , list *p2 )
{
	node *curr1 = p1->head;
	node *curr2 = p2->head;
	list ans;
	init_list(&ans);
	while(curr1!=NULL)
	{
		while(curr2!=NULL)
		{
			insertElement(&ans , ((curr1->factor)*(curr2->factor)), ((curr1->power)+(curr2->power)));
			curr2=curr2->next;
		}
		curr1=curr1->next;
		curr2=p2->head;
	}
	return ans;
}

void resetPoly(list *lst)
{
	freeList(lst);
	init_list(lst);
}

void freeList(list *lst)
{
	node *curr= lst->head;
	node *temp=NULL;
	while(curr!=NULL)
	{
		temp=curr;
		curr=curr->next;
		free(temp);
	}
}

void printPoly(list* lst)
{
	node *curr= lst->tail;
	int f, p, notFirst=0;
	if(isEmpty(lst))
	{
		printf("Zero (Empty Polynomial)");
		return;
	}
	while(curr!=NULL)
	{
		f=curr->factor;
		p=curr->power;
		curr=curr->prev;
		if(f>=0 && notFirst)
			printf("+");
		if(f==-1)
			printf("-");
		if(f!=1&&f!=-1)
			printf("%d",f);
		if(p==1)
			printf("X");
		if(p!=0&&p!=1)
			printf("X^%d",p);
		notFirst=1;
	}
}

int biggestPower (list *lst)
{
	if(isEmpty(lst))
		return -1;
	else
		return lst->tail->power;
}

list multiplyingWithNumber(list *lst , int num)
{
	node *curr= lst->head;
	list ans;
	init_list(&ans);
	while(curr!=NULL)
	{
		insertElement(&ans, (curr->factor)*num ,curr->power);
		curr=curr->next;
	}
	return ans;
}

void deleteNote( list *lst , node *link)
{
	node *temp =NULL;
	if (link == lst->head)
	{
		temp = lst->head;
		if(temp->next == NULL) //if only one link			
			init_list(lst);
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		free(temp);
		return;
	}

	if (link == lst->tail)
	{
		temp = lst->tail;
		if(temp->prev == NULL)	//if only one link
			init_list(lst);
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		free(temp);
		return;
	}
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
}

list subtractionPolynomials( list *p1 , list *p2)
{

	node *curr1 = p1->head;
	node *curr2 = p2->head;
	list ans;
	init_list(&ans);
	for(;curr1!=NULL; curr1=curr1->next)
		insertElement(&ans , curr1->factor  , curr1->power);
	for(;curr2!=NULL; curr2=curr2->next)
		insertElement(&ans, -(curr2->factor)  , curr2->power);
	return ans;
}

list connectingPolynomials(list *p1 , list *p2)
{
	node *curr1 = p1->head;
	node *curr2 = p2->head;
	list ans;
	init_list(&ans);
	for(;curr1!=NULL; curr1=curr1->next)
		insertElement(&ans , curr1->factor  , curr1->power);
	for(;curr2!=NULL; curr2=curr2->next)
		insertElement(&ans , curr2->factor  , curr2->power);
	return ans;
}

void insertElement(list *lst, int factor, int power)
{
	node *current= lst->head;
	node* link=NULL;
	int i;
	if(factor==0)
		return;
	for(i = 0 ;current!=NULL && power > current->power; i++ , current = current->next); // get the right index
	if(current!=NULL && power==current->power) // add to already exist value - only update the factor
		(current->factor)+=factor;
	else //creat note
	{
			link = (node*)malloc(sizeof(node));
			link->factor = factor;
			link->power= power;
			link->next = NULL;
			link->prev = NULL;

		if(i==0) // smallest -add first
		{
			if(isEmpty(lst))
				lst->head = lst->tail = link;	
			else 
			{
				lst->head->prev = link;
				link->next = lst->head;
				lst->head = link;
			}
		}
		else if(current==NULL) // biggest - add last 
		{
				lst->tail->next = link;     
				link->prev = lst->tail;
				lst->tail = link;
		}
		else // somewhere in the middle-  add before
		{
			link->next = current;
			link->prev = current->prev;
			current->prev->next = link;
			current->prev = link;
		}
	}
	if(current!=NULL && current->factor==0)
		deleteNote( lst, current);
}

void init_list(list *lst) //  creat empty list 
{
	lst->head = lst->tail = NULL;	
}

int isEmpty(list *lst)
{
	return lst->head == NULL;
}

