#include "global.h"
#include "functions.h"

double valueOfPi(int itr){

    // x and y are the coordinates of a point in the plane
    
    double x, y, distfromorigin, PI;
    // circle represents number of points present within the circle
    // square represents number of points present within the square
    int circle = 0, square = 0;
    
    // initialize random seed with current time
    srand(time(0));

    for(int i=0; i < itr * itr; i++){
        // generate the x and y coordinates and should lie in the range [0,1]. 
        x = (double)(rand() % (itr+1))/itr;
        y = (double)(rand() % (itr+1))/itr;
        
        distfromorigin = x*x + y*y;
        if(distfromorigin <= 1){
            circle++;
        }
        square++; 

        
    }
    PI = (double)(4 * circle) / square;
    
    // observation: when number of iterations increases PI value nearly goes to real value of PI.
    // as number of iterations increases, accuracy of value of PI increases. 

    return PI;

}
