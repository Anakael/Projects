program Three;
Var 
  x,y,sum:real; otv:char;
begin
  sum:=0;
  otv:='Д';
    while (otv='Д') or (otv='д') do
      begin
         write('Введите числа x,y > 0 ');
        readln(x,y);
        writeln('Их произведение = ',x*y:8:3);
       sum:=sum+x+y;

       write('Завершить программу (Д/Н)? ');
       readln(otv);
     end;
   writeln('Общая сумма = ',sum:8:3);
   readln
end.
