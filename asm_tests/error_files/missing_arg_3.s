




   .name		"
   
   
   # is this saved?
   
   
   
   test_name"
	
	  .comment    "This is a comment?

	  #saved ?
	  



	  still saved?
	  "	
		
live	%1
l2:	
sti	,%:live, r2 # missing 1st ARG
	and	r1,%0,r1

	and	r1,%0,r1
	lldi 42, r2, r3
	st r1, :l2

live:	live	%1
	zjmp	%:live
