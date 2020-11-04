#include<stdio.h>
#include<stdlib.h>
 void create_DoublyLinkedList();
 void Display_DoublyLinkedList();
 void Insert_begin__DoublyLinkedList();
 void Insert_End__DoublyLinkedList();
 void Insert_Pos__DoublyLinkedList();
 void Delete_Begin_DoublyLinkedList();
 void Delete_End_DoublyLinkedList();
 void Delete_POS_DoublyLinkedList();
 void reverseDoublyLL();

 struct node_two
 {
 	int info;
 	struct node_two *next;
 	struct node_two *prev;
};
struct node_two *start = NULL;
struct node_two *tail = NULL;

void create_DoublyLinkedList()
{
	struct node_two *ptr;
	struct node_two *temp;
	temp= (struct node_two*)malloc(sizeof(struct node_two));
	if(temp == NULL)
	{
		printf("Out of memory \n");
	}

    printf("Enter the data in newly created node\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->prev=NULL;
	printf("\n");

	if(start==NULL)
	{
		start = temp;
		tail = temp;
	}
	else
	{   
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}

void Display_DoublyLinkedList()
{
	struct node_two *ptr;
	if(start == NULL)
	{
		printf("The Doubly Linked List is Empity\n");
		printf("\n");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->info);
			ptr=ptr->next;
		}

	}
}

void reverseDoublyLL()
{
    struct node_two *ptr;
    ptr=start;
    if(start==NULL)
    {
    	printf("Doubly Linked List is empty\n");
    }
    struct node_two *temp;
    while(ptr!=NULL)
    {
        temp=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=temp;
        ptr=ptr->prev;
        if(ptr!=NULL && ptr->next==NULL)
        {
        	start=ptr;
        }
    }

}

void Insert_begin__DoublyLinkedList()
{
struct node_two *temp;
temp = (struct node_two*)malloc(sizeof(struct node_two));
if(temp==NULL)
{
	printf("Out of memory\n");
}

printf("Enter the data in newly created node\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->prev=NULL;
printf("Inserting the newly created node at the beginning of the Doubly Linked list\n");
	printf("\n");

	if(start==NULL)
	{
		start = temp;
		tail = temp;
	}
	else
	{   
		temp->next=start;
		start->prev=temp;
		start=temp;
	}

}

void Insert_End__DoublyLinkedList()
{
struct node_two *temp;
temp = (struct node_two*)malloc(sizeof(struct node_two));
if(temp==NULL)
{
	printf("Out of memory\n");
}

printf("Enter the data in newly created node\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->prev=NULL;
	printf("Inserting the newly created node at the ending of the Doubly Linked list\n");
	printf("\n");

	if(start==NULL)
	{
		start = temp;
		tail = temp;
	}
	else
	{   
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}

}

int lengthDoublyLinkedList()
{
struct node_two *ptr;
int count=0;
if(start==NULL)
{
	printf("The Doubly Linked List is Empity\n");
		printf("\n");
	return 0;
}
else
{
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
}

void Insert_Pos__DoublyLinkedList()
{
struct node_two *temp;
struct node_two *ptr;
int i; //loop variable
int pos; //position at which the newly created node is tobe inserted
int c; //stores the number of nodes in a doubly linked list
temp = (struct node_two*)malloc(sizeof(struct node_two));
c=lengthDoublyLinkedList();

if(temp==NULL)
{
	printf("Out of memory\n");
}

printf("Enter the position at which the newly created node is to be inserted\n");
scanf("%d",&pos);
printf("Enter the data in newly created node\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->prev=NULL;
printf("Inserting the newly created node at the position specified by the user in the Doubly Linked list\n");
	printf("\n");

if(pos < 1 || pos > c)
{
	printf("Invalid Position Entered by the user\n");
	printf("\n");
}
else if(pos == 1)
{
	if(start==NULL)
	{
		start = temp;
		tail = temp;
	}
	else
	{   
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
else if(pos==c)
{
	if(start==NULL)
	{
		start = temp;
		tail = temp;
	}
	else
	{   
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
else
{
	ptr = start;
	for(i=1;i<pos-1;i++)
	{
		ptr=ptr->next;
	}
	temp->prev=ptr;
	temp->next=ptr->next;
	ptr->next=temp;
    temp->next->prev=temp;
}

}

void Delete_Begin_DoublyLinkedList()
{
	struct node_two* ptr; //ptr pointer
	if(start==NULL)
	{
		printf("The Doubly Linked List is Empity\n");
		printf("\n");
	}
	else
	{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		ptr->next=NULL;
		free(ptr);
	}
}

void Delete_End_DoublyLinkedList()
{
	struct node_two* ptr; //ptr pointer
	if(start==NULL)
	{
		printf("The Doubly Linked List is Empity\n");
		printf("\n");
	}
	else
	{
		ptr=tail;
		tail=tail->prev;
		tail->next=NULL;
		ptr->prev=NULL;
		free(ptr);
	}
}

void Delete_POS_DoublyLinkedList()
{
 struct node_two* ptr; //ptr pointer
 int i; //while loop variable
 int c; // variable to store the length of a doubly linked list
 c=lengthDoublyLinkedList();
 int pos; //position of the node that you want to delete
 printf("Enter the position of the node that you want to delete from the doubly Linked List\n");
 scanf("%d",&pos);
 printf("\n");
	if(start==NULL)
	{
		printf("The Doubly Linked List is Empity\n");
		printf("\n");
	}
	if(pos <1 || pos >c)
	{
		printf("The Position entered by the user is Invalid\n");
		printf("\n");
	}
	else if(pos==1)  //logic of deleting first node
	{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		ptr->next=NULL;
		free(ptr);
	}
	else if(pos==c) //logic for deletion at the end
	{
		ptr=tail;
		tail=tail->prev;
		tail->next=NULL;
		ptr->prev=NULL;
		free(ptr);
	}
	else
	{
		ptr=start;
		while(i<pos-1)
		{
			ptr=ptr->next;
			i++;
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		ptr->next=NULL;
		ptr->prev=NULL;
		free(ptr);
	}
}

int main()
{
int T=0; //menue variable of the doubly linked list
int c=0; //to store the number of nodes in a doubly linked list
int choice3;
do
{
printf("-----------------------MENUE----------------------\n");
printf("Press 1 to create a node in Doubly Linked List\n");
printf("Press 2 to display all the nodes of Doubly Linked List\n");
printf("Press 3 to Insert the newly created node at the beginning of the Doubly Linked list\n");
printf("Press 4 to Insert the newly created node at the ending of the Doubly Linked list\n");
printf("Press 5 to Insert the newly created node at the specific position Entered by the user in the Doubly Linked list\n");
printf("Press 6 to count the number of nodes of the Doubly Linked list\n");
printf("Press 7 to delete the First node of the Doubly Linked list\n");
printf("Press 8 to delete the Last node of the Doubly Linked list\n");
printf("Press 9 to delete the node of the Doubly Linked list at a specified position\n");
printf("Press 10 to reverse the elements inside the doubly linked list\n");
printf("Press 11 to terminate the program\n");
scanf("%d",&choice3);
printf("\n");
switch(choice3)
{
case 1:
printf("Creating a new node in Doubly Linked List\n");
create_DoublyLinkedList();
printf("\n");
break;

case 2:
printf("Printing the nodes in Doubly Linked List\n");
Display_DoublyLinkedList();
printf("\n");
break;

case 3:
Insert_begin__DoublyLinkedList();
printf("Insertion at beginning complete!!!..");
printf("\n");
break;

case 4:
Insert_End__DoublyLinkedList();
printf("Insertion at ending complete!!!..");
printf("\n");
break;

case 5:
Insert_Pos__DoublyLinkedList();
printf("Insertion at the specified position complete!!!..");
printf("\n");
break;

case 6:
c=lengthDoublyLinkedList();
printf("The number of nodes present inside the Doubly linked list is = %d\n", c);
printf("\n");
break;

case 7:
Delete_Begin_DoublyLinkedList();
printf("Deletion at beginning complete!!!..");
printf("\n");
break;

case 8:
Delete_End_DoublyLinkedList();
printf("Deletion at Ending complete!!!..");
printf("\n");
break;

case 9:
Delete_POS_DoublyLinkedList();
printf("Deletion at the specified position complete!!!..");
printf("\n");
break;

case 10:
reverseDoublyLL();
printf("Reversal complete!!!...\n");
printf("\n");
break;

case 11:
printf("---------DEVELOPER INFO-------------\n");
printf("NAME: Aditya Kumar\n");
printf("COURSE: B.Tech\n");
printf("BRANCH: Computer Science\n");
printf("ROLL NO: 1901230100001\n");
printf("COLLEGE CODE: 123\n");
printf("College Name: Saroj Institute of Technology and Management\n");
printf("\nDoubly Linked List Program terminated by the user\n");
printf("\n");
T=3000;
break;

default:
printf("Wrong choice\n");
printf("\n");
break;

}

}while(T<2000);

}