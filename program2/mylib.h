#include<stdio.h>
#include<string.h>
int myStrStr(char haystack[], char needle[], char buffer[]){
	int i=0,j=0,k=0;
	while(haystack[i] != '\0' ){
		j=0;
		k=i;
		while(haystack[k]==needle[j]){	
			buffer[j]=haystack[k];
				k++;
				j++;
				buffer[j]='\0';
		}	
		i++;
		if(strcmp(needle,buffer)==0)
			return 1;
	}
			return 0;
}
void binaryArray(int n, int array[], int size){
	for(int i=size-1;i>=0;i--){
                array[i]= n & 1;
                n=n>>1;
	}
}
void binaryPrinter(int array[], int size){
		for(int i=0;i<size;i++){
			printf("%d",array[i]);
				}
		}
unsigned int countOnes(int n){
	unsigned int count=0;
	if(n<0){
		n= ~n;
		if(n==0){
			count =32;
		}
		else{
			while(n>0){
                	        if((n&1)== 1){
             	        	           count++;
                       		 }
               		 n=n>>1;
               		 }
		count=32-count;
		}
	}
	else{
		while(n>0){
			if((n&1)== 1){
				count++;
			}
		n=n>>1;
		}
	}
	return count;
}

