#include <Keyboard.h>
#include <Bounce2.h>

#define HOLD_BUTTON_PIN 2
#define HANG_BUTTON_PIN 4

Bounce hangButton = Bounce();
Bounce holdButton = Bounce();

void setup() {
  Serial.begin(115200);

  holdButton.attach(HOLD_BUTTON_PIN, INPUT_PULLUP);
  holdButton.interval(50);

  hangButton.attach(HANG_BUTTON_PIN, INPUT_PULLUP);
  hangButton.interval(50);

  Keyboard.begin();
}

void loop() {
  handleButtons();
}

void handleButtons() {
  holdButton.update();
  hangButton.update();

  if (holdButton.fell()) {
    //    Keyboard.print("Hold");
    holdCallMacro();
  }

  if (hangButton.fell()) {
    //    Keyboard.print("Hang");
    hangCallMacro();
  }
}

void hangCallMacro() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('f');
  Keyboard.releaseAll();
}

void holdCallMacro() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('h');
  Keyboard.releaseAll();
}
