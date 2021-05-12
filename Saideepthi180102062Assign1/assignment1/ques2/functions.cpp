#include "global.h"
#include "functions.h"

/*bool checkPrime(int n){  // O(sqrt(n))
   int i, flag = 1; 
    for (i = 2; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
    if(n<=1) flag=0; 
    else if(n==2) flag=1;  
  
    if (flag == 1) { 
        return true;
    } 
    else { 
        return false;
    } 
}*/

bool checkPrime(int n){  // O(sqrt(n))
   if(n<=1) return false;
   if(n<=3) return true;
   if(n%2==0 || n%3==0) return false; // since many numbers are multiples of 2 and 3
   
   for(int x=5;x*x<=n;x+=6){
     if(n%x==0 || n%(x+2)==0){
        return false;
     }
   }
   return true;
} 
    
void Nprime(int n){
   int count=0;
   int num=1;
      while(count<n){
        if(checkPrime(num)){
           cout<< num <<" ";
           count++;
        } 
        num++;
      }   
}
