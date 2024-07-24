#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_apa
{
	char	*cmd;
	char	**paths;
	int		pid[2];
	int		infile;
	int		outfile;
	char	**envp;
	char	**av;
	char	**cmd_args;
	int		fd[2];
	int		status;
	int		flag;
}			t_apa;

// void	p_werror(char **err, int flag);

void		ft_putstr_fd(char *s, int fd);
int			werror(char *err);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		check_infile(t_apa *pipex);
char		**get_args(char *cmd);
void		find_cmd(t_apa *pipex, int i);
void		ft_free(char **str);
void		check_outfile(t_apa *pipex);
void		ft_process(t_apa *pipex, int i);
void		get_cmd_paths(t_apa *pipex);
void		get_cmd(t_apa *pipex);
void		p_werror(char **err, int flag);
void		find_lite(t_apa *pipex, int i);
void		ft_bzero(void *s, size_t n);

#endif