# BypassAV-1
通过分离的方式规避杀软

读入 Msfvenom 或 Cobalt Strike 等 C2 的 Shellcode 方式分离免杀

或者配合 donut 可以将 exe、dll 转为 Shellcode 载入 MimiKatz 等工具

# 使用方法

自定义一个 key，然后使用 xorencrypt.py 将 Shellcode 加密

```sh
> python .\xorencrypt.py .\calc.bin
> xor encrypted : .\calc_encrypted.bin
```

将加密后的文件名作为参数传递给 fopen

```cpp
	//修改这里
	char key[] = "key";

	//修改这里
	fp = fopen("user.dat", "rb");
```



# 效果

其他杀软请自测

![demo](README.assets/demo.gif)



![image-20231130151411386](README.assets/img1.png)

# 更新记录

增加 xor 加密