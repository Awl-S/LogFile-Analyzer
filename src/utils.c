
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

#include "utils.h"

int isTimeInRange(const struct tm *tm_time, const struct tm *tm_start, const struct tm *tm_end) {
	if ((tm_time->tm_hour > tm_start->tm_hour ||
	     (tm_time->tm_hour == tm_start->tm_hour && tm_time->tm_min >= tm_start->tm_min)) &&
	    (tm_time->tm_hour < tm_end->tm_hour ||
	     (tm_time->tm_hour == tm_end->tm_hour && tm_time->tm_min <= tm_end->tm_min))) {
		return 1;
	}
	return 0;
}
