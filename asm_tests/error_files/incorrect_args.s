.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti 1, %:live, %1 #<----- 1st arg needs to be reg
		and r1, %0, r1

live:	live %1
		zjmp %:live
