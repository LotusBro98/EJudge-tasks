#include "yml.c"
#include <stdio>

int main(){
	FILE* fp;
	struct ymlNode* config;

	fp = fopen("timetable.yml", "r");
	config = parseFile(fp);
	printNode(config);
	return 0;
}
