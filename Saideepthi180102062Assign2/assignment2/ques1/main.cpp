# include "global.h"
#include "complex.h"
int32_t main()
{
    
   
    
    
    //------------------------------------part (A)-------------------------------
    comp<int> a1(20,30),b1(40,50),c1(0,0);

     cout<<"\n"<<"---------PART-A-----------"<<endl;
    c1 = a1+b1;                        //addition
    cout<<"Addition: ";
    c1.display();
    c1=a1-b1;  
    cout<<"Subtraction: ";             //subtraction
    c1.display();
    c1=a1*b1;       
     cout<<"Multiplication: ";         //multiplication
    c1.display();

    //------------------------------------part (B)--------------------------------
    mat<int> a(3,4), b(3,4), c(3,4);

    for(int i=0;i<3;++i)
    for(int j=0;j<4;++j)
    {
        a.matrix[i][j]=(i+1)*3+j;
        b.matrix[i][j]=i*3+j;
    }
     cout<<"---------Matrix-A-----------"<<endl;
     for(int i=0;i<3;++i){
       for(int j=0;j<4;++j){
        cout<<a.matrix[i][j]<<" ";
       }
        cout<<endl;
    }
    cout<<"---------Matrix-B-----------"<<endl;
     for(int i=0;i<3;++i){
       for(int j=0;j<4;++j){
        cout<<b.matrix[i][j]<<" ";
       }
        cout<<endl;
    }
    cout<<"---------PART-B-----------"<<endl;
    c = a + b;                  //addition
    cout<<"Addition: "<<endl;
    c.display();                   
    c=a-b;                      //subtraction
    cout<<"Subtraction: "<<endl;
    c.display();                   

    mat<int> d(4,3), e(3,2);

    for(int i=0;i<4;++i)
       for(int j=0;j<3;++j)
          d.matrix[i][j]=1;

    e=a*d;                      //multiplication
    cout<<"Multiplication: "<<endl;
    e.display();

    d=a.transpose();            //transpose
    cout<<"Transpose: "<<endl;
    d.display();

    
    
    return 0;
}
