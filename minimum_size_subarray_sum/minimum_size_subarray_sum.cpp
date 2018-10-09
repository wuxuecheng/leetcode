#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        bool hasFound(false);
        int sum = 0;
        int firstPos(0);
        int minLen = INT_MAX;//#include <climits>

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];

            while(sum >= s)
            {
                minLen = min(minLen, i - firstPos + 1);
                sum -= nums[firstPos++];

                if (minLen == 1)
                {
                    hasFound = true;
                    break;
                }
            }

            if (hasFound)
            {
                break;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main()
{
    return 0;
}
