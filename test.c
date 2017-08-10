/*name:       test.c
 *function:   调用daemon使函数成为一个守护进程
 */

#include <stdio.h>
#include <time.h>

int main()
{
   FILE *fp;
   time_t t;
   daemon_init();

   while(1)
   {
       sleep(1);
       if((fp=fopen("print_time","a"))>=0)
       {
         t=time(0);
	 fprintf(fp, "the time right now is : %s",asctime(localtime(&t)));
	 fclose(fp);
       }
   }
   return;
}
