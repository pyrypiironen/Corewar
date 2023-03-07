.name "and"
.comment "et (and  r1, r2, r3   r1&r2 -> r3"

# and {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}
ft_label:
			and r1, r2, r3
			and r3, r2, r1
			and r1, r1, r1
			and r15, r16, r17
			and %42, r2, r3
			and %:ft_label, r2, r3
			and %:ft_label2, r2, r3
			and r1, %42, r3
			and r1, %:ft_label, r3
			and r1, %:ft_label2, r3
			and 42, r2, r3
			and :ft_label, r2, r3
			and :ft_label2, r2, r3
			and r1, 42, r3
			and r1, :ft_label, r3
			and r1, :ft_label2, r3
			and %42, %42, r3
			and %:ft_label, %:ft_label, r3
			and %:ft_label2, %:ft_label2, r3
			and %:ft_label, %:ft_label2, r3
			and %:ft_label2, %:ft_label, r3
			and %42, 42, r3
			and %:ft_label, :ft_label, r3
			and %:ft_label2, :ft_label2, r3
			and %:ft_label, :ft_label2, r3
			and %:ft_label2, :ft_label, r3
			and 42, %42, r3
			and :ft_label, %:ft_label, r3
			and :ft_label2, %:ft_label2, r3
			and :ft_label, %:ft_label2, r3
			and :ft_label2, %:ft_label, r3
			and 42, 42, r3
			and :ft_label, :ft_label, r3
			and :ft_label2, :ft_label2, r3
			and :ft_label, :ft_label2, r3
			and :ft_label2, :ft_label, r3

ft_label2:
