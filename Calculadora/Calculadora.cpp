/*
Author:Mario Yahir García Hernández
email:marioygh15@gmail.com
september 26, 2022
*/

#include <iostream>
#include <cmath>

using namespace std;

float n1, n2;
char op;

int main()
{
    cout<<"Este programa hace operaciones basicas entre dos numeros"<<endl;

    cout<<"Primer numero: ";
    cin >> n1;

    cout<<"Operacion: ";
    cin >> op;

    if (op=='+'){
        cout<<"Segundo numero: ";
        cin >> n2;
        cout<<"\nResultado: ";
        cout<< n1 << "+" << n2 << "=" << n1+n2 <<endl;
    }
    else{
        if (op=='-'){
            cout<<"Segundo numero: ";
            cin >> n2;
            cout<<"\nResultado: ";
            cout<< n1 << "-" << n2 << "=" << n1+n2 <<endl;

        }
        else {
            if (op=='*') {
                cout << "Segundo numero: ";
                cin >> n2;
                cout << "\nResultado: "<< endl;
                cout << n1 << " a " << n2 << " = " << n1 * n2 << endl;
            }
            else {
                if (op == '/') {
                    cout << "Segundo numero: ";
                    cin >> n2;
                    if(n2==0){
                    cout << "la división no es posible" << endl;
                  }
                else {
                    cout << "\nResultado: "<< endl;
                    cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
                }
                }
                else {
                    if (op == '%') {
                        cout << "Segundo numero: ";
                        cin >> n2;
                        cout << "\nResultado: " << endl;
                        cout << n1 << " % " << n2 << " = " << fmod(n1, n2) << endl;
                    }
                    else {
                        cout << "Error" << endl;

                    }

                }

            }

        }
    }
    return 0;
}
