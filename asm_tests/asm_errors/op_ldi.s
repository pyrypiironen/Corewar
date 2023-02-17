.name "ldi"
.comment "load index"

# ldi {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
ft_label:
			ldi r1, r2, r3
			ldi r3, r2, r1
			ldi r1, r1, r1
			ldi r15, r16, r17
			ldi %42, r2, r3
			ldi %:ft_label, r2, r3
			ldi %:ft_label2, r2, r3
			ldi r1, %42, r3
			ldi r1, %:ft_label, r3
			ldi r1, %:ft_label2, r3
			ldi 42, r2, r3
			ldi :ft_label, r2, r3
			ldi :ft_label2, r2, r3
			ldi %42, %42, r3
			ldi %:ft_label, %:ft_label, r3
			ldi %:ft_label2, %:ft_label2, r3
			ldi %:ft_label, %:ft_label2, r3
			ldi %:ft_label2, %:ft_label, r3
			ldi 42, %42, r3
			ldi :ft_label, %:ft_label, r3
			ldi :ft_label2, %:ft_label2, r3
			ldi :ft_label, %:ft_label2, r3
			ldi :ft_label2, %:ft_label, r3

ft_label2:
