/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:19:01 by gdel-giu          #+#    #+#             */
/*   Updated: 2023/05/10 08:55:52 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/program.h"

// chiudi e libera

void	close_game(t_cub *cub, char *mex)
{
	int i;

	if (!cub->mlx)
		exit(1);
	if (!cub->win)
		exit(1);
	mlx_destroy_window(cub->mlx, cub->win);
	freematrix(cub->map, row_counter(cub->map));
	freematrix(cub->mat_tmp, row_counter(cub->mat_tmp));
	if (cub->str_tmp)
		free(cub->str_tmp);
	if (!cub->data)
		exit(1);
	free(cub->data);
	i = 0;
	while (i < 4)
		if (cub->wall_imgs_addrs[i++])
			free(cub->wall_imgs_addrs[i - 1]);
	fprintf(stderr, "\033[0;32m Quitting Cube: %s\033[0;37m\n", mex);
	exit(0);
}

// exit call per l'hook

int	exit_call(t_cub *cub)
{
	close_game(cub, "Closed program");
	return (0);
}

// inizzializza array statici

void	init_statics(t_cub *cub)
{
	int i;

	i = 0;
	while (i < 5)
		cub->wall_imgs_addrs[i++] = NULL;
	i = 0;
	while (i < 4)
		cub->wall_imgs[i++] = NULL;
	cub->mat_tmp = NULL;
	cub->str_tmp = NULL;
}

// inizializza le variabili mlx

int game_init(t_cub *cub)
{
	t_data	*d;

	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (0);
	cub->win = mlx_new_window(cub->mlx, WIN_SIZE_W, WIN_SIZE_H, "cub3d");
	if (!cub->win)
		return (0);
	d = (t_data *) ft_calloc(sizeof(t_data), 1);
	if (!d)
		return (0);
	cub->data = d;
	init_statics(cub);
	return (1);
}

// main

int main(int argc, char **argv)
{
	t_cub	cub;

	if (argc < 2)
		return (1);
	if (!game_init(&cub))
		close_game(&cub, "\033[1;31mInit error");
	if (!parse_map(&cub, argv[1]))
		close_game(&cub, "\033[1;31mParse Error");
	render(&cub);
	mlx_hook(cub.win, 17, 0, exit_call, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
