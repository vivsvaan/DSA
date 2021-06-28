"""
    Program to calculate power of a number
"""


# iterative approach
def power_iterative(number, pow):
    res = 1
    while pow > 0:
        if pow & 1:
            res = res * number
        number = number * number
        pow = pow >> 1
    return res


# recursive approach
def power_recursive(number, pow):
    if pow == 0:
        return 1

    temp = power_recursive(number, pow//2)
    temp = temp * temp

    if pow & 1:
        return temp * number
    return temp


number = int(input("Enter Number: "))
pow = int(input("Enter Power: "))
print("Iterative: ", power_iterative(number, pow))
print("Recursive: ", power_recursive(number, pow))
