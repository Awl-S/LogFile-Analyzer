
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
 * @file utils.h
 * @brief Вспомогательные функции для анализа времени в логах. / Utility functions for log time analysis.
 *
 * Этот файл содержит утилиты для работы с временем, включая проверку попадания
 * временного значения в заданный интервал.
 * ---
 * This file contains utilities for working with time, including checking if
 * a given time value falls within a specified interval.
 */

#ifndef LOG_FILE_ANALYZER_UTILS_H
#define LOG_FILE_ANALYZER_UTILS_H

#include <time.h>

/**
 * @brief Проверяет, находится ли заданное время в указанном интервале. / Checks if a given time is within the specified range.
 *
 * @param tm_time Указатель на структуру `tm`, представляющую проверяемое время.
 * / Pointer to the `tm` structure representing the time to check.
 *
 * @param tm_start Указатель на структуру `tm`, представляющую начало интервала.
 * / Pointer to the `tm` structure representing the start of the interval.
 *
 * @param tm_end Указатель на структуру `tm`, представляющую конец интервала.
 * / Pointer to the `tm` structure representing the end of the interval.
 *
 * @return int Возвращает 1, если время попадает в интервал, иначе 0. / Returns 1 if the time falls within the interval, otherwise 0.
 *
 * @note Временные интервалы учитываются только по часам и минутам.
 * / Only hours and minutes are considered for the time intervals.
 */
int isTimeInRange(const struct tm *tm_time, const struct tm *tm_start, const struct tm *tm_end);

#endif // LOG_FILE_ANALYZER_UTILS_H
