/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:37:06 by asebaai           #+#    #+#             */
/*   Updated: 2024/07/24 14:54:25 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
void	get_cmd(t_apa *pipex)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	i = 0;
	while (pipex->paths && pipex->paths[i])
	{
		tmp1 = ft_strjoin(pipex->paths[i], "/");
		tmp = ft_strjoin(tmp1, pipex->cmd_args[0]);
		free(tmp1);
		if (!access(tmp, F_OK & X_OK))
		{
			pipex->cmd = tmp;
			return ;
		}
		free(tmp);
		i++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(127);
}

void	p_werror(char **err, int flag)
{
	if (flag)
	{
		perror(err[4]);
		exit(1);
	}
	else
	{
		perror(err[1]);
		exit(1);
	}
}

void	check_infile(t_apa *pipex)
{
	pipex->infile = open(pipex->av[1], O_RDONLY);
	if (pipex->infile < 0)
		p_werror(pipex->av, 0);
	else
	{
		dup2(pipex->infile, 0);
		dup2(pipex->fd[1], 1);
		close(pipex->infile);
	}
}

char	**get_args(char *cmd)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(cmd, ' ');
	return (args);
}
