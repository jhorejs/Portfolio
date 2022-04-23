 @ The following code follows the same structure as Part 1.2 with the addition of lines.
@ Cycling on LED0 to LED3 at 2 seconds intervals 
@ then cycle off LED3 to LED1 at 2 second intervals.
@ Josh Horejs
@ 11/12/2020
.text
.global _start
_start:
@--------Starting the clock on GPIO1 address block registers----
@ Turn on GPIO1_CLK
	LDR R0, =0x02				@ Value to enable clock for the GPIO1 module
	LDR R1, =0x44E000AC			@ Address of CM_PER_GPIO1_CLKCTRL register
	STR R0, [R1]				@ Write #02 to register
@ Initialize GPIO1_21-24 as off
	LDR R6, =0x4804C190			@ Address of GPIOl_CLEARDATAOUT register
	LDR R5, =0x01E00000			@ Load 1 to set bit GPIO1_21 turning off LED0
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register with 0x190
@ Program GPIO1_21-24 as output with RMW
	LDR R1, =0x4804C134			@ Make GPIO1_OE	register address
	LDR R2, [R1]				@ Read current GPIO1 Output Enable register
	LDR R0, =0xFE1FFFFF			@ Word to enable GPIO1_21-24 as output (note: 0 to enable w/ AND)
	AND R2, R2, R0				@ Clear bit 21 (MODIFY)
	STR R2, [R1]				@ WRITE to GPIO1 output Enable register
@--------Looping on off sequence of GPIO1_21----------------------
LOOP0:						@ Initialize a new loop
	NOP					@ Break point for debug
@ Turn on LED0(GPIO1_21)
	LDR R5, =0x00200000			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C194			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
@ Wait 2 seconds
	LDR R2, =0X00400000			@ Delay time loaded to R2
CLK0:					@ Initialize loop CLK0
	NOP					@ Break point
	SUBS R2, #1				@ Decrement R2 by 1 bit each clock cycle
	BNE CLK0				@ Branch to CLK0 as long as R2 zero flag not set
@ Turn on LED0-1(GPIO1_21-22)
	LDR R5, =0x00600000			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C194			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
@ Wait 2 seconds
	LDR R2, =0X00400000			@
LOOP1:
	NOP
	SUBS R2, #1
	BNE LOOP1
@ Turn on LED0-2(GPIO1_21-23)
	LDR R5, =0x00E00000			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C194			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
@ Wait 2 seconds
	LDR R2, =0X00400000			@ Delay time loaded to R2
CLK1:						@ Initialize loop CLK0
	NOP					@ Break point
	SUBS R2, #1				@ Decrement R2 by 1 bit each clock cycle
	BNE CLK1					@ Branch to CLK0 as long as R2 zero flag not set
@ Turn on LED0-3(GPIO1_21-24)
	LDR R5, =0x01E00000			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C194			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
	LDR R2, =0X00400000			
LOOP2:
	NOP
	SUBS R2, #1
	BNE LOOP2
@ Turn off LED3(GPIO1_24)
	LDR R5, =0x01000000			@ Load value to turn on GPIO1_24
	LDR R6, =0x4804C190			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
@ Wait 2 seconds
	LDR R2, =0X00400000			
CLK3:
	NOP
	SUBS R2, #1
	BNE CLK3
@ Turn off LED2(GPIO1_23)
	LDR R5, =0x01800000			@ Load value to turn on GPIO1_23
	LDR R6, =0x4804C190			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
@ Wait 2 seconds
	LDR R2, =0X00400000			@
LOOP3:
	NOP
	SUBS R2, #1
	BNE LOOP3
@ Turn on LED1(GPIO1_22)
	LDR R5, =0x01C00000			@ Load value to turn on GPIO1_22
	LDR R6, =0x4804C190			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
	@ Wait 2 seconds
	LDR R2, =0X00400000			@
CLK4:
	NOP
	SUBS R2, #1
	BNE CLK4
@ Turn on LED0(GPIO1_21)
	LDR R5, =0x01E00000			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C190			@ Load address of GPIO1_SETDATAOUT register
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register
	LDR R2, =0X00400000			@
CLK5:
	NOP
	SUBS R2, #1
	BNE CLK5

B LOOP0

.END
