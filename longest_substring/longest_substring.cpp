#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s);
    void countSubString(size_t start, size_t end, size_t originStart, size_t currentCount, size_t& totalCount, size_t* status, const string& s);
};

int Solution::lengthOfLongestSubstring(string s)
{
    size_t status[128];
    memset(status, 0, sizeof(status));

    size_t totalCount = 0;

    size_t currentCount = 0;

    countSubString(0, s.length(), 0, currentCount, totalCount, status, s);

    return totalCount;
}

void Solution::countSubString(size_t start, size_t end, size_t originStart, size_t currentCount, size_t& totalCount, size_t* status, const string& s)
{
     for (size_t i = start; i < end; ++i)
     {
         if (status[s[i] - 0] == 0)
         {
            ++currentCount;
            status[s[i] - 0] = i + 1;
         }
         else
         {
            totalCount = max(currentCount, totalCount);

            size_t pos = status[s[i] - 0] - 1;
            //erase
            for (size_t j = originStart; j <= pos; ++j)
            {
                status[s[j] - 0] = 0;
            }

            currentCount = currentCount - (pos - originStart + 1);

            countSubString(i, end, pos + 1, currentCount, totalCount, status, s);
            break;
        }
    }
  
    totalCount = max(currentCount, totalCount);
}
    
int main()
{
    //string ss = "abcabcdabc";
    string ss = "bpfbhmipx";

    Solution s;

    cout << s.lengthOfLongestSubstring(ss) << endl;
    return 0;
}
