# mic10
هدف
روشن شدن ال ای دی به صورت رندوم 
ونشان دادن ان در سریال پلاتر که با فشاردادن پوش باتن بتئان به صورت رندوم روسن وخاموش شود.
شرح
برای این کار مدار را وصل کرده و بعد ازان می توان کد ان را نوشت که اینگونه است
  ```cpp
 const int ledPins[] = {2, 3, 4, 5, 6, 7}; // ارایه ای تعریف کردیم از 0تا 7
const int buttonPin = 8;// پین انتخاب شده 8
bool lastButtonState = LOW;// وضعیت قبلی را مشخص می کند
bool buttonState = LOW;// وضیعت فعلی 

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT); // حلقه برای خروجی 
  }
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(0)); // خواندن وضعیت
}

void loop() {
  buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH && lastButtonState == LOW) { // بررسی می کند که ایا دکمه فشار داده شده است
    int randomNumber = random(1, 7);
   
    Serial.print("Random number: ");// اعداد تصادفی
    Serial.println(randomNumber);

    for (int i = 0; i < 6; i++) {     // اعداد تصادفی از طریق ارتباط سریالی اعداد را چاپ می کند
        digitalWrite(ledPins[i], LOW) ;
        }

    digitalWrite(ledPins[randomNumber - 1], HIGH); // چون ارایه از صفر شروع می شود یکی کم می کند
    delay(500); // شرط توقف نیم ثانیه
  }

  lastButtonState = buttonState;
}
```
