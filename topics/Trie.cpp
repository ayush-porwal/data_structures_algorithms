#include <bits/stdc++.h>

using namespace std;

const int ALPHABETS_SIZE = 26;

class Node
{
public:
    Node *links[ALPHABETS_SIZE];
    bool isEnd;

    Node()
    {
        for (int i = 0; i < ALPHABETS_SIZE; i++)
        {
            links[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *current = root;

        for (auto w : word)
        {
            if (current->links[w - 'a'] == nullptr)
            {
                current->links[w - 'a'] = new Node();
            }
            current = current->links[w - 'a'];
        }
        current->isEnd = true;
    }

    bool search(string word)
    {
        Node *current = root;

        for (auto w : word)
        {
            if (current->links[w - 'a'] == nullptr)
            {
                return false;
            }
            current = current->links[w - 'a'];
        }
        return current->isEnd;
    }

    bool startsWith(string prefix)
    {
        Node *current = root;

        for (auto w : prefix)
        {
            if (current->links[w - 'a'] == nullptr)
            {
                return false;
            }
            current = current->links[w - 'a'];
        }
        return true;
    }
};

int main()
{
    return 0;
}