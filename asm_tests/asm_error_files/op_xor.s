.name "xor"
.comment "ou (xor  r1, r2, r3   r1^r2 -> r3"

# xor {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			xor %42, %42, 3
			xor %:ft_label, %:ft_label, %3
			xor %:ft_label2, %:ft_label2, :ft_label
			xor %:ft_label, %:ft_label2, %:ft_label2
ft_label2:
