def printMe(symbol, theEnd,):
    print(symbol,end = theEnd)

rows = int(input("Enter rows: "))
for i in range(rows):
    print(" ",end="")
print("#")
for i in range(rows):
    for j in range(rows - (i + 1)):
        printMe(" ","")
    for j in range(rows - (rows - (i + 1))):
        printMe("#","")
    printMe(" ","")
    for j in range(rows - (rows - (i + 1))):
        printMe("#","")
    print()







