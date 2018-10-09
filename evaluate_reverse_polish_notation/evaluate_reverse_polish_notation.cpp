#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {

    const string& operatorSet("+-*/");
    
    stack<int> number;
    
    //2 1 + 3 *
    for (vector<string>::iterator iter = tokens.begin(); iter != tokens.end();++iter)
    {
        const char* item = (*iter).c_str();
        
        if (operatorSet.find(item) == string::npos)
        {
            int n = atoi(item);
            number.push(n);
        }
        else
        {
            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();
            
            int s = 0;
            
            switch(*item)
            {
                case '+':
                {
                    s = b + a;
                    break;
                }
                case '-':
                {
                    s = b - a;
                    break;
                }
                case '*':
                {
                    s = b * a;
                    break;
                }
                case '/':
                {
                    if (a == 0)
                    {
                        std::cerr<<"divided number is zero!"<<std::endl;
                        break;
                    }
                    s = b / a;
                    break;
                }
                default:
                    ;
            }
            number.push(s);
        }
    }
    
    return number.top();        
    }
};

int main()
{
    return 0;
}

