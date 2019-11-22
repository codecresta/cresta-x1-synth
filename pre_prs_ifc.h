/*
pre_prs_ifc.h
Defines various structures used to describe a parsed preset file.
*/

#define MAX_PRE_ERR 120
#define MAX_BANKS 16
#define MAX_PRES 512

typedef struct
{
	char* bank;
	char* name;
} preStruct;

void initPrePrs();
void appBank(int line_num, const char *name);
void appPre(int line_num, const char *bank, const char *name);
void freePrePrs();

extern char pre_err[MAX_PRE_ERR];
extern int num_banks;
extern int num_pres;
extern char* pre_fname;
extern int pre_lnum;
extern char* bank[MAX_BANKS];
extern preStruct pre[MAX_PRES];