/*
** EPITECH PROJECT, 2019
** asm
** File description:
** op_needs_args
*/

#include "asm.h"

bool op_needs_args(int index)
{
    if (index == 0 || index == 8 || index == 11 || index == 14)
        return false;
    return true;
}
