#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num)
    {
        int size = num.size() - 1;

        int left = 0;
        int right = size;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if (num[mid] > num[size])
            {
                //left
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return num[left];
    }
};

//other version
class Solution1 {
public:
    int findMin(vector<int> &num)
    {
        sort(num.begin(), num.end());
        return num[0];
    }
};

int main()
{
    return 0;
}
