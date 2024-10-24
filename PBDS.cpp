// Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> pbds;
// PBDS is one kind of Indexed Set
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	pbds pb;
	pb.insert(2);
	pb.insert(7);
	pb.insert(3);
	pb.insert(9);
	//pb.erase(2);
	// find_by_order returns an iterator to the elements at a given position
	auto x = pb.find_by_order(2);
	cout << *x << endl;
	// order_of_key returns position of given element
	int pos = pb.order_of_key(7);
	cout << pos << endl;
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}