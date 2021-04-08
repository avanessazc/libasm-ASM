# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strcmp.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             #
#   Updated: 2021/02/04 12:09:45 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

section.text:
	global ft_strcmp

; rax = ft_strcmp(rdi, rsi)
ft_strcmp:
        xor     rax, rax                ; i = 0
	xor	rbx, rbx
        xor     bl, bl
        xor     cl, cl
        cmp     rdi, 0                  ; !s1
        je      exit
        cmp     rsi, 0                  ; !s2
        je      exit
        
compare:
        mov     bl, BYTE[rdi + rax]     ; rdi = s1, s1[i]
        mov     cl, BYTE[rsi + rax]     ; rsi = s2, s2[i]
        cmp     bl, cl                  ; s1[i] == s2[i]
        je      zero                    ; if s1[i] == s2[i] jump to
        jmp     exit                    ; else jump to

zero:   
        cmp     bl, 0                   ; s1[i] == '\0'
        je      exit                    ; if s1[i] == '\0' jump to
        inc     rax                     ; i++
        jmp     compare                 ; jump to

exit:
        movzx   rax, bl                 ; movzx, copy a register with a 
                                        ; inferior size in a bigger one,
                                        ; then it fills other bits with 0
        movzx   rbx, cl
        sub     rax, rbx                ; sub works like this
                                        ; Destination = Destination - Source.
                                        ; i = s1[i] - s2[i]
        ret                             ; return i
