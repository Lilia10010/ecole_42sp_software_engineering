
#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 

int main() 
{
// open() returns a file descriptor file_desc to a  
// the file "dup.txt" here" 
int file_desc = open("dup.txt", O_WRONLY | O_APPEND); 
if(file_desc < 0) 
printf("Error opening the file\n"); 

int copy_desc = dup(file_desc); 

write(copy_desc,"This will be output to the file named dup.txt\n", 46); 


write(file_desc,"This will also be output to the file named dup.txt\n", 51); 


return 0; 


} 
