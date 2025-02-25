int main()
{
	int a[16384];
	register int b = 0;
	register int c = 0;
	for(c = 0; c < 16384; c = c + 16)
		a[c] = 0;
	register long ctr = 0;
	while(ctr < 1000000)
	{
		for(c = 0; c < 16384; c = c + 64)
			b = a[b+c];
		ctr++;
	}
}
