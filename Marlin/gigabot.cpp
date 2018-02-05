// gigabot.cpp
//
// This source file is intended to isolate customized code for Marlin by 
// separating them into sections
//

#include "systems.h"

#if 0
#if IS_SECTION(MARLIN_MAIN_GLOBAL)
#if FILAMENT_DETECTION_EXT0_PIN > -1 || FILAMENT_DETECTION_EXT1_PIN > -1 || FILAMENT_DETECTION_EXT2_PIN > -1
  bool Out_of_Filament_Detected = false;
#endif

static bool Delayed_Enqueing = false;
static char tmpcmdbuffer[MAX_CMD_SIZE] = {0};

// Keep calling this function in a loop and it will beep 
void Annoying_Beep()
{
  static uint8_t cnt = 0;

  cnt++;
  thermalManager.manage_heater();
  manage_inactivity();
  lcd_update();
  if(cnt==0)
  {
#if BEEPER > 0
    SET_OUTPUT(BEEPER);

    WRITE(BEEPER,HIGH);
    delay(3);
    WRITE(BEEPER,LOW);
    delay(3);
#else
#if !defined(LCD_FEEDBACK_FREQUENCY_HZ) || !defined(LCD_FEEDBACK_FREQUENCY_DURATION_MS)
    lcd_buzz(1000/6,100);
#else
    lcd_buzz(LCD_FEEDBACK_FREQUENCY_DURATION_MS,LCD_FEEDBACK_FREQUENCY_HZ);
#endif
#endif
  }

}

void setup_Filament_Detection_pins()
{
#if FILAMENT_DETECTION_EXT0_PIN > -1 || FILAMENT_DETECTION_EXT1_PIN > -1 || FILAMENT_DETECTION_EXT2_PIN > -1


  Out_of_Filament_Detected = false;
#endif

#if defined(FILAMENT_DETECTION_EXT0_PIN) && FILAMENT_DETECTION_EXT0_PIN > -1
  pinMode(FILAMENT_DETECTION_EXT0_PIN,INPUT);
  WRITE(FILAMENT_DETECTION_EXT0_PIN,HIGH);
#endif

#if defined(FILAMENT_DETECTION_EXT1_PIN) && FILAMENT_DETECTION_EXT1_PIN > -1
  pinMode(FILAMENT_DETECTION_EXT1_PIN,INPUT);
  WRITE(FILAMENT_DETECTION_EXT1_PIN,HIGH);
#endif

#if defined(FILAMENT_DETECTION_EXT2_PIN) && FILAMENT_DETECTION_EXT2_PIN > -1
  pinMode(FILAMENT_DETECTION_EXT2_PIN,INPUT);
  WRITE(FILAMENT_DETECTION_EXT2_PIN,HIGH);
#endif

}

void checkFilamentExistance()
{

#if defined(FILAMENT_DETECTION_EXT0_PIN) && FILAMENT_DETECTION_EXT0_PIN > -1

  if( 0 != degTargetHotend(active_extruder) && !Out_of_Filament_Detected && active_extruder == 0 
    && FILAMENT_DETECTION_EXT0_TRIGGER_VALUE == digitalRead(FILAMENT_DETECTION_EXT0_PIN) )
  {
    enquecommand("M600");
    Out_of_Filament_Detected = true;
  }
#endif

#if defined(FILAMENT_DETECTION_EXT1_PIN) && FILAMENT_DETECTION_EXT1_PIN > -1
  if( 0 != degTargetHotend(active_extruder) &&  !Out_of_Filament_Detected && active_extruder == 1 
    && FILAMENT_DETECTION_EXT1_TRIGGER_VALUE == digitalRead(FILAMENT_DETECTION_EXT1_PIN) )
  {
    enquecommand("M600");
    Out_of_Filament_Detected = true;
  }
#endif

#if defined(FILAMENT_DETECTION_EXT2_PIN) && FILAMENT_DETECTION_EXT2_PIN > -1
  if( 0 != degTargetHotend(active_extruder) && !Out_of_Filament_Detected && active_extruder == 2 
    && FILAMENT_DETECTION_EXT2_TRIGGER_VALUE == digitalRead(FILAMENT_DETECTION_EXT2_PIN) )
  {
    enquecommand("M600");
    Out_of_Filament_Detected = true;
  }
#endif

}

void setup_pausepin()
{
#if defined(PAUSE_PIN) && PAUSE_PIN > -1
pinMode(PAUSE_PIN,INPUT);
WRITE(PAUSE_PIN,HIGH);
#endif
}

inline bool _enqueuecommand(const char* cmd, bool say_ok);
 
void pause()
{
  _enqueuecommand("M600", false);
  _enqueuecommand("G4 P0", false);
  _enqueuecommand("G4 P0", false);
  _enqueuecommand("G4 P0", false);
}
#endif

#if IS_SECTION(MARLIN_MAIN_SETUP)
  setup_Filament_Detection_pins();
#endif

#if IS_SECTION(MARLIN_MAIN_LOOP)
  checkFilamentExistance();
#endif
#endif
