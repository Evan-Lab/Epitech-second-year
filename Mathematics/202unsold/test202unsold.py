#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## 201yams
## File description:
## 202unsold
##

import sys
import math

#### HELP USAGE ####

def print_help():
    print("USAGE")
    print("\t./202unsold a b")
    print("DESCRIPTION")
    print("\ta constant computed from past results")
    print("\tb constant computed from past results")
    sys.exit(84)

################################################################

#### CHECK ARGUMENTS ####

def check_args(args):
    if len(args) < 2 or len(args) > 3:
        print("Error: At least two arguments are required.")
        exit(84)
    if len(args) == 2:
        if args[1] != "-h":
            print("Error: Second argument must be -h.")
            exit(84)
        else:
            print_help()
    else:
        try:
            a = int(args[1])
            b = int(args[2])
        except ValueError:
            print_help()

        if a <= 50 or b <= 50:
            print("Error: a and b must be greater than 50.")
            exit(84)

        return a, b


################################################################

#### CALCUL JOINT LAW ####

def joint_law(a, b):
    X_Y = [[0 for _ in range(5)] for _ in range(5)]
    X = [0 for _ in range(5)]
    Y = [0 for _ in range(5)]

    for i in range(5):
        for j in range(5):
            x = 10 * (i + 1)
            y = 10 * (j + 1)
            prob = ((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150))
            X_Y[i][j] = prob
            X[i] += prob
            Y[j] += prob

    return X_Y, X, Y

###############################################################

#### CALCUL Z LAW ####

def z_law(X_Y):
    Z = [0 for _ in range(9)]

    for i in range(5):
        for j in range(5):
            x = 10 * (i + 1)
            y = 10 * (j + 1)
            z = x + y
            index = (z - 20) // 10
            Z[index] += X_Y[i][j]

    return Z

############################################################

#### CALCUL EXPECTED VALUE ####

def expected_value(law):
    ev = 0

    for i, p in enumerate(law):
        ev += (i + 2) * 10 * p

    return ev

################################################################

#### CALCUL VARIANCE ####

def variance(law, ev):
    var = 0

    for i, p in enumerate(law):
        var += ((i + 2) * 10 - ev) ** 2 * p

    return var

################################################################

#### PRINT LAWS AND REST ####

def print_laws(X_Y, X, Y, Z):
    print("--------------------------------------------------------------------------------")
    print("X=10 X=20 X=30 X=40 X=50 Y law")

    for j in range(5):
        print("Y={:2d}".format((j + 1) * 10), end=" ")
        for i in range(5):
            print("{:.3f}".format(X_Y[i][j]), end=" ")
        print("{:.3f}".format(Y[j]))

    print("X law", end=" ")
    for i in range(5):
        print("{:.3f}".format(X[i]), end=" ")
    print("1.000")

    print("--------------------------------------------------------------------------------")
    print("z", end=" ")
    for i in range(9):
        print("{:2d} ".format(20 + i * 10), end="")
    print()

    print("p(Z=z)", end=" ")
    for z in Z:
        print("{:.3f} ".format(z), end="")
    print()

################################################################

#### MAIN FUNCTION ####

def main(args):
    a, b = check_args(args)
    X_Y, X, Y = joint_law(a, b)
    Z = z_law(X_Y)
    print_laws(X_Y, X, Y, Z)
    ev_x = expected_value(X)
    ev_y = expected_value(Y)
    ev_z = expected_value(Z)
    var_x = variance(X, ev_x)
    var_y = variance(Y, ev_y)
    var_z = variance(Z, ev_z)
    print("--------------------------------------------------------------------------------")
    print("expected value of X: {:.1f}".format(ev_x - 10))
    print("variance of X: {:.1f}".format(var_x))
    print("expected value of Y: {:.1f}".format(ev_y - 10))
    print("variance of Y: {:.1f}".format(var_y))
    print("expected value of Z: {:.1f}".format(ev_z))
    print("variance of Z: {:.1f}".format(var_z))
    print("--------------------------------------------------------------------------------")
if __name__ == '__main__':
    main(sys.argv)
