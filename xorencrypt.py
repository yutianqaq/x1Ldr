import sys

def xor_encrypt(plaintext, key):
    ciphertext = bytearray()
    key_length = len(key)
    for i, byte in enumerate(plaintext):
        key_byte = key[i % key_length]
        encrypted_byte = byte ^ key_byte
        ciphertext.append(encrypted_byte)
    return bytes(ciphertext)

# 读取二进制文件
try:
    filename = sys.argv[1]
except Exception as e:
    print("Usage: python .\\xorencrypt.py .\\calc.bin")
    exit()


with open(filename, "rb") as file:
    plaintext = file.read()

# 设置加密密钥
key = b"key"  # 替换为实际的密钥

# 加密
ciphertext = xor_encrypt(plaintext, key)

# 将加密后的结果写入文件
output_filename = f"{filename[:-4]}_encrypted.bin" 
with open(output_filename, "wb") as file:
    file.write(ciphertext)
print(f"xor encrypted : {output_filename}")
