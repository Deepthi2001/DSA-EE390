/*Given a list of N integers, find its mean (as a double), maximum value, minimum value, and range.
Your program will first ask for N(the number of integers in the list),then the numbers.*/

#include "global.h"
#include "que1.h"

double Mean(int arr[],int n){
    int sum;
    double mean;
    sum = 0;

    for(int i=0; i<n; i++){
      sum += arr[i];
    }

    mean = sum/(double)n;

    return mean;
}


/* n is odd:    3*(n-1)/2  comparison in pairs
   n is even:  1 + 3*(n-2)/2 
   less number of comparisions compared to direct traversal
*/
      
   
void printMaxMin(int arr[],int n){
    int i;
    int maxi,mini;
    if (n % 2 == 0){
        if (arr[0] > arr[1]){
            maxi = arr[0];
            mini = arr[1];
        }
        else{
            mini = arr[0];
            maxi = arr[1];
        }
        i = 2;
    }
  
    else{
        mini = arr[0];
        maxi = arr[0];
        i = 1;
    }
    while (i < n - 1){     	
        if (arr[i] > arr[i + 1]) {
            if(arr[i] > maxi) 	
                maxi = arr[i];    
            if(arr[i + 1] < mini)     	
                mini = arr[i + 1]; 	
        }
        else {
            if (arr[i + 1] > maxi) 	
                maxi = arr[i + 1];
            if (arr[i] < mini)     	
                mini = arr[i]; 	
        }
        i += 2;
    }    
    int range=maxi-mini;
    cout<< "Maximum of the given array is : "<<maxi<<endl;
   cout<< "Minimum of the given array is : "<<mini<<endl;
   cout<< "Range of the given array is : "<<range<<endl;
}
