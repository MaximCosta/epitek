#!/bin/bash

rougefonce='\e[0;31m'
vertfonce='\e[0;32m'
bleufonce='\e[0;33m'
neutre='\e[0;m'

nb=0

print_perc() {
    SIZE1=$(stat -c%s ${1})
    SIZE2=$(stat -c%s ${2})
    PERC=$(bc <<< "scale=2; ($SIZE2 - $SIZE1)/$SIZE1 * 100")
    echo "with $PERC % compression"
}

make_test() {
    echo -ne "${1}" | ./mysh &> ../res_mysh
    echo -ne "${1}" | tcsh &> ../res_tcsh
    sort ../res_mysh > ../res_mysh2
    sort ../res_tcsh > ../res_tcsh2
    Test=$(diff ../res_mysh2 ../res_tcsh2)
    if [ "$Test" = "" ]
            then
                echo -ne "${vertfonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${vertfonce} OK${neutre}\n"
            else
                echo -ne "${rougefonce}TEST ${nb} = ${neutre}"
                echo -n "[${1}]"
                echo -ne "${rougefonce} KO${neutre}\n"
            fi
    let 'nb=nb+1'
}

#make && make clean

echo -e "${bleufonce}1 - MINISHELL1${neutre}\n"
make_test "\n"
make_test "exit"
make_test "../my_segfault"
make_test "ls"
make_test "azedc"
make_test "pwd"
make_test "ls -l"
make_test "./mysh"
make_test "setenv patate"
make_test "setenv patate pat"
make_test "setenv patate\nunsetenv patate"
make_test "unsetenv pwd"
make_test "setenv coucou="
make_test "setenv hey_"
make_test "cd\npwd"
make_test "cd/npwd"
make_test "cd zesdrfgthvf"
make_test "cd main.c"
make_test "cd include"
make_test " ls\t\t-l"
make_test "\t\tpwd\n \t\tcd\npwd"
make_test "  \tpwd\t \ncd\t    \n ls"
make_test "pwd\t\tcd      pwd\t\n"
make_test "ls -l"
make_test "./prog_with_divZero"
make_test "../directory"
make_test "./thbv"
make_test "cd ../\n cd ../\n cd -\n"
