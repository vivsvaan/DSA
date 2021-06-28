"""
    Program to count digits in a number
"""


def count_digits(number):
    res = 0
    while number > 0:
        number = number // 10
        res = res + 1
    print("number of digits are: ", res)


count_digits(int(input("Enter a number: ")))
