.text
.align 4
.arm

.globl strcopy

strcopy:
   LDRB r2,[r1],#1
   STRB r2,[r0],#1
   CMP r2,#0
   BNE strcopy
   MOV pc,lr
.end