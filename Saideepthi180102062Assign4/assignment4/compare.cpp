#include<bits/stdc++.h>
#include<fstream>
using namespace std::chrono;
using namespace std;

class Node{
public:
    int val;
    Node* next;
};

class Stack{
public:
    Node* top=NULL ;
   
    void InsertNode(int value){
        if(top==NULL) {
         top=new Node();
         top->val = value;
         //cout<<"inserted: "<<(top->val)<<endl;
         return ;
        } 
        Node* newNode = new Node();
        newNode->val = value;
        newNode->next=top;
        top=newNode;
        
        //cout<<"inserted: "<<(top->val)<<endl;
    }

    void DeleteNode(){
      if(top==NULL){
      // cout<<"underflow"<<endl;
       return ;
     }
        Node * temp = top;
        //cout<<"deleted: "<<(temp->val)<<endl;
        top = top->next;
        delete(temp);
    }

    void isEmpty(){
       if(top==NULL) cout<<"Empty stack"<<endl;
       else cout<<"Not an Empty stack"<<endl;
    }

    void TopElement(){
       if(top==NULL) cout<<"Empty stack"<<endl;
       else cout<<"Top element: "<< (top->val)<<endl;
    
    }
    
    void PrintStack(){
        if(top==NULL) cout<<"Stack is empty"<<endl;
        else{
            Node* temp = top;
            while(temp!=NULL){
                cout<<(temp->val)<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
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
           // cout<<"inserted: "<<(rear->val)<<endl;
            return;
        }
  
        // Add the new node at the end of queue and change rear
        rear->next = newNode;
        rear = newNode;
        
        //cout<<"inserted: "<<(rear->val)<<endl;
    }

    void DeleteNode(){
      if (front == NULL){
          // If front becomes NULL, then change rear also as NULL
          if (front == NULL) rear = NULL;
          //cout<<"empty queue"<<endl;
          return ;
      } 
        // Store previous front and move front one node ahead
        Node* temp = front;
        front = front->next;
       // cout<<"deleted: "<<temp->val<<endl;
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

void compare(){
    int num_max =10000000;
    ofstream myFile;
    myFile.open("compare.txt"); //Opens our csv file and loads data into our file
    
    // STACK INSERTION AND DELETION COMPARISION
    stack<int>STLstack;
    Stack MyStack;
    
    myFile<<"operations"<<"\t"<<"MyStack Insertion"<<endl;
    auto start = high_resolution_clock::now();
    
    for(int i=0;i<num_max;i++){
        MyStack.InsertNode(i);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        if(i%100000==0){
            myFile <<i<<"\t"<<duration.count()<<endl;
        }
    }
    
    myFile<<"STLstack Insertion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        STLstack.push(i);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    myFile<<"MyStack Deletion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        MyStack.DeleteNode();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    myFile<<"STLstack Deletion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        STLstack.pop();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    // QUEUE INSERTION AND DELETION COMPARISION
    Queue MyQueue;
    queue<int>STLqueue;
    
    myFile<<"MyQueue Insertion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        MyQueue.InsertNode(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    myFile<<"STLqueue Insertion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        STLqueue.push(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    myFile<<"MyQueue Deletion"<<endl;
    
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

        MyQueue.DeleteNode();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }
    
    myFile<<"STLqueue Deletion"<<endl;
    start = high_resolution_clock::now();
    for(int i=0;i<num_max;i++){

       STLqueue.push(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if(i%100000==0){
            myFile<<duration.count()<<endl;
        }
    }



    myFile.close();
}
int main(){
    compare();
    return 0;
}
