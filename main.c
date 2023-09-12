#include <stddef.h>
#include <stdio.h>

#include "MicroMenu.h"
#include "menu.h"

enum ButtonValues {
	KEY_NONE,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
};

int key;
int button;
int distance = 100;
int doze = 20;
float ramp = 1.5;

/** Generic function to write the text of a menu.
 *
 *  \param[in] Text   Text of the selected menu to write, in \ref MENU_ITEM_STORAGE memory space
 */

void Menu_1_Select(void) {//reset value
    printf("Hello in menu 1\n");
}

void Menu_2_Select(void) {//reset value
    printf("Hello in menu 2\n");
}

void Menu_3_Select(void) {//reset value
    printf("Hello in menu 3\n");
}

void Menu_1_1_Select(void) {//reset value
    printf("distance value = %d\n", distance);
}

void Menu_2_1_Select(void) {//reset value
    printf("doze value = %d\n", doze);
}

void Menu_3_1_Select(void) {//reset value
    printf("ramp value = %f\n", ramp);
}


//create: menu name		next	prev		parent		child		f sel			f key1	f key2	f key3		f key4, 	text menu
MENU_ITEM(Menu_1,	Menu_2,		Menu_3,		NULL_MENU,	Menu_1_1,	Menu_1_Select,	NULL,		NULL,			NULL,		NULL,		"1");
MENU_ITEM(Menu_2,	Menu_3,		Menu_1,		NULL_MENU,	Menu_2_1,	Menu_2_Select,	NULL,		NULL,			NULL,		NULL, 		"2");
MENU_ITEM(Menu_3,	Menu_1,		Menu_2,		NULL_MENU,	Menu_3_1,	Menu_3_Select,	NULL,		NULL,			NULL,		NULL, 		"3");

MENU_ITEM(Menu_1_1, NULL_MENU, 	NULL_MENU, 	Menu_1, 	NULL_MENU, 	Menu_1_1_Select,Menu_1_Key3,Menu_1_Key4,	NULL,	NULL,"1.1");
MENU_ITEM(Menu_2_1, NULL_MENU, 	NULL_MENU, 	Menu_2, 	NULL_MENU, 	Menu_2_1_Select,Menu_2_Key3,Menu_2_Key4,	NULL,	NULL,"2.1");
MENU_ITEM(Menu_3_1, NULL_MENU, 	NULL_MENU, 	Menu_3, 	NULL_MENU, 	Menu_3_1_Select,Menu_3_Key3,Menu_3_Key4,	NULL,	NULL,"3.1");

int main()
{
	/* Set up the default menu text write callback, and navigate to an absolute menu item entry. */
	//Menu_SetGenericWriteCallback(Generic_Write);
	Menu_Navigate(&Menu_1);

    while (1)
    {
		/* Example usage of MicroMenu - here you can create your custom menu navigation system; you may wish to perform
		 * other tasks while detecting key presses, enter sleep mode while waiting for user input, etc.
		 */
		printf("Select menu: 1 - prev, 2 - next, 3 - parent, 4 - child -> ");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			Menu_Navigate(MENU_PREVIOUS);
			Menu_RunKey1_Callback();
			break;
		case 2:
			Menu_Navigate(MENU_NEXT);
			Menu_RunKey2_Callback();
			break;
		case 3:
			Menu_Navigate(MENU_PARENT);
			Menu_RunKey3_Callback();
			break;
		case 4:
			Menu_Navigate(MENU_CHILD);
			Menu_RunKey4_Callback();
			break;
		default:
			break;
		}
		key = 0;
    }
	return 0;
}
