/************************************************************************************************************************************************
CONNESSIONI:
	
	pin digitale 13 -> bottone di enable (che chiude a massa) o filo volante (sempre da chiudere massa per attivare il motore)

	pin digitale 12 -> bottone (che chiude a massa) o filo volante (sempre da chiudere massa) che seleziona il senso di rotazione

	pin digitale 10 -> AIN1 (Pin del driver che decide il senso di rotazione)

	pin digitale  9 -> AIN2 (Pin del driver che decide il senso di rotazione)

	pin digitale  8 -> PWMA (Input pwm driver)

	pin digitale  7 -> STBY (Standby del driver)

	pin analogico 0 -> cursore del potenziomentro

Sul monitor seriale vengono visualizzati i valori letti sul potenziomentro (0,1023) e i valori inviati al ponte H (0, 255) (una volta al secondo)
*************************************************************************************************************************************************/

//DEFINIZIONE PIN DIGITALI
#define ENABLE 13
#define ROTATION_DIR 12
#define AIN1 10
#define AIN2 9
#define PWM_PIN 8
#define STANDBY 7
//DEFINIZIONE PIN ANALOGICI
#define POTENTIOMETER_PIN A0

int rotation[] = {LOW, LOW}; //serve per settare il senso di rotazione, {LOW, HIGH} -> SENSO ORARIO (CREDO), {HIGH, LOW} SENSO ANTIORARIO (CREDO)
int potentiometerValue = 0; //valore del potenziomentro da 0 a 1023
int pwmValue = 0; //valore dell'output pwm che pilota il ponte H 
int cnt = 0; //contatore che conta il numero di cicli del loop

void setup() {
	Serial.begin(9600); // inizio comununicazione a 9600 bit/s
	//SETUP PIN FIGITALI DI INPUT CON RESISTENZA DI PULLUP ATTIVATA (IN QUESTO MODO DI DEFAULT STANNO A LIVELLO LOGICO ALTO, QUANDO VENGONO COLLEGATI A MASSA VANNO A LIVELLO LOGICO BASSO)
	pinMode(ENABLE, INPUT_PULLUP);
	pinMode(ROTATION_DIR, INPUT_PULLUP);
	//SETUP PIN DIGITALI DI OUTPUT PER COMUNICARE COL DRIVER
	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
	pinMode(STANDBY, OUTPUT);
	//SETUP PIN ANLOGICO COME INPUT PER LEGGERE IL VALORE DEL POTENZIOMETRO 
	pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() { 
	if (digitalRead(ENABLE) == LOW) //SE IL PIN DI ENABLE É COLLEGATO A MASSA ATTIVO IL FUNZIONAMENTO DEL PONTE H ALTRIMENTI LO DISATTIVO
		digitalWrite(STANDBY, HIGH);	
	else
		digitalWrite(STANDBY, LOW);

	if (digitalRead(ROTATION_DIR) == 0) {//dovrebbe essere senso orario ma potrebbe essere antiorario
		rotation[0] = LOW;
    	rotation[1]= HIGH; 
  	}
	else { //dovrebbe essere senso antiorario ma potrebbe essere orario
		rotation[0] = HIGH;
    	rotation[1] = LOW;
	}
	//configurazione senso di rotazione
	digitalWrite(AIN1, rotation[0]);
	digitalWrite(AIN2, rotation[1]);

	potentiometerValue = analogRead(POTENTIOMETER_PIN); //lettura analogica del valore di tensione sul potenziometro
	pwmValue = map(potentiometerValue, 0, 1023, 0, 255); //conversione valori letti dal pin analogico (funzione inclusa di arduino, per il funzionamento specifico controllare sul sito)
	analogWrite(PWM_PIN, pwmValue); //scrivo il valore del pwm sul relativo pin per regolare la velocitá del motore
	
	cnt++;

	if (cnt % 10 == 0) {
 		//PRINT SU MONITOR SERIALE ogni secondo
 		Serial.print("Valore pot -> ");
  		Serial.print(potentiometerValue);
  		Serial.print("\tValore pwm -> ");
  		Serial.println(pwmValue);	
	}
	delay(100);

}
