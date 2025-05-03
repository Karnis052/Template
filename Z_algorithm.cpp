// z[i] is the length of the longest string that is a prefix of s and a prefix of the suffix of s starting at i

vector<int> z_array(string s)
{
    int n = s.size();
    vector<int>z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            //abcdefabcdeg
            // i-l is the index in the range s[0.... r-l), using z[i-l] we can resue precomputed value of range s[0.... r-l)
            // ex: aaaabaa, r-i+1, because we know nothing about the characters to the right of r
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}