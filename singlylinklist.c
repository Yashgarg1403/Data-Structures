#include<stdlib.h>
#include <stdio.h>
void create();
void traverse();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node
{
  int info;
struct node *next;
};
struct node *start=NULL;
int main()
{
     int choice;
      printf("YASH GARG 2100320130199\n");
    while(1){
                printf("\n1.create\n2.traverse\n3.insertion at beginning\n4.insertion at end\n5.insertion after a given node\n6.deletion at beginning\n7.deletion at end\n8.deletion of a particular node\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {                     
                         case 1:        create();
                                        break;                       
                         case 2:        traverse();
                                        break;                       
                         case 3:        insert_begin();
                                        break;                       
                         case 4:        insert_end();
                                        break;                        
                         case 5:        insert_pos();
                                        break;                        
                         case 6:        delete_begin();
                                        break;                        
                         case 7:        delete_end();
                                        break;                       
                         case 8:        delete_pos();
                                        break;                        
                         case 9:        exit(0);
                                        break;                     
                         default:       printf(" Wrong Choice:");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *new,*ptr;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
                printf("Out of Memory Space:\n");
                exit(0);
        }
        printf("Enter the data value for the node:\n");
        scanf("%d",&new->info);
        new->next=NULL;
        if(start==NULL)
        {
                start=new;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=new;
        }
}
void traverse()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("List is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d",ptr->info );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *new;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the data value for the node:\n" );
        scanf("%d",&new->info);
        new->next =NULL;
        if(start==NULL)
        {
                start=new;
        }
        else
        {
                new->next=start;
                start=new;
        }
}
void insert_end()
{
        struct node *new,*ptr;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the data value for the node:\n" );
        scanf("%d",&new->info );
        new->next =NULL;
        if(start==NULL)
        {
                start=new;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =new;
        }
}
void insert_pos()
{
        struct node *ptr,*new;
        int i,pos;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the position for the new node to be inserted:\n");
        scanf("%d",&pos);
        printf("Enter the data value of the node:\n");
        scanf("%d",&new->info) ;

        new->next=NULL;
        if(pos==0)
        {
                new->next=start;
                start=new;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("Position not found:\n");
                                return;
                        }
                }
                new->next =ptr->next ;
                ptr->next=new;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("List is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("The deleted element is :%d",ptr->info);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("List is Empty:\n");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("The deleted element is:%d\n",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is:%d\n",ptr->info);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("The List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("Enter the position of the node to be deleted:\n");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("The deleted element is:%d\n",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos-1;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("Position not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("The deleted element is:%d\n",ptr->info );
                        free(ptr);
                }
        }
}
