def printMe(symbol, theEnd,):
    print(symbol,end = theEnd)

rows = int(input("Enter rows: "))

for i in range(rows, 0, -1):
    # if i != rows:
    #     print(" ", end="")
    for j in range(rows - i):
        printMe(" ","")
    for j in range(rows - (rows - i)):
        printMe("#","")
    printMe(" ","")
    for j in range(rows - (rows - i)):
        printMe("#","")
    print()
for i in range(rows):
    print(" ",end="")
print("#")

