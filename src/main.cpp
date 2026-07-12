#include <Arduino.h>

#include "PinDefinitions.h"
#include "Button.h"
#include "EventManager.h"
#include "EventListener.h"


//-------------------- BOTONES --------------------

Button btn1(Pins::BTN1);
Button btn2(Pins::BTN2);
Button btn3(Pins::BTN3);
Button btn4(Pins::BTN4);
Button btn5(Pins::BTN5);

Button btn6(Pins::BTN6);
Button btn7(Pins::BTN7);
Button btn8(Pins::BTN8);
Button btn9(Pins::BTN9);
Button btn10(Pins::BTN10);

Button btn11(Pins::BTN11);
Button btn12(Pins::BTN12);
Button btn13(Pins::BTN13);
Button btn14(Pins::BTN14);
Button btn15(Pins::BTN15);


Button* buttons[] =
{
    &btn1,
    &btn2,
    &btn3,
    &btn4,
    &btn5,

    &btn6,
    &btn7,
    &btn8,
    &btn9,
    &btn10,

    &btn11,
    &btn12,
    &btn13,
    &btn14,
    &btn15
};


const uint8_t NUM_BUTTONS = sizeof(buttons) / sizeof(buttons[0]);


//-------------------- EVENTOS --------------------

EventManager eventManager;

EventListener eventListener;


//-------------------- SETUP --------------------

void setup()
{
    
    Serial.begin(115200);

    delay(2000);


    eventManager.begin();

    // Conectar EventManager con EventListener
    eventManager.setListener(&eventListener);


    Serial.println();
    Serial.println("=================================");
    Serial.println("   MACROPAD BY COMPOSERZZ");
    Serial.println("=================================");
    Serial.println("Iniciando...");


    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {

        buttons[i]->begin();


        Serial.print("Boton ");
        Serial.print(i + 1);
        Serial.println(" inicializado");

    }


    Serial.println();

    Serial.println("Setup terminado.");

    Serial.println("Esperando pulsaciones...");

    Serial.println();

}



//-------------------- LOOP --------------------

void loop()
{

    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {

        buttons[i]->update();


        if (buttons[i]->isPressed())
        {

            eventManager.onPress(i);

        }


        if (buttons[i]->isReleased())
        {

            eventManager.onRelease(i);

        }

    }


    eventManager.update();


    delay(1);

}