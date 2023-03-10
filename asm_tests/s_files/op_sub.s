.name "sub"
.comment "subtraction"

# sub {T_REG, T_REG, T_REG}
ft_label:
			sub r1, r2, r3
			sub r3, r2, r1
			sub r1, r1, r1
			sub r15, r16, r17

ft_label2:
