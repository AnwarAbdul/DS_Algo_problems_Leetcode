/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class Trie {

    Trie *children[26];
    bool isEndofWord;
    
    public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->isEndofWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *pCrawl = this;
        int i;
        for(i = 0; i < word.length(); i++){
            if(pCrawl->children[word[i] - 'a'] == NULL)
                pCrawl->children[word[i] - 'a'] = new Trie();
            pCrawl = pCrawl->children[word[i] - 'a'];
        }
        pCrawl->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *pCrawl = this;
        int i;
        for(i = 0; i < word.length(); i++){
            if(pCrawl->children[word[i]-'a'] == NULL)
                break;
            pCrawl = pCrawl->children[word[i] - 'a'];
        }
        if(pCrawl == NULL || i < word.length())
            return false;
        else if(pCrawl->isEndofWord)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *pCrawl = this;
        for(int i = 0; i < prefix.length(); i++){
            if(pCrawl->children[prefix[i]-'a'] == NULL)
                return false;
            pCrawl = pCrawl->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */