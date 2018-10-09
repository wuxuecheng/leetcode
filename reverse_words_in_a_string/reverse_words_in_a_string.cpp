#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) 
    {    
        unsigned int size = s.length();
        
        std::string word;
        
        std::stack<std::string> wordSet;
        
        bool isFirstBlank = false;
        
        for (unsigned int i = 0; i<size;++i)
        {
            char chr = s[i];
            
            if (chr != ' ')
            {
                word.push_back(chr);
                isFirstBlank = true;
            }
            else if (chr == ' ' && isFirstBlank)
            {
                wordSet.push(word);
                word = "";
                isFirstBlank = false;
            }
            
        }
        if (word != "")
        wordSet.push(word);
        
        s.clear();
        
        while(!wordSet.empty())
        {
            s.append(wordSet.top());
            wordSet.pop();
            if (!wordSet.empty())
                s.append(" ");
        }
    }
};

int main()
{
    return 0;
}
