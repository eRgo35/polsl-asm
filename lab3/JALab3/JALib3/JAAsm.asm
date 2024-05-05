;******************************************************************************************
;*          JA Laboratory 3 simple assembly procedure call                                *
;*                                                                                        *
;*          Standard Windows memory model x64                                             *
;******************************************************************************************

.code

;******************************************************************************************
;*                                                                                        *
;*       Assembler procedure MyProc1 changes Flags register in X64 mode                   *
;*                                                                                        *
;*          Input:  a1: QWORD (C++ int type), b1: QWORD (C++ int type)                    *
;*          a1 in RCX, b1 in RDX                                                          *
;*          Output: z1: QWORD (C++ int type) in the RAX register                          *
;*                                                                                        *
;******************************************************************************************

MyProc1 proc a1: QWORD, b1: QWORD
        xor rax, rax       ; RAX = 0
        ror rcx,1          ; shift rcx right by 1
        shld rcx,rcx,2     ; set flags registry
        jnc ET1
        mul a1
        ret                ; return z1 in EAX register
  ET1:  mul a1
        neg b1
        ret                ; return z1 in EAX register
MyProc1 endp


;******************************************************************************************
;*                                                                                        *
;*       Assembler procedure MyProc2 changes Flags register in X64 mode                   *
;*                                                                                        *
;*    Input: a2 in RCX, b2 in RDX, c2 in R8, d2 in R9, f2 then e2 pushed on stack         *
;*    int MyProc2(int a2, int b2, int c2, int d2, int e2, int f2);                        *
;*    Output: z2: QWORD (C++ int type) in the RAX register                                *
;*                                                                                        *
;******************************************************************************************

; liczy iloczyn podanych argumentow
MyProc2 proc a2: QWORD, b2: QWORD, c2: QWORD, d2: QWORD, e2: QWORD, f2: QWORD
        mov rax, rcx
        mul rdx
        mul r8
        mul r9
        mul e2
        mul f2
        ret                ; return z2 in EAX register
MyProc2 endp


;******************************************************************************************
;*                                                                                        *
;*       Assembler procedure MyProc3 changes Flags register in X64 mode                   *
;*                                                                                        *
;*    Input: a3 in XMM0, b3 in XMM1, c3 in XMM2, d3 in XMM3, f2 then e2 pushed on stack   *
;*    int MyProc3 (float a, double b, float c, double d, float e, float f);               *
;*    Output: z3: QWORD (C++ int type) in the RAX register                                *
;*                                                                                        *
;******************************************************************************************

MyProc3 proc a3: REAL4, b3: REAL8, c3: REAL4, d3: REAL8, e3: REAL4, f3: REAL4
        xor rax, rax       ; RAX = 0
        


        ret                ; return z3 in EAX register
MyProc3 endp


;******************************************************************************************
;*                                                                                        *
;*       Assembler procedure MyProc3 changes Flags register in X64 mode                   *
;*                                                                                        *
;*    Input: a4 in RCX, b4 in XMM1, c4 in R8, d4 in XMM3, f4 then e4 pushed on stack      *
;*    int MyProc4 (int a4, double b4, int c4, float d4, int e4, float f4);                *
;*    Output: z4: QWORD (C++ int type) in the RAX register                                *
;*                                                                                        *
;******************************************************************************************

MyProc4 proc a4: QWORD, b4: REAL8, c4: REAL4, d4: REAL8, e4: REAL4, f4: REAL4
        xor rax, rax       ; RAX = 0
;        ror rcx,1          ; shift rcx right by 1
;        shld rcx,rcx,2     ; set flags registry
;        jnc ET1
;        mul b4
;        neg c4
;        add d4
;        add e4
;        add f4
;        ret                ; return z4 in EAX register
;  ET1:  mul 
;        neg c4
;        add d4
;        add e4
;        add f4
        ret                ; return z4 in EAX register
MyProc4 endp


; Example of argument passing 4 - __m64, __m128, and aggregates
; a in RCX, ptr to b in RDX, ptr to c in R8, d in XMM3,
; ptr to f pushed on stack, then ptr to e pushed on stack


;******************************************************************************************
;*                                                                                        *
;*       Assembler procedure MyProc3 changes Flags register in X64 mode                   *
;*                                                                                        *
;*    Input: a5 in RCX, b4 in RDX, ptr to c4 in R8, d4 in XMM3,                           *
;*           ptr to f4 pushed on stack, e4 pushed on stack                                *
;*    int MyProc5 (__m64 a, __m128 b);                                                    *
;*    Output: z5: QWORD (C++ int type) in the RAX register                                *
;*                                                                                        *
;******************************************************************************************

MyProc5 proc a5: QWORD, b5: xmmword
;        mov mm0, dword ptr [a5]
;        movaps xmm0, b5
;
;        addps xmm0, 2
;        movaps b5, xmm0
;        paddq mm0, mm0
;        movq qword ptr [a5], mm0
        ret             
MyProc5 endp






;*******************************************************************************
END                        ; End of ASM file

