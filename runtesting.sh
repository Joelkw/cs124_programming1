#!/bin/bash 
# 
#SBATCH -n 1 # Number of cores 
#SBATCH -N 1 # Ensure that all cores are on one machine 
#SBATCH -t 0-00:01 # Runtime in D-HH:MM 
#SBATCH -p serial_requeue # Partition to submit to 
#SBATCH --mem=1 # Memory pool for all cores (see also --mem-per-cpu) 
#SBATCH -o hostname.out # File to which STDOUT will be written 
#SBATCH -e hostname.err # File to which STDERR will be written 
#SBATCH --mail-type=END # Type of email notification- BEGIN,END,FAIL,ALL 
#SBATCH --mail-user=joelkwartler@college.harvard.edu # Email to which notifications will be sent   

hostname

./testing

