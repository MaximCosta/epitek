#!/usr/bin/env python3
##
# EPITECH PROJECT, 2021
# 104intersection
# File description:
# 104intersection.py
##

import sys
import math


def closed(expr1, expr2, tol):
    return abs(expr1 - expr2) <= tol


def is_sphere(rayon, rayon_p, rayon_v):
    expr1 = rayon_v[0]**2 + rayon_v[1]**2 + rayon_v[2]**2
    expr2 = 2 * (rayon_p[0] * rayon_v[0] + rayon_p[1]
                 * rayon_v[1] + rayon_p[2] * rayon_v[2])
    expr3 = rayon_p[0]**2 + rayon_p[1]**2 + rayon_p[2]**2 - rayon**2
    return expr1, expr2, expr3, 'Sphere of radius {}'.format(rayon)


def is_cylinder(rayon, rayon_p, rayon_v):
    expr1 = rayon_v[0]**2 + rayon_v[1]**2
    expr2 = 2 * (rayon_p[0] * rayon_v[0] + rayon_p[1] * rayon_v[1])
    expr3 = rayon_p[0]**2 + rayon_p[1]**2 - rayon**2
    return expr1, expr2, expr3, 'Cylinder of radius {}'.format(rayon)


def is_cone(angle, rayon_p, rayon_v):
    tengante = math.tan(math.radians(angle))**2
    expr1 = rayon_p[0]**2 + rayon_v[1]**2 - rayon_v[2]**2 * tengante
    expr2 = 2 * (rayon_p[0] * rayon_v[0] + rayon_p[1] * rayon_v[1] - tengante*rayon_p[2] * rayon_v[2])
    expr3 = rayon_p[0]**2 + rayon_p[1]**2 - rayon_p[2]**2 * tengante
    return expr1, expr2, expr3, 'Cone with a {} degree angle'.format(angle)


def calculator(expr1, expr2, expr3):
    if closed(expr1, 0, 1e-7) \
            and closed(expr2, 0, 1e-7) \
            and closed(expr3, 0, 1e-7):
        return []
    elif closed(expr1, 0, 1e-7):
        if closed(expr2, 0, 1e-7):
            return None
        else:
            return [-expr3 / expr2]
    else:
        expr4 = expr2**2 - 4 * expr1 * expr3
        if closed(expr4, 0, 1e-7):
            return [-expr2 / (2*expr1)]
        elif expr4 < 0:
            return None
        elif expr4 > 0:
            return [(-expr2 + math.sqrt(expr4)) / (2*expr1), (-expr2 - math.sqrt(expr4)) / (2*expr1)]


def main(ac):
    if len(sys.argv) == 0: 
        return 84
    if sys.argv[1] == '-h':
        print('USAGE')
        print('    ./104intersection opt xp yp zp xv yv zv p\n')
        print('DESCRIPTION')
        print('    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone')
        print('    (xp, yp, zp)    coordinates of a point by which the light ray passes through')
        print('    (xv, yv, zv)     coordinates of a vector parallel to the light ray')
        print('    p               parameter: radius of the sphere, radius of the cylinder, or ')
        print('                    angle formed by the cone and the Z-axis')
    if len(sys.argv) != 9:
        return 84
    opt = -1
    parameter = 0
    rayon_p = (0, 0, 0)
    rayon_v = (0, 0, 0)
    try:
        opt = int(ac[1])
        rayon_p = (int(ac[2]), int(ac[3]), int(ac[4]))
        rayon_v = (int(ac[5]), int(ac[6]), int(ac[7]))
        parameter = int(ac[8])

    except ValueError:
        print('error: invalid non-integer parameter', file=sys.stderr)
        return 84
    if rayon_v == (0, 0, 0):
        print('error: null vector', file=sys.stderr)
        return 84
    if opt not in [1, 2, 3]:
        print('error: invalid opt parameter (1, 2 or 3 only)', file=sys.stderr)
        return 84
    if opt in [1, 2] and parameter <= 0:
        print('error: invalid radius (must be > 0)', file=sys.stderr)
        return 84
    if opt == 3 and not -90 <= parameter <= 90:
        print('error: invalid angle [-90; 90]', file=sys.stderr)
        return 84
    expr1, expr2, expr3, message = [
        is_sphere, is_cylinder, is_cone][opt - 1](parameter, rayon_p, rayon_v)
    print(message)
    print('Line passing trough the point ({}, {}, {})'.format(*rayon_p), end=' ')
    print('and parallel to the vector ({}, {}, {})'.format(*rayon_v))
    total = calculator(expr1, expr2, expr3)
    if total == None:
        print('No intersection point.')
    elif total == []:
        print('There is an infinite number of intersection points.')
    else:
        print(len(total), 'intersection', 'point:' if len(
            total) == 1 else 'points:')
        for k in total:
            print('({:.3f}, {:.3f}, {:.3f})'.format(rayon_p[0] + k * rayon_v[0],
                                                    rayon_p[1] + k * rayon_v[1], rayon_p[2] + k * rayon_v[2]))
    return 0
