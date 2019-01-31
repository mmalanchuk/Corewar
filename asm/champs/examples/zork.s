.name "zork"
.comment "I'M ALIIIIVE"

l1:		sti r1, %:live, %1
		and r1, %0, r1

l2:	and r1, %0, r1
sti r1, 3, %1

live:	live %1
		zjmp %:live

