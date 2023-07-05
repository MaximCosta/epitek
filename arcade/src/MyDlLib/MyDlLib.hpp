/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** MyDl hpp
*/

#ifndef MYDLLIBHEADER
#define MYDLLIBHEADER

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <stdexcept>
#include <dlfcn.h>
#include <stdexcept>
#include <vector>
#include <utility>

namespace arcade
{
    class MyDlLib {
        public:
            MyDlLib();
            ~MyDlLib();

            void *MyDlOpen(const char *filename, int flag);
            void *MyDlSym(void *handle, const char *symbol);
            void MyDlClose(void *handle);
            std::string MyDlError();

        protected:
        private:
    };
}

#endif /* !MYDLLIBHEADER */
