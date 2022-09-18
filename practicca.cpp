#include <iostream>
#include <string>
using namespace std;

int main(){
    /*this is my first comment*/
    string cadena="john";
    string cadena1="watson";
    int num=15;
    float num1=928.2908;
    cout<< cadena<<endl<<num<<endl<<cadena1<<endl<<num1<<endl;
    int x=2,y=4,z=7;
    cout<<"la suma de x, y z es:"<<x+y+z<<endl;
   
    cadena.append(cadena1);
    auto len =cadena.length();
    cadena[0]='M';
    cout<<cadena<< " -> len:" << len<< endl;
    string fullName;
    cout << "Type your full name: ";
    getline (cin, fullName);
    cout << "Your name is: " << fullName<<endl;
    cout<<"maxxxxxxx:"<<max(x,y)<<endl<<"Minnnnnn:"<<min(x,y)<<endl;
    x>y?cout<<"x es mayor que y":cout<<"y es mayor que x";
    return 0;
}