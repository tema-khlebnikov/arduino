/*
  Автоматический спусковой тросик для камеры Canon для съёмки таймлапсов

  videoSpeedUp - ускрение видео
  fps - количество кадров в секунде видео

  фотографирование будет роисходить каждые videoSpeedUp / fps секунд
*/

int videoSpeedUp = 300;
int fps = 30;

int relayPin = A0;

int shotDuration = 100; // время, достаточное для реакции фотоаппарата и реле
int shotDelay = round(videoSpeedUp / fps * 1000);

int highLevelDelay = shotDuration;
int lowLevelDelay = shotDelay - shotDuration;



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relayPin, OUTPUT);
}



void loop() {
  // замыкаем реле
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(relayPin, LOW); // для реле сигнал обратный
  delay(highLevelDelay);

  // отключаем реле
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(relayPin, HIGH);
  delay(lowLevelDelay);
}
