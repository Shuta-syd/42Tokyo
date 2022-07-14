#!/bin/bash
OS=`uname -a`
CPU_P=`lscpu | grep Socket | cut -f 2 -d ":" | tr -d " "`
V_CPU=`fgrep 'processor' /proc/cpuinfo | wc -l`
total_ram=`free -m | grep Mem: | awk '/ /{print $2}'`
used_ram=`free -m | grep Mem: | awk '/ /{print $3}'`
free_ram=`free -m | grep Mem: | awk '/ /{print $4}'`
parcent_ram=`free | grep Mem: | awk '{printf("%.2f"), $3/$2*100}'`
u_disk=`df -am | grep /dev/mapper | awk '{sum += $3}END{print sum}'`
a_disk=`df -am | grep /dev/mapper | awk '{sum += $2}END{print sum}'`
p_disk=`df -am | grep /dev/mapper | awk '{ad += $2}{ud += $3}END{printf("%d"), ud /ad * 100}'`
CPU_L=`mpstat | grep all | awk '{printf "%.2%%", $5*100}'`
LAST_DATE=`who -b | awk '{print("%s %s"), $2, $3}'`
IF=$(lsblk | grep lvm | wc -l)
if [ $IF -gt 0 ]; then
	LVM="yes"
else
	LVM="no"
fi
CONNECT_TCP=`netstat -ta | grep ESTABLISHED | wc -l`
USER_C=`users | wc -w`
IP=`hostname -I`
MAC=`ip address show | grep ether | awk '{print $2}'`
SUDO_LOG=`grep sudo: /var/log/auth.log | grep COMMAND | wc -l`

# output
wall "	#Architecture: ${OS}
		#CPU physical: ${CPU_P}
		#vCPU: ${V_CPU}
		#Memory Usage: ${userd_ram}/${total_ram}MB (${parcent_ram}%)
		#Disk Usage: ${u_disk}/${a_disk}Gb (${p_disk})
		#CPU load: ${CPU_L}
		#Last boot: ${LAST_DATE}
		#LVM use: ${LVM}
		#Connections TCP: ${CONNECT_TCP} ESTABLISHED
		#User log: ${USER_C}
		#Network IP: ${IP} (${MAC})
		#Sudo: ${SUDO_LOG} cmd"



