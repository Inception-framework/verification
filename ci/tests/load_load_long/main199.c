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
  __asm volatile("mov R0,#0x65"); 
  __asm volatile("mov R2,#0x30"); 
  __asm volatile("mov R4,#0x87"); 
  __asm volatile("mov R5,#0xd9"); 
  __asm volatile("mov R7,#0x2f"); 
  __asm volatile("mov R10,#0xd1"); 
  __asm volatile("mov R11,#0xe3"); 
  __asm volatile("mov R12,#0x64"); 
  __asm volatile("mov R14,#0x31"); 
  __asm volatile("LDRH R12, [R9, +LR]");
  __asm volatile("mov R0,#0xd3"); 
  __asm volatile("mov R2,#0x62"); 
  __asm volatile("mov R4,#0x2d"); 
  __asm volatile("mov R5,#0xab"); 
  __asm volatile("mov R7,#0xb9"); 
  __asm volatile("mov R10,#0x80"); 
  __asm volatile("mov R11,#0x30"); 
  __asm volatile("mov R12,#0x95"); 
  __asm volatile("mov R14,#0x17"); 
  __asm volatile("LDRH R12, [R9, +LR]");
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