# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_write.s                                         :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             #
#   Updated: 2021/02/04 12:09:45 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

section.text:
	global ft_write
	extern __errno_location

; rax = ft_write(rdi, rsi, rdx)
ft_write:
        xor rcx, rcx
        xor rax, rax
        mov rax, 1      	        ; syscall to write
        syscall
	cmp rax, 0		
	jl error
        ret

error:                                  ; set errno and return -1
        neg rax                         ; rax to positive number. Currently, it is a negative one 
        mov rcx, rax                    ; move return value in rcx
        call __errno_location           ; return value in rax, a non-null pointer to the error number.
        mov qword[rax], rcx             ; put value of rcx in rax address
        mov rax, -1
        ret                             ;return
