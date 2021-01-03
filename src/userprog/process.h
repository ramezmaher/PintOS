#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

struct open_file
{
   int fd;
   FILE* ptr;
};

struct child_process
{
   tid_t pid;
   struct thread* t;
};

#endif /* userprog/process.h */
