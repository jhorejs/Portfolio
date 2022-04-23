@ This code is copied from examples in Microprocessor System Design by Doug Hall
@ The code is designed to initialize the BBB LED0, initialize the clock to GPIO1
@ Once initialized the LED0 is cycled on and off every 2 seconds.
@ Josh Horejs
@ 11/12/2020

.text
.global _start
_start:

.equ CA, 0x00400000			@ Create constant CA
.equ CB, 0x00200000			@ Create constant CB


@--------Starting the clock on GPIO1 address block registers----
@ Turn on GPIO1_CLK
	LDR R0, =0x02				@ Value to enable clock fro a GPIO module
	LDR R1, =0x44E000AC			@ Address of CM_PER_GPIO1_CLKCTRL register
	STR R0, [R1]				@ Write #02 to register

@ Initialize GPIO1_21 as off
	LDR R6, =0x4804C190			@ Address of GPIOl_CLEARDATAOUT register
	LDR R5, =0x00200000			@ Load 1 to set bit GPIO1_21 turning off LED0
	STR R5, [R6]				@ Write to GPIO1_SETDATAOUT register with 0x190

@ Program GPIO1_21-24 as output
	LDR R1, =0x4804C134			@ Make GPIO1_OE	register address
	LDR R2, [R1]				@ Read current GPIO1 Output Enable register
	LDR R0, =0xFFCFFFFF			@ Word to enable GPIO1_21-24 as output(note: 0 enables)
	AND R2, R2, R0				@ Clear bit 21 (MODIFY)
	STR R2, [R1]				@ WRITE to GPIO1 output Enable register

@--------Looping on off sequence of GPIO1_21----------------------

LOOP:					@ Initialize loop identifier LOOP
	NOP				@ Break point
@ Turn on LED0(GPIO1_21)
	LDR R1, =CB			@ Load value to turn on GPIO1_21
	LDR R6, =0x4804C194		@ Load address of GPIO1_SETDATAOUT register 0X134
	STR R5, [R6]			@ Write to GPIO1_SETDATAOUT register

@ Wait 2 seconds
	LDR R2, =CA			@ Load the value 0x00400000 to R2
CLK:					@ Initialize loop identifier CLK
	NOP				@ Break point
	SUBS R2, #1			@ SUB: Subtract 1 from R2, S: update flags
	BNE CLK				@ BNE: Branch to label CLK0 when SUBS R2 updates Z(0) flag

	@ Turn off LED0(GPIO_21)
	LDR R5, =CB			@ Load 1 to set bit GPIO1_21 turning on LED0
	LDR R6, =0x4804C190		@ Off Load address of GPIO1_21 turning on LED0
	STR R5, [R6]			@ Write to GPIO1_CLEARDATAOUT register with 0x190
@ Wait 2 seconds
	LDR R2, =CA			@ Load the value 0x00400000 to R2
CLK1:					@ Initialize loop identifier CLK
	NOP				@ Break point
	SUBS R2, #1			@ SUB: Subtract 1 from R2, S: update flags
	BNE CLK1			@ BNE: Branch to label CLK when SUBS R2 updates Z(0) flag

B LOOP					@ B: break to label LOOP
.end

