// defineer de gebruikte noten
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

// dit is de melodie waar de harp mee opent
int melody[] = {
NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

int noteDurations[] = {
4, 8, 8, 4,4,4,4,4 };

void setup() {
  // Poort D op output
   DDRD = 0b11111111;
   
// herhaal de noten van de melodie
for (int thisNote = 0; thisNote < 8; thisNote++) {

// bereken de lengte van een noot
int noteDuration = 1000/noteDurations[thisNote];
tone(53, melody[thisNote],noteDuration);

// plaats een pauze tussen twee noten
int pauseBetweenNotes = noteDuration * 1.30;
delay(pauseBetweenNotes);

// stop met de noot afspelen
noTone(53);
}
}

// deze loop wordt achter elkaar door afgespeeld
void loop() {
 
  int noteDuration = 8;

    // deze loop zorgt ervoor dat de chip blijft checken of een snaar wordt gespeeld
    while(1)
  {
    // dit if statement checkt de eerste snaar (de sensoren zijn aangesloten op A poorten)
    if (PINA & (1<<PA0))
    {
      // als de poort een 0 is, dan speelt er een toon af, de speaker is aangesloten op poort D 53
      PORTD = 0b11111111;
      tone(53, NOTE_C4,noteDuration);
    }
    else
    {
      // als de poort een 1 is, zetten we poort D op 0
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA1))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_D4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA2))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_E4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA3))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_F4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA4))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_G4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA5))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_A4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA6))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_B4,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

    if (PINA & (1<<PA7))
    {
      PORTD = 0b11111111;
      tone(53, NOTE_C5,noteDuration);
    }
    else
    {
      PORTD = 0b11111110;
    }

  }
}




