#include<stdio.h>
#define N 1000
int main() {
int n, i, j;
int a[N];
// считываем количество чисел n
scanf("%d", &n);
// считываем n чисел
for(i = 0 ; i < n; i++) {
scanf("%d", &a[i]);
}
for(i = 0 ; i < n ; i++) {
// сравниваем два соседних элемента.
for(j = 0 ; j < n - i - 1 ; j++) {
if(a[j] > a[j+1]) {
// если они идут в неправильном порядке, то
// меняем их местами.
int tmp = a[j]; a[j] = a[j+1] ; a[j+1] = tmp;
}
}
}
}