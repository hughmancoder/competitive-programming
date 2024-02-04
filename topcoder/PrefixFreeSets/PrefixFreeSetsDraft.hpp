#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {
        children.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode *pCrawl = root;
        int i;
        for (i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }
        // cout << " insert end " << word[i] << endl;
        pCrawl->is_end_of_word = true;
    }
};

class PrefixFreeSets {
public:
    int maxElements(const vector<string>& words) {
        Trie trie;
        int prefix_free_count = 0;
        for (size_t i = 0; i < words.size(); ++i) {
            trie.insert(words[i]);
        }

        for (size_t i = 0; i < words.size(); ++i) {
            string word = words[i];
            TrieNode *pCrawl = trie.root;
            bool isPrefixFree = true;
            for (int j = 0; j < word.length() - 1; ++j) {
                // traverse trie node
                int index = word[j] - 'a';

                if(pCrawl->is_end_of_word == true) {
                    // cout << word[j] << " marks the end of the word for " << word << endl;
                    isPrefixFree = false;
                }
                pCrawl = pCrawl->children[index];
            }
            if (isPrefixFree) {
                    prefix_free_count++;
            }
        }
        return prefix_free_count;
        
        // set<string> contains;
        // for (size_t i = 0; i < words.size(); ++i) {
        //     trie.insert(words[i]);
        // }

        // int prefix_free_count = 0;
        // for (size_t i = 0; i < words.size(); ++i) {
        //     if (contains.find(words[i]) != contains.end()) {
        //         continue;
        //     }
        //     contains.insert(words[i]);
        //     TrieNode *pCrawl = trie.root;
        //     bool isPrefixFree = true;
        //     for (size_t j = 0; j < words[i].length(); ++j) {
        //         int index = words[i][j] - 'a';
        //         pCrawl = pCrawl->children[index];

        //         if (pCrawl->is_prefix) {
        //             // cout << words[i] << " is not prefix free" << endl;
        //             isPrefixFree = false;
        //             break;
        //         }
        //     }

        //     if (isPrefixFree) {
        //         prefix_free_count++;
        //     }
        // }

        // return prefix_free_count != 0 ? prefix_free_count : 1;
    }
};
