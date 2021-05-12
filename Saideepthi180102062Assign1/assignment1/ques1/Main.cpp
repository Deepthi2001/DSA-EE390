/*Given a list of N integers, find its mean (as a double), maximum value, minimum value, and range.
Your program will first ask for N(the number of integers in the list),then the numbers.*/

#include "global.h"
#include "que1.h"



int main(){

    double mean;
    int n;
    cout << "Enter the size of the array: " ;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin >> arr[i];
      
    }

    mean = Mean(arr,n);
    cout<< "Mean of the given array is : "<<mean<<endl; 
    printMaxMin(arr,n);
    cout<<endl;

    

    return 0;
}
