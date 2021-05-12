/* Queue implementation using linkedlist
   insertion and deletion are at opoosite ends
   push - insert node at end of linkedlist
   pop - delete node at beginning of linkedlist
*/

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
};

class Queue{
public:
    Node* rear = NULL;
    Node* front = NULL;

    void InsertNode(int value){
        Node* newNode = new Node();
        newNode->val = value;
  
        // If queue is empty, then new node is front and rear both
        if (rear == NULL) {
            front = rear = newNode;
            cout<<"inserted: "<<(rear->val)<<endl;
            return;
        }
  
        // Add the new node at the end of queue and change rear
        rear->next = newNode;
        rear = newNode;
        
        cout<<"inserted: "<<(rear->val)<<endl;
    }

    void DeleteNode(){
      if (front == NULL){
          // If front becomes NULL, then change rear also as NULL
          if (front == NULL) rear = NULL;
          cout<<"empty queue"<<endl;
          return ;
      } 
        // Store previous front and move front one node ahead
        Node* temp = front;
        front = front->next;
        cout<<"deleted: "<<temp->val<<endl;
        delete (temp);
        
     
    }

     void isEmpty(){
       if(front==rear) cout<<"Empty Queue"<<endl;
       else cout<<"Not an Empty Queue"<<endl;
    }

    
    
    void PrintQueue(){
        if(front==rear){ 
           cout<<"Queue is empty"<<endl;
           return ;
        }
            Node* temp = front;
            while(temp!=rear){
                cout<<(temp->val)<<" ";
                temp = temp->next;
            }
            cout<<(temp->val);
            cout<<endl;
    }
};
int main(){
    // implimenting queue
    Queue Q;
    
    Q.InsertNode(10);
    Q.InsertNode(20);
    Q.InsertNode(30);
    Q.InsertNode(40);
    Q.DeleteNode();
    Q.isEmpty();
    Q.InsertNode(50);
    Q.InsertNode(60);
    Q.PrintQueue();
    return 0;
}
