

var = 0
def scanf(value):
    global var
    var = value
    if var == 0:
        return 0
    else:
        return 1
    

print(f"Enter a number: {var}")
scanf(5)
print(f"You entered: {var}")
