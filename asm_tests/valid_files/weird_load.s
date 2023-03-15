.name "weird_load"
.comment "U bout to get rekt kid"

ad:
	live %-1
ld 1, r2
lld 1, r2
ldi 2, %2, r3
lldi 2, %2, r3
st r1, 5
bc:
	sti r3, %:ad, %2
add r1, r2, r3
and 2, 2, r3
shounen_jump:
	zjmp %8000
fork %4090
lfork %4090
