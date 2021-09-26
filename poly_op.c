#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int num;
	int coeff;
	struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node *, struct node *, struct node *);
struct node *multi_poly(struct node *, struct node *, struct node *);
struct node *add_node(struct node *, int, int);

int option;

int main()
{
	
	do
	{
		printf("\n******* MAIN MENU *******");
		printf("\n 1. Enter the first polynomial");
		printf("\n 2. Display the first polynomial");
		printf("\n 3. Enter the second polynomial");
		printf("\n 4. Display the second polynomial");
		printf("\n 5. Add the polynomials");
		printf("\n 6. Display the result of Addition");
		printf("\n 7. Multiply the polynomials");
		printf("\n 8. Display the result of Multiplication");
		printf("\n 9. QUIT");
		printf("\n\nEnter your option : ");
		scanf("%d", &option);
	
		switch(option)
		{
			case 1: start1 = create_poly(start1);
			break;
			case 2: start1 = display_poly(start1);
			break;
			case 3: start2 = create_poly(start2);
			break;
			case 4: start2 = display_poly(start2);
			break;
			case 5: start3 = add_poly(start1, start2, start3);
			break;
			case 6: start3 = display_poly(start3);
			break;
			case 7: start4 = multi_poly(start1, start2, start4);
			break;
			case 8: start4 = display_poly(start4);
			break;
		}
	}while(option!=9);
	
	if(option==9)
		printf("\n\n********** END **********\n");
			
	return 0;
}

struct node *create_poly(struct node *start)
{
	printf("\n*****Enter number as -1 to end the polynomial*****\n");
	struct node *new_node, *ptr;
	int n, c;
	printf("\nEnter the number : ");
	scanf("%d", &n);
	printf("\tEnter its coefficient : ");
	scanf("%d", &c);
	while(n != -1)
	{
		if(start == NULL)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node -> num = n;
			new_node -> coeff = c;
			new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while(ptr -> next != NULL)
				ptr = ptr -> next;
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node -> num = n;
			new_node -> coeff = c;
			new_node -> next = NULL;
			ptr -> next = new_node;
		}
		printf("\nEnter the number : ");
		scanf("%d", &n);
		if(n == -1)
			break;
		printf("\tEnter its coefficient : ");
		scanf("%d", &c);
	}
	return start;
}

struct node *display_poly(struct node *start)
{
	struct node *ptr;
	ptr = start;
	switch(option)
	{
		case 2: printf("\nFirst poly is :");
		break;
		case 4: printf("\nSecond poly is :");
		break;
		case 6: printf("\nAddition of poly's is :");
		break;
		case 8: printf("\nMultiplication of poly's is :");
		break;
	}
	
	while(ptr != NULL)
	{
		printf("  %d x^%d", ptr -> num, ptr -> coeff);
		ptr = ptr -> next;
	}
	printf("\n");
	return start;
}

struct node *add_poly(struct node *start1, struct node *start2, struct node *start3)
{
	struct node *ptr1, *ptr2;
	int sum_num;
	ptr1 = start1, ptr2 = start2;
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1 -> coeff == ptr2 -> coeff)
		{
			sum_num = ptr1 -> num + ptr2 -> num;
			start3 = add_node(start3, sum_num, ptr1 -> coeff);
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next;
		}
		else if(ptr1 -> coeff > ptr2 -> coeff)
		{
			start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
			ptr1 = ptr1 -> next;
		}
		else if(ptr1 -> coeff < ptr2 -> coeff)
		{
			start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
			ptr2 = ptr2 -> next;
		}
	}
	if(ptr1 == NULL)
	{
		while(ptr2 != NULL)
		{
			start3 = add_node(start3, ptr2 -> num, ptr2 -> coeff);
			ptr2 = ptr2 -> next;
		}
	}
	if(ptr2 == NULL)
	{
		while(ptr1 != NULL)
		{
			start3 = add_node(start3, ptr1 -> num, ptr1 -> coeff);
			ptr1 = ptr1 -> next;
		}
	}
	return start3;
}

struct node *multi_poly(struct node *start1, struct node *start2, struct node *start4)
{
	struct node *ptr1, *ptr2;
	int multi_num, sum_coeff;
	ptr1 = start1, ptr2 = start2;
	
	int count1 = 0, count2 = 0; 
    while (ptr1 != NULL) 
    { 
        count1++; 
        ptr1 = ptr1 -> next; 
    }
    while (ptr2 != NULL) 
    { 
        count2++; 
        ptr2 = ptr2 -> next; 
    }
    ptr1 = start1, ptr2 = start2;
	if(count1 >= count2)
	{
		while(ptr1 != NULL)
		{
			while(ptr2 != NULL)
			{
				multi_num = ptr1 -> num * ptr2 -> num;
				sum_coeff = ptr1 -> coeff + ptr2 -> coeff;
				start4 = add_node(start4, multi_num, sum_coeff);
				ptr2 = ptr2 -> next;
			}
			ptr1 = ptr1 -> next;
			ptr2 = start2;
		}
		if(ptr1 == NULL)
			return start4;
	}
	else
	{
		while(ptr2 != NULL)
		{
			while(ptr1 != NULL)
			{
				multi_num = ptr1 -> num * ptr2 -> num;
				sum_coeff = ptr1 -> coeff + ptr2 -> coeff;
				start4 = add_node(start4, multi_num, sum_coeff);
				ptr1 = ptr1 -> next;
			}
			ptr2 = ptr2 -> next;
			ptr1 = start1;
		}
		if(ptr2 == NULL)
			return start4;
	}
	
	/*struct node *temp, *preptr, *ptr, *fptr, *final_node;
	int sumf = preptr -> num;
	fptr = NULL;
	temp = start4;
	preptr = start4;
	ptr = preptr;
	start4 = final_node;
	while(preptr != NULL)
	{
		do
		{
			ptr = ptr -> next;
			if(preptr -> coeff == ptr -> coeff)
			{
				sumf = sumf + ptr -> num;
				while(temp != ptr)
				{
					if(temp -> coeff == ptr -> coeff)
					{
						temp = start4;
						break;
					}
					temp = temp -> next;
				}	
			}	
		}while(ptr != NULL);
		final_node = (struct node *)malloc(sizeof(struct node));
		final_node -> num = sumf;
		final_node -> coeff = preptr -> coeff;
		final_node -> next = NULL;
		fptr -> next = final_node;
		preptr = preptr -> next;
		ptr = preptr -> next;
		temp = start4;
	}
	return start4;*/
}

struct node *add_node(struct node *start, int n, int c)
{
	struct node *ptr, *new_node;
	if(start == NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> num = n;
		new_node -> coeff = c;
		new_node -> next = NULL;
		start = new_node;
	}
	else
	{
		ptr = start;
		while(ptr -> next != NULL)
			ptr = ptr -> next;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> num = n;
		new_node -> coeff = c;
		new_node -> next = NULL;
		ptr -> next = new_node;
	}
	return start;
}
