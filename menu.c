#include "menu.h"

void Menu1_Select(void) 	{ printf("Menu lvl 1. Distance = %d\n", distance); }
void Menu1_Enter(void) 		{ ++distance; }

void Menu2_Select(void) 	{ printf("Menu lvl 1. Distance = %d\n", distance); }
void Menu2_Enter(void) 		{ --distance; }

void Menu3_Select(void) 	{ printf("Menu lvl 3 is empty\n"); }
void Menu3_Enter(void) 		{ printf("Menu lvl 3 is empty\n"); }

void Menu1_1_Select(void) 	{ printf("Select menu lvl 1_1. Doze = %d\n", doze); }
void Menu1_1_Enter(void) 	{ ++doze; }

void Menu1_2_Select(void) 	{ printf("Select menu lvl 1_1. Doze = %d\n", doze); }
void Menu1_2_Enter(void) 	{ --doze; }