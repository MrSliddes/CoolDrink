// This script is made by Tymon Versmoren
// CoolDrink [v1]

#include <LiquidCrystal_I2C.h> // For the lcd screen
#include <Wire.h> // For the lcd screen
#include <DallasTemperature.h> // For temperature

#define ONE_WIRE_BUS 8 // For temperature

// Load lcd screen
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Set buttons
const int buttonBack = 2; // These numbers wont change so the const
const int buttonMin = 3;
const int buttonAdd = 4;
const int buttonNext = 5;

// Set fan
const int fanPin = 9;

// Set temp sensor wire
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire); // The sensor wire that is in pin 8
float sensorValue = 0;

// Timer for counting cooling time
float stopwatchTime = 0;

// Menu
int currentMenu = 0; // Set the current menu to main menu
// Temprature
int selectedTemperature = 25;

void setup() 
{
  Serial.begin(9600);
  
  // Setup lcd screen
  lcd.begin(20, 4); // Lcd screen width / height
  lcd.clear(); // clear the screen

  // Setup sensor
  sensor.begin();

  // Initialize button pins
  pinMode(buttonBack, INPUT);
  pinMode(buttonMin, INPUT);
  pinMode(buttonAdd, INPUT);
  pinMode(buttonNext, INPUT);

  // Fan
  pinMode(fanPin, OUTPUT);
  digitalWrite(fanPin, LOW); // turn fan off

  DrawMenu();
}

void loop() 
{
  CheckButtons();
  CheckTemperature();
}

void CheckButtons()
{
  //First check on what menu you are
  switch(currentMenu)
  {
    case 0:
      // Main menu      
      if(digitalRead(buttonNext) == HIGH)
      {      
        ChangeMenu(1);
      }
      break;
    case 1:
      // Select temp
      if(digitalRead(buttonBack) == HIGH)
      {
        Serial.print("back");
        ChangeMenu(0);
      }
      else if(digitalRead(buttonMin) == LOW) // My min button is broken, if not broken turn this to HIGH like the rest
      {
        // Lower selectedTemp
        selectedTemperature -= 5;
        if(selectedTemperature < 25) selectedTemperature = 25;
        DrawMenu();
        delay(500);
      }
      else if(digitalRead(buttonAdd) == HIGH)
      {
        // Add selectedTemp
        selectedTemperature += 5;
        if(selectedTemperature > 90) selectedTemperature = 90;
        DrawMenu();
        delay(500);
      }
      else if(digitalRead(buttonNext) == HIGH)
      {
        // Go to cooling
        ChangeMenu(2);
        // Turn fan on
        digitalWrite(fanPin, HIGH);
        delay(4000);
        ChangeMenu(3);
      }
      break;
    case 3:
      // While cooling
      if(digitalRead(buttonBack) == HIGH)
      {
        ChangeMenu(6);
        // Turn fan off
        digitalWrite(fanPin, LOW);
        delay(2000);
        ChangeMenu(0);
      }
      break;
    case 5:
      // Skip when drink is finished
      if(digitalRead(buttonNext) == HIGH)
      {
        ChangeMenu(0);
      }
      break;
    default:
      break;
  }
}

void CheckTemperature()
{
  if(currentMenu == 3)
  {    
    sensor.requestTemperatures();
    sensorValue = sensor.getTempCByIndex(0);
    lcd.setCursor(0,2);
    lcd.print("Current temp: " + String((int)sensorValue) + char(223) + "C");
    // Show loadbar (how close the temp is to the desired temp)    
    int p = map(sensorValue, selectedTemperature, 50, 1, 10);
    if(p > 10) { p = 10; } else if(p < 1) { p = 1; }
    p = (p - 11) * -1;
    String loadbar = "----------";
    for(int i = 0; i < p-1; i++)
    {
      loadbar.setCharAt(i, 255);
    }
    if((int)sensorValue <= selectedTemperature && stopwatchTime > 1)
    {
      // Finished
      loadbar.setCharAt(9, 255);
      delay(1000);
      ChangeMenu(4);
      // Stop cooling
      // Turn fan off
      digitalWrite(fanPin, LOW);
      delay(2000);
      // Show finished screen
      ChangeMenu(5);
      delay(5000);
      ChangeMenu(0);
      stopwatchTime = 0;
      return;
    }
    
    lcd.setCursor(0,3);
    lcd.print("(back) [" + loadbar);    
    lcd.setCursor(18,3);
    lcd.print("]");
    stopwatchTime += 0.5;
    delay(500);
  }
}


/// Called when the menu needs to be changed by input
void ChangeMenu(int index)
{
  currentMenu = index;
  DrawMenu();
  delay(1000);
}

void DrawMenu()
{
  lcd.clear();
  
  // This will draw the current selected menu
  switch(currentMenu)
  {    
    case 0:
      // Main menu
      lcd.setCursor(2,0);
      lcd.print("Drink Cooler [v1]");
      lcd.setCursor(3,1);
      lcd.print("Made by  Tymon");
      lcd.setCursor(15,3);
      lcd.print("Start");
      break;
    case 1:
      // Select temprature drink
      lcd.setCursor(0,0);
      lcd.print("1.Place your drink");
      lcd.setCursor(0,1);
      lcd.print("2.Select temperature");
      lcd.setCursor(0,2);
      lcd.print(">>> Temp: " + String(selectedTemperature) + char(223) + "C" + " <<<");
      lcd.setCursor(0,3);
      //lcd.print("back | - || + | next");
      lcd.print("(back) (-)(+) (next)");
      break;
    case 2:
      // Preparing cooling
      lcd.setCursor(0,0);
      lcd.print("Please wait...");
      lcd.setCursor(0,1);
      lcd.print("Preparing cooling...");
      break;
    case 3:
      // Cooling drink
      lcd.setCursor(0,0);
      lcd.print("Please wait...");
      lcd.setCursor(0,1);
      lcd.print("Desired temp: " + String(selectedTemperature) + char(223) + "C");
      //>> Executed in CheckTemperature();
      //lcd.setCursor(0,2);
      //lcd.print("Current temp: " + String(sensorValue) + char(223) + "C");
      //lcd.setCursor(0,3);
      //lcd.print("(back) [==========]");
      break;
    case 4:
      // Waiting
      lcd.setCursor(0,0);
      lcd.print("Please wait...");
      break;
    case 5:
      lcd.setCursor(0,0);
      lcd.print("Finished!");
      lcd.setCursor(0,1);
      lcd.print("Enjoy your drink!");
      lcd.setCursor(0,2);
      lcd.print("Exiting in (5) sec");
      lcd.setCursor(0,3);
      lcd.print("TimeItTook: " + String((int)stopwatchTime) + "sec");
      break;
    case 6:
      lcd.setCursor(0,0);
      lcd.print("Please wait...");
      lcd.setCursor(0,1);
      lcd.print("Aborting cooling...");
      break;
    default:
      lcd.setCursor(0, 0); // Set the cursor on position 0 in row 0.
      lcd.print("Error:: currentMenu!");
      lcd.setCursor(0, 2);
      lcd.print("Dont touch anything!");
      lcd.setCursor(0, 3);
      lcd.print("Get Tymon for help");
  }
}
