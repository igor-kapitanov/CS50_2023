#from cs50 import get_int

#for i in range(n):
    #print("#")

def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    #instead of "do while" loop:
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not a number")

main()