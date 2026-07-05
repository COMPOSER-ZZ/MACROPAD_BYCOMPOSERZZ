#include <Arduino.h>
#include <Button.h>

constexpr uint8_t NUM_BUTTONS = 9;

Button buttons[NUM_BUTTONS] = {
    Button(4),
    Button(5),
    Button(6),
    Button(7),
    Button(15),
    Button(16),
    Button(17),
    Button(18),
    Button(8)
};

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("=================================");
    Serial.println(" MacroPad - Button Test");
    Serial.println("=================================");

    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        buttons[i].begin();
    }
}

void loop()
{
    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        buttons[i].update();

        if (buttons[i].isPressed())
        {
            Serial.print("Button ");
            Serial.print(i + 1);
            Serial.println(" Pressed");
        }
    }
}