.name "or"
.comment "ou  (or   r1, r2, r3   r1 | r2 -> r3"

# or {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			or r1, r2, r3
			or r3, r2, r1
			or r1, r1, r1
			or r15, r16, r17
			or %42, r2, r3
			or %:ft_label, r2, r3
			or %:ft_label2, r2, r3
			or r1, %42, r3
			or r1, %:ft_label, r3
			or r1, %:ft_label2, r3
			or 42, r2, r3
			or :ft_label, r2, r3
			or :ft_label2, r2, r3
			or r1, 42, r3
			or r1, :ft_label, r3
			or r1, :ft_label2, r3
			or %42, %42, r3
			or %:ft_label, %:ft_label, r3
			or %:ft_label2, %:ft_label2, r3
			or %:ft_label, %:ft_label2, r3
			or %:ft_label2, %:ft_label, r3
			or %42, 42, r3
			or %:ft_label, :ft_label, r3
			or %:ft_label2, :ft_label2, r3
			or %:ft_label, :ft_label2, r3
			or %:ft_label2, :ft_label, r3
			or 42, %42, r3
			or :ft_label, %:ft_label, r3
			or :ft_label2, %:ft_label2, r3
			or :ft_label, %:ft_label2, r3
			or :ft_label2, %:ft_label, r3
			or 42, 42, r3
			or :ft_label, :ft_label, r3
			or :ft_label2, :ft_label2, r3
			or :ft_label, :ft_label2, r3
			or :ft_label2, :ft_label, r3

ft_label2:
