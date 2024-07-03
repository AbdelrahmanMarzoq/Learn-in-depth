.global reset 
reset:
	ldr sp, = Stack_Point
	bl main
stop: b stop