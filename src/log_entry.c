
/*=========================================================*
 |                                                         |
 | Project Log_File_Analyzer.                                |
 | Created by horos on 09 нояб. 2024.                     |
 |                                                         |
 | Copyright © 2024, Nikita Batnikov                       |
 |                                                         |
 | All rights reserved. This source code and all           |
 | accompanying materials are the property of Nikita       |
 | Batnikov and are protected under international          |
 | copyright laws.                                         |
 |                                                         |
 | Permission is hereby granted for personal and           |
 | educational use of this code, provided that this        |
 | copyright notice remains in all copies or substantial   |
 | portions of the code.                                   |
 |                                                         |
 | You may not: copy, modify, merge, publish, distribute,  |
 | sublicense, and/or sell copies of this code for         |
 | commercial purposes without prior written permission    |
 | from Nikita Batnikov.                                   |
 |                                                         |
 | This code is provided "as is", without warranty of any  |
 | kind, express or implied, including but not limited to  |
 | the warranties of merchantability and fitness for a     |
 | particular purpose.                                     |
 |                                                         |
 | Contact Information:                                    |
 | Email: batnikov@internet.ru                             |
 |                                                         |
 *=========================================================*/

#include "log_entry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

LogEntry* logEntries = NULL;
size_t logCount = 0;
pthread_mutex_t logMutex = PTHREAD_MUTEX_INITIALIZER;

void addLogEntry(int id, int year, int month, int day, const char* time, const char* type, const char* message) {
	pthread_mutex_lock(&logMutex);

	logEntries = realloc(logEntries, (logCount + 1) * sizeof(LogEntry));
	if (!logEntries) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	logEntries[logCount].id = id;
	logEntries[logCount].year = year;
	logEntries[logCount].month = month;
	logEntries[logCount].day = day;
	strncpy(logEntries[logCount].time, time, sizeof(logEntries[logCount].time));
	strncpy(logEntries[logCount].type, type, sizeof(logEntries[logCount].type));
	strncpy(logEntries[logCount].message, message, sizeof(logEntries[logCount].message));

	logCount++;
	pthread_mutex_unlock(&logMutex);
}

void loadLogFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		perror("Failed to open file");
		return;
	}

	char line[128];
	int id = 1;

	while (fgets(line, sizeof(line), file)) {
		int year, month, day;
		char time[9], type[10], message[50];

		if (sscanf(line, "\"%d-%d-%d %8s\" %9s \"%49[^\"]\"", &year, &month, &day, time, type, message) == 6) {
			addLogEntry(id++, year, month, day, time, type, message);
		}
	}

	fclose(file);
}

void printLogEntry(LogEntry entry) {
	printf("%-5d %-6d %-7d %-5d %-10s %-10s %-50s\n",
	       entry.id, entry.year, entry.month, entry.day,
	       entry.time, entry.type, entry.message);
}

void printHeader() {
	printf("%-5s %-6s %-7s %-5s %-10s %-10s %-50s\n", "ID", "YEAR", "MONTH", "DAY", "TIME", "TYPE", "MESSAGE");
	printf("------------------------------------------------------------------------------------------\n");
}
