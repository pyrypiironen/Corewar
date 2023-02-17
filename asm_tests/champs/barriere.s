.name "Barriere"
.comment "Envoie des torpilles a l'avant et se protege avec des barrieres a l'avant et a l'arriere"

		and	r6, %0, r6
		zjmp %:init

# On bombarde derriere notre programme

arriere:	ld	%-5, r5
		ld	%1024,r4
arriere2:	ld	%-5, r3
arriere_live:	live %42
		sti	r4, %:arriere, r3
		add	r3, r5, r3
		sti	r4, %:arriere, r3
		add	r3, r5, r3
		sti	r4, %:arriere, r3
		add	r3, r5, r3
		sti	r4, %:arriere, r3
		add	r3, r5, r3
		sti	r4, %:arriere, r3
		add	r3, r5, r3
		xor	r3,%-430,r15
		zjmp	%:arriere2
		and	r6, %0, r6
		zjmp	%:arriere_live

fork_arriere:	live %2
		fork	%:arriere
		zjmp	%:fork_arriere

# On commence les lives en serie
live_live:	live %2	
		sti	r1, %:live100, r9	
		sti	r1, %:live102, r9	
		sti	r1, %:live104, r9	
		sti	r1, %:live106, r9	
		sti	r1, %:live108, r9	
		sti	r1, %:live110, r9	
		sti	r1, %:live112, r9	
		sti	r1, %:live114, r9	
		sti	r1, %:live116, r9	
		sti	r1, %:live118, r9	
		sti	r1, %:live120, r9	
		sti	r1, %:live122, r9	
		sti	r1, %:live124, r9	
		sti	r1, %:live126, r9	
		sti	r1, %:live128, r9	
		sti	r1, %:live130, r9	
		sti	r1, %:live132, r9	
		sti	r1, %:live134, r9
		sti	r1, %:live136, r9
		sti	r1, %:live138, r9	
		sti	r1, %:live140, r9	
		sti	r1, %:live142, r9	
		sti	r1, %:live144, r9	
		sti	r1, %:live146, r9	
		sti	r1, %:live148, r9	
		xor	r9,%6,r10
		zjmp	%:fork_live
		ld	%6,r9
		and	r6,%0,r6
		zjmp	%:live_live	
		
init:		fork	%:kmissile
		live %2
		sti	r1, %:arriere_live, %1	
		fork	%:fork_arriere
		live %2
		sti	r1, %:avant_live, %1
		fork	%:fork_avant
		live %2
		ld	%1,r9
		and	r6,%0,r6
		zjmp	%:live_live
	
fork_live:	live %2
		fork	%:live100
		live %2	
		fork	%:fork_live
		live %2
		zjmp	%:fork_live
	
live100:	live %2
live101:	live %2	
live102:	live %2
live103:	live %2
live104:	live %2
live105:	live %2
live106:	live %2
live107:	live %2
live108:	live %2
live109:	live %2
live110:	live %2
live111:	live %2
live112:	live %2
live113:	live %2
live114:	live %2
live115:	live %2
live116:	live %2
live117:	live %2
live118:	live %2
live119:	live %2
live120:	live %2
live121:	live %2
live122:	live %2
live123:	live %2
live124:	live %2
live125:	live %2
live126:	live %2
live127:	live %2
live128:	live %2
live129:	live %2
live130:	live %2
live131:	live %2
live132:	live %2
live133:	live %2
live134:	live %2
live135:	live %2
live136:	live %2
live137:	live %2
live138:	live %2
live139:	live %2
live140:	live %2
live141:	live %2
live142:	live %2
live143:	live %2
live144:	live %2
live145:	live %2
live146:	live %2
live147:	live %2
live148:	live %2
live149:	live %2
		zjmp	%:live101

fork_avant:	live	%2
		fork	%:avant
		zjmp	%:fork_avant
	
avant:		ld	%-5, r5
		ld	%12, r4
avant2:		ld	%10, r3
avant_live:	live %1
		sti	r4, %:fin, r3
		sub	r3, r5, r3
		sti	r4, %:fin, r3
		sub	r3, r5, r3
		sti	r4, %:fin, r3
		sub	r3, r5, r3
		sti	r4, %:fin, r3
		sub	r3, r5, r3
		sti	r4, %:fin, r3
		sub	r3, r5, r3
		xor	r3,%435,r15
		zjmp	%:avant2
		and	r6, %0, r6
		zjmp	%:avant_live
fin:		zjmp	%:avant_live
kmissile:	live %2
		fork	%:kfork1
		live %2
		fork	%:kfork2
		live %2
		fork	%:kfork4
		ld	%12,r2
		ld	%192,r5
		and	r6,%0,r6
		zjmp	%:kdebut
		
kfork1:		live %2
		fork	%:kfork3
		live %2
		fork	%:kfork6
		ld	%0,r2
		ld	%180,r5
		and	r6,%0,r6
		zjmp	%:kdebut
	
kfork2:		live %2
		fork	%:kfork5
		live %2
		ld	%8,r2
		ld	%188,r5
		and	r6,%0,r6
		zjmp	%:kdebut
	
kfork3:		live %2
		fork	%:live100
		ld	%4,r2
		ld	%184,r5
		and	r6,%0,r6
		zjmp	%:kdebut

kfork4:		ld	%16,r2
		ld	%196,r5
		and	r6,%0,r6
		zjmp	%:kdebut

kfork5:		ld	%20,r2
		ld	%200,r5
		and	r6,%0,r6
		zjmp	%:kdebut

kfork6:		ld	%24,r2
		ld	%204,r5
		and	r6,%0,r6
		zjmp	%:kdebut

kdebut:		ldi	%:kdebut,r2,r3 
		sti	r3,r5,%:kfin   
		live %2
		and	r6,%0,r6
kfin:		zjmp	%180





