# An easy way to calculate the Greatest Common Divisor using the Euclidean algorithm.
# Author: @Arthurdw


def get_gcd(a: int, b: int) -> int:
    """
    Returns the Greatest Common Divisor

    Args:
        a (int): Your first number.
        b (int): Your second number.
    """
    if b == 0:
        return a
    return get_gcd(b, a % b)


if __name__ == "__main__":
    print(f"The GCD of 20 and 45 is {get_gcd(20, 45)}")
