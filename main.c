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

char key;
int button;
int distance = 100;
int doze = 20;

/** Generic function to write the text of a menu.
 *
 *  \param[in] Text   Text of the selected menu to write, in \ref MENU_ITEM_STORAGE memory space
 */
/*static void Generic_Write(const char* Text)
{
	if (Text)
		printf(Text);
}*/
//create: menu name		next		prev		parent		child		func select		func enter		text menu
MENU_ITEM(Menu_1,		Menu_2,		Menu_3,		NULL_MENU,	Menu_1_1,	NULL,			NULL,			"1");
MENU_ITEM(Menu_2,		Menu_3,		Menu_1,		NULL_MENU,	NULL_MENU,	NULL,			NULL,			"2");
MENU_ITEM(Menu_3,		Menu_1,		Menu_2,		NULL_MENU,	NULL_MENU,	NULL,			NULL,			"3");

MENU_ITEM(Menu_1_1, 	Menu_1_2, 	Menu_1_2, 	Menu_1, 	NULL_MENU, 	NULL,			NULL,			"1.1");
MENU_ITEM(Menu_1_2, 	Menu_1_1, 	Menu_1_1, 	Menu_1, 	NULL_MENU, 	NULL,			NULL,			"1.2");

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
		printf("Select menu: 1 - prev, 2 - next, 3 - parent, 4 - child ->");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			button = KEY_1;
			break;
		case 2:
			button = KEY_2;
			break;
		case 3:
			button = KEY_3;
			break;
		case 4:
			button = KEY_4;
			break;
		default:
			button = KEY_NONE;
			break;
		}
		switch (button)
		{
			case KEY_1:
				Menu_Navigate(MENU_PREVIOUS);
				break;
			case KEY_2:
				Menu_Navigate(MENU_NEXT);
				break;
			case KEY_3:
				Menu_Navigate(MENU_PARENT);
				break;
			case KEY_4:
				Menu_Navigate(MENU_CHILD);
				break;
			case KEY_NONE:
				break;
			default:
				break;
		}
		key = 0;
    }
	return 0;
}
