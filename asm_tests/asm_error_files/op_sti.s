.name "sti"
.comment "store index"

# sti {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
ft_label:
			sti r1, r3, 42
			sti r1, r3, :ft_label
			sti r1, r3, :ft_label2
			sti r1, %42, 42
			sti r1, %:ft_label, :ft_label 
			sti r1, %:ft_label2, :ft_label2
			sti r1, %:ft_label, :ft_label2
			sti r1, %:ft_label2, :ft_label
			sti r1, 42, %42
			sti r1, :ft_label, :ft_label 
			sti r1, :ft_label2, :ft_label2
			sti r1, :ft_label, :ft_label2
			sti 42, :ft_label2, :ft_label

ft_label2:
