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
    int n=5;
    
    std::ofstream myFile;
    //opens the text file 
    myFile.open("compared_values.txt");
    cout<<"DFS \t BFS"<<endl;
    myFile << "size" << " " <<  "DFS" << " " << "BFS" << endl;
    while(n<100000){
    vector<vector<int>> Resistance(n,vector<int>(n));
    vector<vector<int>> Voltage(n,vector<int>(n));

    //initialise every element to -1(meaning no resistances)
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            Resistance[i][j] = -1;
            Voltage[i][j] = -1;
            
        }
    }
    
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
    
    
    
    
    
    
    
    
    clock_t start, end; 
    start = clock(); 
    DFS(0,0,Resistance,Voltage,n);
    end = clock(); 
    double time1 = ((double)(end - start)); 
    start = clock(); 
    BFS(0,0,Resistance,Voltage,n);
    end = clock(); 
    double time2 = ((double)(end - start)); 
    
    //stores the values in text file created
    
    myFile << n << " " << time1 << " " << time2 << endl;
    cout<<time1<<"\t "<<time2<<endl;
    n+=100;
    }
    
    myFile.close();

    //closes the text file after storing the values
    
}
