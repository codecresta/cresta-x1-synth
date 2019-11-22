/*
pre_prs_ifc.c

Added _CRT_SECURE_NO_WARNINGS to preprocessor definitions for this file
*/

#include "pre_prs_ifc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char pre_err[MAX_PRE_ERR];
int num_banks;
int num_pres;
char* pre_fname;
int pre_lnum;
char* bank[MAX_BANKS];
preStruct pre[MAX_PRES];

void initPrePrs()
// initialises parser variables
{
	pre_err[0] = 0;
	num_banks = 0;
	num_pres = 0;
	pre_lnum = 1;
}

void appBank(int line_num, const char *name)
{
	if (num_banks < MAX_BANKS)
		bank[num_banks++] = _strdup(name);
	else
		sprintf(pre_err, "Error on line %d: maximum number of banks exceeded.", line_num);
}

void appPre(int line_num, const char *bank, const char *name)
{
	if (num_pres < MAX_PRES)
	{
		pre[num_pres].bank = _strdup(bank);
		pre[num_pres++].name = _strdup(name);
	}
	else
		sprintf(pre_err, "Error on line %d: maximum number of presets exceeded.", line_num);
}

void freePrePrs()
// frees parser variables
{
	int i;
	for (i = 0; i < num_banks; i++)
		free(bank[i]);
	for (i = 0; i < num_pres; i++)
	{
		free(pre[i].bank);
		free(pre[i].name);
	}
}