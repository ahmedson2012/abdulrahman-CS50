from cs50 import SQL

db = SQL("sqlite:///mobile-market.db")
def duplicate(thing, column, table):
    emails = db.execute(f"SELECT {column} FROM {table}")
    for email in emails:
        if thing == email[column]:
            return True
    return False
email = input("Enter your email to check if you have an account: ")
emails = db.execute("SELECT email FROM customer")
for email1 in emails:
    if email == email1['email']:
        customer_id = db.execute("SELECT id FROM customer WHERE email = ?", email)
        customer_id = customer_id[0]['id']
        break
else:
    name = input("Enter your name: ")
    phone = input("Enter your phone number: ")
    address = input("Enter your address: ")


    while True:
        email = input("Enter your email(be sure that no one used it before): ")
        if not duplicate(email, "email", "customer"):
            break
    customer = db.execute("INSERT INTO customer (name, phone, address, email) VALUES (?, ?, ?, ?)", name, phone, address, email)
    customer_id = db.execute("SELECT id FROM customer WHERE email = ?", email)
    customer_id = customer_id[0]['id']
products1 = db.execute("SELECT * FROM product ORDER BY id ASC")
for product in products1:
    print(f"{product['id']}. brand- {product['brand']}, \nmodel- {product['model']}, \nstorage(GB)- {product['storage_gb']}, \ncolor- {product['color']}, \nprice- {product['price']},\nstock- {product['stock_quantity']}\n")

n = int(input("How many products will you buy? "))
products = [None] * n
quantity = [None] * n
prices = [None] * n
for i in range(n):
    product_quantity = 0
    while True:
        products[i] = int(input(f"Enter the id of the product number {i + 1}: "))
        if duplicate(products[i], "id", "product"):
            break
        else:
            print("please enter a right id: ")
    for product in products1:
        if product['id'] == products[i]:
            product_quantity = product['stock_quantity']
            prices[i] = product['price']
            break

    while True:
        quantity[i] = int(input(f"Enter the quantity: "))
        if quantity[i] < 1 or quantity[i] > product_quantity:
            print("the quantity must be one or more and less than stock_quantity: ")
        else:
            break
order = db.execute('INSERT INTO "order" (customer_id, date) VALUES (?, CURRENT_TIMESTAMP)', customer_id)
order_id = db.execute('SELECT id FROM "order" ORDER BY id DESC LIMIT 1')
order_id = order_id[0]['id']
total_price = 0
for i in range(n):
    db.execute("INSERT INTO order_items (order_id, product_id, quantity, price) VALUES (?, ?, ?, ?)", order_id, products[i], quantity[i], prices[i])
    db.execute("UPDATE product SET stock_quantity = stock_quantity - ? WHERE id = ?", quantity[i], products[i])
    total_price += prices[i] * quantity[i]
print(f"Total price is: {total_price}")


