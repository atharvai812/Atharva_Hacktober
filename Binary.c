#include <stdio.h>
#include <conio.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

int ele, count = 1, digit;

typedef struct Node node;
node *insert(node *, int);
node *root = NULL;
void inorder(node *);
void preorder(node *);
void postorder(node *);
void search(node *, int);
node *deleteme(node *, int);

void main()
{
	int x, choice;
	clrscr();

	do
	{
		printf("Select an option\n");
		printf("1. Insert\n");
		printf("2. Inorder\n");
		printf("3. preorder\n");
		printf("4. postorder\n");
		printf("5. Search\n");
		printf("6. Delete\n");
		printf("7. Exit\n");
		printf("Enter the choice:\t");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element: ");
			scanf("%d", &x);
			root = insert(root, x);
			break;
		case 2:
			inorder(root);
			break;
		case 3:
			preorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			printf("Enter the element to search: ");
			scanf("%d", &ele);
			search(root, ele);
			break;

		case 6:
			printf("Enter the element to delete: ");
			scanf("%d", &digit);
			root = deleteme(root, digit);
			break;
		case 7:
			exit(0);
			break;
		default:
			printf(" Invalid choice ");
		}
	} while (choice < 7);
	getch();
}

node *insert(node *p, int digit)
{
	if (p == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->left = p->right = NULL;
		p->data = digit;
		count++;
	}
	else
	{
		if (count % 2 == 0)
		{
			p->left = insert(p->left, digit);
		}
		else
		{
			p->right = insert(p->right, digit);
		}
	}
	return (p);
}

void inorder(node *p)
{
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d\t", p->data);
		inorder(p->right);
	}
}

void preorder(node *p)
{
	if (p != NULL)
	{
		printf("%d\t", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(node *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t", p->data);
	}
}

void search(node *p, int digit)
{
	if (p == NULL)
	{
		printf("%d not present in the tree!!", digit);
	}
	else if (p->data == digit)
	{
		printf("element is founded");
	}
	else if (digit < p->data)
	{
		search(p->left, digit);
	}
	else
	{
		if (digit > p->data)
		{
			search(p->right, digit);
		}
	}
}

node *deleteme(node *p, int digit)
{
	node *temp;
	if (p == NULL)
	{
		printf("Element not found");
	}
	else if (digit < p->data)
	{
		p->left = deleteme(p->left, digit);
	}
	else if (digit > p->data)
	{
		p->right = deleteme(p->right, digit);
	}
	else
	{
		if (p->left == NULL && p->right == NULL)
		{
			free(p);
			p = NULL;
		}
		else if (p->left == NULL)
		{
			temp = p;
			p = p->right;
			free(temp);
		}
		else if (p->right == NULL)
		{
			temp = p;
			p = p->left;
			free(temp);
		}
		else
		{
			temp = p->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			p->data = temp->data;
			p->right = deleteme(p->right, temp->data);
		}
	}
	return p;
}

/*
Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	1
Enter the element: 41

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	1
Enter the element: 23

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	1
Enter the element: 53

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	1
Enter the element: 54

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	2
54	23	41	53

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	3
41	23	54	53

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	3
41	23	54	53

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	4
54	23	53	41

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	5
Enter the element to search: 23
element is founded

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	6
Enter the element to delete: 54

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	6
Enter the element to delete: 23

Select an option
1. Insert
2. Inorder
3. preorder
4. postorder
5. Search
6. Delete
7. Exit
Enter the choice:	7




*/
