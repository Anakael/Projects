/* root.c: Вычисление корня трансцендентного уравнения */
#include <stdio.h>
#include <math.h>
#define EPS 1e-10 // точность результата
double f(double x) {
return exp(x) - 2 - x;
}
int main() {
double l = 0, r = 2, c;
while( r - l > EPS ) {
c = ( l + r ) / 2; // вычисляем середину отрезка;
if( f(c) * f(r) < 0 ) // узнаем, в какой из частей
l = c; // находится искомый корень;
else
r = c;
}
printf ("%.10lf\n", (l + r)/2 ); // выводим результат
}