def printMe(symbol, theEnd, times):
    for i in range(times):
        print(symbol,end = theEnd)

rows = int(input("Enter rows: "))

printMe(" ","",rows)
print("#")
for i in range(rows):
    printMe(" ","",rows - (i + 1))
    printMe("#","",rows - (rows - (i + 1)))
    printMe(" ","",1)
    printMe("#","",rows - (rows - (i + 1)))
    print()









