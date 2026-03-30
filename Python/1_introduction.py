name = input("Your name: ")
while name == "":
    name = input("You can't be no one, silly!\nYour name: ")

while True:
    try:
        age = int(input("Your age: "))
        break
    except ValueError:
        print("Your age must be expressed in numbers.")

favorite = input("Your favorite thing: ")
while favorite == "":
    favorite = input("Really? You're THAT sad?\nYour favorite thing: ")

print("My name is " + name + ", I'm " + str(age) + " and I like " + favorite)
