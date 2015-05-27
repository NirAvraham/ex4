/*
 * log.cpp
 *
 *  Created on: May 26, 2015
 *      Author: avr.nir
 */



#include <fuse.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

#include "log.h"


using namespace std;

FILE *log_open(char* rootdir)
{
    FILE *logfile;


//  strcat(rootdir,".filesystem.log");

	std::cout << rootdir << std::endl;
    logfile = fopen(rootdir, "a+");
    if (logfile == NULL)
    {
    	perror("logfile");
    	exit(EXIT_FAILURE);
    }

    // set logfile to line buffering
    setvbuf(logfile, NULL, _IOLBF, 0);
    cout<<"herebefore"<<endl;
	log_msg("hi loser");
	cout<<"here"<<endl;
    return logfile;
}

void log_msg( char* message)
{
	time_t t = time(NULL);
	struct tm *ptm = gmtime(&t);
	char* buf;
	strftime(buf, sizeof buf, "%F %T", ptm);
	strcat(buf, message);
	fputs(buf, logfile);
}

