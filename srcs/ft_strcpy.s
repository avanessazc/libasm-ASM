# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strcpy.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/14 15:34:01 by ayzapata          #+#    #+#             #
#   Updated: 2021/02/04 12:03:22 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

section.text:
	global ft_strcpy

; rax = ft_strcpy(rdi, rsi)
ft_strcpy:
        xor     rax, rax                ; i = 0
        xor     rbx, rbx
        cmp     rdi, 0                  ; !dest
        je      end
        cmp     rsi, 0                  ; !src
        je      end
        
compare:
        cmp     BYTE[rsi + rax], 0      ; src[i] != '\0'
        jne     copy
	jmp     exit

copy:
        mov     bl, BYTE[rsi + rax]
        mov     BYTE[rdi + rax], bl     ; dest[i] = src[i]
	inc     rax                     ; i++
        jmp     compare

exit:
        mov     bl, 0
        mov     BYTE[rdi + rax], bl     ; dest[i] = '\0'
        mov     rax, rdi
        ret                             ; return dest

end:
        mov     rax, 0
        ret 
