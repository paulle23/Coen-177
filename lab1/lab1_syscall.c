// COEN 146L : Lab 1 - template to use for file transfer (steps 1, 2, and 3)
// You need to adapt this template according to the requirements of each of the steps
// Name: Paul Le
// Date: 1/14/22
// Title: Lab1 – task 2
// Description: This program copies files from source to destination using system call
#include <stdio.h>   // fprintf(), fread(), fwrite(), fopen(), fclose()
#include <stdlib.h>  // malloc(), free()
#include <pthread.h> // pthread_create()
#include <unistd.h>  // read(), write()
#include <fcntl.h>   // open(), close()
#include <errno.h>   // errno
#include <time.h>    // clock()
#include <sys/mman.h> // mmap()

#define BUF_SIZE 2048 //buffer size
clock_t start, end;
double cpu_time_used;

// copies a files from src_filename to dst_filename using functions fopen(), fread(), fwrite(), fclose()

// copies a files form src_filename to dst_filename using syscalls open(), read(), write(), close()
int syscall_copy(char* src_filename, char* dst_filename)  {
	int src_fd, dst_fd;//create 
	char *buf;
	int bytes_read;
	src_fd = open(src_filename, O_RDONLY);	// opens a file for reading
	if (src_fd < 0) { // open() error checking
		fprintf(stderr, "unable to open %s for reading: %i\n", src_filename, errno);
		close(src_fd);
		exit(0);
	}
	// O_WRONLY - write only
	// O_CREAT - create file if it doesn't exist
	// O_TRUNC - truncates file to length 0 if it already exists (deletes existing file)
	// opens a file for writing; erases old file/creates a new file
	dst_fd = open(dst_filename, O_WRONLY | O_CREAT | O_TRUNC);	
	if (dst_fd < 0) { // open() error checking
		fprintf(stderr, "unable to open/create %s for writing: %i\n", dst_filename, errno);
		close(dst_fd);
		exit(0);
	}
	// read/ write loop
	buf = malloc((size_t)BUF_SIZE);   // allocate a buffer to store read data
	// reads up to BUF_SIZE bytes from src_filename
    while((bytes_read=(read(src_fd,buf,BUF_SIZE))) > 0)//read 1 byte from src_fd into buf
    {
		// writes bytes_read to dst_filename
		write(dst_fd,buf,bytes_read);//write 1 byte at a time from buf to dst_fd
	}
	// closes src_fd file descriptor
    close(src_fd);
	// closes dst_fd file descriptor
    close(dst_fd);
	// frees memory used for buf
	free(buf);
	return 0;
}

// checks the runtime to copy a file using functions vs syscalls
void check_copy_times(char* src_filename, char* dst_filename) {
	clock_t func_start, func_end, syscall_start, syscall_end;
	int func_time;
	int syscall_time;
	// capture runtime of func_copy() using start clock, call the copy, end the clock
	/*func_start = clock();
	printf("func start = %d\n", func_start);
	func_copy(src_filename, dst_filename);
	func_end = clock();
	printf("func end = %d\n", func_end);
	func_time = func_end - func_start;
	printf("func_time = %d\n", func_time);*/

	// capture runtime of syscall_copy() using start clock, call the copy, end the clock
	syscall_start = clock();
	printf("syscall start = %d\n", syscall_start);
	syscall_copy(src_filename,dst_filename);
	syscall_end = clock();
	printf("syscall end = %d\n", syscall_end);
	syscall_time = syscall_end - syscall_start;

	//printf("time to copy using functions: %d\n", func_time);
	printf("time to copy using syscalls: %d\n", syscall_time);
}

int main(int argc, char* argv[]) {
    start = clock();//call clock function at beginning
	printf("start = %d\n", start);
	if (argc != 3) {  // check correct usage
		fprintf(stderr, "usage: %s <src_filename> <dst_filename>\n", argv[0]);
		exit(1);
	}
	//get the source and destination files from the command line arguments
	char* src_filename = argv[1]; 
	char* dst_filename = argv[2];
	//FILE *fr = fopen(argv[1], "rb");
	//FILE *fw = fopen(argv[2], "wb");
	//check_copy_times(src_filename,dst_filename);
	//call the check copy times function
	check_copy_times(src_filename, dst_filename);
	end = clock();//call clock function at end 
	printf("end = %d\n", end);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("time = %f\n", cpu_time_used);
	return 0;
}