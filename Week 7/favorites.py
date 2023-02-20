import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    address, apartment, city = 0, 0, 0
    for row in reader:
        favorite = row["City"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

        #if favorite == "Street Assress":
        #    address += 1
        #elif favorite == "Apartment":
        #    apartment += 1
        #elif favorite == "City":
        #    city += 1

#print(f"Street Assress: {address}")
#print(f"Apartment: {apartment}")
#print(f"City: {city}")
#def get_value(language): #sorting by value. key=lambda -> the same
#    return counts[language]

#for favorite in sorted(counts, key=lambda language: counts[language]):
#    print(f"{favorite}: {counts[favorite]}")

favorite = input("Favorite: ")
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
