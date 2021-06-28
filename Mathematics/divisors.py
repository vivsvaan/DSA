"""
    Program to get all divisors of a number
"""


def divisors(number):
    res = []
    i = 1
    print("i is 1 ", i)
    while i*i < number:
        print('in 1st while loop')
        if not number % i:
            print("appending i")
            res.append(i)
        i = i + 1
    while i >= 1:
        print("in 2nd loop")
        if not number % i:
            print("appending number/i ")
            res.append(number//i)
        i = i - 1
    return res


print(divisors(int(input("Enter Number: "))))