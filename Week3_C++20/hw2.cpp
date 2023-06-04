#include <iostream>
using namespace std;

static int i = 1;

struct  A
{
    A() { cout<<"Hello "; };
};

struct  C : public A
{
    C(){
        cout<<"World!"<<endl;
    }
    C (int i) {
        cout<<"World!!!"<<endl;
    };
};

int main(){
    return 0;
}

static C c(1);
//static C c1;