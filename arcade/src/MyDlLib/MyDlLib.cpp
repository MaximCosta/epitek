/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** MyDl cpp
*/

#include "MyDlLib.hpp"

namespace arcade
{
    MyDlLib::MyDlLib()
    {
    }

    void *MyDlLib::MyDlOpen(const char *filename, int flag)
    {
        void *handle = dlopen(filename, flag);

        if (!handle) {
            throw std::runtime_error("Error opening shared library");
        }
        return (handle);
    }

    void *MyDlLib::MyDlSym(void *handle, const char *symbol)
    {
        void *sym = dlsym(handle, symbol);

        if (!sym) {
            throw std::runtime_error("Error finding symbol");
        }
        return (sym);
    }

    void MyDlLib::MyDlClose(void *handle)
    {
        dlclose(handle);
    }

    std::string MyDlLib::MyDlError()
    {
        return (dlerror());
    }

    MyDlLib::~MyDlLib()
    {
    }
}
