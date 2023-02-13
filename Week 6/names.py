import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

name = input("Name: ")

#for n in names:
    #if name == n:
        #print("Found")
        #sys.exit(0)

    #better

if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)