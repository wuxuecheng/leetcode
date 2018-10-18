#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) return 0;

        size_t step = 1, pos = 1;

        while (pos < nums.size())
        {
            if (nums[pos] == nums[pos - 1])
            {
                ++pos;
            }
            else
            {
                nums[step++] = nums[pos++];
            }
        }
        return step;
    }
};

int main()
{
     vector<int> v{0, 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9};

     Solution s;

     s.removeDuplicates(v);

     for (auto i = 0; i < v.size(); ++i)
     {
            cout << v[i] << endl;
     }
     return 0;
}
