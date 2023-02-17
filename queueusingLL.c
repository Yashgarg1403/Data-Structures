#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
struct node *next;
};
struct node *front=0,*rear=0;
void enqueue(){
    int x;
    printf("enter element you want to insert\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front == NULL && rear == NULL)
        front = rear = newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front==0){
        printf("queue is empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0){
        printf("queue is empty\n");
    }
    else{
        printf("the deleted element is %d",front->data);
        front=front->next;
        free(temp);
    }
}
int main()
{
     int choice;
      printf("YASH GARG 2100320130199\n");
    while(1){
                printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {                     
                         case 1:        enqueue();
                                        break;                       
                         case 2:        dequeue();
                                        break;                       
                         case 3:        display();
                                        break;                       
                         case 4:        exit(0);
                                        break;                     
                         default:       printf(" Wrong Choice:");
                                        break;
                }
        }
        return 0;
}