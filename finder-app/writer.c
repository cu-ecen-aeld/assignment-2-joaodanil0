
#include <stdio.h>
#include <syslog.h>
#include <regex.h> 

#define STR_SIZE 1000

int main(int argc, char **argv){

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    FILE *fp;

    openlog(NULL, 0, LOG_USER);

    if(writefile == NULL || writestr == NULL){
        syslog(LOG_ERR, "Missing Parameters");
        return 1;
    }

    syslog(LOG_DEBUG, "“Writing %s to %s", writestr, writefile);

    fp = fopen(writefile, "w");

    if(fp == NULL){
        syslog(LOG_ERR, "Error to open file");
        return 1;
    }

    fprintf(fp, "%s", writestr);

    fclose(fp);

    // printf("Path: %s\nFile: %s\n", writefile, writestr);
    return 0;
}