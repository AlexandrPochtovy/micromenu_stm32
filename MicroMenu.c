/**
              MICRO-MENU V2

          (C) Dean Camera, 2012
        www.fourwalledcubicle.com
     dean [at] fourwalledcubicle.com

        Royalty-free for all uses.
	                                  */

#include "MicroMenu.h"

/** This is used when an invalid menu handle is required in
 *  a \ref MENU_ITEM() definition, i.e. to indicate that a
 *  menu has no linked parent, child, next or previous entry.
 */
const Menu_Item_t NULL_MENU = {0};

/** \internal
 *  Pointer to the currently selected menu item.
 */
static Menu_Item_t* CurrentMenuItem = &NULL_MENU;

/** \internal
 *  Pointer to the generic menu function callback: 
 * do something in EnterCallBack() and display something in SelectCallBack().
 * For example, change value and out the configured text of a menu item.
 */
static void (*EnterCallBackFunc)(void) = NULL;
static void (*SelectCallBackFunc)(void) = NULL;

Menu_Item_t* Menu_GetCurrentMenu(void)
{
	return CurrentMenuItem;
}

void Menu_Navigate(Menu_Item_t* const NewMenu)//All magic is here!
{
	if ((NewMenu != &NULL_MENU) && (NewMenu != NULL)) {
		CurrentMenuItem = NewMenu;
	}
	SelectCallBackFunc = GET_MENU_ITEM_POINTER(CurrentMenuItem->MenuDisplayCallback);
	if (SelectCallBackFunc) {
		SelectCallBackFunc();
	}
}

void Menu_RunKey1_Callback(void) {
	SelectCallBackFunc = GET_MENU_ITEM_POINTER(CurrentMenuItem->Key1Callback);
	if (SelectCallBackFunc) {
		SelectCallBackFunc();
	}
}

void Menu_RunKey2_Callback(void) {
		SelectCallBackFunc = GET_MENU_ITEM_POINTER(CurrentMenuItem->Key2Callback);
	if (SelectCallBackFunc) {
		SelectCallBackFunc();
	}
}

void Menu_RunKey3_Callback(void) {
		SelectCallBackFunc = GET_MENU_ITEM_POINTER(CurrentMenuItem->Key3Callback);
	if (SelectCallBackFunc) {
		SelectCallBackFunc();
	}
}

void Menu_RunKey4_Callback(void) {
		SelectCallBackFunc = GET_MENU_ITEM_POINTER(CurrentMenuItem->Key4Callback);
	if (SelectCallBackFunc) {
		SelectCallBackFunc();
	}
}