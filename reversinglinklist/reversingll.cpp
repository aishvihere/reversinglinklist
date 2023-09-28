#include<iostream>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;

    }
     
};

class LinkedList{
    public:

    Node* head;
    LinkedList(){
        head=NULL;
    }
        
        void InsertAtTail(int value){
            Node* new_node= new Node(value); 
            if(head==NULL){            // if linkedlsit is empty new node is put at head pos
                head=new_node;
                return;
            }

            //To traverse through linked list and add the inserted value at tail

            Node* temp= head;
            while(temp->next!=NULL){
                temp=temp->next;
            }

            temp->next=new_node;


        }

        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        
        
        }


};

Node* Reverselinklist(Node* &head){

    Node* curr_ptr=head;
    Node* prev_ptr=NULL;
    while(curr_ptr!=NULL){
        Node* next_ptr= curr_ptr->next;
        curr_ptr->next=prev_ptr;
        
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
         
    }
    
    Node* new_head= prev_ptr;
    return new_head;
    
}


int main(){

    LinkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.InsertAtTail(5);
    ll.InsertAtTail(6);
    ll.InsertAtTail(7);

    ll.display();
    ll.head = Reverselinklist(ll.head);
    ll.display();

    return 0;

}