/**
 * "easyio.h" library
 *
 * @version 0.1
 * @author Daneel
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define INP_MAX 100



long getlong_r(long min, long max);
//Прочитывает long в диапозоне min<=result<=max

long getlong();
//Прочитывает long

double getdouble_r(double min, double max);
//Прочитывает double в диапозоне min<=result<=max

double getdouble();
//Прочитывает double

void readstr(char* s);
// scanf("%s");

void readline(char* s);
//Прочитывает строку до \n


long getlong_r(long min, long max){
	long res;
	int cor;
	do{
		cor=1;
		char s[INP_MAX], *err, *end=s;
		scanf_s("%s",s);
		res=strtol(s,&err,10);
		while (*(end++));
		end--;
		if (end!=err){
			cor=0;
			printf("Incorrect number!");
		} else
			if (errno == ERANGE || res<min || res>max)
			{
                                errno=0;
				cor=0;
				printf("Number is out of range!");
			}
	
	} while (!cor);
	return res;
}

long getlong(){
	long res;
	int cor;
	do{
		cor=1;
		char s[INP_MAX], *err, *end=s;
		scanf_s("%s",s);
		res=strtol(s,&err,10);
		while (*(end++));
		end--;
		if (end!=err){
			cor=0;
			printf("Incorrect number!");
		} else
		if (errno == ERANGE)
			{
                                errno=0;
				cor=0;
				printf("Number is out of range!");
			}
	} while (!cor);
	return res;
}

double getdouble_r(double min, double max){
	double res;
	int cor;
	do{
		cor=1;
		char s[INP_MAX], *err, *end=s-1;
		scanf_s("%s",s);
		res=strtod(s,&err);
		while (*(++end));
		if (end!=err){
			cor=0;
			printf("Incorrect number!");
		} else
			if (errno == ERANGE || res<min || res>max)
			{
                                errno=0;
				cor=0;
				printf("Number is out of range!");
			}
	
	} while (!cor);
	return res;
}

double getdouble(){
	double res;
	int cor;
	do{
		cor=1;
		char s[INP_MAX], *err, *end=s-1;
		scanf_s("%s",s);
		res=strtod(s,&err);
		while (*(++end));
		if (end!=err){
			cor=0;
			printf("Incorrect number!");
		} else	
                if (errno == ERANGE)
			{
                                errno=0;
				cor=0;
				printf("Number is out of range!");
			}
	} while (!cor);
	return res;
}


void readstr(char* s){
    scanf_s("%s",s);
}

void readline(char* s){
        scanf_s("%[^\n]",s);
}
