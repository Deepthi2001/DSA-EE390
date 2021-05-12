#include "global.h"

//adds the edge to graph with linking the nodes u,v
void add(vector<vector<int>> &adj,int u,int v){
    int f=0;
    for(auto i:adj[u]){
    if(i==v){
    f=1;
    cout << "edge already exists!" << endl;
    break;
    }
    }
    if(f==0){
    adj[v].push_back(u);
    adj[u].push_back(v);
    }
    
    
}

//prints the adjacency list
void print(vector<vector<int>> &adj,int V){
    for(int v=0;v<V;v++){
    for(auto i:adj[v]){
        cout << i << " ";
    }
    cout << endl;
    }
}
//searches for node and prints the children of node
void search(vector<vector<int>> &adj,int u){
    cout << "nodes connected with" << u << "are:"  ;
    for(auto i:adj[u]){
        cout << i << " ";
    }
    cout << endl;
    
}

//traverse the graph  and prints it 
void BFs(vector<vector<int>> &adj,int s,int n){
    vector<bool> visited(n,false);
    queue<int> q;
 
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
       
        s = q.front();
        cout << s << " ";
        q.pop();
 
        
        for (auto i:adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    cout << "enter no of nodes of your choice" << endl;
    cin >> n;
    //creates the 2d array for adjacency list 
    vector<vector<int>> adj(n);
    cout << "enter a to add edge" << endl;
    cout << "enter p to print the graph" << endl;
    cout << "enter b to perform BFs" << endl;
    cout <<"enter s to search" << endl;
    cout << "and also enter nodes ranging from 0 to n-1" << endl;
    char op;
    cout << "enter the operator" << endl;
    cin >> op;
    
    while(1){
        
      
    switch(op){
    //checks the operation and performs the corresponding
        case 'p':
        cout << "adjacency list is:"<< endl;
        print(adj,n);
        break;
        case 'b':
        cout << "enter source" << endl;
        int s;
        cin >> s;
        BFs(adj,s,n);
        break;
        case 's':
        int u;
        cout << "enter node to print children of that" << endl;
        cin >> u;
        search(adj,u);
        break;
        case 'a':
        int v;
        cout << "enter end points of edge"<< endl;
        cin >> u >> v;
        add(adj,u,v);
        break;
        default:
            cout << "enter valid operator" << endl; 
        
    }
    //enter Y to continue or else exists the program
    char a;
    cout << "Do you want to continue?(Y/N)" << endl;
    cin >> a;
    if(a == 'Y'){
        cout << "enter the operator" << endl;
        cin >> op;
    }
    else{
        cout << "Quitting...."<< endl;
        break;
    }
    }

    return 0;
}




