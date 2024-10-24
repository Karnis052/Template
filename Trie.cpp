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
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
// --------------------Trie for numeric value ------------
// Don't forget to init Trie. For getmin insert INF at first, for getmx insert 0 at first
struct Trie
{
  const int B = 31;
  struct node
  {
    int sz;
    node *next[2];
  }*head;

  void init()
  {
    head = new node();
    head->sz = 0;
  }

  void insert(int val)
  {
    node *cur = head;
    cur->sz++;
    for (int i = B - 1; i >= 0; i--)
    {
      int b = ((val >> i) & 1);
      if (cur->next[b] == NULL) cur->next[b] = new node();
      cur = cur->next[b];
      cur->sz++;
    }
  }

  int query(int x, int k)// number of val s.t. x^val<k
  {
    node *cur = head;
    int sum = 0;
    for (int i = B - 1; i >= 0; i--)
    {
      if (cur == NULL) break;
      int b1 = (x >> i) & 1, b2 = (k >> i) & 1;
      if (b2 == 1)
      {
        if (cur->next[b1] != NULL) sum += cur->next[b1]->sz;
        cur = cur->next[!b1];
      }
      else cur = cur->next[b1];
    }
    return sum;
  }

  int  getmax(int x)
  {
    node *cur = head;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--)
    {
      if (cur == NULL) break;
      int b = (x >> i) & 1;
      if (cur->next[!b]) cur = cur->next[!b], ans <<= 1, ans++;
      else cur = cur->next[b], ans <<= 1;
    }
    return ans;
  }

  int getmin(int x)
  {
    node *cur = head;
    int ans = 0;
    for (int i = B - 1; i >= 0; i--)
    {
      if (cur == NULL) break;
      int b = (x >> i) & 1;
      if (cur->next[b]) cur = cur->next[b], ans <<= 1;
      else cur = cur->next[!b], ans <<= 1, ans++;
    }
    return ans;
  }

  void del(node *cur)
  {
    for (int i = 0; i < 2; i++) if (cur->next[i]) del(cur->next[i]);
    delete(cur);
  }
};

int main()
{
  ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
  int n, x = 0, ans = INF;
  cin >> n;
  Trie tr;
  tr.init();
  tr.insert(ans);
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    ans = min(ans, tr.getmin(x));
    tr.insert(x);

  }
  cout << ans << endl;


  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}


// -----------------Trie for string------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
  int prefix_count;
  bool isEnd;
  struct node *child[26];
}*head;

void init()
{
  head = new node();
  head->isEnd = false;
  head->prefix_count = 0;
}

void insert(string word)
{
  node *current = head;
  current->prefix_count++;

  for (int i = 0 ; i < word.length(); ++i)
  {
    int letter = (int)word[i] - (int)'a'; //extrct first character of word
    if (current->child[letter] == NULL)
      current->child[letter] = new node();

    current->child[letter]->prefix_count++;
    current = current->child[letter];
  }
  current->isEnd = true;
}

bool search(string word)
{
  node *current = head;
  for (int i = 0 ; i < word.length(); ++i)
  {
    int letter = (int)word[i] - (int)'a';
    if (current->child[letter] == NULL)
      return false;   //not found
    current = current->child[letter];
  }
  return current->isEnd;
}

int words_with_prefix(string prefix)
{
  node *current = head;
  for (int i = 0; i < prefix.length() ; ++i)
  {
    int letter = (int)prefix[i] - (int)'a';
    if (current->child[letter] == NULL)
      return 0;
    else
      current = current->child[letter];
  }
  return current->prefix_count;
}


int main()
{
  init();
  return 0;
}