#include <iostream>
#include <string>
#include<vector>
#include<fstream>
using namespace std;
int num;
int cont=0;
int sizev=0;
int noacc=0;
class account;
vector<account> v;
class account{
  private:
  string fname,lname;
   int accountno;
  float balance;
float amount;
  public:
  account(){
  
      fname="";
      lname="";
      accountno=cont+1;
      balance;
      cont++;
  }
	//mutators
void setfname(string f);
void setlname(string l);
void setaccountno(int accno);
void setbalance(float b);
//accessors
string getfname();
string getlname();
int getaccountno();
float getbalance();
//major fuctions
void openanaccount();
void display(account a);
void balanceenquiry();
void deposit();
void withdraw();
void closeanacc();
void printall();
  //file functions
friend ifstream & operator>>(ifstream &ifs,account &ac);
 friend ofstream & operator<<(ofstream &fos,account &ac);
};
                                                            //file functions //
ofstream & operator<<(ofstream &fos,account &ac){
	fos<<ac.fname<<endl<<ac.lname<<endl<<ac.accountno<<endl<<ac.balance<<endl;
return fos;
}
ifstream & operator>>(ifstream &ifs,account &ac){
	ifs>>ac.fname;
	ifs>>ac.lname;
	ifs>>ac.accountno;
	ifs>>ac.balance;
return ifs;
}
                                                                //accessors//
string account::getfname(){
	return fname;
}
string account::getlname(){
	return lname;
}
int account::getaccountno(){
	return accountno;
}
float account::getbalance(){
	return balance;
}
                                                                 //mutators//
void account::setfname(string f){
	fname=f;
}
void account::setlname(string l){
	lname=l;
}
void account::setbalance(float b){
	balance=b;
}
void account::setaccountno(int accno){
	accountno=accno;
}
                                                           //open an account//
void account::openanaccount(){
	account newa;

    cout<<"enter your first name: ";
    cin>>fname;
    cout<<"enter your last name: ";
    cin>>lname;
    cout<<"enter your initial balance: ";
    cin>>balance;
newa.setfname(fname);
newa.setlname(lname);
newa.setbalance(balance);
v.push_back(newa);
cout<<endl;
cout<<"congratulations account created"<<endl;
cout<<endl;
    newa.display(newa);
sizev++;
}
                                                            //display fuction//
void account::display(account a){
	
	cout<<"the account no.is: "<<a.getaccountno()<<endl;
    cout<<"account holder name: "<<a.getfname()<<" "<<a.getlname()<<endl;
    cout<<"current balance of the account: "<<a.getbalance()<<endl;
}
                                                            //balance enquiry//
void account::balanceenquiry(){
	cout<<"enter account number:"<<endl;
    cin>>num;
vector<account>::iterator it;
 for(it=v.begin();it!=v.end();it++){
	int temp=it->getaccountno();
if(temp==num){
	cout<<"the balance of this account is:"<<endl;
cout<<it->getbalance()<<endl;
goto endofif;
}
}
cout<<"invalid account number:"<<endl;
endofif:
	cout<<endl;
}
                                                             //deposit function//
void account::deposit(){
	cout<<"enter the account number:"<<endl;
cin>>num;
cout<<"enter amount to be deposited:"<<endl;
cin>>amount;
vector<account>::iterator itr;
for(itr=v.begin();itr!=v.end();itr++){
	int temp=itr->getaccountno();
if(temp==num){
	int tempb=itr->getbalance();
cout<<"current balance"<<endl;
itr->setbalance(tempb+=amount);
cout<<tempb<<endl;
goto finished;
}
}
cout<<"invalid account number"<<endl;
finished:
	cout<<endl;
}
                                                             //withdraw function//
void account::withdraw(){
	cout<<"enter the account number:"<<endl;
cin>>num;
cout<<"enter amount to be withdrawn:"<<endl;
cin>>amount;
vector<account>::iterator itr;
for(itr=v.begin();itr!=v.end();itr++){
	int temp=itr->getaccountno();
if(temp==num){
	int tempb=itr->getbalance();
cout<<"current balance"<<endl;
itr->setbalance(tempb-=amount);
cout<<tempb<<endl;
goto finished;
}
}
cout<<"invalid account number"<<endl;
finished:
	cout<<endl;
}
                                                           //close an account funtion//
void account::closeanacc(){
	cout<<"enter account number:"<<endl;
cin>>num;
vector<account>::iterator itr;
for(itr=v.begin();itr!=v.end();itr++){
	int temp=itr->getaccountno();
if(temp==num){
	itr->display(*itr);
v.erase(itr);
cout<<"account closed"<<endl;
sizev--;
goto finished;
}
}
cout<<"invalid account number"<<endl;
finished:
	cout<<endl;
}
                                                               //print all function//
void account::printall(){
	vector<account>::iterator itr;
for(itr=v.begin();itr!=v.end();itr++){
	itr->display(*itr);
}
}
                                                                //main body//
int main(){
    account acc;
int option;
ifstream infile("bank.txt");
{
    //infile>>acc;
    infile >> noacc;
    infile >> sizev;
	v.resize(sizev);
	vector<account>::iterator itr;
for(itr=v.begin();itr!=v.end();itr++){
	infile>>*itr;
	infile>>acc;
}
infile.close();
cont=noacc;
}

do{

cout<<"**********************BANKING SYSTEM*********************"<<endl;
cout<<"Menu options:"<<endl;
cout<<"\t 1 Open An Account "<<endl;
cout<<"\t 2 Balance Enquiry "<<endl;
cout<<"\t 3 Deposit"<<endl;
cout<<"\t 4 Withdrawal"<<endl;
cout<<"\t 5 Close An Account"<<endl;
cout<<"\t 6 Show All Account "<<endl;
cout<<"\t 7 Quit "<<endl;


cout<<"choose an option"<<endl;
cin>>option;
switch(option){
case 1://creating an account
	cout<<"enter your account details:"<<endl;
	acc.openanaccount();
    break;
case 2://balance enquiry
acc.balanceenquiry();
	break;
case 3://deposite amount
acc.deposit();
	break;
case 4://withdraw amount
	acc.withdraw();
	break;
case 5://close an account
	acc.closeanacc();
	break;
case 6://show all account
     account *show=nullptr;
     cout<<"all accounts created in this bank:"<<endl;
     show->printall();
     break;
case 7://quit 
      cout<<"thanks for using the app";
      goto end;
}
}
while(option!=7);{
	cout<<"invalid input"<<endl;
}
end:
    noacc=cont;
	ofstream outfile("bank.txt",ios::trunc);
{
	outfile << noacc << endl;
	//outfile<<acc;
	outfile << sizev << endl;
	vector<account>::iterator itr;
 for(itr=v.begin();itr!=v.end();itr++){
	outfile<<*itr;
	outfile<<acc;
 }
 outfile.close();
 }
}



