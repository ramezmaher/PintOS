#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include <user/syscall.h>


static void syscall_handler (struct intr_frame *);
static struct lock files_sync_lock;
int get_int (int** esp);
char* get_char_ptr (char*** esp);
void* get_void_char (void*** esp);
void validate_void_ptr (const void* pt);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  
  /* READ INTEGER FROM STACK. */
  
  /* SWITCH STATEMENT ACCORDING TO INTEGER READ
     AND CALLS PROPER SYSTEM CALL WRAPPER.      */ 

  switch (get_int(f->esp)){
    case 0:
    //halt_wrapper();
    case 1:
      exit_wrapper(f->esp);
    case 2:
    //exec_wrapper();
    case 3:
      f->eax = wait_wrapper(f->esp);
    case 4:
    //create_wrapper();
    case 5:
    //remove_wrapper();
    case 6:
    //open_wrapper();
    case 7:
    //filesize_wrapper();
    case 8:
    //read_wrapper();
    case 9:
      f->eax = write_wrapper(f->esp);
    case 10:
    //seek_wrapper();
    case 11:
    //tell_wrapper();
    case 12:
    //close_wrapper();
    default :
      exit(1);
  }
  thread_exit ();
}

int get_int (int** esp){
  return esp;
}

char* get_char_ptr (char*** esp){

}

void* get_void_char (void*** esp){

}

void validate_void_ptr (const void* pt){

}

void halt_wrapper (void){

}

void exit_wrapper (int* esp){
  exit(*(esp + 1));
}
pid_t exec_wrapper (const char *cmd_line){

}
int wait_wrapper (pid_t* esp){
  pid_t pid = *(esp + 1) ;
  return wait(pid);
}
bool create_wrapper (const char *file, unsigned initial_size){

}
bool remove_wrapper (const char *file){

}
int open_wrapper (const char *file){

}
int filesize_wrapper (int fd){

}
int read_wrapper (int fd, void *buffer, unsigned size){

}
int write_wrapper(int* esp){
  int fd = *(esp + 1 );
  void* buffer = (void*)(*(esp+2));
  unsigned size = * ((unsigned*)esp + 3);
  return write(fd, buffer, size);
}
void seek_wrapper (int fd, unsigned position){

}
unsigned tell_wrapper (int fd){

}
void close_wrapper (int fd){

}


void halt (void){

}

void exit (int status){
  process_exit();
}
pid_t exec (const char *cmd_line){

}
int wait (pid_t pid){
  process_wait(pid);
}
bool create (const char *file, unsigned initial_size){

}
bool remove (const char *file){

}
int open (const char *file){

}
int filesize (int fd){

}
int read (int fd, void *buffer, unsigned size){

}
int write (int fd, const void *buffer, unsigned size){
  if (fd == 1)
  {
    putbuf(buffer, size);
    return size;
  }
}
void seek (int fd, unsigned position){

}
unsigned tell (int fd){

}
void close (int fd){

}
