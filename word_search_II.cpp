#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        size_t rawCount = board.size();
        size_t colCount = board.begin()->size();

        for (size_t i = 0; i < rawCount; ++i)
        {
            for (size_t j = 0; j < colCount; ++j)
            {
                m_visitedNode.clear();
                m_word.clear();

                findWordInternal(i, j, board, words);
            }
        }

    }
    void findWordInternal(size_t row, size_t col, vector<vector<char>>& board, vector<string>& words)
    {
        if (row < 0 or col < 0 or row >= board.size() or col >= board.begin()->size())
        {
            return;
        }
        if (find(m_visitedNode.begin(), m_visitedNode.end(), make_pair(row, col) != m_visitedNode.end()))
        {
            return;
        }
        else
        {
            m_visitedNode.push_back(make_pair(row, col));
        }
        m_word += board[row][col];

        if (find(words.begin(), words.end(), m_word) != words.end())
        {
            m_words.push_back(m_word);
        }
    }
private:
    vector<pair<size_t, size_t> > m_visitedNode;
    string m_word;
    vector<string> m_words;
};

