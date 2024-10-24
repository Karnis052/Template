// don't forget to call mobius fuction from the main function
int  mob[N], isprime[N];
void Mobius()
{
	for (int i = 1; i < N; i++)
	{
		isprime[i] = i; mob[i] = 1;
	}

	for (int i = 2; i < N; i++)
	{
		if (isprime[i] == i)

		{
			mob[i] = - mob[i];
			for (int j = 2; i * j < N; j++)
			{
				isprime[i * j] = 0;
				if (j % i == 0)
					mob[i * j] = 0;
				else mob[i * j] = -mob[i * j];
			}
		}
	}
}