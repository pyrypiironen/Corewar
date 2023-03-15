.name "or"
.comment "ou  (or   r1, r2, r3   r1 | r2 -> r3"

# or {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			or %:ft_label, %:ft_label, :ft_label
			or %:ft_label2, %:ft_label2, %ft_label
			or %42, 42, 42
			or %:ft_label, :ft_label, %42
			or :ft_label2, :ft_label, 42

ft_label2:
