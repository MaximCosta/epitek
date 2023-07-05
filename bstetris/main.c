/*
** EPITECH PROJECT, 2022
** Make_fast
** File description:
** main
*/

#include "include/my.h"

typedef struct my_map
{
	char *piece;
	int n1;
	int n2;
	int color;
	char n_ter;
	int error;
} maps_s;

void checker_filer(maps_s *tetris)
{
	int a = 0;

	for (int i = 0; tetris->piece[i]; i++)
		if (tetris->piece[i] == '*')
			a++;
	if (a == 0)
		tetris->error = 84;
}

void checker_file(char *filepath, maps_s *tetris)
{
	struct stat sb;
	tetris->piece = NULL;

	stat(filepath, &sb);
	tetris->piece = malloc(sb.st_size + 1);
	tetris->piece[sb.st_size] = '\0';
	read(open(filepath, O_RDONLY), tetris->piece, sb.st_size);
	checker_filer(tetris);
	tetris->n_ter = filepath[0];
}

void parse_file(maps_s *tetris)
{
	int e = 0;

	for (int i = 0; tetris->piece[i] != '\n'; i++)
		if (tetris->piece[i] <= '9' && tetris->piece[i] >= '0') {
			if (e == 0) {
				tetris->n1 = atoi(&tetris->piece[i]);
				e++;
			}
			else if (e == 1) {
				tetris->n2 = atoi(&tetris->piece[i]);
				e++;
			}
			else
				tetris->color = atoi(&tetris->piece[i]);
		}
}

int main(int argc, char **argv)
{
	maps_s *tetris = malloc(sizeof(maps_s));

	if (argc != 2)
		return 84;
	checker_file(argv[1], tetris);
	if (tetris->error != 0) {
		printf("Tetriminos '%c': error$", tetris->n_ter);
		return 0;
	}
	parse_file(tetris);
	printf("Tetriminos '%c': size %d*%d, color %d\n", tetris->n_ter, tetris->n1, tetris->n2, tetris->color);
	return 0;
}
