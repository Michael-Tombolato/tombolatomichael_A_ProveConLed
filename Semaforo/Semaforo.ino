int semaforo;
int giallo;
int nLampeggi;
int tLampeggi;
int resto;
int rosso1 = 13;
int giallo1 = 12;
int verde1 = 11;
int verde2 = 4;
int giallo2 = 3;
int rosso2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(rosso2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Inserire la durata del semaforo");
  while(Serial.available() == 0) {}
  semaforo = Serial.readString().toInt();
  Serial.println(semaforo);
  Serial.println("Inserire la durata del giallo");
  while(Serial.available() == 0) {}
  giallo = Serial.readString().toInt();
  Serial.println(giallo);
  Serial.println("Inserire il numero di lampeggi");
  while(Serial.available() == 0) {}
  nLampeggi = Serial.readString().toInt();
  Serial.println(nLampeggi);
  Serial.println("Inserire la durata dei lampeggi");
  while(Serial.available() == 0) {}
  tLampeggi = Serial.readString().toInt();
  Serial.println(tLampeggi);
  resto = semaforo/2 - giallo*2;
  controllo();
  fase1();
  fase2();
  fase3();
  fase4();
}

String controllo()
{
  if(semaforo < tLampeggi || semaforo < giallo || semaforo < resto)
  {
    Serial.println("ERRORE");
    digitalWrite(rosso1, HIGH);
    digitalWrite(giallo1, HIGH);
    digitalWrite(verde1, HIGH);
    digitalWrite(verde2, HIGH);
    digitalWrite(giallo2, HIGH);
    digitalWrite(rosso2, HIGH);
  }
}

void fase1()
{
  digitalWrite(rosso1, HIGH);
  digitalWrite(verde2, HIGH);
  delay(resto);
  lampeggio2();
}

void fase2()
{
  digitalWrite(giallo1, HIGH);
  digitalWrite(giallo2, HIGH);
  delay(giallo);
}

void fase3()
{
  digitalWrite(rosso1, LOW);
  digitalWrite(giallo1, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(rosso2, HIGH);
  digitalWrite(verde1, HIGH);
  delay(resto);
  lampeggio1();
}

void fase4()
{
  digitalWrite(giallo2, HIGH);
  digitalWrite(giallo1, HIGH);
  delay(giallo);
  digitalWrite(rosso2, LOW);
  digitalWrite(giallo2, LOW);
  digitalWrite(giallo1, LOW);
}

void lampeggio1()
{
  for(int i = 0; i < nLampeggi; i++)
  {
    digitalWrite(verde1, LOW);
    delay(tLampeggi);
    digitalWrite(verde1, HIGH);
    delay(tLampeggi);
  }
  digitalWrite(verde1, LOW);
}

void lampeggio2()
{
  for(int i = 0; i < nLampeggi; i++)
  {
    digitalWrite(verde2, LOW);
    delay(tLampeggi);
    digitalWrite(verde2, HIGH);
    delay(tLampeggi);
  }
  digitalWrite(verde2, LOW);
}
