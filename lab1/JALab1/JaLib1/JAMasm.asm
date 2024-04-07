;*******************************************************************************
;* Laboratory 1 simple assembly procedure call *
;* *
;* Standard Windows memory model *
;*******************************************************************************
.code
;*******************************************************************************
;* *
;* Assembler procedure MyProc1 changes Flags register in X64 mode *
;* *
;* Input: x: QWORD (C++ int type), y: QWORD (C++ int type) *
;* x in RCX, y in RDX *
;* Output: z: QWORD (C++ int type) in the RAX register *
;* *
;*******************************************************************************
MyProc1 proc x: QWORD, y: QWORD
xor rax, rax ; RAX = 0
ror rcx,1 ; shift rcx right by 1
shld rcx,rcx,2 ; set flags registry
jnc ET1
mul y
ret ; return z in RAX register
ET1: mul x
neg y
ret ; return z in RAX register
MyProc1 endp
end ; End of ASM file