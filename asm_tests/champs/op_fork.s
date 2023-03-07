.name "fork"
.comment "fork"

# fork {T_DIR}
ft_label:
			fork %1
			fork %:ft_label
			fork %:ft_label2

ft_label2:
