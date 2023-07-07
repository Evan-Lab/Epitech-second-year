##
## EPITECH PROJECT, 2023
## B-MAT-400-PAR-4-1-204ducks-pierre-louis.leroy
## File description:
## test_204ducks
##

import pytest
import sys
from io import StringIO
from contextlib import redirect_stdout
from source204ducks import *

def test_check_args_valid():
    sys.argv = ["./204ducks", "1.5"]
    assert check_args() is None

def test_check_args_invalid():
    sys.argv = ["./204ducks"]
    with pytest.raises(SystemExit):
        check_args()
    sys.argv = ["./204ducks", "3"]
    with pytest.raises(SystemExit):
        check_args()
    sys.argv = ["./204ducks", "a"]
    with pytest.raises(SystemExit):
        check_args()

def test_print_help():
    with redirect_stdout(StringIO()) as f:
        print_help()
        assert f.getvalue().strip() == "USAGE\n    ./204ducks a\nDESCRIPTION\n    a constant (between 0 and 2.5)"
