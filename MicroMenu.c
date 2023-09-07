/**
              MICRO-MENU V2

          (C) Dean Camera, 2012
        www.fourwalledcubicle.com
     dean [at] fourwalledcubicle.com

        Royalty-free for all uses.
	                                  
--------------------------------------------------------------------------------------------------
31.08.2023 Alexandr Pochtovy

Fork micromenu for STM32.
*/

#include "MicroMenu.h"

/*	This is used when an invalid menu handle is required in
 *	a \ref MENU_ITEM() definition, i.e. to indicate that a
 *	menu has no linked parent, child, next or previous entry,
 *	for example, menu "main level" has no reference to return "back"
 */
static Menu_Item_t const NULL_MENU_POINT = {0};

/* 	Internal use only!
 *  Pointer to the generic menu text display function
 *  callback, to display the configured text of a menu item
 *  if no menu-specific display function has been set
 *  in the select menu item.
 */
static void (*MenuDrawDisplay)(void) = NULL;

/*	Internal use only!
 *	Pointer to the currently selected menu item.
 */
static Menu_Item_t* CurrentMenuItem = &NULL_MENU_POINT;


Menu_Item_t* Menu_GetCurrentMenu(void) {
	return CurrentMenuItem;
}

void Menu_Navigate(Menu_Item_t* const NewMenu) {
	if ((NewMenu == &NULL_MENU_POINT) || (NewMenu == NULL))
		return;

	CurrentMenuItem = NewMenu;

	if (MenuDrawDisplay != NULL)
		MenuDrawDisplay();

	void (*SelectCallback)(void) = MENU_ITEM_READ_POINTER(&CurrentMenuItem->SelectCallback);

	if (SelectCallback)
		SelectCallback();
}

void Menu_SetGenericWriteCallback(void (*SelectFunc)(void))
{
	MenuDrawDisplay = WriteFunc;
	Menu_Navigate(CurrentMenuItem);
}

void Menu_EnterCurrentItem(void (*EnterFunc)(void))
{
	if ((CurrentMenuItem == &NULL_MENU_POINT) || (CurrentMenuItem == NULL))
		return;

	void (*EnterCallback)(void) = MENU_ITEM_READ_POINTER(&CurrentMenuItem->EnterCallback);

	if (EnterCallback)
		EnterCallback();
}
