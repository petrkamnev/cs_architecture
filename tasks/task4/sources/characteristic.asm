;------------------------------------------------------------------------------
; characteristic.asm - единица компиляции, вычисляющая характеристику для строки
;------------------------------------------------------------------------------


global getSpecCount
getSpecCount:
section .data
    .sumSymbols    dq  0.0
    .addition      dq  1.0
section .text
push rbp
mov rbp, rsp
    xor al, al      ; конечный символ = 0
    mov ebx, [rsi]  ; сохраняем адрес строки со спецсимволами
    ; В rdi адрес начала контейнера
    movsd xmm1, [.sumSymbols]; перенос накопителя суммы в регистр 1
.loop:              ; идем по строке и сравниваем со спецсимволами
    cmp al, [rdi]
    je .endloop
    mov rdx, rsi
    .loopSymbols    ; вложенный цикл для сравнения со всеми спецсимволами
        cmp al, [rdx]
        je .incAndLoop
        mov bl, [rdx]
        cmp [rdi], bl
        jne .incAndLoopSymbols
        addsd xmm1, [.addition]
    .incAndLoopSymbols
        inc rdx
        jmp .loopSymbols 
.incAndLoop
    inc rdi
    jmp .loop
.endloop
.return:
    movsd xmm0, xmm1 ; переносим сумму
leave
ret
