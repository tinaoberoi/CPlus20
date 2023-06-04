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
    cout<<"Find median using sort for a vector of doubles: "<<endl; 
    vector<double> vec {3.2, 2.6, 6.5, 4.1, 1.8, 7.01, 1.5, 8.2};
    printVec(vec);

    auto start = std::chrono::high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    printVec(vec);
    int len = vec.size();
    int n = len/2;
    double median;
    if (n%2 == 0){
        median = (vec[n] + vec[n- 1])/2;
    } else {
        median = vec[n];
    }
    cout<<"Median: "<<median<<"\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout<<"Time Taken: "<< duration.count()<<"\n";

    return 0;
}
