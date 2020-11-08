.text
.align 4
.arm

.globl arm_add

arm_add:
    add r0, r0, r1
    bx      lr

.globl arm_sub
arm_sub:
    sub r0, r0, r1
    bx      lr