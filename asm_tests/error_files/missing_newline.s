.name    "sebc"
.comment "sebc"

l1:	live	%1
	ld	%:l1, r2
l3:	ldi	%:l2, r2, r4
	sti	r4, %:l2, r2
	add	r2, r3, r2
l2: