#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
/*
   Insert Node in a doubly sorted linked list 
   After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
   int data;
   Node *next;
   Node *prev
   }
   */
Node* SortedInsert(Node *head,int data){
    Node *temp=new Node();
    temp->data=data;temp->prev=NULL;temp->next=NULL;

    if(head==NULL){
        return temp;
    }else if(head->data > data) {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }else {
        Node *current = head; 
        while (current->next!=NULL && current->next->data < data) {
            current = current->next;
        }
        if (current->next!=NULL){
           temp->next = current->next;
            temp->next->prev=temp; 
        }
        current->next = temp;
        temp->prev=current;
    }
    return head;    
}

Node* Insert(Node *head, int data){
    Node *temp = new Node();
    temp->data = data; temp->prev = NULL; temp->next = NULL;
    if(head == NULL) return temp;
    head->prev = temp;
    temp->next = head;
    return temp;
}

void Print(Node *head) {
    if(head == NULL) return;
    while(head->next != NULL){ cout<<head->data<<" "; head = head->next;}
    cout<<head->data<<" ";
    while(head->prev != NULL) { cout<<head->data<<" "; head = head->prev; }
    cout<<head->data<<"\n";
}

int main(){
    int t,n,m; 
    cin>>t;
    Node *head = NULL;
    while(t--) {
        cin>>n;
        head = NULL;
        for(int i = 0;i<n;i++) {
            int x; cin>>x;
            head = Insert(head,x);
        }
        cin>>m;
        head = SortedInsert(head,m);
        Print(head);
    }
}
