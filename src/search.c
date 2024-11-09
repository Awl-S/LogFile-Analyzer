
/*=========================================================*
 |                                                         |
 | Project Log_File_Analyzer.                              |
 | Created by horos on 09 нояб. 2024.                      |
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

#include "search.h"

#include "search.h"
#include "log_entry.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

void searchByDate(int year, int month, int day) {
	printHeader();
	pthread_mutex_lock(&logMutex);
	for (size_t i = 0; i < logCount; i++) {
		if ((year == 0 || logEntries[i].year == year) &&
		    (month == 0 || logEntries[i].month == month) &&
		    (day == 0 || logEntries[i].day == day)) {
			printLogEntry(logEntries[i]);
		}
	}
	pthread_mutex_unlock(&logMutex);
}

void searchByTime(const char* startTime, const char* endTime) {
	struct tm tm_start = {0}, tm_end = {0};
	sscanf(startTime, "%2d:%2d", &tm_start.tm_hour, &tm_start.tm_min);
	sscanf(endTime, "%2d:%2d", &tm_end.tm_hour, &tm_end.tm_min);

	printHeader();
	pthread_mutex_lock(&logMutex);
	for (size_t i = 0; i < logCount; i++) {
		struct tm tm_log = {0};
		sscanf(logEntries[i].time, "%2d:%2d", &tm_log.tm_hour, &tm_log.tm_min);

		if (isTimeInRange(&tm_log, &tm_start, &tm_end)) {
			printLogEntry(logEntries[i]);
		}
	}
	pthread_mutex_unlock(&logMutex);
}

// Поиск по типу
void searchByType(const char* type) {
	printHeader();
	pthread_mutex_lock(&logMutex);
	for (size_t i = 0; i < logCount; i++) {
		if (strcmp(logEntries[i].type, type) == 0) {
			printLogEntry(logEntries[i]);
		}
	}
	pthread_mutex_unlock(&logMutex);
}

// Поиск по сообщению
void searchByMessage(const char* message) {
	printHeader();
	pthread_mutex_lock(&logMutex);
	for (size_t i = 0; i < logCount; i++) {
		if (strstr(logEntries[i].message, message) != NULL) {
			printLogEntry(logEntries[i]);
		}
	}
	pthread_mutex_unlock(&logMutex);
}

void searchByDateAndTime(int year, int month, int day, const char *startTime, const char *endTime) {
	struct tm tm_start = {0};
	struct tm tm_end = {0};

	if (sscanf(startTime, "%2d:%2d", &tm_start.tm_hour, &tm_start.tm_min) != 2) {
		fprintf(stderr, "Invalid start time format\n");
		return;
	}
	if (sscanf(endTime, "%2d:%2d", &tm_end.tm_hour, &tm_end.tm_min) != 2) {
		fprintf(stderr, "Invalid end time format\n");
		return;
	}

	printHeader();
	pthread_mutex_lock(&logMutex);
	for (size_t i = 0; i < logCount; i++) {
		struct tm tm_log = {0};
		if ((year == 0 || logEntries[i].year == year) &&
		    (month == 0 || logEntries[i].month == month) &&
		    (day == 0 || logEntries[i].day == day) &&
		    sscanf(logEntries[i].time, "%2d:%2d", &tm_log.tm_hour, &tm_log.tm_min) == 2 &&
		    isTimeInRange(&tm_log, &tm_start, &tm_end)) {
			printLogEntry(logEntries[i]);
		}
	}
	pthread_mutex_unlock(&logMutex);
}
