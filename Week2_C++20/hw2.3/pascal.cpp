#include<iostream>
#include<vector>

using namespace std;

class PascalsTriangle
{
    protected:
        int row_count;
        vector<vector<int>> rows;
    public:
        PascalsTriangle(int n){
            this->row_count = n;
        }
        void createTriangle(){
            auto count = this->row_count;
            vector<vector<int>> arr(count);
            arr[0] = {1};
            arr[1] = {1, 1};
            for(int i = 2; i<count; i++){
                vector<int> temp;
                temp.push_back(1);
                for(int j = 1; j<arr[i-1].size(); j++){
                     temp.push_back(arr[i-1][j-1] + arr[i-1][j]);
                }
                temp.push_back(1);
                arr[i] = temp;
            }
            this->rows = arr;
        }

        void printTriangle(){
             auto arr = this->rows;
             auto row_count = this->row_count;
             for(int i = 0; i<row_count; i++){
                int count = row_count+1-i;
                while(count > 0){
                    cout<<"  ";
                    count--;
                }
                for(int j = 0; j< arr[i].size(); j++){
                    if(arr[i][j] < 10)
                        cout<<" "<<arr[i][j]<<"  ";
                    else
                        cout<<arr[i][j]<<"  ";
                    count = i;
                }
                cout<<"\n";
             }
        }
};

int main(){
    int n;
    cout<<"Enter the number of rows for pascals triangle: ";
    cin>>n;
    PascalsTriangle obj(n);
    obj.createTriangle();
    obj.printTriangle();

    return 0;
}