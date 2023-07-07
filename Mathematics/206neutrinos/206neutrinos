#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## 206neutrinos
## File description:
## 206neutrinos
##

import math
import sys

def print_help() -> None:
    print("""USAGE\n    ./206neutrinos n a h sd\n
    DESCRIPTION
        n      number of values
        a      arithmetic mean
        h      harmonic mean
        sd     standard deviation""")

def check_args() -> None:

    if (len(sys.argv) == 2 and sys.argv[1] == "-h"):
        print_help()
        exit(0)
    elif (len(sys.argv) != 5):
        exit(84)
    if (len(sys.argv) == 5):
        try:
            n = int(sys.argv[1])
            a = float(sys.argv[2])
            h = float(sys.argv[3])
            sd = float(sys.argv[4])
            if (n < 0 or a < 0 or h < 0 or sd < 0):
                raise ValueError
        except:
            print("Invalid arguments")
            exit(84)
    else:
        print("Invalid arguments")
        exit(84)

def get_input_value() -> float:
    return float(input("Enter next value: "))

def update_n(n) -> int:
    return n + 1

def update_mean(mean, n, delta) -> float:
    return mean + delta / n

def update_harmonic_mean(harm_mean, n, val) -> float:
    return n / ((n-1) / harm_mean + 1 / val)

def update_std_dev(std_dev, n, delta) -> float:
    return math.sqrt(((n - 1) * std_dev**2 + delta**2) / n)

def update_rms(mean, std_dev) -> float:
    return math.sqrt(mean**2 + std_dev**2)

def update_stats(n, mean, harm_mean, std_dev) -> tuple:
    val = get_input_value()
    delta = val - mean
    n = update_n(n)
    mean = update_mean(mean, n, delta)
    harm_mean = update_harmonic_mean(harm_mean, n, val)
    std_dev = update_std_dev(std_dev, n, delta)
    rms = update_rms(mean, std_dev)
    return (n, mean, harm_mean, std_dev, rms)

def print_stats(n, mean, harm_mean, std_dev) -> None:
    print("    Number of values: {:7d}".format(n))
    print("    Standard deviation: {:7.2f}".format(std_dev))
    print("    Arithmetic mean:    {:7.2f}".format(mean))
    print("    Root mean square:   {:7.2f}".format(update_rms(mean, std_dev)))
    print("    Harmonic mean:      {:7.2f}\n".format(harm_mean))

def run_neutrinos(n, mean, harm_mean, std_dev) -> None:
    while True:
        try:
            res = update_stats(n, mean, harm_mean, std_dev)
        except:
            break
        n, mean, harm_mean, std_dev, rms = res
        print_stats(n, mean, harm_mean, std_dev)

def main() -> None:

    check_args()

    if len(sys.argv) == 5:
        n = int(sys.argv[1])
        mean = float(sys.argv[2])
        harm_mean = float(sys.argv[3])
        std_dev = float(sys.argv[4])
        run_neutrinos(n, mean, harm_mean, std_dev)

if __name__ == "__main__":
    main()
