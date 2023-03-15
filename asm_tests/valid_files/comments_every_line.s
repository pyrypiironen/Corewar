.name "zork"				#line1
.comment "I'M ALIIIIVE"		#line2
#line3
l2:		sti r1, %:live, %1	#line4
		and r1, %0, r1		#line5 #line5
							#line6
live:	live %1				#line7
		zjmp %:live			#line8
live2:						#line9
live3:						#line10
