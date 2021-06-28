"""
    Program to get prime factors of a number
"""


def prime_factors(number):
    res = []
    if number <= 1:
        return res
    while not number % 2:
        res.append(2)
        number = number // 2
    while not number % 3:
        res.append(3)
        number = number // 3

    i = 5
    while i*i < number:
        while not number % i:
            res.append(i)
            number = number // i
        while not number % (i+2):
            res.append(i+2)
            number = number // (i+2)
        i = i + 6
    if number > 3:
        res.append(number)
    return res


print(prime_factors(int(input("Enter Number: "))))

