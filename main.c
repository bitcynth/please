#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

#define DEFAULT_USER "root"
#define DEFAULT_SHELL "/bin/bash"
#define CREDITS "please - please don't take me too seriously.\nMade by Cynthia Revström <mail@cy.ax> - https://cy.ax\n"

int main(int argc, char** argv)
{
	if(argc < 2) {
		printf("Please what?\n");
		return 0;
	}
	if(strcmp(argv[1], "root")) {
		printf(CREDITS);
		printf("type root as the first argument to please\n");
		return 0;
	}
	printf("No worries.\n");
	struct passwd* pw;
	struct passwd pw_copy;
	pw = getpwnam(DEFAULT_USER);
	pw_copy = *pw;
	pw = &pw_copy;
	setuid(pw->pw_uid);
	setgid(pw->pw_gid);
	char* args[] = { DEFAULT_SHELL, NULL };
	execvp(args[0], args);
	return 0;
}
