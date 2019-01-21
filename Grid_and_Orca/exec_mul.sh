# generate job submission scripts for orca calculations
for ((a=0;a<36;a++))
do

cat << EOF > exec_$a.qsub
#/bin/bash -login
#PBS -l walltime=146:00:00,mem=8gb,nodes=1:ppn=1
#PBS -j oe

for((b=1;b<=36;b+=1))
do

cd \${PBS_O_WORKDIR}

/mnt/home/jinchi/my_orca/orca_3_0_3_linux_x86-64/orca conf_new\$[$[a*36]+\$b].orca>conf_new\$[$[a*36]+\$b].out
qstat -f $PBS_JOBID

done
EOF
done
