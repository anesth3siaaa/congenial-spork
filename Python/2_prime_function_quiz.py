import time

def program():
    def primeNumber():
        while True:
            print("What is the 30th prime number?")
            answer = input()
            try:
                answer = int(answer)
                
                if answer == 113:
                    print("Correct")
                    time.sleep(0.5)
                    break
                else:
                    print("Wrong")
                    time.sleep(0.5)
                continue
                
                
            except ValueError:
                print("expected an integer (whole number)")
                time.sleep(0.5)

    def quiz4Ans():
        while True:
            print("""How do you define a non-return function in C?
A: int myfunc
B: func myfunc
C: def myfunc
D: void myfunc""")
            answer = input().casefold()
            
            wrongAnswer = ["a", "b", "c", "1", "2", "3"]
            rightAnswer = ["d", "4"]
            
            if answer in wrongAnswer:
                print("Wrong")
                time.sleep(0.5)
            elif answer in rightAnswer:
                print("Correct")
                time.sleep(0.5)
                break
            else:
                print("""Answer must be A-D or 1-4.
Tip: the answer is case insensitive.""")
                time.sleep(0.5)
            
    
    primeNumber()
    quiz4Ans()

program()
    
