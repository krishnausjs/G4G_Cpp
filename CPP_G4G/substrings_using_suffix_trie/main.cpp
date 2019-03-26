//Source : https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-trie/
#include <iostream>
#include <bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;

class SuffixTrieNode
{
public:
    SuffixTrieNode *children[MAX_CHAR];
    
    //Constructor
    SuffixTrieNode()
    {
        for(int i = 0; i < MAX_CHAR; i++)
            children[i] = NULL;
    }
    
    //A recursive function to insert a suffice of the s in subtree rooted with this node
    void insertSuffix(string suffix);
};

//A Trie of all suffixes
class SufffixTrie
{
    SuffixTrieNode *root;
    int _countNodesInTrie(SuffixTrieNode *);
public:
    SuffixTrieNode(std::string s)
    {
        root = new SuffixTrieNode();
        
        //Consider all suffixes of given string and insert
        //them into the suffix Trie using recursive function 
        //insertSuffix() in SuffixTrieNode class
        for(int i = 0; i < s.lenght(); i++)
            root->insertSuffix(s.substr(i));
    }
    //method to count total nodes in suffix trie
    int countNodesInTrie() 
    {
        return _countNodesInTrie(root);
    }
};

//A recursive function to insert a suffix of the s in 
//subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s)
{
    //If string has more characters
    if(s.length() > 0)
    {
        //Find the first character and convert it into 0-25 trange
        char cIndex = s.at(0) - 'a';
        
        //If there is no edge for this character add a new edge
        if(children[cIndex] == NULL)
            children[cIndex] = new SuffixTrieNode();
            
        //Recurisve for next suffix
        children[cIndex]->insertSuffix(s.substr(1));
    }    
}

//A recursive function to count nodes in trie
int SuffixTrie::_countNodesInTrie(SuffixTrieNode* node)
{
    //If all characters of pattern have been processed
    if(node == NULL)
        return 0;
        
    int count = 0;
    for(int i = 0; i < MAX_CHAR; i++)
    {
        //If children is not NULL then find count of all nodes in this substrie
        if(node->children[i] != NULL)
            count += _countNodesInTrie(node->children[i]);
    }
    //Return count of nodes of subtrie and plus 1 because of nodes own count
    return (1+count);
}

//Returns count of distinct substrings of str
int countDistinctSubstring(string str)
{
    //Construct a Trie of all suffixes
    SuffixTrie sTrie(str);
    
    //Return count of nodes in Triie of suffixese
    return sTrie.countNodesInTrie();
}
int main()
{
    string str = "ababa";
    cout << "Count of distinct substring is " << countDistinctSubstring(str);
    return 0;
}