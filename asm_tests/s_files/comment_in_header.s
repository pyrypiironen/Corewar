


	.name		""
	#.das TEST THIS
		.comment    ""	
		
live	%1
l2:
sti	r1,%:live, r2
	and	r1,%0, r1

	and	r1,%0,r1
	lldi 42, r2, r3
	st r1, :l2

live:	live	%1
	zjmp	%:live
