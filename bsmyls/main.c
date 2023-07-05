/*
** EPITECH PROJECT, 2021
** bootstrap-my_ls-maxim.costa [WSL: Ubuntu]
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void my_printf(char *buf, ...);

char *parse_file(char const *path)
{
    char *save = (char*)path;

    while (*path)
        if (*path++ == '/')
            save = (char*)path;
    return save;
}

int type_file(struct stat fileStat)
{
    if (S_ISCHR(fileStat.st_mode))
        return 'c';
    if (S_ISDIR(fileStat.st_mode))
        return 'd';
    if (S_ISBLK(fileStat.st_mode))
        return 'l';
    return 'f';
}

void major_minor(struct stat fileStat)
{
    if (S_ISCHR(fileStat.st_mode) || S_ISBLK(fileStat.st_mode)) {
        my_printf("Minor: %lx\n", ((fileStat.st_dev >> 8) & 0x7F));
        my_printf("Major: %lx\n", (fileStat.st_dev & 0xFF));
    } else {
        my_printf("Minor: N/A\n");
        my_printf("Major: N/A\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        my_printf("File not found");
        return 84;
    }

    my_printf("Name: %s\n", parse_file(argv[1]));
    my_printf("Type: %c\n", type_file(fileStat));
    my_printf("Inode: %ld\n", fileStat.st_ino);
    my_printf("Hard Link: %ld\n", fileStat.st_nlink);
    my_printf("size: %ld\n", fileStat.st_size);
    my_printf("Allocated space: %lu\n", fileStat.st_blocks * fileStat.st_blksize);
    major_minor(fileStat);
    my_printf("UID: %d\n", fileStat.st_uid);
    my_printf("GID: %d\n", fileStat.st_gid);
    return 0;
}