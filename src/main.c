#include "log_entry.h"
#include "search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Вывод справки по использованию программы
void printHelp() {
	printf("Usage: Log_File_Analyzer <filename> [options]\n");
	printf("Options:\n");
	printf("  --date [year] [month] [day]       Filter logs by date\n");
	printf("  --time [start_time] [end_time]    Filter logs by time range\n");
	printf("  --type [log_type]                 Filter logs by type (e.g., ERROR, INFO)\n");
	printf("  --message [substring]             Filter logs by message content\n");
	printf("  --full                            Show all logs without filtering\n");
	printf("  --help                            Show this help message\n");
}

// Функция для парсинга аргументов командной строки
void parseArguments(int argc, char* argv[], int* year, int* month, int* day,
                    const char** startTime, const char** endTime,
                    const char** type, const char** message, int* showAllLogs) {
	for (int i = 2; i < argc; i++) {  // Начинаем с 2, так как первый аргумент — имя файла
		if (strcmp(argv[i], "--date") == 0 && i + 3 < argc) {
			*year = atoi(argv[i + 1]);
			*month = atoi(argv[i + 2]);
			*day = atoi(argv[i + 3]);
			i += 3;
		} else if (strcmp(argv[i], "--time") == 0 && i + 2 < argc) {
			*startTime = argv[i + 1];
			*endTime = argv[i + 2];
			i += 2;
		} else if (strcmp(argv[i], "--type") == 0 && i + 1 < argc) {
			*type = argv[i + 1];
			i += 1;
		} else if (strcmp(argv[i], "--message") == 0 && i + 1 < argc) {
			*message = argv[i + 1];
			i += 1;
		} else if (strcmp(argv[i], "--full") == 0) {
			*showAllLogs = 1;
		} else if (strcmp(argv[i], "--help") == 0) {
			printHelp();
			free(logEntries);
			exit(0);
		} else {
			printf("Unknown option: %s\n", argv[i]);
			printHelp();
			free(logEntries);
			exit(1);
		}
	}
}

// Функция применения фильтров для логов
void applyFilters(int year, int month, int day, const char* startTime, const char* endTime,
                  const char* type, const char* message, int showAllLogs) {
	if (showAllLogs) {
		for (size_t i = 0; i < logCount; i++) {
			printLogEntry(logEntries[i]);
		}
	} else {
		if (year || month || day) {
			if (startTime && endTime) {
				searchByDateAndTime(year, month, day, startTime, endTime);
			} else {
				searchByDate(year, month, day);
			}
		} else if (startTime && endTime) {
			searchByTime(startTime, endTime);
		}

		if (type) {
			searchByType(type);
		}
		if (message) {
			searchByMessage(message);
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {  // Проверяем, указан ли файл
		printf("Error: Missing filename.\n");
		printHelp();
		return 1;
	}

	// Имя файла берется из первого аргумента
	const char* filename = argv[1];
	loadLogFile(filename);

	// Переменные для фильтрации
	int year = 0, month = 0, day = 0;
	const char *startTime = NULL, *endTime = NULL, *type = NULL, *message = NULL;
	int showAllLogs = 0;

	// Разбор аргументов командной строки
	parseArguments(argc, argv, &year, &month, &day, &startTime, &endTime, &type, &message, &showAllLogs);

	// Печатаем заголовок, если фильтры активированы или выбран полный вывод
	if (year || month || day || startTime || endTime || type || message || showAllLogs) {
		printHeader();
	}

	// Применение фильтров и вывод результатов
	applyFilters(year, month, day, startTime, endTime, type, message, showAllLogs);

	free(logEntries);
	return 0;
}
