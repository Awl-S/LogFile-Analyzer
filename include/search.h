
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
 * @file search.h
 * @brief Модуль для поиска записей в логах по разным критериям. / Module for searching log entries by various criteria.
 *
 * Содержит функции для поиска записей лога по дате, времени, типу и содержанию сообщения.
 * ---
 * Contains functions for searching log entries by date, time, type, and message content.
 */

#ifndef LOG_FILE_ANALYZER_SEARCH_H
#define LOG_FILE_ANALYZER_SEARCH_H

/**
 * @brief Ищет записи в логе, соответствующие заданной дате. / Searches log entries matching the specified date.
 *
 * @param year Год для поиска. / Year to search for.
 * @param month Месяц для поиска. / Month to search for.
 * @param day День для поиска. / Day to search for.
 */
void searchByDate(int year, int month, int day);

/**
 * @brief Ищет записи в логе, попадающие в указанный временной интервал. / Searches log entries within the specified time range.
 *
 * @param startTime Начальное время (формат HH:MM). / Start time (format HH:MM).
 * @param endTime Конечное время (формат HH:MM). / End time (format HH:MM).
 */
void searchByTime(const char* startTime, const char* endTime);

/**
 * @brief Ищет записи в логе по типу сообщения. / Searches log entries by message type.
 *
 * @param type Тип сообщения для поиска (например, "ERROR", "INFO"). / Type of message to search for (e.g., "ERROR", "INFO").
 */
void searchByType(const char* type);

/**
 * @brief Ищет записи в логе по подстроке сообщения. / Searches log entries by message substring.
 *
 * @param message Подстрока для поиска в сообщении. / Substring to search for in the message.
 */
void searchByMessage(const char* message);

/**
 * @brief Ищет записи в логе, соответствующие заданной дате и временному интервалу. / Searches log entries matching the specified date and time range.
 *
 * @param year Год для поиска. / Year to search for.
 * @param month Месяц для поиска. / Month to search for.
 * @param day День для поиска. / Day to search for.
 * @param startTime Начальное время (формат HH:MM). / Start time (format HH:MM).
 * @param endTime Конечное время (формат HH:MM). / End time (format HH:MM).
 */
void searchByDateAndTime(int year, int month, int day, const char* startTime, const char* endTime);

#endif // LOG_FILE_ANALYZER_SEARCH_H
