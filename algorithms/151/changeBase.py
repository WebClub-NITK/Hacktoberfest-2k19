#!/bin/python3

import sys

def symbol(num):
    if num < 0 or num > 61:
        return 'No Symbol'

    if num < 10:
        return str(num)
    if num < 36:
        return chr(ord('A') + num - 10)
    else:
        return chr(ord('a') + num - 36)

def value(symbol):
    if symbol >= '0' and symbol <= '9':
        return int(symbol)
    if symbol >= 'A' and symbol <= 'Z':
        return ord(symbol) - ord('A') + 10
    if symbol >= 'a' and symbol <= 'z':
        return ord(symbol) - ord('a') + 36

print("USAGE : <number> <original-base> <new-base>")

numbers = input().split(' ')

if len(numbers) != 3:
    sys.exit("Invalid Usage!")

if numbers[0].isalnum():
    num = numbers[0]
else:
    sys.exit("Invalid Number!")

try:
    base     = int(numbers[1])
    new_base = int(numbers[2])
except ValueError:
    sys.exit("Invalid Base!")

# Get Numeric Value of given Number
val = 0
i = 0
for digit in reversed(num):
    digit_val = value(digit)
    if digit_val >= base:
        sys.exit("Invalid base-%d Number!" %(base))
    val += (base**i) * digit_val
    i += 1

# Get representation of number in New Base
rep = ""
while val > 0:
    remainder = val % new_base
    val = val // new_base
    rep = symbol(remainder) + rep

print("( %s )%d  =  ( %s )%d" %(num, base, rep, new_base))
