int main()
{
	int a[] = {0};
	register int b = 0;
	register long ctr = 0;
	while(ctr < 10000000)
	{
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		b = a[b];
		ctr++;
	}
}
