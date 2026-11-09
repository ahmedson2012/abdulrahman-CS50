import csv


class film:
    def __init__(self, name, kind, author, length):
        self.name = name
        self.kind = kind
        self.author = author
        self.length = length

    def writefilm(self):
        print(f"Kind: {kind}\nAuthor: {author}\nLength: {length}")
films = []
def makefilm(name, kind, author, length):
    films.append(film(name, kind, author, length))


for i in range(10):
    name = input(f"Enter the name of the film number {i + 1}: ")
    kind = input(f"Enter the kind of the film number {i + 1}: ")
    author = input(f"Enter the author of the film number {i + 1}: ")
    length = input(f"Enter the time of the film number(in minutes) {i + 1}: ")
    makefilm(name, kind, author, length)

with open("films.csv", "r") as csvfilms:
    writer = csv.writer(csvfilms)
    writer.writerow(["name", "kind", "author", "length in minutes"])
    for i in range(10):
        writer.writerow([films[i].name, films[i].kind, films[i].author, films[i].length])
