#include<vector>
#include<iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

void printVec(vector<double> v) {
    for (int j = 0; j <(int)v.size(); j++)
        cout << v[j] << ", ";
    cout<<"\n";
}

double op_square(double x) { return x * x; }

int main()
{
    vector<double> original_vec;
    vector<double> new_vec;
    for(int i =1; i<=6; i++){
        original_vec.push_back((i));
    }
    cout<<"Printing original vector\n";
    printVec(original_vec);
    new_vec.resize(original_vec.size());
    transform(original_vec.begin(), original_vec.end(), new_vec.begin(), op_square);
    cout<<"Printing new vector\n";
    printVec(new_vec);
    int init = 0;
    cout << "using custom accumulate function \n";
    double sq_sum = accumulate (new_vec.begin(), new_vec.end(), init);
    cout << "Sum of sqaures :"<<sq_sum<<"\n";
    cout << "Pythogorean Distance : " <<sqrt(sq_sum)<<"\n";
    return 0;
}

