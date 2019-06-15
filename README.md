# Corewar
- **Binary name:** asm *.asm, corewar .cor, .cor [.cor, .cor] 
- **Group members:**
  - [@Kilio22](https://github.com/Kilio22)
  - [@HeyShafty](https://github.com/HeyShafty)
  - [@Monsterskx](https://github.com/Monsterskx)
- **Mark:** 100%
 
# Subject

Corewar is a game. A very special game. It consists of pitting little programs against one another in a virtual machine.
The goal of the game is to prevent the other programs from functioning correctly by using all available means.

The game will, therefore, create a virtual machine in which the programs (written by the players) will face off. Each
program’s objective is to "survive", that is to say executing a special instruction ("live") that means I’m still alive.
These programs simultaneously execute in the virtual machine and in the same memory zone, which enables them
to write on one another.
The winner of the game is the last one to have executed the "live" instruction

The project is divided into three seperate parts:
- **The Virtual Machine:** It houses the fighting binary programs (called champions), and provides them with a standard execution environment. It offers all kind of features that are useful to the champions’ fights. It must obviously be able to
execute several programs at once...
- **The Assembler:** It enables you to write programs designed to fight (the champions). It therefore understands the assembly language and generates binary programs that the virtual machine can execute.
- **Champions:** This is your personal handiwork. They must be able to fight and to victoriously leave the virtual machine arena.
They are written in the assembly language specific to our virtual machine (described further on).

This project is one of the most important during first year at Epitech, done in 2 weeks.
For more informations, please read the **Subject.pdf**.

# How to use it ?
- **The assembler:** The assembler need a file given as parameter with valid instructions. It will therefore compile this file to a .cor file which can be used with the Virtual Machine.
  To create a valid file, see the subject.pdf.
- **The Virtual machine:** The virtual machine need at list two champions compiled previously with the asm. The program will after that put the champions into the same arena, and execute the instructions of each champions.

# Bonus
- **Decompiler:** You can find in the asm/bonus directory a file decompilos.tar, which is a program able to convert a .cor file, to a .s file.
- **Virtual Machine:** You can find in the corewar/bonus directory a file this_is_wow.tar, which a graphical version of the corewar, representing the memory and the PC's of each champions.
  It give some informations in real time during the fight.
- **Bonus instructions:** In the directory asm/bonus, you can find an other version of the asm, which is able to manage other instructions.
  Here is a list of theses instructions :
    - Push: Reproduce the behavior of the Push instruction used by the processor.
    - Pop: Reproduce the behavior of the Pop instruction used by the processor.
    - cmp : Compare the 2 values given as parameters, update the carry.
    - Conditionnal jumps : nzjmp, ejmp, nejmp, nlejmp, nljmp, gjmp, gejmp, ngejmp, ngjmp, ljmp --> Depending of the carry value, it jumps to the value (champ_pc + (arg % IDX_MOD) - 3) % MEM_SIZE, where arg is the argument given as parameter to the instruction.
    
# How does it looks like ?
![alt text](https://github.com/Kilio22/Corewar/blob/master/fig1.png?raw=true)
![alt text](https://github.com/Kilio22/Corewar/blob/master/fig2.png?raw=true)
