  #include <L298N.h>

  const unsigned int IN1 = 7; //Input 1 pin
  const unsigned int IN2 = 8;  //Input 2 pin
  const unsigned int EN = 5; //Enable pin

  // Create one motor instance
  L298N motor(EN, IN1, IN2);

  void setup() {
    // Used to display information
    Serial.begin(9600);

    // Wait for Serial Monitor to be opened
    while (!Serial) {
      //do nothing
    }

    // Set initial speed
    motor.setSpeed(1);
  }

  void loop() {
    int x, y, speed;

    Serial.println("Enter runtime(min):");
    Serial.println("Enter time stopped(min):");
    Serial.println("Enter speed values (0-255)");
    while (!Serial.available());
      x = Serial.parseInt(); //read x value from serial prompt
      y = Serial.parseInt();  //read y value from serial prompt
      speed = Serial.parseInt(); //read speed value from serial prompt
      if(speed < 0 || speed > 255) {
        Serial.println("Invalid speed value. Enter a value between 0 and 255.");
        return;
      }

    motor.setSpeed(speed);

    // Tell the motor to go forward (may depend by your wiring)
    motor.forward();
    Serial.print("Motor is moving");
    delay(x * 60000); //Continue spinning for x time ( min -> ms conversion)

    motor.stop();  
    Serial.print("Motor is stopped");
    delay(y * 60000); //Stop for y time ( min -> ms conversion)
  }
