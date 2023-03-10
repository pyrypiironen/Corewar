.name "lfork"
.comment "long fork"

# lfork {T_DIR}
ft_label:
			lfork %1
			lfork %:ft_label
			lfork %:ft_label2

ft_label2:
