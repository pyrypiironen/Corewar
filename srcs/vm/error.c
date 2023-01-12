// Add header

// Includes

void	print_error(char *str, int usage)
{
	ft_printf("{red}ERROR: ");
	ft_printf("{red}%s\n", str);
	if (usage == 1)
		ft_printf("Usage: ./corewar diid diidididid\n") // write correct message
	exit(1);
}