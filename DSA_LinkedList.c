#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
struct node* ptr;
struct node* create_start_node();
struct node* append_node(struct node* start);
struct node* insert_beg(struct node* start);
struct node* insert_interior(struct node* start,int position);
struct node* delete_beg(struct node* start);
struct node* delete_last(struct node* start);
struct node* delete_interior(struct node* start,int position);
void display_list(struct node* start);
void search_node(struct node* start,int key);
struct node* sort_list(struct node* start);
struct node* reverse_list(struct node* start);
struct node* create_start_node()
{
    ptr=malloc(sizeof(struct node));
    printf("Enter start node data :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    start=ptr;
    ptr=NULL;
    free(ptr);
    return start;
}
struct node* append_node(struct node* start)
{
    struct node* cptr;
    ptr=malloc(sizeof(struct node));
    printf("Enter node data :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    cptr=start;
    while(cptr->next!=NULL)
    {
        cptr=cptr->next;
    }
    cptr->next=ptr;
    ptr=NULL;
    cptr=NULL;
    free(ptr);
    free(cptr);
    return start;
}
struct node* insert_beg(struct node* start)
{
    ptr=malloc(sizeof(struct node));
    printf("Enter node data :");
    scanf("%d",&ptr->data);
    ptr->next=start;
    start=ptr;
    ptr=NULL;
    free(ptr);
    return start;
}
struct node* insert_interior(struct node* start,int position)
{
    int i=1;
    struct node* pptr;
    ptr=malloc(sizeof(struct node));
    printf("Enter node data :");
    scanf("%d",&ptr->data);
    ptr->next=NULL;   
    pptr=start;
    while(i!=position-1)
    {
        pptr=pptr->next;
        i++;
    }
    ptr->next=pptr->next;
    pptr->next=ptr;
    ptr=NULL;
    pptr=NULL;
    free(ptr);
    free(pptr);
    return start;
}
struct node* delete_beg(struct node* start)
{
    start=start->next;
    return start;
}
struct node* delete_last(struct node* start)
{
    struct node* pptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=NULL;
    ptr=NULL;
    pptr=NULL;
    free(ptr);
    free(pptr);
    return start;
}
struct node* delete_interior(struct node* start,int position)
{
    struct node* pptr;
    ptr=start;
    pptr=start;
    int i=1;
    while(i!=position)
    {
        pptr=ptr;
        ptr=ptr->next;
        i++;
    }
    pptr->next=ptr->next;
    ptr->next=NULL;
    pptr=NULL;
    ptr=NULL;
    free(pptr);
    free(ptr);
    return start;
}
void display_list(struct node* start)
{
    int node=1;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("Node %d\n",node);
        printf("Data of Node %d : %d\n",node,ptr->data);
        printf("Address of Node %d : %p\n",node,ptr);
        printf("Next Node Address of Node %d : %p\n\n",node,ptr->next);
        ptr=ptr->next;
        node++;
    }
    ptr=start;
    printf("\nThe Linked List is :\n");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
    printf("\n\nTotal nodes : %d",node-1);
    ptr=NULL;
    free(ptr);
}
void search_node(struct node* start,int key)
{
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            printf("%p",ptr);
            return;
        }
        ptr=ptr->next;
    }
    printf("Node not found");
    ptr=NULL;
    free(ptr);
}
struct node* sort_list(struct node* start)
{
    int temp;
    struct node* nptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        nptr=ptr->next;
        while(nptr!=NULL)
        {
            if(ptr->data>nptr->data)
            {
                temp=ptr->data;
                ptr->data=nptr->data;
                nptr->data=temp;
            }
            nptr=nptr->next;
        }
        ptr=ptr->next;
    }
    ptr=NULL;
    nptr=NULL;
    free(ptr);
    free(nptr);
    return start;
}
struct node* reverse_list(struct node* start)
{
    struct node *p,*s;
    p=NULL;
    s=NULL;
    while(start!=NULL)
    {
        s=start->next;
        start->next=p;
        p=start;
        start=s;
    }
    start=p;
    p=NULL;
    s=NULL;
    free(p);
    free(s);
    return start;
}
void main()
{
int ch,pos_insert,pos_delete,key;
printf("IMPLEMENTATION OF OPERATIONS ON A SINGLY LINKED LIST\n");
create_start_node();
printf("Start Node created.");
printf("\nMENU OPTIONS :-");
printf("\n1. APPEND A NODE IN THE LIST");
printf("\n2. INSERT A NODE AT THE BEGINNING OF THE LIST");
printf("\n3. INSERT A NODE AT A DESIRED INTERIOR POSITION IN THE LIST");
printf("\n4. DELETE THE NODE FROM THE BEGINNING OF THE LIST");
printf("\n5. DELETE THE LAST NODE OF THE LIST");
printf("\n6. DELETE A NODE FROM A DESIRED INTERIOR POSITION IN THE LIST");
printf("\n7. DISPLAY THE LINKED LIST");
printf("\n8. LINEAR SEARCH FOR A DESIRED ELEMENT");
printf("\n9. SORT THE LINKED LIST");
printf("\n10. REVERSE THE LINKED LIST");
printf("\n11. EXIT");
do{
printf("\nEnter choice :");
scanf("%d",&ch);
switch(ch)
{
    case 1:
    start=append_node(start);
    printf("Node Appeneded.");
    break;
    case 2:
    start=insert_beg(start);
    printf("Node inserted at beginning.");
    break;
    case 3:
    printf("Enter the position at which new node is to be inserted :");
    scanf("%d",&pos_insert);
    start=insert_interior(start,pos_insert);
    printf("Node inserted at desired position.");
    break;
    case 4:
    start=delete_beg(start);
    printf("Node deleted from beginning.");
    break;
    case 5:
    start=delete_last(start);
    printf("Node deleted from last.");
    break;
    case 6:
    printf("Enter the position from which node is to be deleted :");
    scanf("%d",&pos_delete);
    start=delete_interior(start,pos_delete);
    printf("Node deleted from desired location");
    break;
    case 7:
    display_list(start);
    break;
    case 8:
    printf("Enter the key :");
    scanf("%d",&key);
    printf("%d is found at ",key);
    search_node(start,key);
    break;
    case 9:
    start=sort_list(start);
    printf("Linked List sorted.");
    break;
    case 10:
    printf("Linked List reversed.");
    start=reverse_list(start);
    break;
    case 11:
    printf("Thanks for using");
    break;
    default:
    printf("Invalid Choice");
    break;
}
}while(ch!=11);
}
































