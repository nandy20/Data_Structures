/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     // Code here
     struct Node *temp,*temp1;
     temp=head;
     int c=0;
     while(temp->next!=NULL){
         temp->data=-1;
         // -1 is used to detect loop
         if(temp->next->data==-1){
             temp1=temp->next;
     /* Incase loop is detected -2 is used and a counter variable
     is used and again iterate through the loop and again wen -2
     is encountered return c*/
             temp1->data=-2;
             while(temp1->next!=NULL){
                 temp1->data-2;
                 c++;
                 if(temp1->next->data==-2){
                     return c;
                 }
                 temp1=temp1->next;
             }
         }
         temp=temp->next;
     }
     return 0;
}