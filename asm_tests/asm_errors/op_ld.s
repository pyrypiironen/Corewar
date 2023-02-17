.name "ld"
.comment "load"

# ld {T_DIR | T_IND, T_REG}
ft_label:
			ld %42, r1
			ld 42, r1
			ld %:ft_label, r1
			ld :ft_label, r1
			ld %:ft_label2, r1
			ld :ft_label2, r1

ft_label2:
