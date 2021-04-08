# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strdup.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             #
#   Updated: 2021/02/04 12:09:45 by ayzapata         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

section.text:
        global  ft_strdup
        extern  ft_strlen
        extern  ft_strcpy
        extern  malloc

; rax = ft_strdup(rdi)

ft_strdup:
        xor     rax, rax                ; i = 0
        cmp     rdi, 0                  ; !s
        je      error
        call    ft_strlen               ; rax = ft_strlen(rdi) where rdi = src
        inc     rax                     ; rax = rax + 1
        push    rdi                     ; insert value of rdi onto the stack
        mov     rdi, rax                ; rdi = len, argument for malloc function
        call    malloc                  ; rax = dest, malloc return
        pop     rdi                     ; take value of rdi from the stack
        cmp     rax, 0                  ; if malloc() fails
        je      error                   ; jump to 
        mov     rsi, rdi                ; rsi = src for ft_strcpy function
        mov     rdi, rax                ; rdi = dest for ft_strcpy function
        call    ft_strcpy               ;
        ret                             ; return dest

error:
        xor     rax, rax                ;
        ret                             ; return NULL

