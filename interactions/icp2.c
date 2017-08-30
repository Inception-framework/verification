#include "../Analyzer/include/klee/klee.h"
//int R0;
//
//void test(int * array, int size){
//  int i;
//  for(i=0;i<size;i++){
//    R0 = array[i];
//  }
//}
//
//void main(void){
//int x[3]={1,2,3};
//__asm volatile("mov r0,r0");
//test(x,3);
//}

//__attribute__((naked))
void foo(void){
//  __asm volatile("bx lr");
  #ifndef NOPRINT
  printf("hello from foo\n",&foo);
  #endif
}

void foo2(void){
//  __asm volatile("bx lr");
  #ifndef NOPRINT
  printf("hello from foo2\n",&foo);
  #endif
}

void call(void (*fptr)(void)){
   __asm volatile("mov r0,r0");
   fptr();
}

void main(void){
  //foo(&foo);
  #ifndef NOPRINT
  printf("&foo = %p\ncalling it:\n",&foo);
  #endif
  void (*fptr)(void);
  fptr = &foo;
  fptr();
  #ifndef NOPRINT
  klee_make_symbolic(&fptr,sizeof(fptr),"fptr");
  klee_assume(fptr == &foo || fptr == &foo2 || fptr == 0xdeadbeef );
  printf("now passing the ptr to a llvm-asm func which will call it:\n");
  #endif
  call(fptr);
 
}
