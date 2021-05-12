# include "global.h"
# include "ques5.h"


/*
   FEATURES : 1. ADD TEXT
              2. DELETE TEXT
              3. REPLACE TEXT
              4. PRINT TEXT
              5. EXIT PROGRAM
*/
int main()
{


  
        cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|            TEXT EDITOR                    |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t Enter A Append Text"<<endl;
	cout<<"\t\t Enter D Delete Text"<<endl;
	cout<<"\t\t Enter R Replace Text"<<endl;
	cout<<"\t\t Enter P Print Text"<<endl;
	cout<<"\t\t Enter E EXIT"<<endl;
	
  while(1){
      cout<<"Enter your choice: ";
      char ch; cin>>ch;
      if(ch=='A') append();
      else if(ch=='D') deleteline("myfile.txt");
      else if(ch=='R') replace();
      else if(ch=='P') printfile();
      else if(ch=='E') break;
      else cout<<"Enter correct choice(A/D/R)"<<endl;
  }
  
  return 0;
}

