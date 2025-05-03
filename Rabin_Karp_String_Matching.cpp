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
const int INF = 2e9;
const int N = 1e5 + 5;

vector<int>RabinKarp(string const &s, string const &t) {
	const int p = 31; //for lower case english letters
	//for both lower-case and upper-case english letter take p = 53
	const int m = 1e9 + 9; // take any prime number like 1e9+7
	int patternSize = s.size(), textSize = t.size();
	vector<ll>pPow(max(patternSize, textSize));

	pPow[0] = 1;
	for (int i = 1; i < pPow.size(); i++)
		pPow[i] = pPow[i - 1] * p % m;

	vector<ll>textHash(textSize + 1);
	for (int i = 0; i < textSize; i++)
		textHash[i + 1] = (textHash[i] + (t[i] - 'a' + 1) * pPow[i] % m) % m;

	ll patternHash = 0;
	for (int i = 0; i < patternSize; i++) {
		patternHash = (patternHash + (s[i] - 'a' + 1) * pPow[i] % m) % m;
	}
	vector<int>occurance;
	for (int i = 0; i + patternSize - 1 < textSize; i++) {
		ll curHash = (textHash[i + patternSize] - textHash[i] + m) % m;
		if (curHash == (patternHash * pPow[i] % m))
			occurance.push_back(i);
	}
	return occurance;

}
