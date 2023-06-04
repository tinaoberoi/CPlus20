#include <functional>
#include <iostream>
// The following library needs to be included to use std::accumulate()
#include <numeric>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void printVec(vector<double> v) {
    for (int j = 0; j <(int)v.size(); j++)
        cout << v[j] << ", ";
    cout<<"\n";
}

int main() {
  cout<<"Finding Euclidean distance for vector:  "<<endl; 
  vector<double> vec {3.2, 2.6, 6.5, 4.1, 1.8, 7.01, 1.5, 8.2};
  printVec(vec);
  double sum = 0;
  sum = accumulate(vec.begin(), vec.end(), sum, [](double a, double b) -> double {return a + b * b;});
  cout<<"Euclidiean Distance: "<<sqrt(sum)<<endl;
} 