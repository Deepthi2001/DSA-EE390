# include "global.h"
#include "bankdetails.h"


int main(){
	Bank Canara;
	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|          Bank management                  |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t Enter O Add bank account"<<endl;
	cout<<"\t\t Enter B Show Account Balance"<<endl;
	cout<<"\t\t Enter U Reset Account Pin"<<endl;
	cout<<"\t\t Enter D deposit money into Account"<<endl;
	cout<<"\t\t Enter W Withdraw money from ATM"<<endl;
	cout<<"\t\t Enter C Close Account"<<endl;
	cout<<"\t\t Enter I Apply given Interest rate to all accounts"<<endl;
	cout<<"\t\t Enter P Display Details of all accounts"<<endl;
	cout<<"\t\t Enter S Open Bank"<<endl;
	cout<<"\t\t Enter M Add money to ATM's"<<endl;
	cout<<"\t\t Enter N Check nearest atm with sufficient money"<<endl;
	cout<<"\t\t Enter A Display Amount in all ATMs"<<endl;
	cout<<"\t\t Enter E Exit from the portal "<<endl;
	
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
				case 'U': Canara.resetpin();       break;
				case 'B': Canara.balancecheck();   break;
				case 'M': Canara.addmoneyATM();    break;
				case 'D': Canara.depositamount();  break;
				case 'W': Canara.withdrawamount(); break;
				case 'C': Canara.closeaccount();   break;
				case 'I': Canara.interest();       break;
				case 'P': Canara.allaccounts();    break;
				case 'S': Canara.OpenBank();       break;
				case 'N': Canara.NearATM();        break;
				case 'A': Canara.allATM();         break;
				default:cout<<"Invalid Transaction Type..Choose a valid transation type.."<<endl;
			}
		}
		else{
			if(ch=='S'){ // open bank
				if(Canara.isManager()){
					bankopen=true;
				}
			}
			else{
				cout<<"Bank is not open yet..Please use Transaction type:S to open"<<endl;
			}
		}
	}
	return 0;
}
