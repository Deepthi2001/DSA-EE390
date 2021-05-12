#ifndef BANKDETAILS_H
#define BANKDETAILS_H
#include "accdetails.h"


bool bankopen=false;

// account numbers are from 1001 to anynumber of accounts(no limit)
// atm codes are from 2001 TO ATM 2010

class Bank{
   public:            // creating account for storing each customer details
     int atmdata[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
     int x=1001;
     
     unordered_map<int,Account>m; // account number maps to account holder details
     
     bool isManager(){
       string s;
       cout<<"Enter manager pin: "<<endl;
       cin>>s;
       if(s==managerpin) return true;
       else return false;
     }
    
    
    void openacc(){  // transaction type - O
          int accnum;
          double initdep;
          string pin;
          Account acc;
          string name;
          cout<<"Enter account holder name: ";
          cin>>name;
          cout<<"Enter pin:";
          cin>>pin;
          acc.accountpin(pin);
          cout<<"Enter deposit money: ";
          cin>>initdep;
          acc.name=name;
          acc.AccNum=x;
          acc.Deposit=initdep;
          m.insert({x,acc});
          cout<<"Account number: "<<x<<" "<<"opened successfully"<<endl;
          x++;
       }
       
        bool activeacc(int accnum){
         for(auto x:m){
           if(x.first==accnum){
             return true;
           }
         }
         return false;
       }
       
       void resetpin(){
          int accnum;
          cout<<"Enter account number: ";
          cin>>accnum;
          
          if(activeacc(accnum)){
             cout<<"Account exists"<<endl;
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(m[accnum].checkpin(pin)){
                string s;
		cout<<"Enter new pin: ";
                cin>>s;
                m[accnum].accountpin(s);
                cout<<"Password updated successfully!!";
                
	     }
	     else{
		  cout<<"Incorrect account pin..please enter the correct pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
          
      }
      
        
    void balancecheck(){  // transaction type - B
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"Account exists"<<endl;
             string pin;
             cout<<"Please enter account pin: ";
             cin>>pin;	
             if(m[accnum].checkpin(pin)){
		cout<<"Account number is: ";
                cout<<m[accnum].AccNum<<"   ";
                cout<<"Account balance is: Rs.";
                cout<<m[accnum].Deposit<<endl;
	     }
	     else{
		  cout<<"Incorrect account pin..please enter the correct pin.."<<endl;
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
             if(m[accnum].checkpin(pin)){
               int amt; 
               cout<<"Deposit Amount :Rs";
                cin>>amt;
                (m[accnum].Deposit)+=amt;
		cout<<"Account number is: ";
                cout<<m[accnum].AccNum<<"   "; 
                cout<<"Account balance is: Rs.";
                cout<<m[accnum].Deposit<<endl;
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
	     }
	}
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
	
     }
     
     void fillCashATM(int atmnum){
        cout<<"Admin to be attended to raise ATM funds"<<endl;
        bool flag=false;
        while(1){
            flag=isManager();
            if(flag){
              cout<<"Hello Manager!, raise funds of ATM number "<<atmnum<<endl;
              atmdata[atmnum-2001]+=10000;
              return;
            }
            
        }
    }
     
    void addmoneyATM(){
       if(isManager()){
        string s;
        int amount;
        cout<<"Add amount to all atm's/one atm: "<<endl;
        cout<<"Enter all/one:";
        cin>>s;
        cout<<"Enter Amount:";
        cin>>amount;
        if(s=="all"){
            for(int i=0;i<10;i++){
               atmdata[i]+=amount;
            }
            cout<<"Successfully filled money in all ATM's"<<endl;
        }
        else if(s=="one"){
           int atmnum;
           cout<<"Enter ATM number: ";
           cin>>atmnum;
           atmdata[atmnum-2001]+=amount;
            cout<<"Successfully filled money in ATM num: "<<atmnum<<endl;
        }
        else cout<<"select either all/one"<<endl;
       
       }
       else cout<<"Incorrect manager pin"<<endl;
        
    }
     
     
     
     void withdrawamount(){  // transaction type - W
        int accnum;
        cout<<"Enter account number: ";
        cin>>accnum;
        // first check account is active or not
        if(activeacc(accnum)){
             cout<<"This account is active..";
             while(1){
                  cout<<"Enter atm code(2001-2010) : "<<endl;
                  int atmnum; cin>>atmnum;
                  string pin;
                  cout<<"Please enter account pin: ";
                  cin>>pin;	
                 if(m[accnum].checkpin(pin)){
                   int debitamt; 
                   cout<<"Withdrawal Amount :Rs";
                   cin>>debitamt;
                   if(m[accnum].Deposit - debitamt>=0){
                        if(atmdata[atmnum-2001]>=debitamt){
                              m[accnum].Deposit-=debitamt;
                              cout<<"Account number is: ";
                              cout<<m[accnum].AccNum<<"    "; 
                              cout<<"Account balance is: Rs.";
                    
                              cout<<(m[accnum].Deposit)<<endl;
                              atmdata[atmnum-2001]-=debitamt;
                              break;
                        }
                        else{
                            cout<<"Insufficient money in this atm.."<<endl;
                            cout<<"Check in other nearby ATM"<<endl;
                            fillCashATM(atmnum);
                        }
                }
                else{
                  cout<<"Insufficient balance in your bank account"<<endl;
                  break;
                }
		
	     }
	     else{
		  cout<<"Incorrect account pin..please try with another pin.."<<endl;
		  break;
	     }
	}
      }
            
	else{ 
	   cout<<"Inactive Account/Account doesn't exist.. "<<endl;
	}
   }
     
     void NearATM(){
       int debamt; 
       int c=0;
       cout<<"Enter amount to be debited: ";
       cin>>debamt;
       cout<<"Desired amount is available in "<<endl;
       for(int i=0;i<10;i++){
          if(atmdata[i]>=debamt){
            cout<<"ATM CODE: "<<(2001+i)<<" "<<"Amount :"<<atmdata[i]<<endl;
            c++;
          }
       }
       if(c==0) cout<<"Amount is not available in any nearby ATM"<<endl;
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
             if(m[accnum].checkpin(pin)){
                m.erase(accnum);
                cout<<"Sorry to see you go..."<<endl;
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
          for(auto x:m){
               x.second.Deposit+=(double)(x.second.Deposit*rate)/100;
              
           }
        }
       
       else cout<<"Incorrect manager pin"<<endl;
       
     }
     
     void allaccounts(){  // transaction type - P
      
      if(isManager()){
          if(m.size()==0) cout<<"No accounts opened yet!!"<<endl;
          for(auto x:m){
            cout<<"Account holder name: "<<(x.second.name)<<"  ";
            cout<<"Account number: "<<(x.second.AccNum)<<"  ";
            cout<<"Account Balance: "<<(x.second.Deposit)<<endl;
          }
      }
      else cout<<"Incorrect manager pin"<<endl;
        
     }
     
     void allATM(){
        for(int i=0;i<10;i++){
          cout<<"ATM: "<<(2001+i)<<" "<<"Amount available: "<<atmdata[i]<<endl;
        }
     }
     
     void CloseBank(){  // transaction type - E
             // closes all accounts
             m.clear();
	cout<<"Closing bank.."<<endl;
    }
	
	
     void OpenBank(){  // transaction type - S
		cout<<"Bank is alredy open.."<<endl;
      }	
	
	private:
	string managerpin="HELLO";
     
};

#endif
