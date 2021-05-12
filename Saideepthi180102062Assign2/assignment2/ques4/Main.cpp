/*
Project of inventory management system which provides below functionalities.

1) Add item
2) Delete item information 
3) Search item
4) Update item information
5) Display stock
*/

#include "global.h"
#include "ques4.h"

int main () {
 while(1)
    {
    
        cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|          Warehouse in inventory management        |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter A ADD a new product to store "<<endl;
	cout<<"\t\t     Enter P Display all products to store "<<endl;
	cout<<"\t\t     Enter U Update Existing product details"<<endl;
	cout<<"\t\t     Enter D Delete a particular product item"<<endl;
	cout<<"\t\t     Enter S Search for a product "<<endl;
	cout<<"\t\t     Enter E Exit from the portal "<<endl;
      
      
      cout<<"\n\n Choose you choice:";
      char ch;
      cin>>ch;

      switch(ch)
      {
        case 'A':
        {
          add_item();
          break;
        }
        case 'D':
        {
          delete_item();
          break;
        }
        case 'U':
        {
          update_item();
          break;
        }
        case 'S': 
        {
          if(check_item()){
            cout<<"This item exists"<<endl;
          }
          else{
            cout<<"This item do not exist"<<endl;
          }
          break;
        }
        case 'P':
        {
          display_item();
          break;
        }
        case 'E':
        {
           break;
        }

        default:{
          cout<<"Please choose a correct choice";
          break;
        }
      }
    }
    return 0;
}

