.name "big_load"
.comment "why do we call our files 'load'?"

live:
	live %-1
ld 1, r2
lld 1, r2
moro:
	ldi 2, %:live, r3
lldi 2, %2, r3
st r1, 5
sti r3, :hehe, %:hehe
add r1, r2, r3
hehe:
	and 2, 2, r3
zjmp %:hehe
fork %4090
lfork %:moro
