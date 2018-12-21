// Salman Javed
// Assignment CPP-1
// Calcualte Data For A Clipped Cone

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double starting_amount, interest, rate;
  	double copyStart;
    int compound_times;
    string customer_name, bank_name;
   // cout << "Enter the Bank Name:                      ";
   // cin >> bank_name;
    cout << "Enter starting amount:                    ";
    cin >> starting_amount;
  	copyStart=starting_amount;
    cout << " Enter the interest rate as decimal:      ";
    cin >> interest;
  	interest*=100;
    cout << "How many times will it be compounded:     ";
    cin >> compound_times;
    cin.ignore();
   // cout << "Enter customer name:                       ";
  //  getline(cin, customer_name);
    cout << endl;

    for(int i=0;i<compound_times;i++)
        starting_amount+=(starting_amount*interest)/100;
     cout<<starting_amount;
/**

    cout << "-------------" << bank_name << "    earning report----" << endl;
    cout << "Customer Name is             " << customer_name << endl;
    cout << "Interest Rate:           " << interest << endl;
    cout << "Times Compounded           " << compound_times << endl;
    cout << "Principal:          " << copyStart << endl;
    cout << "Interest:       " << interest << endl;
    cout << "amount in savings:        " <<  starting_amount-copyStart << endl;
 */
    ///
}
