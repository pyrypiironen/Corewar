.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1
		st r1, %2

live:	live %1
		zjmp %:live
