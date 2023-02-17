.name "lldi"
.comment "long load index"

# lldi {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
ft_label:
			lldi r1, r2, r3
			lldi r3, r2, r1
			lldi r1, r1, r1
			lldi r15, r16, r17
			lldi %42, r2, r3
			lldi %:ft_label, r2, r3
			lldi %:ft_label2, r2, r3
			lldi r1, %42, r3
			lldi r1, %:ft_label, r3
			lldi r1, %:ft_label2, r3
			lldi 42, r2, r3
			lldi :ft_label, r2, r3
			lldi :ft_label2, r2, r3
			lldi %42, %42, r3
			lldi %:ft_label, %:ft_label, r3
			lldi %:ft_label2, %:ft_label2, r3
			lldi %:ft_label, %:ft_label2, r3
			lldi %:ft_label2, %:ft_label, r3
			lldi 42, %42, r3
			lldi :ft_label, %:ft_label, r3
			lldi :ft_label2, %:ft_label2, r3
			lldi :ft_label, %:ft_label2, r3
			lldi :ft_label2, %:ft_label, r3

ft_label2:
