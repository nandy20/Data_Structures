/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
int detectloop(Node *head) {
    
    // your code here
    Node *temp;
    temp=head;
    temp->data=-1;
    while(temp->next!=NULL){
        temp->data=-1;
        if(temp->next->data==-1){
            return true;
        }
        temp=temp->next;
    }
    
    return false;
    
}