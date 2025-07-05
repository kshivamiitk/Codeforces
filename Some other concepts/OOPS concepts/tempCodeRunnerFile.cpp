#include<iostream>
using namespace std;
class shape{
    public:
    virtual void print(){
        cout<<"This is a shape"<<endl;
    }
};
class rectangle:public shape{
    public:
    virtual void print(){
        cout<<"This is a rectangle"<<endl;
    }
};
int main(){
    shape s;
    rectangle r;
    s.print();
    r.print();
    return 0;

}