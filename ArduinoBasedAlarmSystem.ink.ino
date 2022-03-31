

#define REDLED 7
#define GREENLED 8

const int LDR = A0;
int input_val = 0;
const int buzzerPin = 9;
const int switchPin = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int switchVal;
  switchVal = digitalRead(switchPin);
  input_val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(input_val);
  delay(100);



    if (switchVal == HIGH) {
      noTone(buzzerPin);
      digitalWrite(GREENLED, HIGH);
      digitalWrite(REDLED, HIGH);
    }
    else if (switchVal == LOW) {
      if(input_val < 850) {
        noTone(buzzerPin);
        digitalWrite(GREENLED, HIGH);
        digitalWrite(REDLED, LOW);
      }
      else {
        tone(buzzerPin, 3000);
        digitalWrite(GREENLED, LOW);
        digitalWrite(REDLED, HIGH);
      }
    }
   }
