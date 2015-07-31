int noteON = 144;//144 = 10010000 in binair, dit is het 'note on' commando

void setup() {
  //  MIDI baud rate:
  Serial.begin(31250);
  
  // Gebruik het harpgeluid in plaats van het standaard pianogeluid.
  programChange(0xc0, 46);
}

// Deze loop wordt achter elkaar door afgespeeld.
void loop() {

 
    // Deze loop zorgt ervoor dat de chip blijft checken of een snaar wordt gespeeld.
    while(1)
  {
      int velocity = 127;
      int note;
      
    // Dit if statement checkt de eerste snaar (de sensoren zijn aangesloten op A poorten).
    if (PINA & (1<<PA0))
    {
      // Als de poort een 0 is, dan speelt er een toon af. 
      
      note = 48; 
           
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA0));

      MIDImessage(noteON, note, 0);

    }

    if (PINA & (1<<PA1))
    {
   
      note = 50; 
    
     
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA1));

      MIDImessage(noteON, note, 0);

    }


    if (PINA & (1<<PA2))
    {
      note = 52;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA2));

      MIDImessage(noteON, note, 0);
    }


    if (PINA & (1<<PA3))
    {
      note = 53;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA3));

      MIDImessage(noteON, note, 0);
    }

    if (PINA & (1<<PA4))
    {
      note = 55;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA4));

      MIDImessage(noteON, note, 0);
    }

    if (PINA & (1<<PA5))
    {
      note = 57;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA5));

      MIDImessage(noteON, note, 0);
    }

    if (PINA & (1<<PA6))
    {
      note = 59;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA6));

      MIDImessage(noteON, note, 0);
    }

    if (PINA & (1<<PA7))
    {
      note = 60;
      MIDImessage(noteON, note, velocity);
      do
      {
        delay(1);
      } 
      while (PINA & (1<<PA7));

      MIDImessage(noteON, note, 0);
    }

  }
  
}

// Methode om het harpgeluid te gebruiken in plaats van het standaard pianogeluid.
void programChange(char ProgramCommand, char Tone)
{
  Serial.write(ProgramCommand);
  Serial.write(Tone);
}

// Methode om een bericht te sturen naar het MIDI device.
void MIDImessage(int command, int MIDInote, int MIDIvelocity) 
{
  Serial.write(command);//send note on or note off command 
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}




