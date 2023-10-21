#include<stdio.h>
#include<stdlib.h>

int a[100],n,i,value,position;

void create();
void display();
void insert();

int main(){
    int ch;
    create();
    do{
        printf("*-------------MENU---------------*\n");
        printf("1.Display\n");
        printf("2.Insert\n");
        printf("3.Exit\n");
        printf("Enter the choice\t");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            display();
            break;
        
        case 2:
           insert();
            break;
        
        case 3:
            exit(0);
            break;
        
        default:
        printf("Invalid Choice.!!\n");
            break;
        }
    }while(ch<4);
    return 1;
}

//Creating array elements
void create(){
    printf("\nEnter the size of array elements:\t");
    scanf("%d",&n);

    printf("Enter the elements of array:\t");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

//Display array elements
void display(){
    printf("Array elements are:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

//Insert in array

void insert(){
    printf("Insert the position of new element:\t");
    scanf("%d",&position);

    if(position<=n){
        printf("\nEnter the  element you have to insert:\t");
        scanf("%d",&value);
        for(i=n-1;i>=position;i--){
            a[position+1]=a[i];
        }
        a[position-1]=value;
        n=n+1;
    }else{
            printf("\nEnter the position between 1 to %d",n);
    }
}