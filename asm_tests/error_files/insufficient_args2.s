.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live
		and r1, %0, r1

live:	live %1
		zjmp %:live
