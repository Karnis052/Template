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
bool f1 =0;
struct node
{
	int data;
	node *left, *right;
};
node *head;

void mergenode(node *head , node *curnode)
{
	if(head->data<curnode->data)
	{
		if(head->right==NULL)
			head->right = curnode;
		else
			mergenode(head->right, curnode);
	}
	else
	{
		if(head->left==NULL)
			head->left = curnode;
		else 
			mergenode(head->left, curnode);
	}
}

void construct(int n)
{
	node *curnode;
	head = NULL;
	int data;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		curnode = new node;
		curnode->data = data;
		curnode->left = NULL; curnode->right= NULL;
		if(head==NULL)
			head = curnode;
		else
		{
			mergenode(head, curnode);
		}
	}
}
void preoder(node *root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	preoder(root->left);
	preoder(root->right);
}

void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node *root)
{
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void search(node *root, int val)
{
	if(root==NULL) return;
	if(root->data== val)
	{
		 cout<<val<<" Found"<<endl;
		 f1=1;
		 return;
	}
	if(root->data>val)
		search(root->left, val);
	else search(root->right, val);
}

int main()
{
	ios::sync_with_stdio(false);   cin.tie(0);
	int n, val;
	cin>>n;
	construct(n);
	preoder(head); cout<<endl;
	inorder(head); cout<<endl;
	postorder(head); cout<<endl;
	cout<<"Enter value to search in BST ";
	cin>>val; cout<<val<<endl;
	f1 =0;
	search(head, val);
	if(!f1) cout<<"Enterer value not found in BST "<<endl;
	return 0;
}
