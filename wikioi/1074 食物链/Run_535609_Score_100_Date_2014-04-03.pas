program poj_1182;
var
  f,r:array[0..50001] of longint;
  n,m,i,j,k,x,y,z,ans,fx,fy:longint;
function find(x:longint):longint;
var
  temp:longint;
begin
  if f[x]=x then exit(x);
  temp:=f[x];
  f[x]:=find(temp);
  r[x]:=(r[temp]+r[x]) mod 3;
  exit(f[x]);
end;
procedure combine(x,y,z:longint);
var
  fx,fy:longint;
begin
  fx:=find(x); fy:=find(y);
  f[fy]:=fx;
  r[fy]:=(3+(z-1)+r[x]-r[y]) mod 3;
end;
begin
  readln(n,m);
  for i:=1 to n do f[i]:=i;
  ans:=0;
  for i:=1 to m do begin
    readln(z,x,y);
    if (x>n) or (y>n) then inc(ans)     
      else if (z=2) and (x=y) then inc(ans)     
        else begin
          fx:=find(x);
          fy:=find(y);
          if fx<>fy then combine(x,y,z)
          else if (z=1) and (r[x]<>r[y]) then inc(ans)         
            else if (z=2) and ((r[y]-r[x]+3) mod 3<>1) then inc(ans);
        end;
  end;
  writeln(ans);
end.