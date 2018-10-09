class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
        {
        	return 0;
        }

        int orderNumber[8];

        memset(orderNumber, 0, sizeof(orderNumber));

        unsigned int newM = m;
        unsigned int newN = n;

        int i = 0;
        for (; i < 8; ++i)
        {
        	newN = newN >> (i * 4);
        	newM = newM >> (i * 4);

        	if (newN - newM < 16)
        	{
                int resTmp = newM;
        		for (unsigned int j = newM + 1; j <= newN; ++j)
        		{
        			resTmp = resTmp & j;
        		}
        		orderNumber[i] = resTmp;

        		break;
        	}
        }

        int res = 0;

        for (int k = i; k >=0; --k)
        {
        	res += (orderNumber[k] << (k * 4));
        }

        return res;

    }
};

//other version
/*int rangeBitwiseAnd(int m, int n)
{
    while (n > m)
    {
        n = n & (n - 1);
    }

    return n;

}*/
