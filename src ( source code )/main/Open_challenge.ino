#include <NewPing.h> // Librería para el control optimizado de los sensores de ultrasonido
#include <Servo.h>   // Librería para controlar el servomotor de la dirección

Servo SERVO_DIRECCION;    // Crea el objeto para controlar el servo de dirección
const int PIN_SERVO = 2;  // Pin digital asignado al servo

// Configuración de los ángulos del servo para la dirección del vehículo
const int ANGULO_CENTRO = 90; // Ángulo para ir recto
const int ANGULO_IZQ = 45;    // Ángulo máximo para girar a la izquierda
const int ANGULO_DER = 140;   // Ángulo máximo para girar a la derecha

const int MAX_DISTANCIA = 200; // Distancia máxima que medirá el sensor (en cm)

// Asignación de pines para el sensor de ultrasonido Izquierdo
const int PIN_TRIG_IZQ = 40;
const int PIN_ECHO_IZQ = 41;

// Asignación de pines para el sensor de ultrasonido Derecho
const int PIN_TRIG_DER = 39;
const int PIN_ECHO_DER = 38;

// Inicialización de los objetos NewPing para cada sensor
NewPing SONAR_IZQ(PIN_TRIG_IZQ, PIN_ECHO_IZQ, MAX_DISTANCIA);
NewPing SONAR_DER(PIN_TRIG_DER, PIN_ECHO_DER, MAX_DISTANCIA);

// Variables para almacenar las distancias medidas de cada lado
int DISTANCIA_IZQ;
int DISTANCIA_DER;

// Pines de control del puente H (Driver L298N o similar) para el motor de tracción
const int PIN_MOTOR_PWM = 5;  // Pin PWM para controlar la velocidad del motor
const int PIN_MOTOR_IN3 = 11; // Pin de dirección 1 del motor
const int PIN_MOTOR_IN4 = 10; // Pin de dirección 2 del motor

// Valores de velocidad para el motor (rango de 0 a 255)
int VELOCIDAD_ARRANQUE = 128; // Velocidad inicial o de empuje para salir de la inercia
int VELOCIDAD_RECTA = 180;    // Velocidad de crucero al avanzar en línea recta
int VELOCIDAD_GIRO = 110;     // Velocidad reducida en curvas para evitar derrapes/choques

int curvas = 0;               // Contador de curvas realizadas
bool estaba_girando = false;  // Bandera de control para no contar la misma curva varias veces

/**
 * Función auxiliar para obtener la distancia de un sensor de forma segura.
 * Evita el problema del '0' (fuera de rango) devolviendo la distancia máxima.
 */
int obtenerDistanciaSegura(NewPing &sonar) {
  int cm = sonar.ping_cm(); // Realiza la medición en centímetros
  if (cm == 0) return MAX_DISTANCIA; // Si da 0 (sin eco), asumimos que el camino está despejado
  return cm; // Si detecta algo, devuelve la distancia real
}

void setup() {
  // Inicialización del servo y posicionamiento en el centro (recto)
  SERVO_DIRECCION.attach(PIN_SERVO);
  SERVO_DIRECCION.write(ANGULO_CENTRO);

  // Configuración de los pines del motor como salidas
  pinMode(PIN_MOTOR_PWM, OUTPUT);
  pinMode(PIN_MOTOR_IN3, OUTPUT);
  pinMode(PIN_MOTOR_IN4, OUTPUT);

  // Configura el sentido de giro del motor para avanzar hacia adelante
  digitalWrite(PIN_MOTOR_IN3, LOW);
  digitalWrite(PIN_MOTOR_IN4, HIGH);

  // Inicia el movimiento del coche con la velocidad de arranque
  analogWrite(PIN_MOTOR_PWM, VELOCIDAD_ARRANQUE);
}

void loop() {
  // CONTROL DE CARRERA: Si ya completó 13 curvas, el coche se detiene por completo
  if (curvas >= 13) {
    digitalWrite(PIN_MOTOR_IN3, LOW);      // Apaga el sentido de giro del motor
    digitalWrite(PIN_MOTOR_IN4, LOW);      
    analogWrite(PIN_MOTOR_PWM, 0);         // Detiene la velocidad del motor
    SERVO_DIRECCION.write(ANGULO_CENTRO);  // Endereza las llantas
    while(1); // Bucle infinito para congelar el programa aquí (Fin de la pista)
  }

  // Lectura de los sensores con un pequeño delay intermedio para evitar interferencias
  DISTANCIA_IZQ = obtenerDistanciaSegura(SONAR_IZQ);
  delay(25); // Breve pausa para que el eco del sensor izquierdo no afecte al derecho
  DISTANCIA_DER = obtenerDistanciaSegura(SONAR_DER);

  // LÓGICA DE NAVEGACIÓN

  // CASO 1: Si el sensor derecho detecta un vacío/apertura (distancia mayor a 50cm)
  if (DISTANCIA_DER > 50) {
    analogWrite(PIN_MOTOR_PWM, VELOCIDAD_GIRO); // Baja la velocidad para girar seguro
    SERVO_DIRECCION.write(ANGULO_DER);          // Gira el volante a la derecha
    
    // Control para contar la curva solo una vez al entrar en ella
    if (estaba_girando == false) {
      curvas++;             // Incrementa el contador de curvas
      estaba_girando = true; // Activa la bandera (ya está registrado que está girando)
    }
  } 
  // CASO 2: Si el sensor izquierdo detecta un vacío/apertura (distancia mayor a 50cm)
  else if (DISTANCIA_IZQ > 50) {
    analogWrite(PIN_MOTOR_PWM, VELOCIDAD_GIRO); // Baja la velocidad para girar seguro
    SERVO_DIRECCION.write(ANGULO_IZQ);          // Gira el volante a la izquierda
    
    // Control para contar la curva solo una vez al entrar en ella
    if (estaba_girando == false) {
      curvas++;             // Incrementa el contador de curvas
      estaba_girando = true; // Activa la bandera
    }
  } 
  // CASO 3: RECTA (Ambos sensores ven paredes cerca, es decir, distancias <= 50cm)
  else {
    analogWrite(PIN_MOTOR_PWM, VELOCIDAD_RECTA); // Sube a velocidad de crucero
    SERVO_DIRECCION.write(ANGULO_CENTRO);         // Endereza el volante
    estaba_girando = false; // Resetea la bandera para estar listo para la siguiente curva
  }
}
