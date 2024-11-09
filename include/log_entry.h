
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

/**
 * @file log_entry.h
 * @brief Модуль для управления записями логов. / Module for managing log entries.
 *
 * Определяет структуру `LogEntry` и функции для добавления, загрузки и отображения записей логов.
 * ---
 * Defines the `LogEntry` structure and functions for adding, loading, and displaying log entries.
 */

#ifndef LOG_FILE_ANALYZER_LOG_ENTRY_H
#define LOG_FILE_ANALYZER_LOG_ENTRY_H

#include <stddef.h>
#include <pthread.h>

/**
 * @struct LogEntry
 * @brief Структура для представления одной записи в логе. / Structure representing a single log entry.
 *
 * Структура содержит идентификатор, дату, время, тип и текст сообщения лог-записи.
 * ---
 * The structure contains an ID, date, time, type, and message text of a log entry.
 */
typedef struct {
	int id;                 /**< Уникальный идентификатор записи / Unique entry ID */
	int year;               /**< Год создания записи / Entry year */
	int month;              /**< Месяц создания записи / Entry month */
	int day;                /**< День создания записи / Entry day */
	char time[9];           /**< Время записи (формат HH:MM:SS) / Entry time (format HH:MM:SS) */
	char type[10];          /**< Тип записи (например, "ERROR", "INFO") / Entry type (e.g., "ERROR", "INFO") */
	char message[50];       /**< Сообщение / Message text */
} LogEntry;

extern LogEntry* logEntries;       /**< Глобальный массив записей лога / Global array of log entries */
extern size_t logCount;            /**< Количество записей в логе / Number of log entries */
extern pthread_mutex_t logMutex;   /**< Мьютекс для потокобезопасного доступа к логу / Mutex for thread-safe log access */

/**
 * @brief Добавляет новую запись в лог. / Adds a new entry to the log.
 *
 * @param id Уникальный идентификатор записи. / Unique entry ID.
 * @param year Год создания записи. / Entry year.
 * @param month Месяц создания записи. / Entry month.
 * @param day День создания записи. / Entry day.
 * @param time Время записи. / Entry time.
 * @param type Тип записи (например, "ERROR"). / Entry type (e.g., "ERROR").
 * @param message Сообщение. / Entry message.
 */
void addLogEntry(int id, int year, int month, int day, const char* time, const char* type, const char* message);

/**
 * @brief Загружает логи из файла. / Loads logs from a file.
 *
 * @param filename Имя файла для загрузки логов. / Name of the file to load logs from.
 *
 * @note Логи должны быть в определенном формате, чтобы функция корректно их интерпретировала.
 * ---
 * Logs must follow a specific format for the function to interpret them correctly.
 */
void loadLogFile(const char* filename);

/**
 * @brief Печатает одну запись лога. / Prints a single log entry.
 *
 * @param entry Запись лога для печати. / Log entry to print.
 */
void printLogEntry(LogEntry entry);

/**
 * @brief Печатает заголовок таблицы логов. / Prints the log table header.
 *
 * Используется для упрощения восприятия данных при выводе нескольких записей.
 * ---
 * Used to simplify data perception when displaying multiple entries.
 */
void printHeader();

#endif // LOG_FILE_ANALYZER_LOG_ENTRY_H
