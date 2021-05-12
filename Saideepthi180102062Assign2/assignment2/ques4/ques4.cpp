

#include "global.h"
#include "productinfo.h"



vector<Product>v;

bool check_item(){
    
    string code;
    cout<<"Enter item code: ";
    cin>>code;
    
    for(int i=0;i<v.size();i++){
    if(v[i].product_code==code){
       return true;
    }
   }
   return false;
}
// find index of product based on product code
int product_index(string code){
  int x=-1;
  for(int i=0;i<v.size();i++){
    if(v[i].product_code==code){
       x=i; break;
    }
   }
   return x;
}
// Adding new item to stock
void add_item(){
   string name;
   string code;
   string loc;
   cout<<"enter name: ";
   cin>>name;
   cout<<"enter code: ";
   cin>>loc;
   cout<<"enter location: ";
   cin>>code;
   int ind=product_index(code);
   if(ind!=-1){ // if already present
      cout<<"This product already exists.Please go for update option"<<endl;
   }
   else{
     v.push_back({name,code,loc,1});
   }
   
}
// Deleting particular item in stock
void delete_item(){
   string code;
   cout<<"enter code: ";
   cin>>code;
   int ind=product_index(code);
   if(ind!=-1){ // if already present
      v.erase(v.begin()+ind);
   }
   else{
     cout<<"There is no such item present to delete"<<endl;
   }
   
}
// Update stock information
void update_item(){
   string code;
   int frq;
   cout<<"enter code: ";
   cin>>code;
  
   int ind=product_index(code);
   if(ind!=-1){
      cout<<"You want to add/remove items?\n Enter add/sub? ";
     string s;
     cin>>s;
      cout<<"enter quantity: ";
      cin>>frq;
    if(s=="add"){
       v[ind].product_count+=frq;
    }
    else if(s=="sub"){
       if(v[ind].product_count>frq){
           v[ind].product_count-=frq;
       }
       else{
           cout<<"Insufficient number of items"<<endl;
       }
    }
    else{
       cout<<"Enter either add/sub "<<endl;
    }
   }
   else{
    cout<<"No such item exists"<<endl;
   }
}
// Displaying whole information of stock   
void display_item(){
    for(int i=0;i<v.size();i++){
      cout<<"ProductName: "<<v[i].product_name<<" "<<"ProductCode: "<<v[i].product_code<<" "<<"ProductCount: "<<v[i].product_count<<endl;
    }
   
}  
