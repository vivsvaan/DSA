"""
    Program to check if number is palindrome
"""


def is_palindrome(number):
    num = number
    reverse = 0
    while num != 0:
        last_digit = num % 10
        reverse = reverse*10 + last_digit
        num = num // 10
    if reverse == number:
        return True
    return False


number = int(input("Enter number: "))

print("yes") if is_palindrome(number) else print("no")
