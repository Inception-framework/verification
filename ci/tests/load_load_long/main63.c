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
  __asm volatile("mov R0,#0x6c"); 
  __asm volatile("mov R2,#0x51"); 
  __asm volatile("mov R4,#0xc9"); 
  __asm volatile("mov R9,#0xe3"); 
  __asm volatile("mov R10,#0x12"); 
  __asm volatile("mov R11,#0xba"); 
  __asm volatile("mov R12,#0xa3"); 
  __asm volatile("mov R14,#0xd8"); 
  __asm volatile("LDR LR, [SP ,#-80]!");
  __asm volatile("mov R0,#0x12"); 
  __asm volatile("mov R2,#0xdc"); 
  __asm volatile("mov R4,#0xbe"); 
  __asm volatile("mov R9,#0x89"); 
  __asm volatile("mov R10,#0x0e"); 
  __asm volatile("mov R11,#0xee"); 
  __asm volatile("mov R12,#0xc2"); 
  __asm volatile("mov R14,#0x54"); 
  __asm volatile("LDR LR, [SP ,#-80]!");
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
