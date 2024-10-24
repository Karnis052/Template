int tr[N];
struct BIT {

    BIT(int n)
    {
        for (int i = 0; i < n + 5; i++)
            tr[i] = 0;
    }
    void update(int idx , int val)
    {
        while (idx < N)
        {
            tr[idx] += val;
            idx += (idx & -idx);
        }
    }
    ll query(int idx)
    {
        ll sum = 0;
        if (idx <= 0) return sum;
        while (idx > 0)
        {
            sum += tr[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};