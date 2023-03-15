.name "sub"
.comment "subtraction"

# sub {T_REG, T_REG, T_REG}
ft_label:
			sub 1, 2, 3
			sub r3, %2, r1
			sub r1, %:r1, 1
			sub 15, r16, r17

ft_label2:
