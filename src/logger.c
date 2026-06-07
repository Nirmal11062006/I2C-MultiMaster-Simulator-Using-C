#include <stdio.h>
#include "logger.h"
void log_info(const char *message)
{
	printf("info->%s\n",message);
}
void log_error(const char *message)
{
	printf("error->%s\n",message);
}
void log_master(int id,const char *message)
{
	printf("master:%d %s\n",id,message);
}
