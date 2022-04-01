// Definindo as portas de tudo que está conectado; 

# define piezo 2
# define lVERDE 13
# define lVERMELHO 12
# define sensor1 A0
# define sensor2 A1

// Dizendo que os valores de Temp do Sensor são 0;

int TempSensor1=0;
int TempSensor2=0;

// PinMode: Configura o pino especificado
// para funcionar como uma entrada ou saída (I/O);

void setup()
{
  pinMode(lVERDE, OUTPUT);
  pinMode(lVERMELHO, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  
}

// AnalogRead: Lê o valor de um pino analógico especificado;
// As entradas digitais só podem assumir dois estados, HIGH e LOW;
// Grandezas digitais são aquelas que não variam continuamente no tempo, 
// mas sim em saltos entre valores bem definidos;
void loop()
{
  TempSensor1 = analogRead(sensor1);
  // Aqui eu digo que a Temperatura vai ser igual a leitura do pino onde está o sensor;
  TempSensor2 = analogRead(sensor2);
  // Pelo Monitor Serial, verifico qual variação seria igual o mesmo que por algum valor (por exemplo 50 graus)
  // Para poder me guiar
  
  if(TempSensor1 > 209 || TempSensor2 > 209){
  // Se a temperatura for menor que esse valor que achei no serial que seria algo como 50 graus;
  // Tanto o do sensor 1 e do sensor 2ele vai:
    
    digitalWrite(lVERMELHO, HIGH);
    //digitalWrite: Aciona um valor HIGH ou LOW em um pino digital.
    // Vai ligar o led vermelho;
    digitalWrite(lVERDE, LOW);
    // Vai desligar o led verde;
    tone(piezo, 1000);
    // tone: Gera uma onda quadrada na frequência especificada;
    // Ou seja a frequência que ele toca;
  }
  else{ // Caso não tenha aquela temperatura ele vai:
    digitalWrite(lVERDE, HIGH); // Ligar o LED Verde
    digitalWrite(lVERMELHO, LOW); // Desligar o LED Vermelho	
    noTone(piezo); //Desligar o Piezo (O que faz barulho)
  }  
                         
}