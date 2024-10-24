// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int, int>PI;
typedef pair<ll, ll > PL;
typedef vector<int>VI;
typedef vector<ll>VL;
#define FF first
#define SS second
#define sz size()
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e6 + 5;

struct node {
    int prefix_count;
    bool isEnd;
    struct node *child[26];
};
node *head;

void init()
{
    head = new node();
    head->isEnd =  false;
    head->prefix_count = 0;
}

void insert(string s1)
{
    node *current = head;
    current->prefix_count++;
    for (int i = 0; i < s1.size(); i++)
    {
        int letter = (int)s1[i] - 'a';
        if (current->child[letter] == NULL)
            current->child[letter] = new node();

        current = current->child[letter];
        current->prefix_count++;
    }
    current->isEnd = true;

}

bool search(string s1)
{
    node *current = head;
    for (int i = 0; i < s1.size(); i++)
    {
        int letter = (int)s1[i] - 'a';
        if (current->child[letter] == NULL)
            return false;
        current = current->child[letter];
    }
    return current->isEnd;
}

int words_with_prefix(string s1)
{
    node *current = head;
    for (int i = 0; i < s1.size(); i++)
    {
        int letter = (int)s1[i] - 'a';
        if (current->child[letter] == NULL)
            return 0;
        current = current->child[letter];

    }
    return current->prefix_count;
}

int main()
{
    ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
    init();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}