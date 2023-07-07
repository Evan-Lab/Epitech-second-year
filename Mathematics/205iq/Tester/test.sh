##
## EPITECH PROJECT, 2023
## 205IQ
## File description:
## test
##

#!/bin/bash

# Test 1
output=$(python3 205IQ 24 100 90 100)
expected_output="3.1% of people have an IQ between 90 and 100"
if [ "$output" == "$expected_output" ]; then
    echo "Test 1 passed"
else
    echo "Test 1 failed: expected '$expected_output', but got '$output'"
fi

# Test 2
output=$(python3 205IQ 100 15 140 150)
expected_output="0.3% of people have an IQ between 140 and 150"
if [ "$output" == "$expected_output" ]; then
    echo "Test 2 passed"
else
    echo "Test 2 failed: expected '$expected_output', but got '$output'"
fi

# Test 3

output=$(python3 205IQ 100 24 90)
expected_output="33.8% of people have an IQ inferior to 90"
if [ "$output" == "$expected_output" ]; then
    echo "Test 3 passed"
else
    echo "Test 3 failed: expected '$expected_output', but got '$output'"
fi

# Test 4

output=$(python3 205IQ 100 24 90 95)
expected_output="7.9% of people have an IQ between 90 and 95"
if [ "$output" == "$expected_output" ]; then
    echo "Test 4 passed"
else
    echo "Test 4 failed: expected '$expected_output', but got '$output'"
fi

# Test 5

output=$(python3 205IQ)
expected_output="Invalid number of arguments"
if [ "$output" == "$expected_output" ]; then
    echo "Test 5 passed"
else
    echo "Test 5 failed: expected '$expected_output', but got '$output'"
fi

# Test 6

output=$(python3 205IQ 500)
expected_output="Invalid number of arguments"
if [ "$output" == "$expected_output" ]; then
    echo "Test 6 passed"
else
    echo "Test 6 failed: expected '$expected_output', but got '$output'"
fi

# test 7

output=$(python3 205IQ 100 24 90 95 100)
expected_output="Invalid number of arguments"
if [ "$output" == "$expected_output" ]; then
    echo "Test 7 passed"
else
    echo "Test 7 failed: expected '$expected_output', but got '$output'"
fi