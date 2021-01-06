; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/04 20:42:22 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/06 12:34:52 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcpy

section	.text

_ft_strcpy:
	xor		rcx, rcx						; i = 0
	xor		rdx, rdx						; tmp = 0

copy:
	mov		dl, BYTE[rsi + rcx]				; tmp = src[i]
	cmp		dl, 0							; if (tmp == 0)
	je		return
	mov		BYTE[rdi + rcx], dl				; dst[i] = tmp
	inc		rcx								; i++
	jnz		copy							; loop

return:
	mov		BYTE[rdi + rcx], 0				; dst[i] = 0
	mov		rax, rdi						; ret = dst
	ret
