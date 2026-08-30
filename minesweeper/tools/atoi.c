static int	parse_number(char *str, int *i)
{
	int	total;

	total = 0;
	while ((str[*i] && (str[*i] >= '0') && (str[*i] <= '9')))
	{
		total *= 10;
		total += ((str[*i] - '0'));
		(*i)++;
	}
	return (total);
}

int	my_atoi(char *str)
{
	int	a;
	int	*i;
	int	total;

	if (!str)
		return (0);
	a = 0;
	i = &a;
	while (str[*i] == ' ')
		(*i)++;
	total = parse_number(str, i);
	return (total);
}
