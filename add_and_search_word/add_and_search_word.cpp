#include <iostream>
#include <string>

using namespace std;

namespace
{
    const int MAX_NODE_NUM = 26;
}

struct TrieNode
{
    TrieNode* m_nodes[MAX_NODE_NUM];
    bool m_isWord;

    TrieNode() : m_isWord(false)
    {
         for (auto& a : m_nodes)
         {
             a = nullptr;
         }
    } 
};

class WordDictionary{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        m_trie = new TrieNode();
    }

    ~WordDictionary()
    {
        //release(m_trie);
    }
    
    void addWord(string word)
    {
        auto currentNode = m_trie;
        for (auto p : word)
        {
            if (currentNode->m_nodes[p - 'a'] == nullptr)
            {
                auto node = new TrieNode();
                currentNode->m_nodes[p - 'a'] = node;
            }
            currentNode = currentNode->m_nodes[p - 'a'];
        }
        currentNode->m_isWord = true;        
    }
    
    bool search(string word)
    {
        auto currentNode = m_trie;

        return searchInternal(word, 0, currentNode);
    }
    
private:
    bool searchInternal(const string& word, size_t start, TrieNode* node)
    {
        if (start == word.length()) return node->m_isWord;

        if (word[start] == '.')
        {
            for (auto ii = 0; ii < MAX_NODE_NUM; ++ii)
            {
                if (node->m_nodes[ii] == nullptr) continue;
                if (searchInternal(word, start + 1, node->m_nodes[ii])) return true;
            }
            return false;
        }
        return node->m_nodes[word[start] - 'a'] == nullptr ? false : searchInternal(word, start + 1, node->m_nodes[word[start] - 'a']);
    }

    void release(TrieNode* node)
    {
        if (node == nullptr) return;

        for (size_t i = 0; i < MAX_NODE_NUM; ++i)
        {
            release(node->m_nodes[i]);
        }
        delete node;
    }
private:
    TrieNode* m_trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);

 * Trie trie = new Trie();

 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 */

int main()
{
    WordDictionary dict = WordDictionary();
    dict.addWord("apple");
    std::cout << dict.search("apple") << std::endl;   // returns true
    std::cout << dict.search("a..le") << std::endl;     // returns false
    std::cout << dict.search("a...") << std::endl;     // returns true
    return 0;
}
