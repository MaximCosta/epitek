/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** main
*/

#include "my_ls.h"
#include "my_printf.h"

int print_info(files_t child_)
{
    print_perms(child_.st);
    print_nlink(child_.st);
    print_users(child_.st);
    print_group(child_.st);
    print_sizes(child_.st);
    print_mtime(child_.st);
    my_printf(" %s", child_.filename);
    print_iflink(child_.st, child_.flpath);
    my_printf("\n");
    return 0;
}

void get_all_folder(option_t opt, files_t *child_)
{
    struct dirent *dir;
    int i;

    for (i = 0; (dir = readdir(opt.fcol[opt.index].dp)) != NULL; i++) {
        child_[i].filename = dir->d_name;
        child_[i].path = opt.fcol[opt.index].path;
        child_[i].flpath = concat_str(opt.fcol[opt.index].path, dir->d_name);
        lstat(child_[i].flpath, &child_[i].st);
    }
    if (opt.t) sort_time(child_, i);
    if (opt.r) revarr_t(child_, i);
}

void browser_folder(option_t opt)
{
    files_t *child_;

    total_print(opt, opt.index, &opt.count);
    child_ = my_calloc(sizeof(files_t), 0,  opt.count);
    get_all_folder(opt, child_);
    for (int j = 0; j < opt.count; j++) {
        if (!opt.a && child_[j].filename[0] == '.')
            continue;
        if (opt.l)
            print_info(child_[j]);
        if (!opt.l && (opt.a || child_[j].filename[0] != '.'))
            my_printf("%s\n", child_[j].filename);
    }
    if (closedir(opt.fcol[opt.index].dp) == -1)
        perror("closedir");
    free(child_);
}

int print_ls_for(option_t opt)
{
    for (int i = 0; i < opt.f[2]; i++) {
        my_printf("ls: cannot access '%s'", opt.error[i]);
        my_printf(": No such file or directory\n");
    }
    for (int i = 0; i < opt.f[1]; i++)
        if (opt.l) print_info(opt.fcil[i]);
        else my_printf("%s\n", opt.fcil[i].flpath);
    for (opt.index = 0; opt.index < opt.f[0]; opt.index++, errno = 0) {
        if (opt.index != 0) my_printf("\n");
        if (opt.f[0] > 1) my_printf("%s:\n", opt.fcol[opt.index].path);
        browser_folder(opt);
    }
    return 0;
}

int main(int ac, char *av[])
{
    option_t opt = { 0 };

    opt.fcol = (folder_t *)my_calloc_2d(sizeof(folder_t), ac + 1);
    opt.fcil = (files_t *)my_calloc_2d(sizeof(files_t), ac + 1);
    opt.error = (char **)my_calloc_2d(sizeof(char *), ac + 1);
    opt.f = (int *)my_calloc(sizeof(int), 0, 3);
    option_stat(av, &(opt));
    if (opt.h) help_print();
    if (opt.f[0] == 0 && opt.f[1] == 0 && opt.f[2] == 0) {
        opt.fcol[0].dp = opendir(".");
        opt.fcol[0].path = ".";
        opt.f[0]++;
    }
    print_ls_for(opt);
    return 0;
}
