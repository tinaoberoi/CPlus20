#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>

using namespace std;

template<typename T>
struct Counter {
    int mutable count = 0;
    T callback;
    Counter(T func )
    : callback(func), count(0)
    { }

    template<typename... args>
    auto operator()(args... Args) const
    {
        count = count + 1;
        return callback(Args...);
    }
};


int f(double d)
{
     return static_cast<int>(2*d); 
}

Counter cf(f);

int main()
{
    cf(2.3); 
    cf(5.4);
    cf(6);
    cf(6.889);
    cout << cf.count << endl;
}
