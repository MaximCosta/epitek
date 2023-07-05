/*
** EPITECH PROJECT, 2021
** Test
** File description:
** For test functions
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_to_word_array, convert_str_in_array)
{
    char str[] = "Bonjour\ncoucou\tbisous";
    char str2[] = "Bonjour\n\ncoucou\n\t\nbisous";
    char str3[] = "\t$";
    char str4[] = "";
    char str6[] = ",,,,,,,,,,,,,,,,,,,,,,,,,,Hello";
    char str5[] = "$£^¨*_(hello')=-$";
    char str7[] = ",:'(-è;:(,è$$££:;('=+=}";
    char str1[][8] = {"Bonjour", "coucou", "bisous"};
    char **array = my_str_to_word_array(str);
    char **array2 = my_str_to_word_array(str2);
    char **array3 = my_str_to_word_array(str3);
    char **array4 = my_str_to_word_array(str4);
    char **array5 = my_str_to_word_array(str5);
    char **array6 = my_str_to_word_array(str6);
    char **array7 = my_str_to_word_array(str7);
    char **array8 = my_str_to_word_array(NULL);

    for (int i = 0; i < 3; i++) {
        cr_assert_str_eq(array[i], str1[i]);
        cr_assert_str_eq(array2[i], str1[i]);
    }
    cr_assert_null(array3[0]);
    cr_assert_null(array4[0]);
    cr_assert_str_eq(array5[0], "hello");
    cr_assert_null(array5[1]);
    cr_assert_null(array7[0]);
    cr_assert_null(array8);
    cr_assert_str_eq(array6[0], "Hello");
}
