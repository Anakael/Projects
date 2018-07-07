Program One;
Var 
  Z, А : Real; M : integer;
Function Step (N: integer; X:real): real;
Var 
  I: integer; Y: Real;
    Begin
      I:=1; Y:=1;
      While I<=N do
        Begin
          Y:=Y*X; I:=I+1;
        End;
          Step:=Y;
      End; 
Begin
   Write(‘Введи степень и возводимое число’); Readln(Z,M);
   F:=Step(M,Z);
   Writeln(Z, ‘ в степени’, M, ‘=’,F);
End.