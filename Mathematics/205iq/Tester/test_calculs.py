#!/usr/bin/env python3

import unittest
import io
import sys
from unittest.mock import patch

import sys
sys.path.append('/path/to/Test205IQ')
from Test205IQ import *

from Test205IQ import normal_density, percentage_below, percentage_between

class TestIQ(unittest.TestCase):

    def test_normal_density(self):
        self.assertAlmostEqual(normal_density(100, 100, 15), 0.02659615202676218, places=9)
        self.assertAlmostEqual(normal_density(115, 100, 15), 0.01613138163460956, places=9)
        self.assertAlmostEqual(normal_density(130, 100, 15), 0.003599397767545871, places=9)

    def test_percentage_below(self):
        self.assertAlmostEqual(percentage_below(100, 100, 15), 50.0, places=1)
        self.assertAlmostEqual(percentage_below(115, 100, 15), 84.1345, places=4)
        self.assertAlmostEqual(percentage_below(130, 100, 15), 97.72498680380883, places=4)

    def test_percentage_between(self):
        self.assertAlmostEqual(percentage_between(85, 115, 100, 15), 68.26894921369143, places=4)
        self.assertAlmostEqual(percentage_between(100, 130, 100, 15), 47.724986805178816, places=4)
        self.assertAlmostEqual(percentage_between(85, 130, 100, 15), 81.85946141200871, places=4)

if __name__ == '__main__':
    unittest.main()
