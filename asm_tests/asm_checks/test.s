.name    "Survivor"
.comment "Invincible"

	live	%1
	fork	%:f1
	zjmp	%:j1
f1:	ld	%4, r2
	zjmp	%:run
j1:
run:	xor	r0, r0, r0
l1:	st	r2, 1
	live	%1
	zjmp	%:l1

# should handle:
# empty name/comment within ""
# huge label names
# non-existing labels, no label name = ERROR
# newline in name and comment is OK