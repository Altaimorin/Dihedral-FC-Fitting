for((a=1;a<=1296;a++))
do

cat << EOF > min_${a}.in
MINIMIZATION
 &cntrl
  imin = 1,
  maxcyc = 4, ncyc = 1, ntb = 0, igb = 0, cut = 12,ntpr=1,
/
EOF

sander -O -i min_${a}.in -o min_${a}.out -p YOPRO.top -c conf${a}.crd -r conf${a}.rst -ref conf${a}.crd < /dev/null

done
