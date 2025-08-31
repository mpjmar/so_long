
int	check_size(char **matrix)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = get_width(matrix);
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		if (j != width)
			return (1);
		i++;
	}
	return (0);
}

