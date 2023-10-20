#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int a[100], n,top=-1, i,temp, value, position;

void push(int);
void pop();
void display();

void main()
{
    int choice,x;
    // clrscr();
    printf("\nEnter the size of Stack:\t");
    scanf("%d",&n);
    do
    {
	printf("\n\n*-------MENU-------*\n");
	printf("1.Display\n");
	printf("2.Push\n");
	printf("3.Pop\n");
	printf("4.Exit\n");
	printf("*------------------*");
	printf("\nEnter Your Choice:\t");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	    if (n == 0)
	    {
		printf("No elements to display");
	    }
	    else
	    {
		display();
	    }
	    break;
	case 2:
	    printf("Enter the element of stack ");
		scanf("%d",&x);

	    push(x);
	    break;
	case 3:
	    pop();
	    break;

	    
	case 4:
		    exit(0);
		    break;
	default:
	    printf("\nInvalid choice\n");
	    break;
	}
    } while (choice <= 4);
    getch();
}

// Creating stack elements
void push(int x)
{
	if(top == n-1){
		printf("Stack Overflow\n");
	}else{
		top=top+1;
		a[top]=x;
	}
}

// displaying stack elements
void display()
{
    int i;
    printf("\nStack elements are:\n");
    for(i=top;i>=0;i--)
    {
	printf("%d\t", a[i]);
    }
}

// deleting stack elements
void pop()
{
	if(top==-1){
			printf("Stack is empty\n");
	}else{
		     temp=a[top];
		     top=top-1;
		     printf("Deleted element is %d \n",temp);
		     }
	}

/*
Enter the size of Stack:	3
*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	2
Enter the element of stack 7
*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	2
Enter the element of stack 9
*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	1
Stack elements are:
9	7	

*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	3
Deleted element is 9 


*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	3
Deleted element is 7 


*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	3
Stack is empty


*-------MENU-------*
1.Display
2.Push
3.Pop
4.Exit
*------------------*
Enter Your Choice:	*/
