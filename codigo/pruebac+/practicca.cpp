#include <iostream>
#include <vector>

using namespace std;

class clase{
    public:
    int val;
    vector<int> vec;
    clase(int v){
        this->val=v;
    }
    clase(){}
    ~clase(){}
    clase operator+(clase &a){
        clase nu(this->val + a.val);
        return nu;
    }
    clase operator-(clase&a){
        clase nue=(this->val - a.get_val());
        return nue;
    }

    friend ostream& operator << (ostream& os,const clase& este);
    int&  operator [] (int index){
        return vec[index];
    }
    void operator - (int val){
        vec.emplace_back(val);
    }
    int get_val(){return val;}
};
ostream& operator <<(ostream& os, const clase &a){
    os<<a.val<<endl;
    return os;
}

int main(void){
    clase a(2);
    clase b(3);
    clase c=a+b;
    cout<<c.get_val()<<endl;
    clase d= c-a;
    cout<<d;
    c-3;
    cout<<c[0]<<endl;

}
