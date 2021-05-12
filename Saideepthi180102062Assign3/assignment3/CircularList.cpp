#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node* next;

        Node(){
            data=0;
            next=NULL;
        }

        Node(T val){
            data = val;
            next = NULL;
        }
};

template<class T>
class circularList{
    public:
    Node<T> *head;

    circularList(){
        head = NULL;
    }

    circularList(Node<T> *x){
        head=x;
    }

    /* linked list is empty */
    void addToEmptyList(T val){
        Node<T>*end=head;
        Node<T>* temp = new Node<T>(val);
        end = temp;
        end->next = end;
        head = end;
         cout<<val<<" is inserted"<<endl;
    }

    /* insert element at front of linked list */
    void insertStart(T val){
        Node<T>* temp = new Node<T>(val);
        Node<T>*end =head;
        temp->next = end->next;
        end->next = temp;
        head = end;
         cout<<val<<" is inserted at front"<<endl;
    }

    /* insert element at end of linked list */
    void insertEnd(T val){
        Node<T>*end=head;
        Node<T>* temp = new Node<T>(val);
        temp->next = end->next;
        end ->next = temp;
        end = temp;
        head = end;
        cout<<val<<" is inserted at end"<<endl;
    }

    /* search given element in the linked list */
    void searchNode(T val){
        Node<T>*end=head;
        Node<T>* temp = end->next;
        if(end->data == val){
            cout<< val <<" : exists"<<endl;
            return;
        }

        else{
            while(temp != end){
                if(temp->data == val){
                    cout<< val << " Exists"<<endl;
                    return;
                }
                temp = temp->next;
            }
        }
        
        cout<< val << " Doesn't Exist"<<endl;
        return ;
    }

    /* Delete node or nearest value node in linkedlist */
    void deleteNode(T val){
        Node<T>* headref = head;        
        Node<T>* temp = headref->next;
        Node<T>* prev = NULL;
        
        if (temp != NULL && temp->data == val){
        
            (headref)->next = temp->next; 
            cout<<(temp->data)<<" is deleted"<<endl;
            free(temp);
        }
        else{
            while (temp->next != headref && temp->data != val){
                prev = temp;
                temp = temp->next;
                cout<<val<<" doesn't exist hence cannot be deleted"<<endl;
                break;
            }
        
            if (temp->next == headref && headref->data == val ){
                
                temp->next = headref->next;
                head = temp;
                return;
            }
            prev->next = temp->next;
            cout<<(temp->data)<<" is deleted"<<endl;
            free(temp);
        }
        head = headref;
    }

    /* print the entire linkedlist */
    void print(){

        Node<T>* temp = head->next;
        while (temp != head){
            cout<<temp->data<< " ";
            temp = temp ->next;
        }
        cout<<head->data<<endl;
        return ;
        
    }

};

int main(){
    Node<int>* head = new Node<int>();
    circularList<int> c(head);

    c.addToEmptyList(108);
    c.insertEnd(56);
    c.insertStart(38);
    c.insertStart(64);
    c.insertEnd(93);
    c.print();
    c.searchNode(4);
    c.searchNode(56);
    c.deleteNode(64);
    c.print();
    c.insertStart(84);
    c.deleteNode(84);
    c.searchNode(84);
    c.searchNode(54);
    c.deleteNode(54);
    c.print();


    return 0;
}
