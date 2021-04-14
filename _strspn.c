unsigned int _strspn(char *s, const char *find)
{
	unsigned int x = 0, n = 0;
	int count = 0;

	while (s[x] != 0)
	{
		while (find[n] != '\0')
		{
			if (s[x] == find[n])
			{
				count++;
				break;
			}
			n++;
		}
		if (find[n] == '\0')
			break;
		n = 0;
		x++;
	}
	return (count);
}
