#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct maxlenftn
{
    maxlenftn() { maxlen = 0; }
    void operator()(string s)
    {
        maxlen = max(maxlen, s.size());
    }
    string::size_type maxlen;
};
int main()
{
    vector<string> names{"Smith", "Jones", "Johnson", "Grant"};
    maxlenftn maxf;
    // Reason why for_each(names.begin(),names.end(),maxf) did not work
    // Foreach is creating a coopy of maxf for itself, which destroys once the execution of foreach is over.
    // As a result if we pass this by reference we can modify the maxf value.
    // The fix is as follows:
    for_each(names.begin(), names.end(), [&](string name) {maxf(name);});
    cout << maxf.maxlen << endl;
    return 0;
}