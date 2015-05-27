/*
 * log.h
 *
 *  Created on: May 26, 2015
 *      Author: avr.nir
 */

#ifndef LOG_H_
#define LOG_H_
static FILE* logfile;

FILE *log_open(char* rootdir);
void log_msg(char* message);


#endif /* LOG_H_ */
