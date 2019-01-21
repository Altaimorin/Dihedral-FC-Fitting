diary('d2_YOPRO_s1_4cos.txt')
for i=-180:1:180
string = strcat('d2_at_',int2str(i),'.txt')
%output = strcat('d2_at_',int2str(i),'_output.txt')
if(~exist(string,'file'))
continue;
else
T = load(string);
x = T(:,1);
y = T(:,2);
y2 = y -min(y);
f5 = fit(x,y2,'a0+a2/2*(1+cos((2*x-b2)*3.14159265/180))+a4/2*(1+cos((4*x-b4)*3.14159265/180))+a6/2*(1+cos((6*x-b6)*3.14159265/180))+a8/2*cos(1+cos((8*x-b8)*3.14159265/180))')

figure
plot(f5,x,y2)

end
end
diary off
