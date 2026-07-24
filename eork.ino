// Define the pins connected to the sensor
const int TRIG_PIN = 9;   // Connect Trig pin to Digital Pin 9
const int ECHO_PIN = 10;  // Connect Echo pin to Digital Pin 10

// Define threshold distance (in centimeters)
const int DETECTION_DISTANCE = 20; // Object is "detected" if closer than 20 cm

void setup() {
  // Initialize communication with computer at 9600 bits per second
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("Ultrasonic Sensor Initialized!");
}

void loop() {
  // 1. Clear the trigger pin to start fresh
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // 2. Send a 10-microsecond pulse to fire the sound wave
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // 3. Read how long the Echo pin stays HIGH (travel time in microseconds)
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // 4. Calculate distance in centimeters
  int distanceCm = duration * 0.034 / 2;
  
  // 5. Check if object is detected and print to Serial Monitor
  if (distanceCm > 0 && distanceCm <= DETECTION_DISTANCE) {
    Serial.print("STATUS: Object Detected! | Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  } else {
    Serial.println("STATUS: No Object Detected (Clear)");
  }
  
  // Wait half a second before taking another reading
  delay(500);
}