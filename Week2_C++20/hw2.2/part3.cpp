#include<vector>
#include<iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <chrono>

using namespace std;

void printVec(vector<double> v) {
    for (int j = 0; j <(int)v.size(); j++)
        cout << v[j] << ", ";
    cout<<"\n";
}

int main()
{
    cout<<"Find median using nth element func for a vector of doubles: "<<endl; 
    vector<double> vec {3.2, 2.6, 6.5, 4.1, 1.8, 7.01, 1.5, 8.2};
    int len = vec.size();
    int n = len/2;
    printVec(vec);
    auto start = std::chrono::high_resolution_clock::now();
    nth_element(vec.begin(), vec.begin()+n ,vec.end());
    printVec(vec);
    double median;
    if(len%2 == 0){
        nth_element(vec.begin(), vec.begin()+n-1 ,vec.end());
        median = (vec[n-1] + vec[n])/2;
    } else{
        median = vec[n];
    }
    cout<<"Median: "<<median<<"\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout<<"Time Taken: "<< duration.count()<<"\n";

    /*
    Do you think this is even more efficient? Why?
    n_th element uses quickselect algorithm which has expected time of O(N). Thus it will even faster.
    */
    return 0;
}
