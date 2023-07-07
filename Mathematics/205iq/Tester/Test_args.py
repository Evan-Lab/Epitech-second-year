#!/usr/bin/env python3

import unittest
import sys

from Test205IQ import check_args

class TestCheckArgs(unittest.TestCase):

    def test_invalid_arguments(self):
        with self.assertRaises(SystemExit) as cm:
            sys.argv = ['test_script.py', '100', '-15', '120']
            check_args()
        self.assertEqual(cm.exception.code, 84)

    def test_valid_arguments(self):
        sys.argv = ['test_script.py', '100', '15', '120']
        self.assertIsNone(check_args())

        sys.argv = ['test_script.py', '100', '15', '85', '115']
        self.assertIsNone(check_args())

        sys.argv = ['test_script.py', '100', '15']
        self.assertIsNone(check_args())

if __name__ == '__main__':
    unittest.main()
