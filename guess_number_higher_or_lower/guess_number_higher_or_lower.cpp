// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        int middle = 1;
         while (1)
         {
             middle = (end - start) / 2 + start;
             if (guess(middle) == 1)
             {
                 start = middle + 1;
             }
             else if (guess(middle) == -1)
             {
                 end = middle - 1;
             }
             else
             {
                 return middle;
             }
          }
          return middle;
    }
};

int main()
{
    return 0;
}
