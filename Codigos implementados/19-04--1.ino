#define SER 2
#define RCLK 4
#define SRCLK 5

void setup()
{
  Serial.begin(9600); //Inicializo puerto serial
  //configuro puertos digitales como salida
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

void loop()
{
  while(Serial.available()==0);
  int check=Serial.parseInt(); // guardo dato de entrada al CI 
  digitalWrite(SER, check); // mando estimulo al SER sea 0/1
  
  // Activo el reloj que me almacena el estimulo
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);
 
  // Activo el reloj que envia el estimulo a la salida
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);
}
