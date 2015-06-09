//ans from discuss
class Trie {
public:
struct TrieNode {
    TrieNode* nodes[26];
    bool isEnd;
    TrieNode() { 
        for (int i = 0; i < 26; i++)
            nodes[i] = NULL;
        isEnd = false; 
    }
};

Trie() { root = new TrieNode(); }
TrieNode* getRoot() { return root; }

void addString(string s) {
    TrieNode* t = root;
    for (int i = 0; i<s.length(); i++) {
        if (t->nodes[s[i] - 'a'])
            t = t->nodes[s[i] - 'a'];
        else {
            TrieNode* n = new TrieNode();
            t->nodes[s[i] - 'a'] = n;
            t = n;
        }
    }
    t->isEnd = true;
}

TrieNode* moveNext(TrieNode* t, char c) {
    return t->nodes[c - 'a'];
}

private:
   TrieNode* root;
};



class Solution {
Trie t;

void findWords(vector<string>& result, vector<vector<char>>& board, Trie::TrieNode* root, int row, int col, string str) {
    root = t.moveNext(root, board[row][col]);

    if (root) {
        if (root->isEnd) {
            result.push_back(str + board[row][col]);
            root->isEnd = false;
        }

        char c = board[row][col];
        board[row][col] = NULL;

        if (col - 1 >= 0 && board[row][col - 1]) 
            findWords(result, board, root, row, col - 1, str + c);
        if (row - 1 >= 0 && board[row - 1][col]) 
            findWords(result, board, root, row - 1, col, str + c);
        if (col + 1 < board[row].size() && board[row][col + 1]) 
            findWords(result, board, root, row, col + 1, str + c);
        if (row + 1 < board.size() && board[row + 1][col]) 
            findWords(result, board, root, row + 1, col, str + c);

        board[row][col] = c;
    }
}

public:
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (int i = 0; i<words.size(); i++)
        t.addString(words[i]);

    vector<string> result;
    for (int i = 0; i<board.size(); i++)
        for (int j = 0; j < board[i].size(); j++) 
            findWords(result, board, t.getRoot(), i, j, "");
    return result;
  }
};

//my version, time limited exceed....
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty())
        {
            return m_words;
        }
        size_t rowCount = board.size();
        size_t colCount = board.begin()->size();

        for (size_t i = 0; i < rowCount; ++i)
        {
            for (size_t j = 0; j < colCount; ++j)
            {
                vector<pair<size_t, size_t> > visitedNode;
                string word;

                findWordInternal(i, j, board, words, word, visitedNode, 0);
            }
        }

        return m_words;

    }
    void findWordInternal(int row,
                                                int col,
                                                vector<vector<char>>& board,
                                                vector<string>& words,
                                                const string& word,
                                                const vector<pair<size_t, size_t>>& visitedNodes,
                                                size_t wordPos)
    {
        if (row < 0 or col < 0 or row >= (int)board.size() or col >= (int)board.begin()->size())
        {
            return;
        }
        auto visitedNodeNew = visitedNodes;

        size_t colNew = col;
        size_t rowNew = row;
        auto val = make_pair(rowNew, colNew);

        if (find(visitedNodes.begin(), visitedNodes.end(), val) != visitedNodes.end())
        {
            return;
        }
        else
        {
            visitedNodeNew.push_back(val);
        }

        string newWord = word + board[row][col];

        if (newWord.size() > words[wordPos].size() or words[wordPos][newWord.size() - 1] != board[row][col])
        {
            size_t ii = wordPos;
            for (; ii < words.size(); ++ii)
            {
                if (newWord.size() <= words[ii].size() and words[ii].substr(0, newWord.size()) == newWord)
                {
                    wordPos = ii;
                    if (newWord == words[ii])
                    {
                        m_words.push_back(newWord);
                    }
                    break;
                }
            }
            if (ii == words.size())
            {
                return;
            }
        }

        //dfs
        findWordInternal(row - 1, col, board, words, newWord, visitedNodeNew, wordPos);
        findWordInternal(row + 1, col, board, words, newWord, visitedNodeNew, wordPos);
        findWordInternal(row, col - 1, board, words, newWord, visitedNodeNew, wordPos);
        findWordInternal(row, col + 1, board, words, newWord, visitedNodeNew, wordPos);
    }
private:
    vector<string> m_words;
};
