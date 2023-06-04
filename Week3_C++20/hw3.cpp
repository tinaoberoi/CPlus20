#include <iostream>
#include <vector>
#include <algorithm>
#include<iterator>
using namespace std;


class Nth_Power{
    private:
        int cube;
    public:
        Nth_Power(int n) : cube(n) {}
        int operator() (int arr_num) const {
            return arr_num*arr_num*arr_num;
        }

};

int main(){
    vector<int> v = { 1, 2, 3, 4, 5 };
    Nth_Power cube{3};
    cout << cube(7) << endl; // prints 343
    // print first five cubes
    transform(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), cube);
    cout<<endl;
    return 0;
}