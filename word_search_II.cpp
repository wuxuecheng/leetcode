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
                vector<pair<size_t, size_t> > visitedNode;
                visitedNode.push_back(make_pair(i, j));

                string word;
                findWordInternal(i, j, board, words, word, visitedNode);
            }
        }

        return m_words;

    }
    void findWordInternal(int row, int col, vector<vector<char>>& board, vector<string>& words, const string& word, const vector<pair<size_t, size_t>>& visitedNodes)
    {
        if (row < 0 or col < 0 or row >= board.size() or col >= board.begin()->size())
        {
            return;
        }
        auto visitedNodeNew = visitedNodes;
        if (find(visitedNode.begin(), visitedNode.end(), make_pair(row, col) != visitedNode.end()))
        {
            return;
        }
        else
        {
            visitedNodeNew.push_back(make_pair(row, col));
        }

        string newWord = word + board[row][col];

        if (find(words.begin(), words.end(), newWord) != words.end())
        {
            m_words.push_back(newWord);
        }
        
        //dfs
        findWordInternal(row - 1, col, board, words, newWord, visitedNodeNew);
        findWordInternal(row + 1, col, board, words, newWord, visitedNodeNew);
        findWordInternal(row, col - 1, board, words, newWord, visitedNodeNew);
        findWordInternal(row, col + 1, board, words, newWord, visitedNodeNew);
    }
private:
    vector<string> m_words;
};
