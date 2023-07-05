/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** print_ls_2
*/

#include "my_ls.h"
#include "my_printf.h"

int total_print(option_t opt, int i, int *child)
{
    DIR *dp;
    struct stat sb;
    struct dirent *drt;
    int tot = 0;

    *child = 0;
    if ((dp = opendir(opt.fcol[i].path)) == NULL) error();
    while ((drt = readdir(dp)) != NULL) {
        (*child)++;
        if ((lstat(concat_str(opt.fcol[i].path, drt->d_name), &sb)) == 0)
            tot += (opt.a || drt->d_name[0] != '.') ? sb.st_blocks : 0;
    }
    if (opt.l)
        my_printf("total %d\n", tot / 2);
    closedir(dp);
    return 0;
}

int print_group(struct stat fileStat)
{
    struct group *pw;
    pw = getgrgid(fileStat.st_gid);
    my_printf("%s ", pw->gr_name);
    return 0;
}

int print_sizes(struct stat fileStat)
{
    if (S_ISCHR(fileStat.st_mode) || S_ISBLK(fileStat.st_mode)) {
        my_printf("%ld, ", (fileStat.st_rdev >> 8) & 0x7F);
        my_printf("%ld ", fileStat.st_rdev & 0x7F);
    }
    else
        my_printf("%ld ", fileStat.st_size);
    return 0;
}

int print_mtime(struct stat fileStat)
{
    write(1, ctime(&fileStat.st_mtime)+4, 12);
    return 0;
}

int print_iflink(struct stat fileStat, char const *pathname)
{
    char buf[255] = {0};

    if (S_ISLNK(fileStat.st_mode)) {
        readlink(pathname, buf, 255);
        my_printf(" -> %s", buf);
    }
    return 0;
}
