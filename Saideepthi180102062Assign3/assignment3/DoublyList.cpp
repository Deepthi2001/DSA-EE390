#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <class T>
class doublyNode{
    public:
    T data;
    doublyNode<T> *next;
    doublyNode<T> *prev;

    doublyNode(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    doublyNode(T val){
        data = val;
        next = NULL;
        prev = NULL;
    }
    
};

template <class T>
class doublyList{
    public:
    doublyNode<T> *head;
    
    doublyList(){
        head = NULL;
    }

    doublyList(doublyNode<T> *x){
        head = x;
    }

    void push_front(T val){
        doublyNode<T>*newNode= new doublyNode<T>(val);
        newNode->next=head;
        newNode->prev=NULL;
        if(head) {
            head->prev=newNode;
        }
        head=newNode;
        return;
    }

    void push_back(T val){
        doublyNode<T>*newNode=new doublyNode<T>(val);
        doublyNode<T>*end=head;
        if(!head){
            newNode->prev=NULL;
            head=newNode;
            return;
        }
        while(end->next) end=end->next;
        end->next=newNode;
        newNode->prev=end;
    }

    void pop_front(){
        // empty list
        if(!head){
            return;
        }
        doublyNode<T>*temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }

    void pop_back(){
        // if linked list is empty
        if(!head){
            return;
        }
        if(!head->next){
            head=NULL;
            free(head);
            return;
        }
        doublyNode<T>*temp=head;
        while(temp->next) temp=temp->next;
        temp->prev->next=NULL;
        free(temp);
    }

    int search(T val){
        doublyNode<T>*temp=head;
        int i=1;
        while(temp){
            if(temp->data==val) return i;
            i++;
            temp=temp->next;
        }
        return -1;
    }

};


int main()
{
    ofstream fout;
    fout.open("DoublyListInfo.txt");

    int array[15] = {10, 100, 300, 500, 700, 1000, 2000, 3000, 9000, 20000, 40000, 60000, 80000, 150000, 170000   };

    for(int k=0; k<15; k++){
        int n=array[k];

        list<int> stlList;

        doublyNode<int> *head = new doublyNode<int>();
        doublyList<int> s(head);

        auto startTime1 = high_resolution_clock::now();
        
        
        for(int i=0;i<n/4;i++){
            s.push_front(i);
        }
        for(int i=0;i<n/4;i++){
            s.push_back(i);
        }
        for(int i=0;i<n/4;i++){
            if(i&1){
                s.pop_front();
            }
            else{
                s.pop_back();
            }
        }

        auto stopTime1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stopTime1 - startTime1); 

        auto startTime2 = high_resolution_clock::now();


        for(int i=0;i<n/4;i++){
            stlList.push_front(i);
        }
        for(int i=0;i<n/4;i++){
            stlList.push_back(i);
        }
        for(int i=0;i<n/4;i++){
            if(i&1){
                stlList.pop_front();
            }
            else{
                stlList.pop_back();
            }
        }

        auto stopTime2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stopTime2 - startTime2); 
    
        cout << "\n\nNo of iterations: " << n << endl;
        cout << "\t MyList : " << duration1.count() << endl;
        cout << "\t StlList: " << duration2.count() << endl;

        fout << n << " " << duration1.count() << " " << duration2.count() << endl;

    }

    fout.close();
    
    return 0;
}
