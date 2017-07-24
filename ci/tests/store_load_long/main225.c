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
  __asm volatile("mov R0,#0x29"); 
  __asm volatile("mov R5,#0x14"); 
  __asm volatile("mov R7,#0x56"); 
  __asm volatile("mov R8,#0xd8"); 
  __asm volatile("mov R10,#0x56"); 
  __asm volatile("mov R11,#0x1a"); 
  __asm volatile("STR R7, [R9, +R5]");
  __asm volatile("mov R0,#0xab"); 
  __asm volatile("mov R5,#0xc2"); 
  __asm volatile("mov R7,#0xe7"); 
  __asm volatile("mov R8,#0x50"); 
  __asm volatile("mov R10,#0x79"); 
  __asm volatile("mov R11,#0x38"); 
  __asm volatile("LDR R7, [R9, +R5]");
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
