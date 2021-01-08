; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/07 20:23:51 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/08 15:51:45 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_write
extern	___error

section	.text

_ft_write:
	mov		rax, 0x02000004
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
