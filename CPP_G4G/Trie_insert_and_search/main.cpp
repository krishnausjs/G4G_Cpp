// Source : https://www.geeksforgeeks.org/trie-insert-and-search/ 

//   Trie is an efficient information reTrieval data structure
//  Key length determins Trie depth
// However memory requirements of Trie is O(ALPAHET_SIZE*key_length*N) where N is the number of keys in Trie.
 
#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE  = 26;

//Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* getNode(void)
{
        struct TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = false;
        
        for(int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
        
        return pNode;                
}

//If not present , inserts key into Trie
//If the key is prefix of trie node just make it leaf node

void insert(struct TrieNode *root, string key) 
{
    struct TrieNode *pCrawl = root;
    
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        //If a node doesnt exist create one
        if( !pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    //Make lastnode
    pCrawl->isEndOfWord = true;
}

//Returns true if key is present in Trie else false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for(int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

//If not present, inserts key into trie
int main()
{
    string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root = getNode();
    
    //Construct Trie
    for(int i = 0; i < n; i++)
            insert(root, keys[i]);
            
    //search for different keys
    search(root, "the") ? cout << "Yes \n" : cout << "No\n";
    search(root,"there") ? cout << "Yes\n": cout << "No\n";
    return 0;
}