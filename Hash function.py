import hashlib

def hash_function(data):

    hash_object = hashlib.sha256()

    hash_object.update(data.encode('utf-8'))

    hash_result = hash_object.hexdigest()

    return hash_result

data = input("Enter the data for the hash function: ")

hash_value = hash_function(data)

print(f"Input data: {data}")
print(f"Hash value: {hash_value}")
