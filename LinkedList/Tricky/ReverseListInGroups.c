{
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;
struct node *reverse (struct node *head, int k);
/* Reverses the linked list in groups of size k and returns the
   pointer to the new head node. */
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value,i;
    scanf("%d",&n);
    struct node *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
  struct node *temp,*temp1,*newhead,*prev;
  temp=head;
  newhead=NULL;
  int stack[100000],top=0;
  while(temp!=NULL){
      int c=0;
      top=0;
	  //until u get tht size of group add nums to list
	  // After adding use stsck and create new list
      while(c<k&&temp!=NULL){
          stack[top]=temp->data;
          
          top++;
          temp=temp->next;
          c++;
         
      }
      top--;
      while(top>=0){
          if(newhead==NULL){
              newhead=(struct node*)malloc(sizeof(struct node));
              newhead->data=stack[top];
              
              top--;
              newhead->next=NULL;
              prev=newhead;
          }
          else{
              temp1=(struct node*)malloc(sizeof(struct node));
              temp1->data=stack[top];
              
              top--;
              temp1->next=NULL;
              prev->next=temp1;
              prev=temp1;
          }
      }
  }
  return newhead;
}