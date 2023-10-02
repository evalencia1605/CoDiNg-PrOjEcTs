print("Encrypt a message")
name = input("Enter the message:")
key = input("Enter an integer for an encryption key:")
name = name.upper()
encrypted_values = []
for x in name:
    encrypted = ord(x) + int(key)

    encrypted_values.append(chr(encrypted))

encrypted_message = ''.join(encrypted_values)
print("Encrypted message:", encrypted_message)

