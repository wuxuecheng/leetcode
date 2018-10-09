#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target);
private:
    //找出 target value第一个位置 
    int foundFirstTarget(int low,int high,int A[],const int target);
 
    //找出 target value 最后的位置 
    int foundLastTarget(int low,int high,int A[],const int target); 
 
};
 
inline int Solution::foundFirstTarget(int low,int high,int A[],const int target)
{
    int mid;
    int pos = high;
 
    //仍然二分查找
    while(low <= high)
    {
         mid = (low + high)/2;
 
         if (A[mid] != target)
         {
            low = mid +1;
         }
         else
         {
            pos = mid;
            high = mid -1;
         }
     }
 
     return pos;
}
 
inline int Solution::foundLastTarget(int low,int high,int A[],const int target)
{
    int mid,pos = low;
 
    //仍然二分查找
    while(low <= high)
    {
         mid = (low + high)/2;
 
         if (A[mid] != target)
         {
            high = mid - 1;
         }
         else
         {
            pos = mid;
            low = mid + 1;
         }
     }
 
     return pos;
}
 
vector<int> Solution::searchRange(int A[], int n, int target)
{
 
    vector <int> posSet;
  
    int low = 0,high = n -1;
    int mid;
 
    while(low <= high)
    {
        mid = (low + high)/2;
 
        if (target == A[mid])
        {
           int firstPos = foundFirstTarget(low,mid,A,target);
           int lastPos = foundLastTarget(mid,high,A,target);
 
           posSet.push_back(firstPos);
           posSet.push_back(lastPos);
 
           break;
        }
 
        if (target > A[mid])
        {
            low = mid + 1;
        }
 
        if (target < A[mid])
        {
            high = mid - 1;
        }
    }
 
     if(posSet.size() == 0)
     {
        posSet.insert(posSet.begin(),2,-1);
     }
     return posSet;
}

int main()
{
    return 0;
}
