#include "global.h"
#include "functions.h"

int main(){
    int iterations;
    
    cout << "enter the iterations : ";
    cin >> iterations;
    
    cout << "the value of pi for " << iterations <<" iterations is : ";
    cout << valueOfPi(iterations) << endl;

    return 0;
}