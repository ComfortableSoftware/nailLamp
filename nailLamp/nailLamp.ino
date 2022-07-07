

#include <MicroView.h>


#define BEAMISBROKEN beamBroken == LOW
#define BEAMISNOTBROKEN beamBroken == HIGH
#define CHECKBEAM beamBroken = digitalRead(INPIN)
#define INPIN 3
#define ONTIME 90
#define OUTPIN 2
#define SECONDS int(millis() / 1000)
#define TURNOFFLEDS digitalWrite(OUTPIN, LOW)
#define TURNONLEDS digitalWrite(OUTPIN, HIGH)
#define WAIT_A_SEC delay(1000)


bool beamBroken = false;
bool serialEnabled = false;
char digits[80];
float timeAtExpiry;
int upTime, downTime;


/*
  - Eventually if a move from the microview is needed.
  - All setup on screen.
  - PWM/brightness of UV/LED.
  - PWM brightness of backlight on display.
  - Stop on removal of hand from the unit.
  - Timer options.
*/


void printMe(char thingToPrint)
{
  if (serialEnabled == true)
  {
    Serial.println(thingToPrint);
  }
}


void displayTimers()
{
  uView.clear(PAGE);
  uView.display();
  uView.setCursor(0,0);
  sprintf(digits, "%02d %02d", upTime, downTime);
  upTime += 1;
  downTime -= 1;
  // printMe("Displaying time");
  printMe(digits);
  uView.println(digits);
  uView.display();
}


void setup()
{
  if (serialEnabled)
  {
    Serial.begin(115200);
  }

  uView.begin();		// begin of MicroView
  uView.clear(ALL);	// erase hardware memory inside the OLED controller
  uView.clear(PAGE);	// erase the memory buffer, when next uView.display() is called, the OLED will be cleared.
  uView.setFontType(3);
  uView.setCursor(0,0);
  uView.display();	// display the content in the buffer memory, by default it is the MicroView logo
  upTime = 0;
  downTime = ONTIME;
  displayTimers();
  pinMode(OUTPIN, OUTPUT);
  TURNOFFLEDS;
  pinMode(INPIN, INPUT_PULLUP);
}


//*
void loop()
{
  CHECKBEAM;
  while (BEAMISNOTBROKEN)
  {
    CHECKBEAM;
  }
  printMe("Beam broken");
  timeAtExpiry = SECONDS + ONTIME;
  upTime = 0;
  downTime = ONTIME;
  TURNONLEDS;
  while (
      (SECONDS < timeAtExpiry) &&
      (BEAMISBROKEN)
  )
  {
    displayTimers();
    WAIT_A_SEC;
    CHECKBEAM;
  }
  TURNOFFLEDS;
  upTime = 0;
  downTime = ONTIME;
  displayTimers();
  while (BEAMISBROKEN)
  {
    CHECKBEAM;
    WAIT_A_SEC;
  }
}
// */

/*
void loop()
{
  printMe("Looping.");
  while (1)
  {
    displayTimers();
    WAIT_A_SEC;
  }
}
// */
