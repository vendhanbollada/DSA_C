void printBytes(long* num){
	char *ptr = (char*)&num
#if METHOD == 1
	for(int i = 0 ; i< sizeof(long){
		printf("byte %d is %\n" , i+1 , (char)num); 
		num >>= 8 ; 
	}
#else
	for(int i = 0 ; i < sizeof(long)){
		printf("byte %d is %x\n " , i+1 , *ptr++);
	}
#if


}
// arr[i] instead arr[i%Size] == to make sure it withtin the range 

int mylen(char *str){
	int i = 0 ; 
	while(str[i] != '\0'){
		count++;
	}
	return count++
}

union test{
	long l;
	char arr[sizeof (long)];
};

void printBytes(long l){
	union test a ;
	for(int i =0 ; i < sizeof() ; )
}