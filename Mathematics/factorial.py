"""
    Program to find the factorial of a number
"""


def factorial(num):
    res = 1
    for i in range(2, num+1):
        res = res*i
    return res


print(factorial(int(input("Enter Number: "))))
