.name "zork"
.comment "I'M ALIIIIVE"

l2:		Xt_i r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
