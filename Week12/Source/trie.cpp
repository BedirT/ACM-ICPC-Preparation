#include <iostream>
#include <string>

using namespace std;

struct Node
{
    bool isEnd;
    Node* child[26];
    
    Node()
    {
        isEnd = false;
        memset(child, 0, sizeof(child));
    }
};

Node* root = new Node();

void add(const string& str)
{
    auto node = root;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(node->child[str[i] - 'a'] != nullptr)
        {
            node = node->child[str[i] - 'a'];
        }
        else
        {
            node->child[str[i] - 'a'] = new Node();
            
            if(i == str.length() - 1)
            {
                node->child[str[i] - 'a']->isEnd = true;
                return;
            }
            
            node = node->child[str[i] - 'a'];
        }
    }
}

bool find(const string& str)
{
    auto node = root;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(node->child[str[i] - 'a'] != nullptr)
        {
            node = node->child[str[i] - 'a'];
        }
        else
        {
            return false;
        }
    }
    
    return node->isEnd;
}

int main()
{
	// Number of queries
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
		// 1: add a new word
		// 2: search for an existing word
        int option;
        string word;
        cin >> option >> word;
        
        if(option == 1)
        {
            add(word);
        }
        else if(option == 2)
        {
            cout << (find(word) ? "Found" : "Not found") << endl;
        }
		else
		{
			continue;
		}
    }

    return 0;
}