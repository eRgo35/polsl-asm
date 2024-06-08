.386
.model flat, stdcall
option casemap :none ; case sensitive
.nolist
.nocref
; ############################################################
include \masm32\include\windows.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
; ############################################################
.list
.cref
.data
Tytul_okna db "Minimum MASM32", 0
Tekst_w_oknie db " --- To jest mój pierwszy program asemblerowy pod W2k! --- ", 0
.code
start:
push MB_OK
push offset Tytul_okna
push offset Tekst_w_oknie
push 0
call MessageBox
push 0
call ExitProcess
end start