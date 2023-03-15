.name "ldi"
.comment "load index"

# ldi {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
ft_label:
			ldi %42, 42, r3
			ldi %:ft_label, :ft_label, r3
			ldi %:ft_label2, :ft_label2, r3
			ldi %:ft_label, :ft_label2, r3
			ldi %:ft_label2, :ft_label, r3
			ldi 42, 42, r3
ft_label2:
