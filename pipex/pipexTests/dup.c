
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 

int main() 
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND); 
	if(file_desc < 0) 
	{
		printf("error opening the file\n"); 
		return (1);
	}

	int copy_desc = dup(file_desc); 
	if (file_desc < 0)
	{
		printf("error opening the file\n");
		return (1);
	}

	printf("copy_desc %i\n", copy_desc);
	printf("file_desc %i\n", file_desc);

	write(copy_desc," dup.txt\n", 8); 

	close(file_desc);
	close(copy_desc);

	return (0); 

} 
