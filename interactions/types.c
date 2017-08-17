typedef struct {
  int a;
  int b;
} my_type;

__attribute__((naked))
int foo(my_type* mt){
  __asm volatile("ldr r1,[r0]");
  __asm volatile("add r1,r1,#1");
  __asm volatile("str r1,[r0]");
  __asm volatile("str r1,[r0,#4]");
  __asm volatile("bx lr");
}

__attribute__((naked))
char bar(char a){
  __asm volatile("add r0,r0,#1");
  __asm volatile("bx lr");
}

__attribute__((naked))
my_type* mario(my_type* my_thing){
  __asm volatile("add r0,r0,#1");
  __asm volatile("bx lr");
}

void main(void){
 int i = 0;
 //#ifndef NOPRINT
 //klee_make_symbolic(&global,sizeof global,"global");
 //#endif
 my_type my_thing;
 my_thing.a = 0;
 foo(&my_thing);
 char b = bar(1);
 my_type* my_thing2_ptr = mario(&my_thing);
 #ifndef NOPRINT
 printf("my_thing .a=%d .b=%d\n",my_thing.a,my_thing.b);
 printf("b=%d\n",b);
 printf("&my_thing=%p, mt_thing2_ptr=%p\n",&my_thing,my_thing2_ptr);
 #endif
}
