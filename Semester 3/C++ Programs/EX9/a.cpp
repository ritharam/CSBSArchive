#include<iostream>
using namespace std;

class Account2;

class Account1{
public:
    int balance1=50000;
    friend void transferAmt(Account1 &a,Account2 &b,int opt,int amt);
};

class Account2{
public:
    int balance2=50000;
    friend void transferAmt(Account1 &a,Account2 &b,int opt,int amt);
};

void transferAmt(Account1 &a,Account2 &b,int opt,int amt){
    switch(opt){
        case 1:{
            cout<<"TRANSFERING FROM ACCOUNT 1 TO ACCOUNT 2"<<endl;
            a.balance1=a.balance1-amt;
            b.balance2=b.balance2+amt;
            cout<<"BALANCE IN ACCOUNT 1 :"<<a.balance1<<endl;
            cout<<"BALANCE IN ACCOUNT 2 :"<<b.balance2;
            break;}

        case 2:{
            cout<<"TRANSFERING FROM ACCOUNT 2 TO ACCOUNT 1"<<endl;
            b.balance2=b.balance2-amt;
            a.balance1=a.balance1+amt;
            cout<<"BALANCE IN ACCOUNT 1 :"<<a.balance1<<endl;
            cout<<"BALANCE IN ACCOUNT 2 :"<<b.balance2;
            break;}

        default:{
            cout<<"WRONG OPTION!!TRY AGAIN"<<endl;
            break;}
    }
}

int main(){
    Account1 a1;
    Account2 a2;
    int amt,opt;
    cout<<"ENTER THE AMOUNT OF TRANSFER :";
    cin>>amt;
    cout<<"ENTER SUITABLE OPTION FOR TRANSACTION:\n1.FROM ACCOUNT1 TO ACCOUNT2\n2.FROM ACCOUNT2 TO ACCOUNT1"<<endl;
    cin>>opt;
    transferAmt(a1,a2,opt,amt);
    return 0;
}