/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:47:58 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/04/02 11:21:31 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
  * Verifica si un caracter es una letra, ya sea mayúscula o minúscula.
  * @param c el caracter como int.
  * @returns 0 si no es una letra. Cualquier otro número si lo es.
  */
int		ft_isalpha(int c);

/**
  * Verifica si un caracter es un número.
  * @param c el caracter como int.
  * @returns 0 si no es un número. Cualquier otro número si lo es.
  */
int		ft_isdigit(int c);

/**
  * Verifica si un caracter es una letra o un número.
  * @param c el caracter como int.
  * @returns 0 si no es un número o letra. Cualquier otro número si lo es.
  */
int		ft_isalnum(int c);

/**
  * Verifica si c es un unsigned char (7 bits) que pertenece a la tabla
  * ASCII de caracteres.
  * @param c caracter a verificar.
  * @returns 0 si no pertenece a la tabla ASCII. Cualquier otro número
  * si lo cumple.
  */
int		ft_isascii(int c);

/**
  * Los caracteres imprimibles son un subconjunto de la tabla ASCII.
  * Esta función verifica si el entero recibido es un caracter imprimible
  * de la tabla ASCII.
  * @param c Entero para verificar si es imprimible.
  * @returns 0 si no lo cumple. Cualquier otro número si lo cumple.
  */
int		ft_isprint(int c);

/**
  * Calcula el tamaño de un string.
  * @param str el string a procesar.
  * @returns el tamaño del string.
  */
size_t	ft_strlen(const char *str);

/**
  * Rellena los primero n bytes de un area de memoria con el valor
  * especificado.
  * La función modifica el contenido del puntero y también la devuelve.
  * @param b El bloque de memoria a rellenar.
  * @param c El valor que se quiere asignar.
  * @param len El nº de bytes que se quieren rellenar.
  * @returns Un puntero al principio de la misma posición 
  * de memoria que se pasa por parámetros.
  */
void	*ft_memset(void *b, int c, size_t len);

/**
  * Rellena los primeros n bytes de un bloque de memoria a 0.
  * La función modifica el contenido del puntero y también lo devuelve,
  * por si acaso.
  * @param s El bloque de memoria a rellenar.
  * @param n El nº de bytes que se quieren rellenar a 0.
  * @returns Un puntero al principio de la misma posición
  * de memoria que se pasa por parámetros.
  */
void	ft_bzero(void *s, size_t n);

/**
  * Copia n bytes de un bloque de memoria, src, a otro bloque
  * de memoria, dst. Los bloques de memoria no se pueden solapar. 
  * Usa memmove si se solapan. :)
  * @param dst bloque de memoria donde se ponen los bytes.
  * @param src bloque de memoria del cual se copian los bytes.
  * @param n nº de bytes a copiar.
  * @returns un puntero al principio de dst por si acaso.
  */
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif
