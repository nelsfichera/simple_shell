ssize_t _strcspn(const char *s, const char *reject)
{
	unsigned int x = 0;
	unsigned int n = 0;
	ssize_t count = 0;

	while (s[x] != '\0')
	{
		while (reject[n] != '\0')
		{
			if (s[x] == reject[n])
				return (count);
			n++;
		}
		n = 0;
		count++;
		x++;
	}
	return (count);
}
