#include <stdio.h>
#include <stdint.h>

#define MAX_BYTE 4
uint64_t change_byteorder(uint64_t n){
	uint64_t result = 0;
	
	for(int i=0; i < MAX_BYTE; i ++)		
	        result |= (((n >> 8*i)&0xff) << 8*(MAX_BYTE-1-i));
	
    return result;
}
int main(int argc, char**argv) {
	if(argc != 3) {
		printf("[USAGE] : %s file1 file2\n",argv[0]);
		return 0;
	}

	uint32_t n1, n2;
	FILE * fp1 = fopen(argv[1],"r");
	FILE * fp2 = fopen(argv[2],"r");

	if(fp1 == NULL || fp2 == NULL) {
		printf("[ERROR] Failed to read file\n");
		return 0;
	}

	fread(&n1,4,1,fp1);
	fread(&n2,4,1,fp2);

	n1 = (uint32_t)change_byteorder(n1);
	n2 = (uint32_t)change_byteorder(n2);

	printf("n1 + n2 : %u \n",n1+n2);
}
