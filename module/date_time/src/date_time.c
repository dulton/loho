#include <stdio.h>
#include <string.h>
#include <time.h>

#include"date_time.h"

/*
	return -1 ʧ��
	return >=0 �������ڼ�
*/
int get_weekday(int year,int month,int day)
{
	struct   tm   tm1,*tm2;  
	time_t timep;
	int week = -1;

	tm1.tm_year= year-1900;  
	tm1.tm_mon=month-1;  
	tm1.tm_mday=day;  
	tm1.tm_hour=12;  
	tm1.tm_min=0;  
	tm1.tm_sec=0; 

	timep=mktime(&tm1); 
	tm2=localtime(&timep); 
	week=(int) (tm2->tm_wday);


	return week;
}


int get_pre_month(int year, int month, int *new_year, int *new_month)
{
	if(!new_year || !month)
	{
		return -1;
	}

	if((year == 2000) &&(month == 1))
	{
		*new_year = 2000;
		*new_month = 1;
		return 0;
	}

	int temp_month = 0;
	int temp_year = 0;

	temp_month = --month;
	if(temp_month == 0)
	{
		temp_month = 12;
		temp_year = --year;
	}
	else
	{
		temp_year = year;
	}

	*new_year = temp_year;
	*new_month = temp_month;


	return 0;
}



int get_next_month(int year, int month, int *new_year, int *new_month)
{
	if(!new_year || !month)
	{
		return -1;
	}

	if((year == 2037) &&(month == 12))
	{
		*new_year = 2037;
		*new_month = 12;
		return 0;
	}

	int temp_month = 0;
	int temp_year = 0;

	temp_month = ++month;
	if(temp_month == 13)
	{
		temp_month = 1;
		temp_year = ++year;
	}
	else
	{
		temp_year = year;
	}

	*new_year = temp_year;
	*new_month = temp_month;

	return 0;
}
