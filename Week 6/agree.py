s = input("Do you agree? ")

s = s.lower()
#if s == "Y" or s == "y" or s == "YES" or s == "Yes" or s == "yes":
if s in ["y", "yes"]:
    print("Agreed")
#elif s == "N" or s == "n" or s == "NO" or s == "No" or s == "no":
elif s in ["n", "no"]:
    print("Not agreed")