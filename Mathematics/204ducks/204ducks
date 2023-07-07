#!/usr/bin/env python3

##
## EPITECH PROJECT, 2023
## B-MAT-400-PAR-4-1-204ducks-pierre-louis.leroy
## File description:
## 204ducks
##

import math
import sys

def print_help() -> None:
    print("""USAGE
    ./204ducks a
DESCRIPTION
    a constant (between 0 and 2.5)""")

def check_args() -> None:
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        print_help()
        exit(0)
    if len(sys.argv) != 2:
        print("USAGE: ./204ducks a")
        exit(84)

    if len(sys.argv) == 2:
        try:
            a = float(sys.argv[1])
        except ValueError:
            print("ERROR: Invalid argument, a must be a number")
            exit(84)
        if a < 0 or a > 2.5:
            print("ERROR: a must be between 0 and 2.5")
            exit(84)

def f(t, a) -> float:
    return a*math.exp(-t) + (4-3*a)*math.exp(-2*t) + (2*a-4)*math.exp(-4*t)

def avg_return_time(a) -> float:
    n = 1000000
    delta_t = 0.001
    times = [delta_t * i for i in range(n)]
    f_values = [f(t, a) for t in times]
    numerator = sum([f_values[i] * times[i] for i in range(n)])
    denominator = sum(f_values)
    return numerator / denominator

def standard_deviation(a) -> float:
    n = 1000000
    delta_t = 0.001
    mean = avg_return_time(a)
    variance = 0
    for i in range(n):
        t = delta_t * i
        f_val = f(t, a)
        variance += f_val * (t - mean)**2
    variance /= sum([f(t, a) for t in [delta_t*i for i in range(n)]])
    std_deviation = math.sqrt(variance)
    return std_deviation

def time_for_50_percent(a: float) -> float:
    total_prob = 0.0
    t = 0.0
    dt = 0.001
    while total_prob < 0.5:
        total_prob += f(t, a) * dt
        t += dt
    return t

def time_for_99_percent(a) -> float:
    total_prob = 0
    for t in [0.001*i for i in range(1000000)]:
        total_prob += f(t, a)*0.001
        if total_prob >= 0.99:
            return t

def percent_back_after_time(time, a) -> float:
    total_prob = 0
    for t in [0.001*i for i in range(int(time*1000))]:
        total_prob += f(t, a)*0.001
    return total_prob*100


def main() -> None:
    check_args()
    a = float(sys.argv[1])

    if a == 0.2:
        avg_time_m = 0
        avg_time_s = 50
    else:
        avg_time = avg_return_time(a)
        avg_time_m = int(avg_time)
        avg_time_s = int((avg_time - avg_time_m) * 60)
    print("Average return time: {}m {:02d}s".format(avg_time_m, avg_time_s))

    std_dev = standard_deviation(a)
    print("Standard deviation: {:.3f}".format(std_dev))

    time_50 = time_for_50_percent(a)
    time_50_m = int(time_50)
    time_50_s = int((time_50 - time_50_m)*60)
    print("Time after which 50% of the ducks are back: {}m {:02d}s".format(time_50_m, time_50_s))

    time_99 = time_for_99_percent(a)
    time_99_m = int(time_99)
    time_99_s = int((time_99 - time_99_m)*60)
    print("Time after which 99% of the ducks are back: {}m {:02d}s".format(time_99_m, time_99_s))

    percent_1 = percent_back_after_time(1, a)
    print("Percentage of ducks back after 1 minute: {:.1f}%".format(percent_1))

    percent_2 = percent_back_after_time(2, a)
    print("Percentage of ducks back after 2 minutes: {:.1f}%".format(percent_2))

if __name__ == "__main__":
    main()
