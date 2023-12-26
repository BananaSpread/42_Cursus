#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*v;

	i = 0;
	v = malloc((sizeof(char) * ft_strlen(s)) + 1);
	while(s[i])
	{
		v[i] = f(i, s[i]);
		i++;
	}
	v[i] = '\0';
	return (v);
}
