#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cubeSum' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY operations
 */

#define ll long long int

// 3D Binary Indexed Tree to store Partial Sums
ll BIT[102][102][102];
int N;

// Function to handle updates
void updateQuery(int x, int y, int z, ll val)
{
    int i, j, k;
    // Update all the cells that store the partial sum of
    // cell (x, y, z)
    for (i = x; i <= N; i += i & -i) {
        for (j = y; j <= N; j += j & -j) {
            for (k = z; k <= N; k += k & -k) {
                BIT[i][j][k] += val;
            }
        }
    }
}

// Function to get the prefix sum from (0, 0, 0) to
// (x, y, z)
ll sumQuery(int x, int y, int z)
{
    ll sum = 0;
    int i, j, k;
    // Calculate prefix sum by summing up all the cells
    // storing the partial sums
    for (i = x; i > 0; i -= i & -i) {
        for (j = y; j > 0; j -= j & -j) {
            for (k = z; k > 0; k -= k & -k) {
                sum += BIT[i][j][k];
            }
        }
    }
    return sum;
}



vector<int> cubeSum(int n, vector<string> operations) {
    int m = operations.size();
    vector<int>ans;
    for (int i = 0; i < m; i++)
    {
        string op = "";
        // 1. UPDATE x y z W
        // 2. QUERY  x1 y1 z1 x2 y2 z2
        int j = 0;
        while (j < operations[i].size())
        {
            if (operations[i][j] == ' ')
                break;
            op += operations[i][j];
            j++;
        }
        cout << op << endl;
        if (op == "UPDATE")
        {
            int x, y, z, W, num = 0;
            while (j < operations[i].size())
            {
                if (operations[i][j] == ' ')
                    break;
                int cur = (operations[i][j] - '0');
                num = num * 10 + cur;
                j++;
            }
            x = num;
            cout << x << endl;

        }

    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int matSize = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> ops(m);

        for (int i = 0; i < m; i++) {
            string ops_item;
            getline(cin, ops_item);

            ops[i] = ops_item;
        }

        vector<int> res = cubeSum(matSize, ops);

        for (size_t i = 0; i < res.size(); i++) {
            fout << res[i];

            if (i != res.size() - 1) {
                fout << "\n";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

\hfill\href{https://github.com/blp-workshop/blp_task2?tab=readme-ov-file#leaderboard}{\textcolor{red}{Team : CUET\_NLP\_Noob}}}