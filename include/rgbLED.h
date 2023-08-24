void LED_off()
{
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
}

void LED_white()
{
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 255);
}

void LED_red()
{
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 10);
  analogWrite(LED_B, 1);
}

void LED_green()
{
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 0);
}

void LED_blue()
{
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 30);
  analogWrite(LED_B, 255);
}

void LED_purple()
{
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 255);
}

void LED_yellow()
{
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 175);
  analogWrite(LED_B, 0);
}

void LED_orange()
{
  analogWrite(LED_R, 220);
  analogWrite(LED_G, 50);
  analogWrite(LED_B, 20);
}

void LED_cycle()
{
  int d = 300;
  LED_white();
  delay(d);
  LED_red();
  delay(d);
  LED_green();
  delay(d);
  LED_yellow();
  delay(d);
  LED_blue();
  delay(d);
  LED_purple();
  delay(d);
}

void LED_cycle3()
{
  int d = 300;
  LED_white();
  delay(d);
  LED_red();
  delay(d);
  LED_yellow();
  delay(d);
}

void LED_cycleRed()
{
  int d = 100;
  LED_white();
  delay(d);
  LED_red();
  delay(d);
  LED_white();
  delay(d);
  LED_red();
  delay(d);
}