.data
	PI REAL8 3.14159265358979323846264338328
	ONE_EIGHTY REAL8 180.0
.code
RadToDegAsm proc dRad: QWORD, isSSE2: BYTE
test dl, dl
jz ET

cvtsi2sd xmm0, rcx

movsd xmm1, PI
movsd xmm2, ONE_EIGHTY

divsd xmm2, xmm1

mulsd xmm0, xmm2

; cvtsd2si rax, xmm0

ET: ret
RadToDegAsm endp

CpuIdAsm proc
xor rax, rax
inc rax
cpuid
mov rax, rdx
shr rax, 25
test rax, 1
jz ERR
shr rax, 1
test rax, 1
jz ERR
mov rax, 1
ret
ERR: xor rax, rax
ret
CpuIdAsm endp

end