#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
struct node *next;
};
struct node *top=0;
void push(){
    int x;
    printf("enter element you want to insert\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void display(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("stack is empty\n");
    }
    else{
        printf("the popped element is %d",top->data);
        top=top->next;
        free(temp);
    }
}
int main()
{
     int choice;
      printf("YASH GARG 2100320130199\n");
    while(1){
                printf("\n1.push\n2.pop\n3.display\n4.exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {                     
                         case 1:        push();
                                        break;                       
                         case 2:        pop();
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