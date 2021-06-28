"""
    Program to count trailing zeros in factorial of a number
"""


def count_trailing_zeros(num):
    res = 0
    i = 5
    while i < num+1:
        res = res + num//i
        i = i*5
    return res


print(count_trailing_zeros(int(input("Enter Number: "))))
