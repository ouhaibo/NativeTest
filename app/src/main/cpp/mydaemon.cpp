//
// Created by t540p on 2017/8/30.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/resource.h>

void start_daemon()
{
    int pid1 = fork();
    if (pid1 < 0)
    {
        printf("first fork failed!\n");
        exit(pid1);
    } else if (pid1 > 0)
    {
        exit(0);
    }
    int sid = setsid();
    if (sid < 0)
    {
        printf("create new session failed!\n");
        exit(0);
    }
    int pid2 = fork();
    if (pid2 < 0)
    {
        printf("second fork failed!\n");
        exit(pid2);
    } else if (pid2 > 0)
    {
        exit(0);
    }
    chdir("/");
    umask(0);
    rlimit r;
    if (r.rlim_max == RLIM_INFINITY)
    {
        r.rlim_max = 1024;
    }
    for (int i = 0; i < r.rlim_max; i++)
    {
        close(i);
    }

}

int main(int argc, char *const argv[])
{
    start_daemon();
}

