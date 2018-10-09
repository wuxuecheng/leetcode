#include<map>

using namespace std;

class Solution {
public:
    bool isHappy(int n);
private:
    map<int, int> m_existSums;
};

bool Solution::isHappy(int n)
{
	if (n == 1)
	{
		return true;
	}
	int sum = 0;
	while (n >= 10)
	{
		int number = n % 10;
		sum += (number * number);
		n /= 10;
	}

	sum += (n * n);

	if (m_existSums.find(sum) != m_existSums.end())
	{
		return false;
	}
	m_existSums[sum]++;

	return isHappy(sum);
}

int main()
{
    return 0;
}
