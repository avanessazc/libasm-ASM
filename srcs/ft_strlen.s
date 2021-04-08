# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strlen.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             #
#   Updated: 2021/02/04 11:03:22 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

section.text:
	global ft_strlen	        ;

; rax = ft_strlen(rdi)     
ft_strlen:
        xor     rax, rax                ; i = 0
        cmp     rdi, 0                  ; !s
        je      exit

compare:
        cmp     BYTE[rdi + rax], 0      ; s[i] != '\0'
        jne     inc_count
        jmp     exit

inc_count:
        inc     rax                     ; i++
        jmp     compare

exit:
        ret                             ; return i (rax)