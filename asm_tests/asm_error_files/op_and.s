.name "and"
.comment "et (and  r1, r2, r3   r1&r2 -> r3"

# and {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			and :ft_label, :ft_label, :ft_label
