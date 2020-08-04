#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info()
{
	printf("Usage: sysfo [FUNC]\n\n"
	"sysfo is a neofetch inspired idea written in C\n"
	"sysfo will display system information upon request\n\n"
	"INFO:\n"
	"\tkernel		Will display the kernel version\n"
	"\thostname	Will display the system hostname\n"
	"\tPATH		Will display the $PATH\n"
	"\tEDITOR		Will display the $EDITOR\n"
	"\tSHELL		Will display the $SHELL\n");
}
int main(int argc, char *argv[])
{
	/* if(argc == "--help") { */
	/* 	printf("Usage: afetch [FUNC]\n\n"); */
	/* 	printf("Afetch is a neofetch inspired idea written in C\n"); */
	/* 	printf("Afetch will display system information apon request\n"); */
	/* 	printf(""); */
	/* } */

	const char *kernel = "uname -r";
	const char *hostname = "hostname";
	/* char *path = "echo $PATH"; */
	/* const char *editor = "echo $EDITOR"; */
	const char* PATH = getenv("PATH");
	const char* EDITOR = getenv("EDITOR");
	const char* SHELL = getenv("SHELL");

	if(argc == 1)
		info();

	if(argc == 2)
	{
		if(strcmp(argv[1], "--help") == 0)
			info();
		else if(strcmp(argv[1], "kernel") == 0)
			system(kernel);
		else if(strcmp(argv[1], "hostname") == 0)
			system(hostname);
		else if(strcmp(argv[1], "path") == 0)
			printf("%s\n", PATH);
		else if(strcmp(argv[1], "shell") == 0)
			printf("%s\n", SHELL);
		else if(strcmp(argv[1], "editor") == 0) {
			if (EDITOR == NULL) {
				fprintf(stderr, "You need to export an $EDITOR in your shell profile\n");
				return -1;
			} else
				printf("%s\n", EDITOR);
		} else {
			fprintf(stderr, "Sorry, not a recognized command\n");
			return -1;
		}
	} 
}
