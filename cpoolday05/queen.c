/*
** EPITECH PROJECT, 2021
** queen
** File description:
** get all pose of queen
*/

int can_be_her(int ver[4][30], int y, int x, int n)
{
    int a = ver[0][y - x + n - 1] != 1;
    int b = ver[1][y + x] != 1;
    int c = ver[2][y] != 1;

    return (a && b) && c;
}

void update_arr_one_safe(int ver[4][30], int y, int x, int n)
{
    ver[0][y - x + n - 1] = 1;
    ver[1][y + x] = 1;
    ver[2][y] = 1;
}

void update_arr_zero_safe(int ver[4][30], int y, int x, int n)
{
    ver[0][y - x + n - 1] = 0;
    ver[1][y + x] = 0;
    ver[2][y] = 0;
}

int queen_backtracking(int n, int board[n][n], int x, int ver[4][30])
{
    if (x >= n)
        return 1;
    for (int y = 0; y < n; y++) {
        if (can_be_her(ver, y, x, n)) {
            board[y][x] = 1;
            update_arr_one_safe(ver, y, x, n);
            ver[3][0] += queen_backtracking(n, board, x+1, ver);
            board[y][x] = 0;
            update_arr_zero_safe(ver, y, x, n);
        }
    }
    return 0;
}

int count_valid_queens_placements(int n)
{
    int ver[4][30] = { 0 };
    int board[n][n];

    queen_backtracking(n, board, 0, ver);
    return ver[3][0];
}
