/* Stack implementation using linkedlist
   insertion and deletion at same end(either front or back)
   Here first element of linked list is top element of stack
   push - insert node at beginning of linkedlist
   pop - delete node at beginning of linkedlist
*/

#include<iostream>
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
         cout<<"inserted: "<<(top->val)<<endl;
         return ;
        } 
        Node* newNode = new Node();
        newNode->val = value;
        newNode->next=top;
        top=newNode;
        
        cout<<"inserted: "<<(top->val)<<endl;
    }

    void DeleteNode(){
      if(top==NULL){
       cout<<"underflow"<<endl;
       return ;
     }
        Node * temp = top;
        cout<<"deleted: "<<(temp->val)<<endl;
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
int main(){

    // Stack implementation
    Stack st;
    st.InsertNode(10);
    st.InsertNode(20);
    st.InsertNode(30);
    st.InsertNode(40);
    st.DeleteNode();
    st.TopElement();
    st.isEmpty();
    st.InsertNode(50);
    st.InsertNode(60);
    st.PrintStack();
    return 0;
}
