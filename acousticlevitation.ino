void setup()
{
  Serial.begin(115200);

  ledcSetup(1, 40000, 8);
  ledcAttachPin(32, 1);
  ledcWrite(1, 127);

  ledcSetup(2, 40000, 8);
  ledcAttachPin(33, 2);
  ledcWrite(2, 127);
}

void loop()
{
  if (Serial.available())
  {
    switch (Serial.read())
    {
    case 's':
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      break;
    case 'o':
      ledcWrite(1, 127);
      ledcWrite(2, 127);
      break;

    default:
      break;
    }
  }
}