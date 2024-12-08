#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void InsertAtHead()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value\n");
    scanf("%d",&item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("\nNode inserted");

}

void insertAtEnd()
{
    struct node *ptr, *tmp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    printf("\nEnter value\n");
    scanf("%d",&item);
    ptr->data = item;
    tmp->next = ptr;
    ptr->next = NULL;
}

void InsertAtSpecificIndex()
{
    struct node *tmp,*ptr,*prv;
    tmp = head;
    int value,idx;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter Value and  Index Number which you want to Insert: ");
    scanf("%d %d",&value, &idx);
    ptr->data = value;
    idx--;
    while(idx--)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    prv->next = ptr;
    ptr->next = tmp;
}

void DeleteAtHead()
{
    struct node *tmp;
    tmp = head;
    head = tmp->next;
    free(tmp);
}

void DeleteAtEnd()
{
    struct node *tmp, *prv;
    tmp = head;
    prv = NULL;
    while(tmp->next != NULL)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    prv->next = NULL;
    free(tmp);
}

void DeleteSpecificIndex()
{
    struct node *tmp,*ptr,*prv;
    tmp = head;
    int idx;
    printf("Enter Index Number which you want to Delete: ");
    scanf("%d",&idx);
    idx--;
    while(idx--)
    {
        prv = tmp;
        tmp = tmp->next;
    }
    prv->next = tmp->next;
    free(tmp);
}

void display()
{
    struct node *ptr;
    ptr = head;


    printf("\nprinting values . . . . .\n");
    while (ptr!=NULL)
    {
        printf("%d-> ",ptr->data);
        ptr = ptr -> next;
    }


}


int main ()
{
    int choice =0;
    while(1)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insert at End\n3.Insert at a specific index\n4.Delete At Head\n5.Delete At End\n6.Delete From Specific Location\n7.Show\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            InsertAtHead();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            InsertAtSpecificIndex();
            break;
        case 4:
            DeleteAtHead();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteSpecificIndex();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}

