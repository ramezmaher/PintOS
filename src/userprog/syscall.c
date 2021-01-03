#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

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
     
  thread_exit ();
}

int get_int (int** esp){

}

char* get_char_ptr (char*** esp){

}

void* get_void_char (void*** esp){

}

void validate_void_ptr (const void* pt){

}
