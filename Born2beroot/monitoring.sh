#!/bin/bash

# ARCHITECTURE
arch=$(uname -a)

# CPU PHYSICAL CORES
fcores=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL CORES
vcores=$(grep processor /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f", $3/$2*100)}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf("%.0fGb", disk_t/1024)}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3; disk_t += $2} END {printf("%d", disk_u/disk_t*100)}')

# CPU LOAD
cpu_ul=$(vmstat | tail -1 | awk '{print $15}')
cpu_op=$(expr 100 - $cpu_ul)
cpu_l=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvm=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONN
tcp_conn=$(ss -t | grep ESTAB | wc -l)

# USERS NO
users_no=$(users | wc -w)

# IP/MAC
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
scmd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $fcores
	vCPU: $vcores
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_l%
	Last boot: $lb
	LVM use: $lvm
	TCP Connections: $tcp_conn ESTABLISHED
	User log: $users_no
	Network: IP $ip ($mac)
	Sudo: $scmd cmd"
