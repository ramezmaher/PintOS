#include "devices/shutdown.h"
#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/vaddr.h"
#include "threads/synch.h"
#include "threads/malloc.h"
#include "userprog/process.h"
#include "userprog/pagedir.h"

typedef int pid_t;

struct lock files_sync_lock;
int fd_num;

static void syscall_handler(struct intr_frame *);


void 
syscall_init(void)
{
  intr_register_int(0x30, 3, INTR_ON, syscall_handler, "syscall");
  lock_init(&files_sync_lock);
  fd_num = 2;
}


static int
get_data (const uint8_t *uaddr)
{
  int result;
  asm ("movl $1f, %0; movzbl %1, %0; 1:"
  : "=&a" (result) : "m" (*uaddr));
  return result;
}


static bool
put_data (uint8_t *udst, uint8_t byte)
{
  int error_code;
  asm ("movl $1f, %0; movb %b2, %1; 1:"
  : "=&a" (error_code), "=m" (*udst) : "q" (byte));
  return error_code != -1;
}

static bool 
validate(void *ptr) {
  return ptr != NULL && is_user_vaddr(ptr) && get_data(ptr) != -1;
}


static void 
validate_multiple(void *ptr, int size) {
  char *temp = ptr;
  if (!validate(temp + size - 1)) {
    exit(-1);
  }
}

static int 
GET_ARG(void *ptr, int offset)
{
  int *temp = (int*) ptr + offset;
  validate_multiple(temp, 4);
  return *temp;
}


static void
syscall_handler(struct intr_frame *f)
{
  switch ((int)GET_ARG(f->esp, 0))
  {
  case SYS_HALT:
    //halt_wrapper();
    break;
  case SYS_EXIT:
    exit_wrapper(f->esp);
    break;
  case SYS_EXEC:
    f -> eax = exec_wrapper(f->esp);
    break;
  case SYS_WAIT:
    f -> eax = wait_wrapper(f->esp);
    break;
  case SYS_CREATE:
    //f->eax = create_wrapper();
    break;
  case SYS_REMOVE:
    //f->eax = remove_wrapper();
    break;
  case SYS_OPEN:
    //f->eax = open_wrapper();
    break;
  case SYS_FILESIZE:
    //f->eax = filesize_wrapper();
    break;
  case SYS_READ:
    //f->eax = read_wrapper();
    break;
  case SYS_WRITE:
    f -> eax = write_wrapper(f->esp);
    break;
  case SYS_SEEK:
    //f->eax = seek_wrapper();
    break;
  case SYS_TELL:
    //f->eax = tell_wrapper();
    break;
  case SYS_CLOSE:
    //f->eax = close_wrapper();
    break;
  default:
    break;
  }
}

void halt_wrapper (void){

}

void exit_wrapper (int* esp){
  exit(GET_ARG(esp, 1));
}
pid_t exec_wrapper (const char *esp){
  int arg = GET_ARG(esp, 1);
  validate_multiple(arg, 4);
  return exec (arg);
}
int wait_wrapper (pid_t* esp){
  return wait(GET_ARG(esp, 1));
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
  int fd = GET_ARG(esp, 1);
  void* buffer = GET_ARG(esp, 2);
  unsigned size = GET_ARG(esp, 3);
  validate_multiple(buffer, size);
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
  printf("%s: exit(%d)\n", thread_current()->name, status);
  if(thread_current()->self != NULL)
  {
    thread_current()->self->exit_status = status;
    thread_current()->self->t =NULL;
  }
  thread_exit();
  NOT_REACHED();
}

pid_t exec (const char *cmd_line){
  return process_execute(cmd_line);
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