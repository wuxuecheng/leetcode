class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 3)
        {
            return 0;
        }

        bool flag[n];
        memset(flag, 1, sizeof(flag));
        int primesCount = n - 2;//apart 1

        for (int i = 2; i <= n/2; ++i)
        {
            if (flag[i])
            {
                int j = 2;
                int res = i * j;
                while (res < n)
                {
                    if (flag[res])
                    {
                        //update flag
                        flag[res] = false;
                        --primesCount;
                    }
                    ++j;
                    res = i * j;
                }
            }
        }

        return primesCount;
    }
};
