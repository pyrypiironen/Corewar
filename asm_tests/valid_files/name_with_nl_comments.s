




   .name		"
   
   
   # is this saved?
   
   
   
   test_name"
	
	  .comment    "This is a comment!"	
		

l2:	sti	r1,%:live,%0
	and	r1,%0,r1

	and	r1,%0,r1

live:	live	%1
	zjmp	%:live
