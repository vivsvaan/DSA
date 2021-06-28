"""
    Program to find GCD/HCF or LCM of two given numbers
"""


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def lcm(a, b):
    return (a * b)//gcd(a, b)


a = int(input("Enter Number a: "))
b = int(input("Enter Number b: "))

print("GDC/HCF is: ", gcd(a, b))
print("LCM is: ", lcm(a, b))

