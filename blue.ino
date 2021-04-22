
int segmentosArr[] = {PA5, PA4, PA10, PA9, PA8, PA6, PA7};
int numeros[][10] = {
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 0, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1}, //9
    {1, 1, 1, 1, 1, 1, 0}, //0
};
int longitud = sizeof(segmentosArr);

void setup()
{
    pinMode(PA11, INPUT);
    pinMode(PC13, OUTPUT);

    for (int i = 0; i < sizeof(segmentosArr); i++)
    {
        pinMode(segmentosArr[i], OUTPUT);
    }
}

void loop()
{

    if (digitalRead(PA11) == HIGH)
    {
        digitalWrite(PC13, LOW);
        espera(4, 40);
        seleccionNumero(random(0, 9));
    }
    else
    {
        digitalWrite(PC13, HIGH);
    }
}

void seleccionNumero(int numero)
{

    for (int i = 0; i < 10; i++)
    {
        digitalWrite(segmentosArr[i], numeros[numero][i]);
    }
}

void espera(int conteo, int velocidad)
{

    for (int i = 0; i < 7; i++)
    {
        digitalWrite(segmentosArr[i], LOW);
    }

    for (int i = 0; i < conteo; i++)
    {
        for (int i = 0; i < 6; i++)
        {
            digitalWrite(segmentosArr[i], HIGH);
            delay(velocidad);
        }
        for (int i = 0; i < 6; i++)
        {
            digitalWrite(segmentosArr[i], LOW);
            delay(velocidad);
        }
    }
}