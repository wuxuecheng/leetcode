//Given an array of integers, every element appears three times except for one. Find that single one.
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

//refs: https://github.com/haoel/leetcode/blob/master/src/singleNumber/singleNumber.II.cpp
//anyway,it's hard for me to think out this scheme.

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int one(0), two(0), three(0);

        for (int i = 0; i < n; ++i)
        {
        	two |= (one & A[i]);

        	one ^= A[i];

        	three = one & two;

        	one &= ~three;
        	two &= ~three;
        }

        return one;
    }
};

/* 
*   The following solution is popular solution on Internet, but it looks it's not easy to understand. 
* 
*   Actually, it just optimizes the above soultion. 
* 
*   Let's see how it improve the above. 
* 
*   We use three bitmasks,  
*    1) `ones`     as a bitmask which represents the i-th bit had appeared once. 
*    2) `twos`     as a bitmask which represents the i-th bit had appeared twice. 
*    3) `threes`   as a bit mask which represents the i-th bit had appeared three times. 
* 
*    When the i-th bit had appeared for the third time, clear the i-th bit of both `ones` and `twos` to 0. 
*    The final answer will be the value of `ones` 
* 

int singleNumber_2(int A[], int n)
{ 
	int ones = 0, twos = 0, threes = 0;

 	for (int i = 0; i < n; i++)
 	{ 
		 // `ones & A[i]` the result is the bitmask which the bits appeared twice 
		 twos |= ones & A[i];  
		 // XOR means remove the bit which appeared twice int `ones`  
		 ones ^= A[i]; 
		 // count the `three` 
		 threes = ones & twos; 
		 // clear the `ones` and `twos` if the i-th bit had appeared three times. 
		 ones &= ~threes; 
		 twos &= ~threes; 
 	} 
 	return ones; 
} 
*/ 