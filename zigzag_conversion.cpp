#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows);
};

string Solution::convert(string s, int numRows)
{
    vector<string> subStrings;

    subStrings.resize(numRows);

    size_t verTexPos = numRows + (numRows - 2);

    for (size_t i = 0; i < s.length(); ++i)
    {
        size_t pos = i / verTexPos;

        size_t minPos = pos * verTexPos;
        size_t maxPos = (pos + 1) * verTexPos;

        size_t realSubStringPos = min((i - minPos), (maxPos - i));

        subStrings[realSubStringPos] += s[i];       
    }

    string res;

    for (size_t i = 0; i < numRows; ++i)
    {
        res += subStrings[i];
    }
    return res;
}

int main()
{
    Solution sol;

    string s = "PAYPALISHIRING";

    cout << sol.convert(s, 2) << endl;

    return 0;
}
