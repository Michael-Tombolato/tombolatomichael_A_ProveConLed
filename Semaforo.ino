int Rosso1 = 13;
int Giallo1 = 12;
int Verde1 = 11;
int Verde2 = 4;
int Giallo2 = 6;
int Rosso2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(Rosso1, OUTPUT);
  pinMode(Giallo1, OUTPUT);
  pinMode(Verde1, OUTPUT);
  pinMode(Verde2, OUTPUT);
  pinMode(Giallo2, OUTPUT);
  pinMode(Rosso2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Fase1();
  Fase2();
  Fase3();
  Fase4();
}

void Fase1()
{
  digitalWrite(Rosso1, HIGH);
  digitalWrite(Verde2, HIGH);
  delay(2500);
  Lampeggio2();
}

void Fase2()
{
  digitalWrite(Giallo1, HIGH);
  digitalWrite(Giallo2, HIGH);
  delay(750);
}

void Fase3()
{
  digitalWrite(Rosso1, LOW);
  digitalWrite(Giallo1, LOW);
  digitalWrite(Giallo2, LOW);
  digitalWrite(Rosso2, HIGH);
  digitalWrite(Verde1, HIGH);
  delay(2500);
  Lampeggio1();
}

void Fase4()
{
  digitalWrite(Giallo2, HIGH);
  digitalWrite(Giallo1, HIGH);
  delay(750);
  digitalWrite(Rosso2, LOW);
  digitalWrite(Giallo2, LOW);
  digitalWrite(Giallo1, LOW);
}

void Lampeggio1()
{
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(11, LOW);
  delay(200);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(11, LOW);
}

void Lampeggio2()
{
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
}
