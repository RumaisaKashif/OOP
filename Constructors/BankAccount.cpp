#include "iostream"
#include <string>
using namespace std;
class BankAccount{
    string* depositorname=new string;
    string* accountnumber=new string;
    string* acctype=new string;
    double* rembalance=new double;
    public:
    // Default constructor
    BankAccount() : rembalance(new double(1000.0)), depositorname(new string("Rumaisa Kashif")), accountnumber(new string("972004")), acctype(new string("Current")) {
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    BankAccount(string name, string num, string type, double bal) : depositorname(new string(name)), accountnumber(new string(num)), acctype(new string(type)), rembalance(new double(bal)) {
        cout << "Parametricised constructor called" << endl;
    }

    // Copy constructor
    BankAccount(const BankAccount &obj) : depositorname(new string(*(obj.depositorname))), accountnumber(new string(*(obj.accountnumber))), acctype(new string(*(obj.acctype))), rembalance(new double(*(obj.rembalance))) {
        cout << "Copy constructor called" << endl;
    }
    ~BankAccount()
    {
        delete  depositorname;
        delete  accountnumber;
        delete  rembalance;
        delete  acctype;
        cout<<"Destructor called"<<endl;
    }
    void displayInfo()
    {
        cout<<"Account holder's name: "<<*depositorname<<endl;
        cout<<"Account type "<<*acctype<<endl;
        cout<<"Account number: "<<*accountnumber<<endl;
        cout<<"Account balance: "<<*rembalance<<endl;
    }
    void withdrawAmount(double amt)
    {
        if (*rembalance>=amt)
            *rembalance-=amt;
        else 
            cout<<"Insufficient Balance!"<<endl;
    }
    void depositAmount(double dep)
    {
        *rembalance+=dep;
    }
};
int main(){
    int size;
    cout<<"Enter array size"<<endl;
    cin>>size;
    cin.ignore();
    string name, type, num;
    double balance;
    cout<<"Enter your name: ";
    getline(cin,name);
    cout<<"Enter your account type: ";
    cin>>type;
    cout<<"Enter your account number: ";
    cin>>num;
    cout<<"Enter your balance: ";
    cin>>balance;
    BankAccount* acc = new BankAccount[size]{ 
    BankAccount(),
    BankAccount(name, num, type, balance), // Initialize as second object
    BankAccount()
};
    acc[2]=acc[0];

    // Before any functions are called to action, let's display the information stored for each account oject
    for (int i=0;i<size;i++)
    {
        acc[i].displayInfo();
        cout<<"--------------------------------------"<<endl;
    }

    acc[1].withdrawAmount(500);
    cout<<"\nAfter withdrawal of Rs.500 from Account No.2\n";
    acc[1].displayInfo();
    delete[] acc;
}
