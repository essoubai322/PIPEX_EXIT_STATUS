/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:38:32 by asebaai           #+#    #+#             */
/*   Updated: 2024/07/26 16:17:25 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	found_slash(char *str)
{
	while (str && *str && *str != '/' && str++)
		;
	if (!(*str))
		return (0);
	return (1);
}

void	find_lite(t_apa *pipex, int i)
{
	if (open(pipex->av[i + 2], __O_DIRECTORY) >= 0)
	{
		ft_putstr_fd("Is a directory\n", 2);
		ft_free(pipex->paths);
		ft_free(pipex->cmd_args);
		exit(126);
	}
}

void	find_cmd(t_apa *pipex, int i)
{
	pipex->cmd_args = get_args(pipex->av[i + 2]);
	if (!pipex->cmd_args)
	{
		ft_free(pipex->paths);
		exit(20);
	}
	if (found_slash(pipex->av[i + 2]))
	{
		pipex->cmd = pipex->cmd_args[0];
		pipex->flag = 1;
		return ;
	}
	find_lite(pipex, i);
	if (!access(pipex->av[i + 2], X_OK))
	{
		pipex->cmd = pipex->cmd_args[0];
		pipex->flag = 1;
		return ;
	}
	get_cmd(pipex);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (free(str));
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_outfile(t_apa *pipex)
{
	pipex->outfile = open(pipex->av[pipex->ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		p_werror(pipex->av, 1);
	else
	{
		dup2(pipex->outfile, 1);
		close(pipex->outfile);
		close(pipex->fd[1]);
		close(pipex->fd[0]);
	}
}
