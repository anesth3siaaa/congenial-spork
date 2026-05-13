def listCode():
    answers = ["1", "2", "3", "4", "5", "6"]
    print("What do you want to learn?")
    print("""    1. Web development
    2. Game development
    3. Data science
    4. Mobile development
    5. Systems programming
    6. Cybersecurity""")
    while True:
        answer = input()



        if answer in answers:
            if answer == answers[0]:
                print("Learn Javascript, HTML, CSS.")
            elif answer == answers[1]:
                print("What engine inspires you the most?")
                print("""    1. Unity
    2. Unreal Engine
    3. Godot
    4. I want to use a framework""")
                engine = input()
                while True:
                    if engine == "1":
                        print("Learn C#.")
                    elif engine == "2":
                        print("Learn C++.")
                    elif engine == "3":
                        print("Learn GDScript or C#.")
                    elif engine == "4":
                        print("Learn LOVE2D it is stupidly good.")
                    else:
                        print("You should choose something.")
                        engine = input()
                        continue
                    break
            elif answer == answers[2]:
                print("Learn Python or R.")
            elif answer == answers[3]:
                print("iOS only?")
                iosOnly = input("[y/N]: ").casefold()
                
                
                if iosOnly == "y":
                    print("Learn Swift.")
                else:
                    print("Learn React.")
            elif answer == answers[4]:
                print("C for systems, C++ for Arduino.")
            elif answer == answers[5]:
                print("Learn how to use Kali.")
        else:
            print("You should choose something.")
            continue
        break
