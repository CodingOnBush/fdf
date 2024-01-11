int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	void	*mlx; //display
	void	*mlx_win; //window
	t_data	image; //image

	mlx = mlx_init(); //display init
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //window init
	image.img = mlx_new_image(mlx, 1920, 1080); //image init
	return (0);
}
