#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

template <class T>
class Node{
    public:
        T data;
        Node<T> * next;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(T val){
            data = val;
            next = NULL;
        }

};

template <class T>
class singleLinkedList{
    public:
        Node<T> * head;
        Node<T> * tail;
        
        singleLinkedList(){
            head = NULL;
            tail = NULL;
        }

        singleLinkedList(Node<T> *n){
            head = n;
            tail = n;
        }
        
        void insertNode(T val, int index){
            Node<T> *temp = new Node<T>(val);
            if(head == NULL){
                head = temp;
                return;
            }

            if(index < -1){
                return;
            }

            // insert element in the front(prepend)
            if(index == 0){
                temp->next = head;
                head = temp;
                return;
            }
            // insert element at the end(append)
            else if(index == -1){
                tail->next = temp;
                tail = tail->next;
                return;
            }
            // insert element in middle of the list
            else{
                Node<T> *dummy = head;
                int i=1;
                //if the index is more than the length of the list, it appends the node at the end
                while(dummy->next && i<index){
                    dummy = dummy->next;
                    i++;
                }
                temp->next = dummy->next;
                dummy->next = temp;
            }
            return;
        }

        void deleteNode(T val){
            if(head == nullptr){
                // cerr << "No nodes to delete!\n";
                return;
            }
            
            Node<T> *dummy = head;
            
            DELETENODE:
            if(dummy->next == NULL && dummy->data == val){
                free(dummy);
                head = NULL;
                return;
            }
            else if(dummy->data == val){
                head = dummy->next;
                free(dummy);
                return;
            }
            else if(dummy->next == nullptr and dummy->data != val){
                // cerr << "no node with that value, nothing is deleted!\n";
                return;
            }
            while(dummy->next->next != nullptr){
                if(dummy->next->data == val){
                    break;
                }
                else{
                    dummy = dummy->next;
                }
            }

            if(dummy->next->next == nullptr and dummy->next->data!=val){
                // cerr << "There exist no node with value " << val << ", So nothing is deleted!\n";
                return;
            }
            else{
                Node<T> *tobedeleted = dummy->next;
                dummy->next = dummy->next->next;
                free(tobedeleted);
                // cerr << "Node deleted!!\n";
            }
            goto DELETENODE;
            return;
        }

        int searchNode(T val){
            if(head == nullptr){
                // cerr << "No nodes in the list!\n";
                return -1;
            }
            int i=0;
            Node<T> *temp = head;
            while(temp->next){
                if(temp->data == val){
                    break;
                }
                else{
                    temp = temp->next;
                    i++;
                }
            }

            if(temp->next == NULL && temp->data!=val){
                // cerr << "There exist no node with value " << val << endl;
                return -1;
            }
            else{
                // cerr << "Node found in the list and the index is : " << i << endl;
            }
            return i;
        }
        
        void printList(){
            Node<T> *temp = head;
            while(temp){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
        
};



int main(){
    ofstream fout;
    fout.open("SingleListInfo.txt");

    int array[15] = {10, 100, 300, 500, 700, 1000, 2000, 3000, 9000, 20000, 40000, 60000, 80000, 150000, 170000   };

    for(int i=0; i<15; i++){
        int n = array[i];
        list<int> stlList;

        Node<int> *head = new Node<int>();
        singleLinkedList<int> s(head);
        int val; 
        int index;
        auto startTime1 = high_resolution_clock::now();
        
        for(int j=n/4; j>=0; j--){
            s.insertNode(j,0);
        }
        for(int j=n/4; j<n/2; j++){
            s.insertNode(j, -1);
        }
        for(int j=0; j<n/2; j++){
            if(j&0){
                s.deleteNode(j);
            }
            else{
                s.deleteNode(n/2-j);
            }
        }
        
        auto stopTime1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stopTime1 - startTime1); 


        auto startTime2 = high_resolution_clock::now();
        
        for(int j=0; j<n/4; j++){
            stlList.push_back(9);
        }
        for(int j=n/4; j<n/2; j++){
            stlList.push_front(j);
        }

        for(int j=0; j<n/2; j++){
            if(j&0){
                stlList.pop_back();
            }
            else{
                stlList.pop_front();
            }
        }
        auto stopTime2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stopTime2 - startTime2); 
    
        cout << "\n\nNo of iterations: " << n << endl;
        cout << "\t MyList : " << duration1.count() << endl;
        cout << "\t STLList: " << duration2.count() << endl;

        fout << n << " " << duration1.count() << " " << duration2.count() << endl;
    }

    fout.close();
    return 0;
    
}
