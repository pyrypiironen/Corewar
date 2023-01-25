

# include "../../../includes/vm.h"

void	op_jump(t_carriage *carriage, t_vm_data *d)
{
	unsigned char	first;
	unsigned char	second;
	short			arg;

	if (carriage->carry)
	{
		first = d->arena[(carriage->cursor + 1) % MEM_SIZE];
		second = d->arena[(carriage->cursor + 2) % MEM_SIZE];
		arg = ((first << 8) + second);
		carriage->cursor = (carriage->cursor + (arg % IDX_MOD)) % MEM_SIZE;
	}
	else
	{
		; // How does cursor move here??
	}
}

