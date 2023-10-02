print("Decrypt a message")
name = input("Enter the encrypted message:")
key = input("Enter the key used for encryption:")

decrypted = []

for x in name:
    decrypted_char = chr(ord(x)- int(key))
    decrypted.append(decrypted_char)

decrypted_message = ''.join(decrypted)
print("Decrypted message:", decrypted_message)
