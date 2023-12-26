char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	vx;
	char	**v;

	if (!*s)
		return (NULL);
	i = 0;
	vx = 0;
	vy = 0;
	v = malloc(sizeof(char) * 1024);
	while (s[i])
	{
		if (!v[vx])
			v[vx] = malloc(sizeof(char) * 128);
		if (s[i] == c)
		{
			v[vx][vy] = '\0';
			vx++;
			vy = 0;
		}
		else
		{
			if (!v[vx])
				v[vx] = malloc(sizeof(char) * 128);
			v[vx][vy] = s[i];
			vy++;
		}
		i++;
	}
	v[vx][vy] = '\0';
	free(v);
	return (v);
}
