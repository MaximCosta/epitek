/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 03
*/

#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include "../array.h"
#include "../char.h"
#include "../float.h"
#include "../int.h"
#include "../new.h"
#include "../player.h"
#include "../point.h"
#include "../vertex.h"
#include "../list.h"

Test(tests, test_player) {
    Object *player = new (Player);
}

Test(tests, test_point) {
    Object *point = new (Point, 10, 20);
    str(point);

    delete (point);
}

Test(tests, test_vertex) {
    Object *vertex = new (Vertex, 10, 20, 30);
    Object *vertex2 = new (Vertex, 10, 20, 30);

    str(vertex);
    str(vertex2);
    str(addition(vertex, vertex2));
    str(subtraction(vertex, vertex2));
    delete (vertex2);
    delete (vertex);
}

Test(tests, test_int) {
    Object *i = new (Int, 10);
    Object *i2 = new (Int, 20);

    str (addition (i, i2));
    str (subtraction (i, i2));
    str (multiplication (i, i2));
    str (division (i, i2));

    cr_assert_eq(eq(i, i2), 0);
    cr_assert_eq(eq(i, i), 1);

    cr_assert_eq(gt(i, i2), 0);
    cr_assert_eq(gt(i2, i), 1);

    cr_assert_eq(lt(i, i2), 1);
    cr_assert_eq(lt(i2, i), 0);

    delete (i2);
    delete (i);
}

Test(tests, test_float) {
    Object *f = new (Float, 10.5);
    Object *f2 = new (Float, 20.5);

    str (addition (f, f2));
    str (subtraction (f, f2));
    str (multiplication (f, f2));
    str (division (f, f2));

    cr_assert_eq(eq(f, f2), 0);
    cr_assert_eq(eq(f, f), 1);

    cr_assert_eq(gt(f, f2), 0);
    cr_assert_eq(gt(f2, f), 1);

    cr_assert_eq(lt(f, f2), 1);
    cr_assert_eq(lt(f2, f), 0);

    delete (f2);
    delete (f);
}

Test(tests, test_char) {
    Object *c = new (Char, 'a');
    Object *c2 = new (Char, 'b');

    str (addition (c, c2));
    str (subtraction (c, c2));
    str (multiplication (c, c2));
    str (division (c, c2));

    cr_assert_eq(eq(c, c2), 0);
    cr_assert_eq(eq(c, c), 1);

    cr_assert_eq(gt(c, c2), 0);
    cr_assert_eq(gt(c2, c), 1);

    cr_assert_eq(lt(c, c2), 1);
    cr_assert_eq(lt(c2, c), 0);

    delete (c2);
    delete (c);
}

Test(tests, test_array) {
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    delete(it);
    delete(it_end);
    delete(array);
}

Test(tests, test_list) {
    Object *list = new (List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    printf("list size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);
    setval(it, 12);
    while (getval(it) != NULL) {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    eq(it, it_end);
    getitem(list, 5);
    delete (it);
    delete (it_end);
    delete (list);
}
