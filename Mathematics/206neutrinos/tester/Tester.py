#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## 206neutrinos
## File description:
## Tester
##

import io
import sys
import unittest
from unittest.mock import patch
sys.path.append('/path/to/Test206neutrinos.py')
from Test206neutrinos import *

from Test206neutrinos import check_args, update_n, update_mean, update_harmonic_mean, update_std_dev, update_rms, update_stats, run_neutrinos

class TestNeutrinos(unittest.TestCase):

    def test_check_args(self):
        # Test help option
        with self.assertRaises(SystemExit):
            sys.argv = ["./206neutrinos", "-h"]
            check_args()

        # Test invalid number of arguments
        with self.assertRaises(SystemExit):
            sys.argv = ["./206neutrinos", "1", "2.5", "3.2"]
            check_args()

        # Test invalid arguments
        with self.assertRaises(SystemExit):
            sys.argv = ["./206neutrinos", "-5", "2.5", "3.2", "1.0"]
            check_args()

    def test_update_n(self):
        self.assertEqual(update_n(0), 1)
        self.assertEqual(update_n(5), 6)

    def test_update_mean(self):
        self.assertEqual(update_mean(0.0, 1, 5.0), 5.0)
        self.assertEqual(update_mean(2.5, 2, 1.5), 3.25)

    def test_update_rms(self):
        self.assertAlmostEqual(update_rms(2.5, 1.5), 2.96, delta=0.1)
        self.assertAlmostEqual(update_rms(0.0, 0.0), 0.0)

    def test_update_stats(self):
        sys.stdin = io.StringIO("2\n3.0\n4.0\n")
        res = update_stats(2, 3.0, 2.5, 0.0)
        self.assertEqual(res[0], 3)
        self.assertAlmostEqual(res[1], 2.6666666666666665, delta=0.1)
        self.assertAlmostEqual(res[2], 2.3076923076923075, delta=0.1)
        self.assertAlmostEqual(res[3], 0.5773502691896257, delta=0.1)

if __name__ == '__main__':
    unittest.main()
