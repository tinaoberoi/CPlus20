#include <iostream>
#include <memory>
using namespace std;

class A {
    private:
        int member1 { 0 };
        double member2 { 1.2 };
    public:
        A (int m1 = 0, double m2 = 1.2): member1{m1}, member2{m2} {}
        friend ostream& operator<<(ostream& out, A a1){
            out << a1.member1 << " and "<<a1.member2<<endl;
            return out;
        }
};

struct B {
    int i;
    double j;
    int bfunc (int *b){
        cout<<"Function exec from B \n";
        return ((*b)+5);
    }
    int bffunc (double (*a)(float &)){
        cout<<"Invoking function a from B bfunc :: \n";
        float param = 1.2;
        return int(a(param));
    }
};

char* c_func(char* a, char* b){
    if(a[0] == 'a'){
        return a;
    } else {
        return b;
    }
}

int func2(){
    return -1;
}

double func(float &x){
    x -= 1;
    return x / 1.2;
}

void func3(void (*f)()) {
    cout<<"Calling function that is passed\n";
    f();
}

void func4() {
    cout<<"Function passed executed\n";

}

int main(){
    int i = 5;
    /* int * */
    int *ip = &i;
    cout<<"Before changing int ref: "<<i<<endl;
    /* int & */
    int &ir = i;
    // Assign new value to x using ref
    ir = 20;
    cout<<"After changing int ref: "<<i<<endl;

    /* double */
    double d = 1.2;

    /* A * (A is any appropriate class). */
    A a(1, 2.6);
    A *pObj = &a;
    cout << "Membes of class A is: " << *pObj << endl;

    /* char const * */
    char const* constVal = "Char value cannot be changed";
    /* char const & */
    char const &constRef = *constVal;

    /* long[7] */
    long larr[7] = {};

    /* int ** */
    int **ipp = &ip;

    /* int *& */
    int *&ipr = ip;

    /* float & */
    float fval = 1.2;
    cout<<"Before changing float ref: "<<fval<<endl;
    float &fref = fval;
    //Chnage fval
    fref = 3.6;
    cout<<"After changing float ref: "<<fval<<endl;

     /* int (*)() */
    int (*pt2func2)() = NULL;
    pt2func2 = &func2;
    cout<<"Printing result of func2 \n" << (*pt2func2)();

    /* int (*&)() */
    int (*&ppt2func2)() = pt2func2;

    /* char *(*)(char *, char *) */
    char *(*cptrfunc)(char*, char*) = &c_func;
    char ca = 'a', cb = 'b';
    cout<<"Printing result of c func " << *cptrfunc(&ca, &cb)<<endl;

    B b;
    /* int A::* */
    int B::*bip = &B::i;
    cout<<"Incrementing this pointer from :: "<< (b.*bip)<<"to :: "<<(b.*bip)++<<endl;

    /* int (A::*)(int *) */
    int (B::*bfuncp)(int *) = &B::bfunc;
    cout<<"Calling b func pointer\n";
    (b.*bfuncp)(ip);

    /* int (A::**)(int *) */
    int (B::**bfuncpp)(int *) = &bfuncp;
    cout<<"Calling b func pointer pointer\n";
    (b.**bfuncpp)(ip);

    /* int (A::*&)(int *) */
    int (B::*&bfuncppref)(int *) = bfuncp;
    cout<<"Calling b func pointer pointer\n";
    (b.*bfuncppref)(ip);

    /* int (A::*)(double (*)(float &)) */
    int (B::*bffuncp)(double (*)(float &)) = &B::bffunc;
    cout<<"Calling b func pointer that calls another function\n";
    (b.*bffuncp)(func);

    /* void (*p[10]) (void (*)() ) */
    void (*p[10]) (void (*)() ) = {func3, func3, func3, func3, func3, func3, func3, func3, func3, func3};
    p[5](&func4);


    return 0;
}