; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/07 20:02:13 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/07 20:20:00 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcmp

section	.text

_ft_strcmp:
	xor		rbx, rbx				; i = 0
	xor		rcx, rcx				; tmp1 = 0
	xor		rdx, rdx				; tmp2 = 0

compare:
	mov		cl, BYTE[rdi + rbx]		; tmp1 = s1[i]
	mov		dl, BYTE[rsi + rbx]		; tmp2 = s2[i]
	cmp		cl, 0					; if (tmp1 == 0)
	je		return
	cmp		dl, 0					; if (tmp2 == 0)
	je		return
	cmp		cl, dl					; if (tmp1 == tmp2)
	jne		return
	inc		rbx
	jmp		compare

return:
	sub		rcx, rdx
	mov		rax, rcx
	ret
