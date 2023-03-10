.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1
		sti r1, %:death, %1
		sti r1, :live, %1

zombie:
death:
live:	live %1
		zjmp %:live
