; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/07 20:23:51 by tkomatsu          #+#    #+#              ;
;    Updated: 2021/01/07 20:25:14 by tkomatsu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_write

section	.text

_ft_write:
	mov		rax, 0x02000004
	syscall

	ret