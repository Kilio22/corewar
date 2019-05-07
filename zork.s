#
# zork.sforcorewar
#
# BobBylan
#
# SatNov1003:24;302081
#

.name "zork"
.comment "justabasiclivingprog"

l2:
sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
