; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/07 21:53:59 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/08 16:14:41 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy
extern	___error

global	_ft_strdup

section	.text

_ft_strdup:
	push	rdi

	call	_ft_strlen			; rax = ft_strlen(src)

	mov		rdi, rax
	call	_malloc
	jz		_err
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
	ret

_err:
	mov		rax, 0
	ret
