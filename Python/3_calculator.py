def calcProg():

    viableOps = ["+", "-", "*", "/", "^", "%"]
    
    while True:
        try:
            number1 = float(input("Number 1: "))
        except ValueError:
            print("Must be a number, silly.")
            continue
        
        try:
            number2 = float(input("Number 2: "))
        except ValueError:
            print("Must be a number, silly.")
            continue
        
        operation = input("Operation: ")
    
        if operation in viableOps:
            if operation == viableOps[0]:
                print(number1 + number2)
            elif operation == viableOps[1]:
                print(number1 - number2)
            elif operation == viableOps[2]:
                print(number1 * number2)
            elif operation == viableOps[3]:
                if number2 == 0:
                    print("Cannot divide by 0.")
                    continue
                else:
                    print(number1 / number2)
            elif operation == viableOps[4]:
                print(pow(number1, number2))
            elif operation == viableOps[5]:
                print(number1 % number2)
            else:
                print("how did you even manage to trigger this")
        elif operation == "skip":
            print("""


""")
            break
        else:
            print("Operation must be in viableOps")
            print(viableOps)
        break
    print("""


""")
