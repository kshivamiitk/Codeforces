#include<iostream>
using namespace std;
class shape{
    //please use virtual keyword
    public:
    void virtual print(){
        cout<<"This is shape"<<endl;
    
    }
   
    
};
class rectangle:public shape{
    public:
    void virtual print(){
        cout<<"This is rectangle"<<endl;
    }
    
};
int main(){
    shape s;
    rectangle r;
    s.print();
    r.print();
    return 0;

}