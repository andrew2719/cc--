import hashlib
import time
# Set target value as a string
target_value = "000003A30C000000000000000000000000000000000000000000000000000000"

# Convert target value from hex string to bytes
target_bytes = bytes.fromhex(target_value)

# Loop until a valid hash is found
nonce = 0
start = time.time()
max_nonce = 2**32-1
flag = True
while nonce < max_nonce:
    # Concatenate nonce with target bytes
    data = bytes(nonce) + target_bytes
    
    # Compute SHA-256 hash of data
    hash_value = hashlib.sha256(data).hexdigest()
    
    # print the difference between hash_value and target_value
    # print(abs(int(hash_value, 16) - int(target_value, 16)))
    # Check if hash value meets target
    if hash_value < target_value:
        print("Valid hash found!")
        print("Nonce: ", nonce)
        print("Hash: ", hash_value)
        flag = False
        break
    
    # Increment nonce and try again
    # calc time taken to do 5000 nonce
    if nonce % 5000 == 0:
        print("time taken for 5000 nonce: ", time.time() - start)
    nonce += 1
if(flag):
    print("No valid hash found")
end = time.time()
print("Time taken: ", end - start)
