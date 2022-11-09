#include <Arduino.h>
#include <BleCombo.h>

int x, y;
bool centor, pre_centor, top;

void setup()
{
    pinMode(26, INPUT);
    pinMode(33, INPUT);
    pinMode(21, INPUT_PULLUP);
    pinMode(22, INPUT_PULLUP);
    Keyboard.begin();

    Serial.begin(9600);
}

void loop()
{
    while(Keyboard.isConnected())
    {
        x = analogRead(26);
        y = analogRead(33);
        top = digitalRead(21);
        centor = digitalRead(22);

        Serial.println("Sending 'Hello world'");
        
        // x axis
        if(1100 < x && x < 1550) Keyboard.println("a");
        else if(x < 1101) Keyboard.println("a");
        else if(1950 < x && x < 2400) Keyboard.println("d");
        else if(2400 < x) Keyboard.println("d");

        // y axis
        if(1100 < y && y < 1550) Keyboard.println("w");
        else if(y < 1101) Keyboard.println("w");
        else if(1950 < y && y < 2400) Keyboard.println("s");
        else if(2400 < y) Keyboard.println("s");

        // centor button (bag)
        if(centor && !pre_centor)
        {
            Keyboard.println("e");
            pre_centor = centor;
        }
    }

    Serial.println("Reconnect!");
    delay(2000);
}