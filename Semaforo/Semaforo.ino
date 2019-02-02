String numero;
int fase1;
int fase2;
int fase3;
int fase4;
int lampeggio;
int Rosso1 = 13;
int Giallo1 = 12;
int Verde1 = 11;
int Verde2 = 4;
int Giallo2 = 3;
int Rosso2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(Rosso1, OUTPUT);
  pinMode(Giallo1, OUTPUT);
  pinMode(Verde1, OUTPUT);
  pinMode(Verde2, OUTPUT);
  pinMode(Giallo2, OUTPUT);
  pinMode(Rosso2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Input();
  Fase1();
  Fase2();
  Fase3();
  Fase4();
}

void Input()
{
  if (Serial.available() > 0)
  {
    for (int i = 0; i < 5; i++)
    {
      if (i == 0)
      {
        Serial.print("Inserire il delay");
        while (numero == "")
        {
          numero = Serial.readString();
        }
        fase1 = numero.toInt();
      }
      if (i == 1)
      {
        Serial.print("Inserire il delay");
        while (numero == "")
        {
          numero = Serial.readString();
        }
        fase2 = numero.toInt();
      }
      if (i == 2)
      {
        Serial.print("Inserire il delay");
        while (numero == "")
        {
          numero = Serial.readString();
        }
        fase3 = numero.toInt();
      }
      if (i == 3)
      {
        Serial.print("Inserire il delay");
        while (numero == "")
        {
          numero = Serial.readString();
        }
        fase4 = numero.toInt();
      }
      if (i == 4)
      {
        Serial.print("Inserire il delay del lampeggio");
        while (numero == "")
        {
          numero = Serial.readString();
        }
        lampeggio = numero.toInt();
      }
    }
  }
}

void Fase1()
{
  digitalWrite(Rosso1, HIGH);
  digitalWrite(Verde2, HIGH);
  delay(fase1);//2500
  Lampeggio2();
}

void Fase2()
{
  digitalWrite(Giallo1, HIGH);
  digitalWrite(Giallo2, HIGH);
  delay(fase2);//750
}

void Fase3()
{
  digitalWrite(Rosso1, LOW);
  digitalWrite(Giallo1, LOW);
  digitalWrite(Giallo2, LOW);
  digitalWrite(Rosso2, HIGH);
  digitalWrite(Verde1, HIGH);
  delay(fase3);//2500
  Lampeggio1();
}

void Fase4()
{
  digitalWrite(Giallo2, HIGH);
  digitalWrite(Giallo1, HIGH);
  delay(fase1);//750
  digitalWrite(Rosso2, LOW);
  digitalWrite(Giallo2, LOW);
  digitalWrite(Giallo1, LOW);
}

void Lampeggio1()
{
  digitalWrite(11, LOW);
  delay(lampeggio);//200
  digitalWrite(11, HIGH);
  delay(lampeggio);
  digitalWrite(11, LOW);
  delay(lampeggio);
  digitalWrite(11, HIGH);
  delay(lampeggio);
  digitalWrite(11, LOW);
  delay(lampeggio);
  digitalWrite(11, HIGH);
  delay(lampeggio);
  digitalWrite(11, LOW);
  delay(lampeggio);
  digitalWrite(11, HIGH);
  delay(lampeggio);
  digitalWrite(11, LOW);
}

void Lampeggio2()
{
  digitalWrite(4, LOW);
  delay(lampeggio);
  digitalWrite(4, HIGH);
  delay(lampeggio);
  digitalWrite(4, LOW);
  delay(lampeggio);
  digitalWrite(4, HIGH);
  delay(lampeggio);
  digitalWrite(4, LOW);
  delay(lampeggio);
  digitalWrite(4, HIGH);
  delay(lampeggio);
  digitalWrite(4, LOW);
  delay(lampeggio);
  digitalWrite(4, HIGH);
  delay(lampeggio);
  digitalWrite(4, LOW);
}
