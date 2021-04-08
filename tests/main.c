/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:02:52 by ayzapata          #+#    #+#             */
/*   Updated: 2021/02/09 10:37:22 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libasm.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char *p_s1;
	const unsigned char *p_s2;

	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p_s1[i] == p_s2[i])
			i++;
		else
			return ((p_s1[i] - p_s2[i]));
	}
	return (0);
}

void    ft_tests()
{
    
    char    *str;
    char    *s1;
    char    *s2;
    int     i;
    int     rc;
    int     rasm;
    char    *rc_arr;
    char    *rasm_arr;
    
    printf("\n%25s %20s\n", "Real function C", "ASM");
    printf("%s\n", "------------------------------------------------------------------------");
    i = 0;
    str = "Pido perdón a los niños por haber dedicado este libro a una persona mayor. \
            Tengo una seria excusa: esta persona mayor es el mejor amigo que tengo en el mundo. \
            Tengo otra excusa: esta persona mayor es capaz de entenderlo todo, hasta los libros \
            para niños. Tengo una tercera excusa: esta persona mayor vive en Francia, donde pasa \
            hambre y frío. Verdaderamente necesita consuelo. Si todas esas excusas no bastasen, \
            bien puedo dedicar este libro al niño que una vez fue esta persona mayor. Todos los \
            mayores han sido primero niños. (Pero pocos lo recuerdan). Corrijo, pues, mi dedicatoria";
    i++;
    rc = strlen(str);
    rasm = ft_strlen(str);
    printf("ft_strlen:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
   
   
    i++;
    str = "";
    rc = strlen(str);
    rasm = ft_strlen(str);
    printf("ft_strlen:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
   
   
    i++;
    str = "0123456789";
    rc = strlen(str);
    rasm = ft_strlen(str);
    printf("ft_strlen:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    str = "\0";
    rc = strlen(str);
    rasm = ft_strlen(str);
    printf("ft_strlen:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    str = "0";
    rc = strlen(str);
    rasm = ft_strlen(str);
    printf("ft_strlen:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");

   
   
   
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    s1 = "burro";
    s2 = "burro";
    rc = strcmp(s1, s2);
    rasm = ft_strcmp(s1, s2);
    printf("ft_strcmp:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    s1 = "burro chiquito";
    s2 = "burro grande";
    rc = strcmp(s1, s2);
    rasm = ft_strcmp(s1, s2);
    printf("ft_strcmp:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    s1 = "burro";
    s2 = "burrov";
    rc = strcmp(s1, s2);
    rasm = ft_strcmp(s1, s2);
    printf("ft_strcmp:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    s1 = "burro 2";
    s2 = "burro 1";
    rc = strcmp(s1, s2);
    rasm = ft_strcmp(s1, s2);
    printf("ft_strcmp:%15d %20d %5s test_%d %11s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");
    
    
    i++;
    s1 = "\0";
    s2 = "\0";
    rc = strcmp(s1, s2);
    rasm = ft_strcmp(s1, s2);
    printf("ft_strcmp:%15d %20d %5s test_%d %10s\n", rc, rasm, " ", i, rc == rasm ? "OK" : "KO");

    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    char src[] = "Roma";
    char dest[] = "Ciudad";
    rc_arr = strcpy(dest, src);
    rasm_arr = ft_strcpy(dest, src);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    i++;
    char src1[] = "Chao";
    char dest1[] = "Bonsoir";
    rc_arr = strcpy(dest1, src1);
    rasm_arr = ft_strcpy(dest1, src1);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    i++;
    char src2[] = "";
    char dest2[] = "Hello";
    rc_arr = strcpy(dest2, src2);
    rasm_arr = ft_strcpy(dest2, src2);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    i++;
    char src3[] = "How are you?";
    char dest3[] = "";
    rc_arr = strcpy(dest3, src3);
    rasm_arr = ft_strcpy(dest3, src3);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    i++;
    char src4[] = "Salut";
    char dest4[] = "Bonne apres-midi";
    rc_arr = strcpy(dest4, src4);
    rasm_arr = ft_strcpy(dest4, src4);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    i++;
    char dest5[] = "Pido perdón a los niños por haber dedicado este libro a una persona mayor. \
            Tengo una seria excusa: esta persona mayor es el mejor amigo que tengo en el mundo. \
            Tengo otra excusa: esta persona mayor es capaz de entenderlo todo, hasta los libros \
            para niños. Tengo una tercera excusa: esta persona mayor vive en Francia, donde pasa \
            hambre y frío. Verdaderamente necesita consuelo. Si todas esas excusas no bastasen, \
            bien puedo dedicar este libro al niño que una vez fue esta persona mayor. Todos los \
            mayores han sido primero niños. (Pero pocos lo recuerdan). Corrijo, pues, mi dedicatoria";
    char src5[] = "i";
    rc_arr = strcpy(dest5, src5);
    rasm_arr = ft_strcpy(dest5, src5);
    printf("ft_strcpy:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    char *s = "Hola!";
    rc_arr = strdup(s);
    rasm_arr = ft_strdup(s);
    printf("ft_strdup:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    free(rc_arr);
    free(rasm_arr);
    
    
    i++;
    rc_arr = strdup("");
    rasm_arr = ft_strdup("");
    printf("ft_strdup:%15s %20s %5s test_%d %10s\n", rc_arr, rasm_arr, " ", i, ft_memcmp(rc_arr, rasm_arr, ft_strlen(rc_arr)) == 0 ? "OK" : "KO");
    free(rc_arr);
    free(rasm_arr);

    
    
    printf("%s\n", "------------------------------------------------------------------------\n");
   
    printf("%s\n", "-----------------------WRITE FUNCTION-----------------------------------\n");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(1, "Hello Worldx!\n", 14), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(1, "Hello Worldx!\n", 14), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(-1, "test\n", 5), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(-1, "test\n", 5), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(1, "\te\n", 3), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(1, "\te\n", 3), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(1, "42\n", 3), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(1, "42\n", 3), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(-42, "", 0), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(-42, "", 0), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(1, NULL, 10), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(1, NULL, 10), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(2, "", 1), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(2, "", 1), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(2, (void*)0, 10), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(2, (void*)0, 10), errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
    printf("write return:    %ld | errno num %i : %s\n", write(89, "test\n", 5), errno, strerror(errno));
    errno = 0;
    printf("ft_write return: %ld | errno num %i : %s\n", ft_write(89, "test\n", 5), errno, strerror(errno));


    
    printf("%s\n", "------------------------------------------------------------------------\n");
    
    printf("%s\n", "----------------------- READ FUNCTION-----------------------------------\n");
    i++;
    printf("test_%d\n", i);
    int			fd;
	char		buff_c[851];
	char		buff_asm[851];
	int			ret;
    errno = 0;
	fd = open("test_read.txt", O_RDONLY);
	ret = read(fd, buff_c, 850);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
	close(fd);
    errno = 0;
	fd = open("test_read.txt", O_RDONLY);
	ret = ft_read(fd, buff_asm, 850);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));
	close(fd);

   
   
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
	char		buff1_c[85];
	char		buff1_asm[85];
    errno = 0;
	ret = read(42, buff1_c, 84);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
    errno = 0;
	ret = ft_read(42, buff1_asm, 84);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
	ret = read(-1, buff1_c, 84);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
    errno = 0;
	ret = ft_read(-1, buff1_asm, 84);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));

   
   
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
    errno = 0;
	ret = read(2, buff1_c, -2);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
    errno = 0;
	ret = ft_read(2, buff1_asm, -2);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));
    
    
    
    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    errno = 0;
	char		buff2_c[120];
	char		buff2_asm[120];
    int         fd1;
    printf("test_%d\n", i);
    errno = 0;
    fd1 = open("test_read.txt", O_RDONLY);
	ret = read(fd1, buff2_c, 119);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
    close(fd1);
    errno = 0;
    fd1 = open("test_read.txt", O_RDONLY);
	ret = ft_read(fd1, buff2_asm, 119);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));
    close(fd1);



    printf("%s\n", "------------------------------------------------------------------------");
    i++;
    printf("test_%d\n", i);
	char		buff3_c[42];
	char		buff3_asm[42];
    errno = 0;
	ret = read(1, buff3_c, 41);
	printf("read return:    %d | errno num %i : %s\n", ret, errno, strerror(errno));
    errno = 0;
	ret = ft_read(1, buff3_asm, 41);
	printf("ft_read return: %d | errno num %i : %s\n", ret, errno, strerror(errno));
}

int		main(void)
{
    ft_tests();
    return (0);
}