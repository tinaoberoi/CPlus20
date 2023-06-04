#include<iostream>
#include<numeric>
#include<vector>
#include<cmath>

using namespace std;
int main(){
    vector<double> v;
    for(int i =1; i<=6; i++){
        v.push_back((i));
    }
    cout << "Using inner product\n";
    double sq_sum = inner_product(v.begin(), v.end(), v.begin(), 0);
    cout << "Sum of Squares of all elemets in array  : " << sq_sum << endl;
    cout << "Euclidean Distance: " <<sqrt(sq_sum)<<"\n";
}