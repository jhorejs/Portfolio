@ LED/Timer2 INTERRUPT PROGRAM
@ Runs on BeagleBone BlackBoard with Pushbutt on/LED cape.
@
@ WHEN THE OUTPUT FROM A DEBOUNCED SWITCH ONGPI01_14 GOES LOW ,
@ THIS PROGRAM PRODUCES AN IRQ INTERRUPT TO THE PROCESSOR. The IRQ
@ SERVICE@PROCECDURE FOR THIS REQUESTWILL LIGHT AN LED CONNECTED
@ TO GPIOl_12 and start Timer2. When the Timer 2 count overflows
@ after 0.5 seconds, an IRQ Interrupt generated. In response to
@ this interrupt, the LED will be toggled. Note: Program uses modified
@ Startup_ARMCA8 file to access IRQ In terrupt Service Procedure
@ INT_Director
@ Copy right Douglas V. Hall Fall 2016

@ This code is coppied from Microprocessor System Design by Doug Hall Chapter 5 Figure 5-18 pg. 243-246
@ The code is ARM Assembly for a button/serviceLED.
@ The point of this project is to discover the processor interupts and how to use them
@ Specifically this code applies the IRQ and SVC executions.
@
@ Note: My changes for the code in page 243 are labeled with a @<--
@
@ ECE 371 Project 1.2.1
@ Josh Horejs 12/5/2020
@
@								Discription
@ Using a external input button on pin GPIO1_30, the we trigger the onboard LED0 aka
@ GPIO1_21 The process is compmleted using the ARM structure interupt IRQ. Once the
@ this IRQ is recognized the Timer2 starts a procedure and continues until the overflow
@ triggers after 2s at which point a IRQ is executed triggering LED0.
@
@ Note: INT_DIRECTOR modifies the Startup_ARMCA8 file using b loop interrup at ~

.text
.global _start
.global INT_DIRECTOR
_start:

@
	LDR R13, =STACK1			@ Point to the base of the STACK for SVC mode
	ADD R13, R13, #0x1000		@ Point to the top of the STACK
	CPS #0x12					@ Switch to IRQ mode
@
	LDR R13, =STACK2			@ Point to IRQ stack
	ADD R13, R13, #0x1000		@ Point to top of STACK
	CPS #0x13					@ Back to SVC mode

@ Turn on GPIO1 CLK
	LDR R0, =0x02				@ Value to enable clock for GPIO modules
	LDR R1, =0x44E000AC			@ Load to R1 address of CM_PER_GPIO1_CLCKCTRL registers
	STR R0, [R1]				@ Write hex word 0x02 to R1 (CM_PER_GPIO1_CLCKCTRL) for R1=0x4804C134

@ Initialize the output bit as off with CLEARDATAOUT 190 R4 ADDED to R0 GPIO1 base address
	@LDR R0, =0x4804C000		@ GPIO1 OE register to R0=0x4804C000
	@ADD R4, R0, #0x190			@ 190 is the GPIO1_CLEARDATAOUT register, R4=0x4804C190
	LDR R1, =0x4804C190
	MOV R7, #0x00200000			@ Load 1 to set bit GPIO1_21 turning off LED0 using hex 0x002000000
	STR R7, [R1]				@ Write to GPIO1 output enable register

@ Program GPIO1_21-23 as output
	@ADD R1, R0, #0x0134		@ Make GPIO1_OE register address,  0x134 to turn on OE
	@LDR R6, [R1]				@ Read current GPIO1 base address to Output Enable registers
	LDR R1, =0x4804C134
	LDR R0, =0xFE1FFFFF@<--   from FFFFEFFF	bit 12		@ Word to enable GPIO1_30 as output(0 enables)
	AND R2, R2, R0				@ Clear bit 21-24
	STR R2, [R1]				@ Write to GPIO1_OE output enable register

@ Detect falling edge on GPIO1_30 and enable to assert POINTEREND1
	@ADD R1, R0, #0x14C			@ R1 = address of GIO1_FALLINGDETECT register
	LDR R1, =0x4804C14C
	LDR R2, =0x40000000@<-- from 0x00004000 bit 14		@ Load value for bit GPIO1_30 (1 enables See Table 3)
	LDR R3, [R1]				@ read GPIO1_FALLINGDETECT register
	ORR R3, R3, R2				@ Modify (set GPIO1_30 )
	STR R3, [R1]				@ Store the contents of R1 to R3
	@ADD R1, R0, #0x34			@ Address of GPIO1_IRQSTATUS_SET_0 register
	LDR R1, =0x4804C034
	STR R2, [R1]				@ Enable GPIO1_30 request on POINTERPEND1

@@@@@@@@@@@@@@@@@@@@@ NOT WORKING TRY SOMETHING DIFF
@ Initialize INTC interrupt controller INTC. processes base address of 0x48200000
	@LDR R1, =0X48200000		@ Base address for INTC,
	@MOV R2, #0x2				@ Value to reset INTC
	@STR R2, [R1, #0x10] 		@ Write to Timer2 CFG register
	@MOV R2, #0x10       @<--	@ UnmaskINTC INT 93, Timer2 interrupt, Need to change
	@STR R2, [R1, #0xC8]		@ Write to INTC_MIR_CLEAR2 register
	@MOV R2, #0x04				@ Value to unmask INTC INT 98, GPIOINTA
	@STR R2, [R1, #0xE8]		@ Write to INTC_MIR_CLEAR3 register
@@@@@@@@@@@@@@@@@@@
	LDR R1, =0X48200010			@ Base address for INTC,
	MOV R2, #0x2				@ Value to reset INTC
	STR R2, [R1] 		@ Write to Timer5 CFG register

	LDR R1, =0X482000C8
	MOV R2, #0x20000000 @<--	@ UnmaskINTC INT 93, Timer2 interrupt, Changed from 2=0x00000010
	STR R2, [R1]			@ Write to INTC_MIR_CLEAR2 register

	LDR R1, =0X482000E8
	MOV R2, #0x04				@ Value to unmask INTC INT 98, GPIOINTA
	STR R2, [R1]			@ Write to INTC_MIR_CLEAR3 register

@ Turn on Timer5 CLK
	MOV R2, #0x2				@ Value to enable Timer5 CLK
	LDR R1, =0x44E000EC	@ <--	@ Address of CM_PER_TIMER2_CLKCTRL. Changes from 0x44E00080
	STR R2, [R1]				@ Turn on timer
	LDR R1, =0x44E00518 		@ Address of PRCMCLKSE_TIMER2 register
	STR R2, [R1]				@ Select 32 KHz CLK for Timer2

@ Initialize Timer5 registers, use count and the overflow flag interrupt generation
	LDR R1, =0x48046000@<--		@ Base address of TIMER5 register CHANGED FROM: =0x48040000
	MOV R2,     #0x1				@ Value to reset Timer5
	STR R2,     [R1, #0x10] 		@ Write to Timer5 CFG register
	MOV R2,     #0x2				@ Value to Enable Overflow interrupt
	STR R2,     [R1, #0x2C]			@ Write to Timer5 CFG register
	LDR R2,     =0xFFFF0000@<--		@ Count value for 2 seconds In TI manual
	STR R2,     [R1, #0x40]			@ Timer5 TLDR load register (Reload value)
	STR R2,     [R1, #0x3C]			@ Write to Timer5 TCRR count register


@ Make sure processor IRQ enabled in CPSR
	MRS R3,     CPSR				@ Copy CPSR to R3
	BIC R3,     #0x80				@ Clear bit 7
	MSR CPSR_c, R3				@ Write back cleared bit 7 to CPSR_c

@ Wait for interrupt
LOOP: NOP						@ wait Loop
	B LOOP						@ break point for loop

INT_DIRECTOR:					@ Defining the INT_DIRECTOR for implementation in the startup file
	STMFD SP!, {R0-R3, LR}		@ Push registers on stack
	LDR R0, =0x482000F8			@ Address of INTC-PENDINGIRQ3
	LDR R1, [R0]				@ Read INTC-Pending_IRQ3 register
	TST R1, #0x00000004			@ Test BIT 2
	BEQ TCHK					@ Not from GPIOINT1A, check if Timer5, else
	LDR R0, =0x4804C02C			@ Load GPIO1_IRQSTATUS_0 register address
	LDR R1, [R0]  				@ Read STATUS register
	TST R1, #0x40000000@<--		@ Check if bit 30 = 1? Changed From TST,dont know why this worked?
	BNE BUTTON_SVC				@ Iff bit 30 = 1, button was pushed/Vcc=~0
	LDR R0, =0x48200048			@ Else, go back. INTC_CONTROL register
	MOV R1, #01					@ Value to clear bit 0
	STR R1, [R0]				@ Write to INTC_CONTROL register
	LDMFD SP!, {R0-R3, LR}		@ Restore registers
	SUBS PC, LR, #4				@ Pass execution to wait LOOP for now

TCHK:
	LDR R1, =0x482000D8			@ Address of INTC PENDING _1RQ2 register
	LDR R0, [R1]				@ Read value
	TST R0, #0x20000000@<--		@ Check if interrupt from TIMER2
	BEQ PASS_ON					@ No, return yes, check for overflow
	LDR R1, =0x48046028@<--		@ Address of Timer2 IRQSTATUS register
	LDR R0, [R1]	 			@ Read value
	TST R0, #0x2				@ Check bit 1
	BNE LED						@ If Overflow, then go toggle LED

PASS_ON: 						@ Else go back to wait loop
	LDR R0, =0x48200048			@ Address of INTC_CONTROL register
	MOV R1, #01					@ Balue to clear bit 0
	STR R1, [R0]				@ Write to INTC_CONTROL register
	LDMFD SP!, {R0-R3, LR}		@ Restore registers
	SUBS PC, LR, #4				@ Pass execution to wait LOOP for now

BUTTON_SVC:						@ Supervisor control interupt execution tag
	LDR R1, =0x40000000@<-- From 0x0000400 GPIO1_14			@ Hex word to deactivate GPIO1_30(button) interupt request
	LDR R0, =0x4804C02C			@ Also turns off INTC interrupt request
	STR R1, [R0]				@ Write to GPIO1_IRQSTATUS_0 register

@ Turn on LED0 GPIO1_21 Code from part 1
	LDR R0, =0x4804C194			@ Load address of GPIO1_SETDATAOUT register
	LDR R1, =0x00200000@<-- 0x00001000 GPIO1_12			@ Load value to turn on GPIO1_21(LED0)
	STR R1, [R0]				@ Write to GPIO1_SETDATAOUT register
	MOV R2, #0x01@<--			@ Load value to auto reload timer and start
	LDR R1, =0x48046038@<--		@ address of Timer5 TCLR register CHANGED FROM: =0x48040038
	STR R2, [R1] 				@ Write to TCLR register


@ Turn on Timer5 interrupt and enable INTC for next IRQ
 	LDR R1, =0x48046000@<--		@ Timer5 IRQSTATUS register FROM:=0x48040028
 	LDR R2, =0xFFFF0000			@ Value to reset Timer5 Overflow IRQ request
 	STR R2, [R1, #0x3C]			@ Write
@Turn off NEWIRQA bit in INTC_CONTROL, so processor can respond to new IRQ
	LDR R0, =0x48200048			@ Address of the INTC_CONTROL register
	MOV R1, #01					@ Value to clear bit 0
	STR R1, [R0]				@ Write to INTC_CONTROL register
	LDMFD SP!, {R0-R3, LR}		@ Restore register
	SUBS PC, LR, #4				@ Pass execution on to wait LOOP for now


LED:
@ Turn off Timer5 interrupt and enable INTC for next IRQ
	LDR R1, =0x48046028@<--		@ Load address of Timer5 IRQSTATUS register FROM:=0x48040028
	MOV R2, #0x2				@ Value to reset Timer5 Overflow IRQ request
	STR R2, [R1]				@ Write

@ Toggle LED
	LDR R1, =0x4804C000			@ Base Address of GPIO1
	LDR R2, [R1,#0x013C]		@ Read value from GPI01_DATAOUT
	TST R2, #0x00200000	@<--	@ Check bit 21 wehre LED connectd
	MOV R2, #0x00200000	@<--	@ Value to set or clear bit 12
	BNE TOFF					@ LED on, go turn off
	STR R2, [R1, #0x194]		@ LED off, turn on with GPIO1_SETDATAOUT
@ Turn on Timer5 interrupt and enable INTC for next IRQ
@	LDR R1, =0x48046000@<--		@ Timer5 IRQSTATUS register FROM:=0x48040028
@	LDR R2, =0xFFFF0000			@ Value to reset Timer5 Overflow IRQ request
@	STR R2, [R1, #0x3C]				@ Write

	B BACK						@ Back to wait loop

TOFF:
	LDR R1, =0x4804C190
	STR R2, [R1]			@ Turn LED off with GPIO1_CLEARDATAOUT
	BACK:
	LDR R1, =0x48200048			@ Address of INTC_CONTROL register
	MOV R2, #0x01				@ Value to enable new IRQ response in INTC
	STR R2, [R1]				@ Write
	LDMFD SP!, {R0-R3, LR}		@ Restore registers
	SUBS PC, LR, #4				@ Return from IRQ interrupt procedure


.data							@
.align 2						@
STACK1: .rept 1024				@
		.word 0x0000			@
		.endr					@
STACK2: .rept 1024				@
		.word 0x0000			@
		.endr					@
.END

