; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/07 21:26:48 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/08 15:58:50 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_read
extern	___error

section .text

_ft_read:
	mov		rax, 0x02000003
	syscall
	jb		_error
	ret

_error:
	push	rax
	call	___error
	pop		r8
	mov		[rax], r8
	mov		rax, -1
	ret
