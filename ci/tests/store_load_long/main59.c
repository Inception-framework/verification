#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  #ifndef KLEE
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  #endif
  __asm volatile("mov R9,sp"); 
  __asm volatile("mov R1,#0x6b"); 
  __asm volatile("mov R2,#0xf9"); 
  __asm volatile("mov R6,#0xc7"); 
  __asm volatile("mov R7,#0x01"); 
  __asm volatile("mov R11,#0x88"); 
  __asm volatile("mov R14,#0x34"); 
  __asm volatile("STMDB R9!, {R1, R7, LR, R7, R7, R11}");
  __asm volatile("mov R1,#0x30"); 
  __asm volatile("mov R2,#0x0e"); 
  __asm volatile("mov R6,#0xdd"); 
  __asm volatile("mov R7,#0xe4"); 
  __asm volatile("mov R11,#0x75"); 
  __asm volatile("mov R14,#0xa2"); 
  __asm volatile("LDMDB R9!, {R1, R7, LR, R7, R7, R11}");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  int i;  for(i=0;i<2050;i++){
      STACK[2050-1-i]=i;
  }
  foo();
}
