//************-------N QUEENS PROBLEM WITH BACKTRACKING-------*************///
//Complexity :: T(n)= n*(T(n-1) + O(n)) ==> T(n)= n!

/* #include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > vec;
int n, total_count = 0, mat[1009][1009] = {0};

bool check (int r1, int c1, int r2, int c2) {	//checker function for 2 coordinates

	if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2)	//check for diagonal perfection
		return false;
	if (r1 == r2 || c1 == c2)	//check for rw column perfection
		return false;

	return true;
}

void printit() {		//function for printing the possible arrangment
	cout << endl;
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n; i++)
		mat[vec[i].first][vec[i].second] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
}

void solve(int col) {

	for (int i = 0; i < n; i++) {		//trying on different rws

		int ch = 1;

		for (int j = 0; j < col; j++) {	//checking with previosly placed queens
			if ( !check(vec[j].first, vec[j].second, i, col) ) {
				ch = 0;
				break;
			}
		}
		if	(ch) {		// if no problem with previously placed queens
			vec[col] = make_pair(i, col);
			if (col == n - 1) {
				total_count++;
				printit();
			}
			else
				solve( col + 1 );
		}
	}
}

int main() {

	cin >> n;

	vec.resize(n);
	cout << "The possible combinations are:\n";
	solve(0);
	cout << "\nTotal combinations are " << total_count << endl;

	return 0;
}*/


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
vector<vector<vector<int>>>ans;
int coun = 0, n;
bool isvalid(vector<vector<int>>&chess, int rw, int col)
{
	for (int i = 0; i  <= rw; i++)
		if (chess[i][col] == 1)
			return false;
	for (int i = 0; i <= col; i++)
		if (chess[rw][i] == 1)
			return false;
	for (int i = rw , j = col ; i >= 0 and j >= 0 ; i--, j--)
		if (chess[i][j] == 1) return false;
	for (int i = rw, j = col; i<n and j >= 0 ; i++, j--)
		if (chess[i][j] == 1) return false;
	return true;

}
void  Backtrack(int col, vector<vector<int>>&chess)
{
	if (col >= n)
	{
		ans.push_back(chess);
		coun++;
		return;
	}
	for (int rw = 0; rw < n; rw++)
	{
		if (isvalid(chess, rw, col))
		{
			chess[rw][col] = 1;
			Backtrack(col + 1, chess);
			chess[rw][col] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);   cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<int>>chess(n, vector<int>(n));
	Backtrack(0, chess);
	cout << coun << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int c = 0; c < n; c++)
				cout << ans[i][j][c] << " ";
			cout << endl;
		}
		cout << endl;
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}