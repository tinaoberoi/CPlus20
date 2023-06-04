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
    cout<<"Find median using partial sort for a vector of doubles: "<<endl; 
    vector<double> vec {3.2, 2.6, 6.5, 4.1, 1.8, 7.01, 1.5, 8.2};
    int len = vec.size();
    int n = len/2;
    printVec(vec);

    auto start = std::chrono::high_resolution_clock::now();
    partial_sort(vec.begin(), vec.begin() + n + 1, vec.end());
    printVec(vec);
    double median;
    if (len%2 == 0){
        median = (vec[n] + vec[n - 1])/2;
    } else {
        median = vec[n];
    }
    cout<<"Median: "<<median<<"\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout<<"Time Taken: "<< duration.count()<<"\n";
    /*
    Is this more efficient? Why do you think that? (You can give an intuitive or practical answer without precise mathematical analysis).

    The partial sort complexity is O(N*logK), where K in this case is N/2. The performance improvement wont be vissible much for small
    N but for large N, partial sort will perform better than sort.
    */
    return 0;
}
