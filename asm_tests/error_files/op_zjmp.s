.name "zjmp"
.comment "jump if zero"

# zjmp {T_DIR}
ft_label:
			zjmp 1
			zjmp :ft_label
			zjmp :ft_label2

ft_label2:
