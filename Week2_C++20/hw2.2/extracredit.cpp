#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std; 

template<class T> void printVec(vector<T> v) {
    for (int j = 0; j <(int)v.size(); j++)
        cout << v[j] << ", ";
    cout<<"\n";
}

template <class T> double find_median (vector<T> vec){
    double median;
    int len = vec.size();
    int n = len/2;
    nth_element(vec.begin(), vec.begin()+n ,vec.end());
    printVec(vec);
    if(len%2 == 0){
        nth_element(vec.begin(), vec.begin()+n-1 ,vec.end());
        median = (vec[n-1] + vec[n])/2.0;
    } else {
        median = vec[n];
    }
    return median;
} 

int main(){
    cout<<"Median using elements using median template. "<<endl; 
    cout<<"Finding median for vector of doubles"<<endl;
    vector<double> double_vec {3.2, 2.6, 6.5, 4.1, 1.8, 7.01, 1.5, 8.2};

    double median = find_median(double_vec);
    cout<<"Median: "<<median<<"\n";

    cout<<"Finding median for vector of ints"<<endl;
    vector<double> int_vec {3, 2, 6, 4, 1, 7, 1, 5};
    median = find_median(int_vec);
    cout<<"Median: "<<median<<"\n";
    return 0;
}