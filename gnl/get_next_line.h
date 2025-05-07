#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * Gets the next line from a file descriptor
 * @param fd The file descriptor to read from
 * @return The next line from the file descriptor
 */
char	*get_next_line(int fd);

/**
 * Returns the length of a string
 * @param str The string to measure
 * @return The length of the string
 */
size_t	ft_strlen(const char *str);

/**
 * Locates the first occurrence of c in the string s
 * @param s The string to search in
 * @param c The character to search for
 * @return A pointer to the first occurrence of c in s, or NULL if not found
 */
char	*ft_strchr(const char *s, int c);

/**
 * Joins two strings together
 * @param s1 The first string
 * @param s2 The second string
 * @return The joined string
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * Allocates memory with error handling
 * @param size The size to allocate
 * @return A pointer to the allocated memory
 */
void	*ft_malloc(size_t size);

#endif