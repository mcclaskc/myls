#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"
#include <dirent.h>

/*
 * myls() - produce the appropriate directory listing(s)
 */
void myls(char **roots) {
    /* TODO: Complete this function */
  struct dirent *dir;
  DIR *direct;

  if ((direct = opendir(roots))){
    fprintf(stderr, "myls: can't open %s\n", roots);
  }
  else {
    while ((dir = readdir(direct)) != NULL) // readdir reads a
      printf("%s\n", dir->d_name);
    closedir(direct); // close the connection
  }

}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s [FILE]...\n", progname);
    printf("List information about the FILEs (the current directory by default).\n");
    printf("Behavior should mirror /bin/ls -1\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
    /* for getopt */
    long opt;

    /* run a student name check */
    check_student(argv[0]);

    /* parse the command-line options.  For this program, we only support  */
    /* the parameterless 'h' option, for getting help on program usage. */
    /* TODO: make sure to handle any other arguments specified by the assignment */
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
          case 'h': help(argv[0]); break;
        }
    }

    /* TODO: fix this invocation */
    myls(argv);
}