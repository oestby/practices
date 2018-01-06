"""
Oppgave 1 a)

"""

def isFibbonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b = b + a
        a = temp
    return b == n
