  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.
.global time2string
.global delay

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
  
	.text

hexasc:	
	andi 	$t0,$a0,0xf
	addi 	$t1,$0,9
	
	ble 	$t0,$t1,islessorequal
	nop
	add	$t0,$t0,55
	move 	$v0,$t0
	
	j return
	nop
	
	islessorequal:
		addi 	$t0,$t0,48
		move 	$v0,$t0
		
		j return
		nop
	
	return:
		move	$a0,$v0
		jr	$ra
		nop
# Start of timer delay	
	
delay:
	PUSH $s2
	PUSH $s3
	move	$s2, $a0
	nop
while:
	ble	$s2, $0, end
	nop
	sub	$s2, $s2, 1
	addi	$s3, $0, 0
	nop
loop:
	nop
for:
	beq	$s3, 10000, while		#change value dependig on speed on computer
	nop
	addi	$s3, $s3, 1
 	j	loop
 	nop
 	
 end:
	POP $s3
	POP $s2
	move 	$a0, $s2
	jr	$ra
	nop
# End of timer delay	
 
time2string:
	PUSH	$ra
	PUSH	$s0
	PUSH	$s1
	PUSH	$s2
	PUSH	$s3

	add	$s0,$0,$a1	# load a1(mytime) to s0		=>	5957
	add	$s1,$0,$a0	# load a1(timstr adress) to s0	=>	adress to "The time is:                        \n\0"
	
		# print ding
		
	# DING if sec == 00 
#	andi	$a0,$s0,0x0FF
#	beq	$a0,0x00,ding
#	nop
#	jal	noding
#	nop
	
#ding:
#	la	$a0,printding
#	li	$v0,4
#	syscall
#	nop
#	j	afterding
#	nop

#noding:
	# Take first number
	andi	$a0,$s0,0x0F000
	srl	$a0,$a0,0xC
	jal	hexasc
	nop
	sb	$v0,0($s1)

	# Take second number
	andi	$a0,$s0,0x0F00
	srl	$a0,$a0,0x8
	jal	hexasc
	nop
	sb	$v0,1($s1)	# Put after first number
	
	addi 	$s2, $0, 0x3a	# :
	sb	$s2, 2($s1) 

	# Take third number
	andi	$a0,$s0,0x00F0
	srl	$a0,$a0,0x4
	jal	hexasc
	nop
	sb	$v0,3($s1)


	# Take fourth number
	andi	$a0,$s0,0x000F
	jal	hexasc
	nop
	sb	$v0,4($s1)

	# 0x00 => NUL
	addi 	$s3, $0, 0x00	# NUL
	sb	$s3, 5($s1) 
	
	POP	$s3
	POP	$s2
	POP	$s1
	POP	$s0
	POP	$ra
	

	jr	$ra
	nop

print:
	li	$v0,11
	syscall
	li $v0,10
	syscall

#afterding:
#	j	main
