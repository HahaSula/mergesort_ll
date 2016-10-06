#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} LIST;


LIST *append( LIST *, int );
LIST *sort( LIST * );

LIST *mergesort( LIST * ,int );
LIST *merge( LIST * , LIST * );
LIST *list_switch( LIST *, LIST * );
int countln(LIST *);
void swap(LIST * , LIST *);
LIST *NofList(LIST *, int );
void print_list( LIST * );

int main(void)
{
    LIST *try;
    int i;

    // This is just testing code
    try = NULL;
    try = append( try, 5 );
    try = append( try, 2 );
    try = append( try, 9 );
    try = append( try, 8 );
    try = append( try, 1 );
    try = append( try, 7 );
	try = append( try, 7 );
    
	printf("Original list:\n");
    print_list( try );
	
	    
	try = mergesort( try , countln(try));
    printf("Sorted list:\n");
    print_list( try );
	
    return 0;
}

void print_list( LIST *t )
{
    while( t != NULL ) {
        printf( "%d,", t->data );
        t = t->next;
    }
	printf("\n");
}

LIST *append( LIST *start, int newdata )
{
    LIST *new, *end, *ret;

    if( (new = (LIST *)malloc(sizeof(LIST))) == NULL) {
        fprintf( stderr, "Memory Allocation error.\n" );
        // In Windows, replace following with a return statement.
        exit(1);
    }
    if( start == NULL )
        ret = new;
    else {
        ret = start;
        end = start;
        while( end->next != NULL ) end = end->next;
        end->next = new;
    }
    new->data = newdata;
    new->next = NULL;
    return ret ;
}

LIST *mergesort( LIST *start , int number)
{
	if(start == NULL) 
		return NULL ;
	if(number == 1)
		return start ;
	//spilt	
	LIST *left , *right;
	left = start;	
	right = NofList(start,number/2+1);
	NofList(start,number/2)->next = NULL;	 
	
	
	left = mergesort(left , number/2) ;	
	right = mergesort(right ,number/2+(number%2));	
	start = merge(left,right);
	

	return start;
}
LIST *merge(LIST * a , LIST *b )
{	
	
	
	if(a == NULL)
	{
		return b;
	}
	else if(b == NULL)
	{
		return a ;
	}
	LIST * start,* current;
	
	if(a->data > b->data)
	{
		LIST *temp;
		temp = a ;
		a = b ; 
		b = temp ;
	}
	current = a ;  
	start = current;
	a=a->next;	
	current->next = NULL;	
	while((a!=NULL)&&(b!=NULL))
	{	
		
		
		if(a->data < b->data)
		{
			current->next = a;
			a = a->next;
			
		}
		else
		{
			current->next = b;
			b = b->next;
		}
		current = current ->next;
	}
	if(a == NULL)
		current->next = b ;
	if(b == NULL)
		current->next = a ;
	
	return start ;
	
}
int countln(LIST *start)
{
	int answer = 1 ;	
	if(start == NULL)
		return 0 ;
	while(start->next!=NULL)
	{
		start = start->next;
		answer++;
	}
	return answer;
}
void swap(LIST *a, LIST *b)
{
	a->data = a->data ^ b->data;
	b->data = a->data ^ b->data;
	a->data = a->data ^ b->data;
	return ;
}

//start as 1 ;
LIST *NofList(LIST *start, int number)
{
	if(start == NULL)
	{
		perror("pass null str in Noflist");
		return NULL ;
	}	
	if(number == 1)
		return start;
	int i  ; 
	for(i = 0 ; i < number-1 ; i++)
	{
		start = start->next;
	}
	if(start == NULL)
	{
		perror("pass a number bigger than ths list has");
	}

	return start ;
}

