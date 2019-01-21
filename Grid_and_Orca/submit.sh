# submit all jobs
#! /bin/bash

for a in `ls *.qsub`
do
qsub $a
done
