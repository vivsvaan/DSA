"""
    Program to check if number is prime or not
"""


def is_prime(number):
    if number == 1:
        return False
    if number == 2 or number == 3:
        return True
    if (not number % 2) or (not number % 3):
        return False

    i = 5
    while i*i <= number:
        if not number % i:
            return False
        if not number % (i+2):
            return False
        i = i + 6
    return True


print("Prime") if is_prime(int(input("Enter Number: "))) else print("Not Prime")
