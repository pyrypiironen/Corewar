.name "xor"
.comment "ou (xor  r1, r2, r3   r1^r2 -> r3"

# xor {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			xor r1, r2, r3
			xor r3, r2, r1
			xor r1, r1, r1
			xor r15, r16, r17
			xor %42, r2, r3
			xor %:ft_label, r2, r3
			xor %:ft_label2, r2, r3
			xor r1, %42, r3
			xor r1, %:ft_label, r3
			xor r1, %:ft_label2, r3
			xor 42, r2, r3
			xor :ft_label, r2, r3
			xor :ft_label2, r2, r3
			xor r1, 42, r3
			xor r1, :ft_label, r3
			xor r1, :ft_label2, r3
			xor %42, %42, r3
			xor %:ft_label, %:ft_label, r3
			xor %:ft_label2, %:ft_label2, r3
			xor %:ft_label, %:ft_label2, r3
			xor %:ft_label2, %:ft_label, r3
			xor %42, 42, r3
			xor %:ft_label, :ft_label, r3
			xor %:ft_label2, :ft_label2, r3
			xor %:ft_label, :ft_label2, r3
			xor %:ft_label2, :ft_label, r3
			xor 42, %42, r3
			xor :ft_label, %:ft_label, r3
			xor :ft_label2, %:ft_label2, r3
			xor :ft_label, %:ft_label2, r3
			xor :ft_label2, %:ft_label, r3
			xor 42, 42, r3
			xor :ft_label, :ft_label, r3
			xor :ft_label2, :ft_label2, r3
			xor :ft_label, :ft_label2, r3
			xor :ft_label2, :ft_label, r3

ft_label2:
