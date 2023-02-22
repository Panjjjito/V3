#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <HX711_ADC.h>
#include <AccelStepper.h>
#include <ClickEncoder.h>
#include <TimerOne.h>
#include <EEPROM.h>
#include <Stepper.h>

// Sección 1: Definición de constantes y variables

// Definición de pines de entrada y salida
const int PIN_MOTOR_PASOS_PULSO = 5;
const int PIN_MOTOR_PASOS_DIRECCION = 6;
const int PIN_ENCODER_CLK = 8;
const int PIN_ENCODER_DT = 9;
const int PIN_ENCODER_BTN = 10;
const int PIN_CELDA_CARGA_DT = A0;
const int PIN_CELDA_CARGA_SCK = A1;
const int PIN_BOTON_EMERGENCIA = 12;
const int PIN_BOTON_INICIO_FIN = 13;

// Definición de constantes para el control del motor, celda de carga, LCD y encoder
const int NUMERO_DE_PASOS_POR_REVOLUCION_DEL_MOTOR = 200;
const int MICROSEGUNDOS_ENTRE_PASOS_MOTOR = 200;
const float CALIBRACION_CELDA_DE_CARGA = -22591.0;
const int MAX_LONGITUD_MENSAJE_LCD = 16;

// Definición de variables
bool esBotonInicioFinPresionado = false;
bool esBotonEmergenciaPresionado = false;
float pesoObjeto = 0.0;
bool objetoEnMovimiento = false;
bool direccionMovimiento = true; // true = hacia el inicio, false = hacia el final
bool esInicioMovimiento = false;
int posicionActual = 0;

// Declaración de objetos
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711_ADC celdaDeCarga;
AccelStepper motorDePasos(AccelStepper::DRIVER, PIN_MOTOR_PASOS_PULSO, PIN_MOTOR_PASOS_DIRECCION);
ClickEncoder encoder(PIN_ENCODER_DT, PIN_ENCODER_CLK, PIN_ENCODER_BTN, 2, true);
Stepper stepper(NUMERO_DE_PASOS_POR_REVOLUCION_DEL_MOTOR, 8, 9, 10, 11);

//Aquí empieza sección 2:

// Declaración de variables y constantes

const int motorPin = 9;   // Pin del motor
const int buttonPin = 2;  // Pin del botón
int buttonState = 0;      // Estado del botón
int motorState = LOW;     // Estado del motor

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (motorState == LOW) {
      motorState = HIGH;
      digitalWrite(motorPin, motorState);
    }
    else {
      motorState = LOW;
      digitalWrite(motorPin, motorState);
    }
    delay(1000);
  }
}
