/**
 * @file PolynomialInterface.cpp
 * @author Ritik Jain
 * @date 17/09/2019
 * @brief Main Interface for Polynomial
 */

#include "Polynomial.cpp"
#include <iostream>

using namespace std;
using namespace asn5;

int main(int argc, char **argv)
{
    cout << "Copyright (C) 2019 Ritik Jain" << endl << "Polynomial Adder / Multiplier ver 1.0.0" << endl << endl;

    char k;
    unsigned int j;
    double c;
    unsigned int p;
    unsigned int n;
    Polynomial p1,p2;
    cout << "Number of terms in the expression : " ;
    cin >> n;
    cout << "Coefficient\tPower" << endl;
    for(j=0; j<n; j++)
    {
        cin >> c;
        cin >> p;

        p1.set(p,c);
    }

    cout << endl;
    
    cout << "Number of terms in the expression : " ;
    cin >> n;
    cout << "Coefficient\tPower" << endl;
    for(j=0; j<n; j++)
    {
        cin >> c;
        cin >> p;

        p2.set(p,c);
    }
    
    cout << endl;

    double *_p1 = p1.get();
    unsigned int _n1 = p1.degree();

    cout << "Enter 1 to add or 2 for multiply" << endl;
    
    cin >> k;

    if(k=='1')
    p1 = p1+p2;
    else if(k=='2')
    p1 = p1*p2;
    
    cout << endl << "Output :" << endl << "Coefficient\tPower" << endl;

    for(j=p1.degree(); j >=0; j--)
    {
    if(p1.get(j))
    cout << p1.get(j) << "\t\t" << j << endl;
    if(!j)
    break;
    }
    
    cout << endl;

    cout << "Enter 1 to add or 2 for multiply" << endl;
    
    cin >> k;

    p1 = Polynomial(_n1,_p1);

    if(k=='1')
    p1 = p1+p2;
    else if(k=='2')
    p1 = p1*p2;

    cout << endl << "Output :" << endl << "Coefficient\tPower" << endl;
    for(j=p1.degree(); j >=0; j--)
    {
    if(p1.get(j))
    cout << p1.get(j) << "\t\t" << j << endl;
    if(!j)
    break;
    }
    cout << endl;

    delete [] _p1;
    
    return 0;
}