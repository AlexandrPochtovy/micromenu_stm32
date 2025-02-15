/**
              MICRO-MENU V2

          (C) Dean Camera, 2012
        www.fourwalledcubicle.com
     dean [at] fourwalledcubicle.com

        Royalty-free for all uses.
	                                  */
#ifndef _MICRO_MENU_H_
#define _MICRO_MENU_H_

	#include <stddef.h>
	#include <stdint.h>

/** Configuration for the macro or function required to read out a pointer from
 *  the memory storage space set by \ref const.
 *
 *  \param[in] Addr  Address of the pointer to read
 */
#define GET_MENU_ITEM_POINTER(Addr)   *(Addr)

/** Type define for a menu item. Menu items should be initialized via the helper
 *  macro \ref MENU_ITEM(), not created from this type directly in user-code.
 * parameter void (*KeyN_Callback)(void); is pointer to function for KeyN press processing, add and edit macro MENU_ITEM for your quantity keys
 */
typedef const struct Menu_Item {
	const struct Menu_Item *Next;		/*< Pointer to the next menu item of this menu item */
	const struct Menu_Item *Previous;	/*< Pointer to the previous menu item of this menu item */
	const struct Menu_Item *Parent;		/*< Pointer to the parent menu item of this menu item */
	const struct Menu_Item *Child;		/*< Pointer to the child menu item of this menu item */
	void (*MenuDisplayCallback)(void);	/*< Pointer to the optional menu-specific select callback of this menu item, use it for draw display */
	void (*Key1Callback)(void);			/*< Pointer to the optional menu-specific enter callback of this menu item, use it for KEY1 press processing */
	void (*Key2Callback)(void);			/*< Pointer to the optional menu-specific select callback of this menu item, use it for KEY2 press processing */
	void (*Key3Callback)(void);			/*< Pointer to the optional menu-specific enter callback of this menu item, use it for KEY3 press processing */
	void (*Key4Callback)(void);			/*< Pointer to the optional menu-specific select callback of this menu item, use it for KEY4 press processing */
	const char *Text; 					/*< Menu item text to pass to the menu display callback function */
} Menu_Item_t;

/** Creates a new menu item entry with the specified links and callbacks.
 *
 *  \param[in] Name      Name of the menu entry, must be unique.
 *  \param[in] Next      Name of the next linked menu item, or \ref NULL_MENU if no menu link.
 *  \param[in] Previous  Name of the previous linked menu item, or \ref NULL_MENU if no menu link.
 *  \param[in] Parent    Name of the parent linked menu item, or \ref NULL_MENU if no menu link.
 *  \param[in] Child     Name of the child linked menu item, or \ref NULL_MENU if no menu link.
 *  \param[in] SelectFunc  Function callback to execute when the menu item is selected, or \c NULL for no callback.
 *  \param[in] EnterFunc   Function callback to execute when the menu item is entered, or \c NULL for no callback.
 */
#define MENU_ITEM(Name, Next, Previous, Parent, Child, Select, Key1Func, Key2Func, Key3Func, Key4Func, Text) \
	extern Menu_Item_t const Next;     \
	extern Menu_Item_t const Previous; \
	extern Menu_Item_t const Parent;   \
	extern Menu_Item_t const Child;  \
	Menu_Item_t const Name = {&Next, &Previous, &Parent, &Child, Select, Key1Func, Key2Func, Key3Func, Key4Func, Text}

/** Relative navigational menu entry for \ref Menu_Navigate(), to move to the menu parent. */
#define MENU_PARENT		GET_MENU_ITEM_POINTER(&Menu_GetCurrentMenu()->Parent)
/** Relative navigational menu entry for \ref Menu_Navigate(), to move to the menu child. */
#define MENU_CHILD		GET_MENU_ITEM_POINTER(&Menu_GetCurrentMenu()->Child)
	/** Relative navigational menu entry for \ref Menu_Navigate(), to move to the next linked menu item. */
#define MENU_NEXT		GET_MENU_ITEM_POINTER(&Menu_GetCurrentMenu()->Next)
/** Relative navigational menu entry for \ref Menu_Navigate(), to move to the previous linked menu item. */
#define MENU_PREVIOUS	GET_MENU_ITEM_POINTER(&Menu_GetCurrentMenu()->Previous)

/** Null menu entry, used in \ref MENU_ITEM() definitions where no menu link is to be made. */
extern const Menu_Item_t NULL_MENU;

/** Retrieves the currently selected meny item.
 *
 *  \return Pointer to the currently selected meny item.
 */
Menu_Item_t* Menu_GetCurrentMenu(void);

/** Navigates to an absolute or relative menu entry.
 *
 * \param[in] NewMenu  Pointer to the absolute menu item to select, or one of \ref MENU_PARENT,
 *                     \ref MENU_CHILD, \ref MENU_NEXT or \ref MENU_PREVIOUS for relative navigation.
 */
void Menu_Navigate(Menu_Item_t* const NewMenu);

/** Run the currently selected menu item's configured select callback function. */
void Menu_RunKey1_Callback(void);
void Menu_RunKey2_Callback(void);
void Menu_RunKey3_Callback(void);
void Menu_RunKey4_Callback(void);

#endif
