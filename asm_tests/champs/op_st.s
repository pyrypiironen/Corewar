.name "st"
.comment "store"

# st {T_REG, T_IND | T_REG}
ft_label:
			st r1, 42
			st r1, r2
			st r1, r1
			st r2, :ft_label
			st r3, :ft_label2

ft_label2:
