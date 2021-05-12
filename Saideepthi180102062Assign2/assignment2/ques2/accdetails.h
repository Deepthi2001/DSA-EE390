#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
  public: 
  string name;
  int AccNum;
  double Deposit;
  void accountpin(string p){
     pin=p;
  }
  bool checkpin(string s){
    if(s==pin) return true;
    else return false;
  }
  private: 
  string pin;
};

#endif
