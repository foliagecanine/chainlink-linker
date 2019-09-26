#include "include/arguments.h"

int parse_arguments(int argc, char *argv[]) {
	int argparse = 0;
	printf("Chainlink starting...\n");
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i],"-v")||!strcmp(argv[i],"--version")) {
			printf("Chainlink - symlink GUI\n");
			printf("Version 1.0\n");
			return 0;
		}
		if (!strcmp(argv[i],"-h")||!strcmp(argv[i],"--help")||!strcmp(argv[i],"-?")) {
			printf("Chainlink - symlink GUI\n");
			printf("--help		-h,-?	Show this help\n");
			printf("--version	-v	Show version information\n");
			return 0;
		}
		printf("Failed to parse argument: %s\n",argv[i]);
		printf("Try %s --help for more information\n", argv[0]);
		return -1;
	}
	return 1;
}
