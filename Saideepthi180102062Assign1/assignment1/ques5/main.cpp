# include "global.h"
#include "bankdetails.h"


int main(){
	Bank Canara;
	while(1){
		cout<<"Choose a Transaction Type?"<<endl;
		char ch;
		cin>>ch;
		
		if(ch=='E'){
			if(Canara.isManager()){
				Canara.CloseBank(); // type-E
				break;
			}else{
				cout<<"Incorrect Manager pin.."<<endl;
			}
		}
		if(bankopen){
			switch(ch){
				case 'O': Canara.openacc();        break;
				case 'B': Canara.balancecheck();   break;
				case 'D': Canara.depositamount();  break;
				case 'W': Canara.withdrawamount(); break;
				case 'C': Canara.closeaccount();   break;
				case 'I': Canara.interest();       break;
				case 'P': Canara.allaccounts();    break;
				case 'S': Canara.OpenBank();       break;
				default:cout<<"Invalid Transaction Type..Choose a valid transation type.."<<endl;
			}
		}
		else{
			if(ch=='S'){
				if(Canara.isManager()){
					bankopen=true;
				}
			}
			else{
				cout<<"Bank is not open yet.."<<endl;
			}
		}
	}
	return 0;
}
