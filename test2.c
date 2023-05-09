#include <stdio.h>
#include <unistd.h>
pid_t c;
int main() {
 c = fork();
 int x = 5;
 if (c == 0)
   x += 5;
 else {
   c = fork();
   x += 10;
   if (c)
     x += 5;
 }
printf("%d",x);
 return 0;
}
