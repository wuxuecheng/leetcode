class Solution {
public:
    int calculate(string s)
    {
        int tmpResult = 0;
        string content;
        stack<int> unCalNumbers;
        stack<char> unCalOperators;

        for (size_t i = 0; i < s.size(); ++i)
        {
            switch (s[i]) {
                case ' ':
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                {
                    if (unCalOperators.empty())
                    {
                        unCalNumbers.push(atoi(content.c_str()));
                        unCalOperators.push(s[i]);
                        content = "";
                        break;
                    }
                    if (unCalOperators.top() == '*' || unCalOperators.top() == '/')
                    {
                        tmpResult = unCalOperators.top() == '/' ? unCalNumbers.top() / atoi(content.c_str()) : unCalNumbers.top() * atoi(content.c_str());
                        unCalNumbers.pop();
                        unCalOperators.pop();
                        if (!unCalOperators.empty() and (s[i] == '+' or s[i] == '-'))
                        {
                            tmpResult = unCalOperators.top() == '+' ? unCalNumbers.top() + tmpResult : unCalNumbers.top() - tmpResult;
                            unCalNumbers.pop();
                            unCalOperators.pop();
                        }

                        unCalOperators.push(s[i]);
                        unCalNumbers.push(tmpResult);
                        content = "";
                        break;
                    }
                    else
                    {
                        if (s[i] == '+' or s[i] == '-')
                        {
                            tmpResult = unCalOperators.top() == '+' ? unCalNumbers.top() + atoi(content.c_str()) : unCalNumbers.top() - atoi(content.c_str());
                            unCalOperators.pop();
                            unCalNumbers.pop();
                            unCalOperators.push(s[i]);
                            unCalNumbers.push(tmpResult);
                            content = "";
                            break;
                        }
                    }
                    unCalOperators.push(s[i]);
                    unCalNumbers.push(atoi(content.c_str()));
                    content = "";
                    break;
                }
                default:
                {
                    content += s[i];
                    break;
                }
            }

        }

        //process last number
        if (!unCalOperators.empty() && (unCalOperators.top() == '*' || unCalOperators.top() == '/'))
        {
            tmpResult = unCalOperators.top() == '/' ? unCalNumbers.top() / atoi(content.c_str()) : unCalNumbers.top() * atoi(content.c_str());
            unCalOperators.pop();
            unCalNumbers.pop();
            unCalNumbers.push(tmpResult);
        }
        else
        {
            unCalNumbers.push(atoi(content.c_str()));
        }

        tmpResult = unCalNumbers.top();
        unCalNumbers.pop();

        while (!unCalNumbers.empty() || !unCalOperators.empty())
        {
            tmpResult = unCalOperators.top() == '+' ? tmpResult + unCalNumbers.top() : unCalNumbers.top() - tmpResult;
            unCalNumbers.pop();
            unCalOperators.pop();
        }
        return tmpResult;
    }
};
