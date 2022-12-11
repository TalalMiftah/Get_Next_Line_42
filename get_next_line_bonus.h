#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*ft_rhyme(char *str);
char	*next_rhyme(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		find_break(char *str);
char	*ft_join(char *s1, char *s2);

#endif
