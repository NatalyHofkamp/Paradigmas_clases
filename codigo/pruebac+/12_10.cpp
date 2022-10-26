#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void){
    vector <string> names;
     names.reserve(3);
     names.emplace_back("Adam");
     names.emplace_back("Maria");
     auto iter= names.begin();
     names.insert(iter,"prueba");
     for(int i=0;i<names.size();i++){
        cout <<names.at(i)<<endl;
     }
     cout<< endl;
     names.push_back("hola");
     names.emplace_back("laura");
     names[2]="xxx";/* cambia el valor en la posición*/
     auto iter2 = 4+names.begin();
     names.insert(iter2,"xxxxxxx");/*inserta un valor en esa posición*/
     auto iter3= names.begin();
     names.erase(iter3);
     for(auto each = names.begin(); each != names.end();each++){
        /*mejor pq no dependemos de los indices*/
        cout <<*each<<endl;
     }
     return 0;
}