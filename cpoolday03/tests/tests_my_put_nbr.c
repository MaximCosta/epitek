/*
** EPITECH PROJECT, 2021
** tests/tests_my_put_nbr
** File description:
** Test file
*/

void my_put_nbr(int c);

int main(void) 
{
    my_put_nbr(2147483647);
    my_put_nbr(-2147483648);
    my_put_nbr(-21);
    my_put_nbr(21);
    my_put_nbr(0);
    return 0;
}
