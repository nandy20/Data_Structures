#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node *rotate(struct Node *head, int k);
Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
int main(void) {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    // Your code here
    int c=0,n=0;
    Node *temp,*temp1,*temp2,*head2;
    temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    if(c<=k){
        /*If k<=c then no need for rotation so jus return head*/
        return head;
    }
    else{
    c=0;
    temp=head;
    temp1=(Node*)malloc(sizeof(Node));
    temp1=temp->next;
    /*Iterate through the array until the head for the list
    to be formed is found thn make the next of element before tht
    as null*/
    while(temp->next!=NULL&&c<k-1){
        c++;
        temp=temp->next;
        temp1=temp1->next;
    }
    temp->next=NULL;
    head2=temp1;
    temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=head;
    return head2;
    }
}
