#include <TimerOne.h>     // Include the internal timer library
#include <LedControl.h>   // Include the library for controlling a 7x8 segment display

LedControl lc = LedControl(12, 11, 10, 1);  // Initialize the 7x8 segment display with pin numbers and create an object

#define p1_button_pin 2   // First player's button pin
#define p2_button_pin 3   // Second player's button pin

int mins_p1 = 2;          // Initial minutes for player 1
int Time_p1 = 60;         // Initial seconds for player 1

int mins_p2 = 2;          // Initial minutes for player 2
int Time_p2 = 60;         // Initial seconds for player 2

boolean p1_win = false;   // Indicator for player 1's win
boolean p2_win = false;   // Indicator for player 2's win

void setup() {
  lc.shutdown(0, false);   // Turn on the display at index 0
  lc.setIntensity(0, 2);   // Set display brightness
  lc.clearDisplay(0);      // Clear the display

  pinMode(p1_button_pin, INPUT_PULLUP);     // Declare player 1's button pin for input with pull-up resistor
  pinMode(p2_button_pin, INPUT_PULLUP);     // Declare player 2's button pin for input with pull-up resistor

  attachInterrupt(digitalPinToInterrupt(p1_button_pin), p1_play, FALLING);   // Attach an external interrupt for player 1's timer
  attachInterrupt(digitalPinToInterrupt(p2_button_pin), p2_play, FALLING);   // Attach an external interrupt for player 2's timer

  Timer1.initialize(1000000);   // Initialize the internal timer for 1-second updates
}

void loop() {
  // Here, you would typically implement the main program logic, but it's currently empty.
}
