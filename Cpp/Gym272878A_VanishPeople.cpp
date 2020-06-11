#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 36;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;

    bool isEndOfWord;
    bool isIlegal;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;
    pNode->isIlegal = false;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        if(pCrawl->isIlegal)
            break;
        if(!pCrawl->children[key[i]])
            pCrawl->children[key[i]] = getNode();

        pCrawl = pCrawl->children[key[i]];
    }
    if(!pCrawl->isIlegal)
        pCrawl->isEndOfWord = true;
}

void insertIlegal(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        if(pCrawl->isIlegal)
            break;
        if(!pCrawl->children[key[i]])
            pCrawl->children[key[i]] = getNode();

        pCrawl = pCrawl->children[key[i]];
    }
    pCrawl->children.clear();
    pCrawl->isIlegal = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        if (!pCrawl->children[key[i]])
            return false;

        pCrawl = pCrawl->children[key[i]];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

string S [1000005];
string P [10005];

// Driver
int main()
{


    int n,q;

    cin>>n>>q;

    for (int i = 0; i < n; ++i) {
        cin>>S[i];
    }

    for (int i = 0; i < q; ++i) {
        cin>>P[i];
    }

    struct TrieNode *root = getNode();

    for (int i = 0; i < q; i++)
        insertIlegal(root, P[i]);

    for (int i = 0; i < n; i++)
        insert(root, S[i]);




    sort(S, S+n);


    int cont = 0;
    string result = "";

    for (int i = 0; i < n; i++) {
        if(search(root, S[i])){
            result+=S[i];
            result+="\n";
            cont++;
        }
    }

    cout<<cont<<"\n";
    cout<<result;
    return 0;
}

/*
10 2
ivan1
ivan3
erick
rafa
crystal
franco
francisco
omar
uriel
rob
r
fr

 */