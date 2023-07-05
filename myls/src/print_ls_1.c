/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** print_ls_1
*/

#include "my_ls.h"
#include "my_printf.h"

int type_file(struct stat fileStat)
{
    switch ( fileStat.st_mode & S_IFMT) {
        case S_IFBLK: return 'b';
        case S_IFCHR: return 'c';
        case S_IFDIR: return 'd';
        case S_IFIFO: return 'p';
        case S_IFLNK: return 'l';
        case S_IFSOCK: return 's';
        default: return '-';
    }
}

int print_perms(struct stat fileStat)
{
    my_printf("%c",type_file(fileStat));
    char str[] = "---------";
    str[0] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    str[1] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    str[2] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    if (fileStat.st_mode & S_ISUID)
        str[2] = str[2] == 'x' ? 's' : 'S';
    str[3] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    str[4] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    str[5] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    if (fileStat.st_mode & S_ISUID)
        str[5] = str[5] == 'x' ? 's' : 'S';
    str[6] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    str[7] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    str[8] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    if (fileStat.st_mode & S_ISUID)
        str[8] =  str[8] == 'x' ? 't' : 'T';
    my_printf("%s", str);
    return 0;
}

int print_nlink(struct stat fileStat)
{
    my_printf(" %lu ",fileStat.st_nlink);
    return 0;
}

int print_users(struct stat fileStat)
{
    struct passwd *pw;
    pw = getpwuid(fileStat.st_uid);
    my_printf("%s ", pw->pw_name);
    return 0;
}

void help_print(void)
{
    my_printf("Usage: ./my_ls -[OPTION]... [FILE]...\n");
    my_printf("Option are : \n");
    my_printf("\tl : Long listing format\n");
    my_printf("\tr : reverse order while sorting\n");
    my_printf("\tt : sort by modification time, newest first\n");
    my_printf("\tR : list subdirectories recursively\n");
    my_printf("\td : list directories themselves, not their contents\n");
    my_printf("\ta : list hidden file\n");
    my_printf("\th : diplay help\n");
    exit(SUCESS);
}
