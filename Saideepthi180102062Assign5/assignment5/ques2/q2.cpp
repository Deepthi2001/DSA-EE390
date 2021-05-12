#include "global.h"

//depth first search
void DFS(int R, int V, vector<vector<int>> &Resistance, vector<vector<int>> &Voltage,int n) {
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    stack<int>S;
    int start = R;
    S.push(start);
    while(!S.empty()) {
        start = S.top();
        S.pop();

        if(!visited[start]) 
            visited[start] = true;
        
        for(int i=0;i<n;i++) {
            if(!visited[i] && Resistance[start][i]!=-1) {
                visited[i] = true;
                S.push(i);
            }
        }

    }

    for(int i=0;i<n;i++)
        visited[i] = false;
    start = V;
    S.push(start);
    while(!S.empty()) {
        start = S.top();
        S.pop();

        if(!visited[start]) 
            visited[start] = true;
        
        for(int i=0;i<n;i++) {
            if(!visited[i] && Voltage[start][i]!=-1) {
                visited[i] = true;
                S.push(i);
            }
        }

    }
}

//breadth first search
void BFS(int R, int V, vector<vector<int>> &Resistance, vector<vector<int>> &Voltage,int n) {
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;

    queue<int>Q;
    int start = R;
    Q.push(start);
    while(!Q.empty()) {
        start = Q.front();
        Q.pop();

        for(int i=0;i<n;i++) {
            if(!visited[i] && Resistance[start][i]!=-1) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
    for(int i=0;i<n;i++)
        visited[i] = false;
    start = V;
    Q.push(start);
    while(!Q.empty()) {
        start = Q.front();
        Q.pop();

        for(int i=0;i<n;i++) {
            if(!visited[i] && Voltage[start][i]!=-1) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

int main() {
    int n;
    cout << "enter no.of nodes: " << endl;
    cin >> n;
    vector<vector<int>> Resistance(n,vector<int>(n));
    vector<vector<int>> Voltage(n,vector<int>(n));

    //initialise every element to -1(meaning no resistances)
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            Resistance[i][j] = -1;
            Voltage[i][j] = -1;
            
        }
    }
    cout<<"Resistance matrix -> "<<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<Resistance[i][j]<<" ";
        cout<< endl;
    }
    cout<<"\n";
    cout<<"Voltage matrix -> "<<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<Voltage[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    fstream fin;
    //takes input from text file provided
    fin.open("input.txt", ios::in);
    
    while(!fin.eof()) {
        string data;
        getline(fin,data);
        string str;
        stringstream iss(data);
        iss >> str;
        if(str[0]=='I')
            continue;
        else {
            string n1, n2, value;
            iss >> n1;
            iss >> n2;
            if(str[0]=='R') {
                iss >> value;
                Resistance[atoi(n1.c_str())][atoi(n2.c_str())] = atoi(value.c_str());
                Resistance[atoi(n2.c_str())][atoi(n1.c_str())] = atoi(value.c_str());
            }
            else {
                iss >> value;
                Voltage[atoi(n1.c_str())][atoi(n2.c_str())] = atoi(value.c_str());
                Voltage[atoi(n2.c_str())][atoi(n1.c_str())] = atoi(value.c_str());
            }
        }
    }
    fin.close();
    cout<<"Resistance matrix -> "<<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<Resistance[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Voltage matrix -> "<<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<Voltage[i][j]<<" ";
        cout<<"\n";
    }
}
