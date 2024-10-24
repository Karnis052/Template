vector<int>prime;
int vis[N];

void liner_sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])prime.push_back(i);
        for (int j = 0; j < prime.size() and i * prime[j] < N; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}