#include "menu.h"

void Menu_1_Key1(void) {//reset value
    distance = 0;
}
void Menu_1_Key2(void) {//set default value
    distance = 110;
}
void Menu_1_Key3(void) {//up value
    ++distance;
}
void Menu_1_Key4(void) {//down value
    --distance;
}

void Menu_2_Key1(void) {//reset value
    doze = 0;
}
void Menu_2_Key2(void) {//set default value
    doze = 110;
}
void Menu_2_Key3(void) {//up value
    doze += 2;
}
void Menu_2_Key4(void) {//down value
    doze -= 3;
}

void Menu_3_Key1(void) {//reset value
    ramp = 0.0;
}
void Menu_3_Key2(void) {//set default value
    ramp = 1.5;
}
void Menu_3_Key3(void) {//up value
    ramp += 0.1;
}
void Menu_3_Key4(void) {//down value
    ramp -= 0.1;
}