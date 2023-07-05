/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-maxim.costa [WSL: Ubuntu]
** File description:
** my
*/

#define NUM(x) (x - '0')
#define ASC(x) (x + '0')
#define MIN(x, y) (x > y ? y : x)
#define MAX(x, y) (x > y ? x : y)
#ifndef FOO_H_
    #define FOO_H_
void my_putchar(char c);
void my_putchar_err(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
int my_putstr_err(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
int my_strlen_2d(char **str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
int find_minimum(float a[], int n);
int my_putnbr_base(int nbr, char const *base);
int my_max(int s1, int s2);
int my_min(int s1, int s2);
int my_abs(int val);
void my_strswap(char **str1, char **str2);
void *my_calloc(int type, int r, int size);
void **my_calloc_2d(int type, int size);
char *my_realloc(char *ptr, int size);
void my_exit(int code, char *msg);
char *my_strdup(char *str);
void my_sort_2d(char **arr);
void my_revarr(char *arr[], int n);
char *my_itoa(int value, char *buffer, int base);
int my_atoi(const char *str);
long int my_strtol(char *s, char **endptr);
typedef struct linkedlist_s {
    void *data;
    struct linkedlist_s *next;
} linkedlist_t;
linkedlist_t *lc_create(void *value);
void lc_addf(void *data, linkedlist_t **node);
void lc_addb(void *data, linkedlist_t **node);
void lc_delf(linkedlist_t **list);
void lc_delb(linkedlist_t **list);
void lc_sort(linkedlist_t *list, int (*cmp)(), int ref);
void lc_rev(linkedlist_t **head_ref);
#endif
