def printMe(symbol, theEnd, times):
    for i in range(times):
        print(symbol,end = theEnd)

rows = int(input("Enter rows: "))

for i in range(rows, 0, -1):
    # if i != rows:
    #     print(" ", end="")
    printMe(" ","",rows - i)
    printMe("#","",rows - (rows - i))
    printMe(" ","",1)
    printMe("#","",rows - (rows - i))
    print()
printMe(" ","",rows)
print("#")
