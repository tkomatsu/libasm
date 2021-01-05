; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +;+  +:+       +;+         ;
;                                                 +;+;+;+;+;+   +;+            ;
;    Created: 2021/01/04 18:04:44 by tkomatsu          ;+;    ;+;              ;
;    Updated: 2021/01/04 18:04:44 by tkomatsu         ;;;   ;;;;;;;;.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strlen

section	.text

_ft_strlen:
	xor		rax, rax					; rax = 0
	jmp		compare

increment:
	inc		rax							; rax++

compare:
	cmp		BYTE[rdi + rax], 0			; str[rax] = 0 ?
	jne		increment					; if (*str != 0) jmp increment

done:
	ret
