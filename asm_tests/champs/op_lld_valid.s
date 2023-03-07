.name "lld"
.comment "long load"

# lld {T_DIR | T_IND, T_REG}
ft_label:
			lld %42, r1
			lld %:ft_label, r1
			lld %:ft_label2, r1
			lld 42, r1
			lld :ft_label, r1
			lld :ft_label2, r1
ft_label2:
