/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:54:28 by asebaai           #+#    #+#             */
/*   Updated: 2024/07/24 15:01:13 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_processing(t_apa *pipex, int i)
{
	if (!i)
	{
		check_infile(pipex);
		find_cmd(pipex, i);
	}
	else
	{
		check_outfile(pipex);
		find_cmd(pipex, i);
	}
}

void	ft_process(t_apa *pipex, int i)
{
	pipex->pid[i] = fork();
	if (pipex->pid[i] < 0)
		exit(20);
	if (!pipex->pid[i])
	{
		ft_processing(pipex, i);
		execve(pipex->cmd, pipex->cmd_args, pipex->envp);
		perror(pipex->cmd);
		ft_free(pipex->paths);
		ft_free(pipex->cmd_args);
		if (!pipex->flag)
			free(pipex->cmd);
		exit(126);
	}
	else
	{
		dup2(pipex->fd[0], 0);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
	}
}

void	get_cmd_paths(t_apa *pipex)
{
	int	i;

	i = 0;
	pipex->paths = NULL;
	if (!pipex->envp && !pipex->envp[0])
		return ;
	while (pipex->envp[i])
	{
		if (!ft_strncmp(pipex->envp[i], "PATH=", 5))
		{
			pipex->paths = ft_split(pipex->envp[i], ':');
			break ;
		}
		i++;
	}
}

void	get_start(t_apa *pipex)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		pipe(pipex->fd);
		ft_process(pipex, i);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_apa	pipex;
	int		i;

	i = 0;
	pipex.envp = envp;
	pipex.av = av;
	pipex.cmd_args = NULL;
	pipex.cmd = NULL;
	pipex.paths = NULL;
	pipex.flag = 0;
	if (ac != 5)
		return (werror("ARGS not enough ajmi! \n"));
	get_cmd_paths(&pipex);
	get_start(&pipex);
	while (i < 2)
	{
		waitpid(pipex.pid[i], &pipex.status, 0);
		i++;
	}
	close(pipex.infile);
	close(pipex.outfile);
	ft_free(pipex.paths);
	exit(WEXITSTATUS(pipex.status));
}
