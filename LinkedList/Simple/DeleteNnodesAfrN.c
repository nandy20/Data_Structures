{
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void linkdelete(struct node  *head, int M, int N);
/* Function to print nodes in a given linked list */
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
void insert(int n1)
{
    int n,value,i;
    //scanf("%d",&n);
    n=n1;
    struct node *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            start=(struct node *) malloc( sizeof(struct node) );
            start->data=value;
            start->next=NULL;
            temp=start;
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
int main()
{
    
     int m,n;
    
    int t,n1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n1);
        scanf("%d",&m);
        scanf("%d",&n);
        insert(n1);
        
       
        
        
  
        linkdelete(start,m,n);
        
        
        printList(start);
    }
    
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void linkdelete(struct node  *head, int m, int n)
{
     //Add code here 
     struct node *temp,*temp1,*pre,*head2;
     int c=0,k=0,to=0;
     temp=head;
     while(temp!=NULL){
         to++;
         temp=temp->next;
     }
     temp=head;
     head2=NULL;
     while(temp!=NULL&&to>=m&&to>=n){
          printf("%d ",temp->data);
         while(c<m&&temp!=NULL&&to>=m){
            
             if(head2==NULL){
                 head2=(struct node*)malloc(sizeof(struct node));
                 head2->data=temp->data;
                 head2->next=NULL;
                 pre=head;
             }
             else{
                 temp1=(struct node*)malloc(sizeof(struct node));
                 temp1->data=temp->data;
                 temp1->next=NULL;
                 pre->next=temp1;
                 pre=temp1;
             }
             temp=temp->next;
             c++;
             to++;
         }
         
         while(temp!=NULL&&to>=n&&k<n){
             k++;
             temp=temp->next;
             to++;
         }
         c=0;
         k=0;
     }
     head=head2;
}