#define MaxStack 100

typedef struct{
	int top;
	char items[MaxStack];
}stack;

typedef struct node 
{
   double factor;	
   int power;
   struct node *next;
   struct node *prev;
}node;

typedef struct list
{
	node *head;
	node *tail;
}list;
// exe1 
void create_stack(stack *);

int push(char, stack *);

int pop(stack *, char *);

int stack_top(stack *, char *);

int stack_is_empty(stack *);

int stack_is_full(stack *);

void printFunction(char, char, char, char);

int selector (char*,stack*,stack*);

int rankOperations(char ch);

//exe2
list multiplyingTwoPoly (list *p1 , list *p2 );

void resetPoly(list *lst);

void freeList(list *lst);

void printPoly(list* lst);

int biggestPower (list *lst);

list multiplyingWithNumber(list *lst , int num);

void deleteNote( list *lst , node *link);

list subtractionPolynomials(list *p1 , list *p2);

list connectingPolynomials(list *p1 , list *p2);

void insertElement(list *lst, int factor , int power);

void init_list(list *lst);

int isEmpty(list *lst);


