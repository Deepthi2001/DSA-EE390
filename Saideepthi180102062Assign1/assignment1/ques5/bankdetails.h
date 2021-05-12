#ifndef BANKDETAILS_H
#define BANKDETAILS_H
#include "accdetails.h"


bool bankopen=false;



class Bank{
   public:
     Account account[100]; // creating 100 accounts for storing each customer details
     int actacc[100]={0};     // to check account is active(1) or not(0)
    
    
     bool isManager(){
       string s;
       cout<<"Enter manager pin: "<<endl;
       cin>>s;
       if(s==managerpin) return true;
       else return false;
     }
    
     
     bool activeacc(int accnum){
        if(actacc[accnum-1001]==0){
           return false;
        }
        else return true;
     } 
    
    
    void openacc(){  // transaction type - O
      int x=-1;
      int i=0;
      while(i<100){
         if(activeacc(1001+i)==false){ // inactive
            actacc[i]=1;        // make it active
            x=i; break;
         }
         i++;
      }
      if(x>=0){
          double initdep;
          string pin;
          Account acc;
          cout<<"enter pin:";
          cin>>pin;
          acc.accountpin(pin);
          cout<<"Enter deposit money: ";
          cin>>initdep;
          acc.AccNum=1001+x;
          acc.Deposit=initdep;
          account[x]=acc;
          cout<<"Account number is: "<<(1001+x)<<endl;
       }
      
      else{
         cout<<"Accounts limit exceeeded.."<<endl;
      }
     
   }
    
        
    void balancecheck(){  // transaction type - B
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"This account is active..";
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(account[accnum-1001].checkpin(pin)){
		cout<<"Account number is: ";
                cout<<account[accnum-1001].AccNum<<"   ";
                cout<<"Account balance is: Rs.";
                cout<<account[accnum-1001].Deposit<<endl;
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
    }
    
    
    void depositamount(){   // transaction type - D
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"This account is active..";
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(account[accnum-1001].checkpin(pin)){
               int amt; 
               cout<<"Deposit Amount :Rs";
                cin>>amt;
                (account[accnum-1001].Deposit)+=amt;
		cout<<"Account number is: ";
                cout<<account[accnum-1001].AccNum<<"   "; 
                cout<<"Account balance is: Rs.";
                cout<<account[accnum-1001].Deposit<<endl;
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
	
     }
     
     
     void withdrawamount(){  // transaction type - W
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"This account is active..";
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(account[accnum-1001].checkpin(pin)){
               int debitamt; 
               cout<<"Withdrawal Amount :Rs";
                cin>>debitamt;
                if(account[accnum-1001].Deposit - debitamt>=0){
                account[accnum-1001].Deposit-=debitamt;
                    cout<<"Account number is: ";
                    cout<<account[accnum-1001].AccNum<<"    "; 
                    cout<<"Account balance is: Rs.";
                    
                    cout<<(account[accnum-1001].Deposit)<<endl;
                }
                else{
                  cout<<"Insufficient balance.."<<endl;
                }
		
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
     }
     
     
     void closeaccount(){  // transaction type - C
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"This account is active..";
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(account[accnum-1001].checkpin(pin)){
                actacc[accnum-1001]=0;
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
     }
     
     
     void interest(){    // transaction type - I
       if(isManager()){
          double rate;
          cout<<"Enter rate of interest: ";
          cin>>rate;
          for(int i=0;i<100;i++){
            if(actacc[i]!=0){
              account[i].Deposit+=(double)(account[i].Deposit*rate)/100;
              
           }
        }
       }
       else cout<<"Incorrect manager pin"<<endl;
       
     }
     
     void allaccounts(){  // transaction type - P
      if(isManager()){
        for(int i=0;i<100;i++){
          if(actacc[i]!=0){
              cout<<"Account number is:";
              cout<<account[i].AccNum<<"        ";
              cout<<"balance: Rs:";
              cout<<account[i].Deposit<<endl;
          }
        }
      }
        
     }
     
    
     
     void CloseBank(){  // transaction type - E
             // closes all accounts
             for(int i=0;i<100;i++){
                   actacc[i]==0;
              }
		cout<<"Closing bank.."<<endl;
    }
	
	
     void OpenBank(){  // transaction type - S
		cout<<"Bank is alredy open.."<<endl;
	}	
	
	private:
	string managerpin="HELLODEEPTHI";
     
};

#endif
