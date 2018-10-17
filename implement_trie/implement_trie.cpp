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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
    {
        m_trie = new TrieNode();
    }

    ~Trie()
    {
        release(m_trie);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
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
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto currentNode = m_trie;
        for (auto p : word)
        {
             if (currentNode->m_nodes[p - 'a'] == nullptr)
             {
                  return false;
             }
             currentNode = currentNode->m_nodes[p - 'a'];
        }
        return currentNode->m_isWord;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto currentNode = m_trie;
        for (auto p : prefix)
        {
             if (currentNode->m_nodes[p - 'a'] == nullptr)
             {
                  return false;
             }
             currentNode = currentNode->m_nodes[p - 'a'];
        }
        return true;        
    }
private:
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
    
    Trie trie = Trie();
    trie.insert("apple");
    std::cout << trie.search("apple") << std::endl;   // returns true
    std::cout << trie.search("app") << std::endl;     // returns false
    std::cout << trie.startsWith("app") << std::endl; // returns true
    trie.insert("app");
    std::cout << trie.search("app") << std::endl;     // returns true
    return 0;
}
