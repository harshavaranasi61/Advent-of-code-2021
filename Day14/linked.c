#include<stdio.h>
#include<stdlib.h>
void create();
void insert_at_beg(int);
void insert_at_end(int);
void insert_at_pos(int);
int delete_at_beg();
int delete_at_end();
int delete_at_pos();
void display();
struct node
{
  int data;
  struct node *next;
}*header=NULL;
struct node *temp,*ptr;


int main()
{
    int num,i,n,item,k;
    while(1)
    {
        printf("\n1.CREATE");
        printf("\n2.ADD AT BEGINNING");
        printf("\n3.ADD AT END");
        printf("\n4.ADD AT GIVEN POSITION:");
        printf("\n5.DELETE AT BEGINNING");
        printf("\n6.DELETE AT END");
        printf("\n7.DELETE AT POSITION:");
        printf("\n8.DISPLAY");
        printf("\n9.EXIT");
        printf("\nEnter the choice:");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            printf("Enter how many nodes you want:");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                create();
            }
            display();
            break;
        case 2:
            insert_at_beg(item);
            display();
            break;
        case 3:
            insert_at_end(item);
            display();
            break;
        case 4:
            insert_at_pos(item);
            display();
            break;
        case 5:
            k=delete_at_beg();
            printf("\nDeleted item:%d",k);
            display();
            break;
        case 6:
            k=delete_at_end();
            printf("\nDeleted item:%d",k);
            display();
            break;
        case 7:
            k=delete_at_pos();
            printf("\nDeleted item:%d",k);
            display();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("EXIT");
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
void create()
{
    int item;
    //struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->data=item;
    temp->next=NULL;
    if(header==NULL)
    {
        header=temp;
        ptr=temp;
    }
    else
    {
        ptr->next=temp;
        ptr=temp;
    }
}
void display()
{
    //struct node *temp;
    temp=header;
    printf("Elements in the linked list:");
    while(temp!=NULL)
    {
        printf("%d -> ",&temp->data);
        temp=temp->next;
    }
}
void insert_at_beg(int item)
{
    //struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter item:");
    scanf("%d",&item);
    temp->data=item;
    temp->next=NULL;
    if(header==NULL)
        header=temp;
    else
    {
        temp->next=header;
        header=temp;
    }
}
void insert_at_end(int item)
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter item:");
    scanf("%d",&item);
    temp->data=item;
    temp->next=NULL;
    if(header==NULL)
        header=temp;
    else
    {
        ptr=header;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
    }
}
void insert_at_pos(int item)
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter item:");
    scanf("%d",item);
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    temp->data=item;
    temp->next=NULL;
    ptr=header;
    while(ptr->next!=pos)
        ptr=ptr->next;
    temp->next=ptr->next;
    ptr->next=temp;
}
int delete_at_beg()
{
    int item;
    temp=header;
    header=header->next;
    item=temp->data;
    free(temp);
    return item;
}
int delete_at_end()
{
    int item;
    temp=header;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    item=temp->data;
    free(temp);
    return item;
}
int delete_at_pos()
{
    int item,n;
    temp=header;
    printf("Enter position:");
    scanf("%d",&n);
    while(temp->next!=n)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=temp->next;
    item=temp->data;
    free(temp);
    return item;
}