{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
 void reorderList(struct Node* head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=newNode(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=newNode(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
freeList(head);
   }
   return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/
void reorderList(Node* head) 
{
    // Your code here
    int stack[100000],top=0,n=0,c=0;
    Node *temp,*temp1,*head1,*pre;
    temp=head;
    head1=NULL;
    while(temp!=NULL){
         if(head1==NULL){
                head1=(Node*)malloc(sizeof(Node));
                head1->data=temp->data; 
                head1->next=NULL;
                pre=head1;
            }
            else{
                temp1=(Node*)malloc(sizeof(Node));
                temp1->data=temp->data; 
                temp1->next=NULL;
                pre->next=temp1;
                pre=temp1;
            }
        stack[top]=temp->data;
        temp=temp->next;
        top++;
        n++;
        
    }
    
    top--;
    temp=head1;
    temp1=head;
    while(n>0){
       
        if(c%2==0){
            if(c==0){
                head->data=temp->data; 
                temp1=temp1->next;
            }
            else{
                temp1->data=temp->data;
                temp1=temp1->next;
            }
             temp=temp->next;
        }
        else{
                temp1->data=stack[top];
                temp1=temp1->next;
                top--;
        }
        c++;
        n--;
    }
}