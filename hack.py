import random

def generate_4_digit_password():
    # Generate a random 4-digit password
    password = ''.join(random.choice('0123456789') for _ in range(4))
    return password

if _name_ == "_main_":
    password = generate_4_digit_password()
    print("Your 4-digit password is:", password)
