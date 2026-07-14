#include <Servo.h>

// Pines de conexión
#define SERVO_PIN         6
#define LEFT_TRIG         11
#define LEFT_ECHO         12
#define RIGHT_TRIG        8
#define RIGHT_ECHO        9
#define MOTOR_ENA         10
#define MOTOR_IN3         3
#define MOTOR_IN4         4

// Configuración del carro
#define ANGULO_RECTO          90    // Ruedas derechas
#define GIRO_DERECHA          135
#define GIRO_IZQUIERDA        45

#define VELOCIDAD_CRUCERO     140   // Velocidad en rectas
#define VELOCIDAD_GIRO        115   // Más lento en curvas para no derrapar

#define UMBRAL_VACIO          55    // Distancia en cm para detectar la esquina
#define DISTANCIA_MAX_MAPEO   250

// Tiempos de las maniobras (en milisegundos)
#define TIEMPO_GIRO_MS         850  // Duración de la vuelta
#define TIEMPO_ENDEREZADO_MS   650  // Tiempo avanzando ciego para salir de la curva
#define TIEMPO_INMUNIDAD_MS    2500 // Tiempo de gracia antes de leer otra esquina

// Estados del vehículo
enum EstadoVehiculo {
  AVANZAR_RECTO,       
  GIRANDO,             
  ENDEREZADO_FORZADO,  
  META_ALCANZADA       
};

// Para saber hacia dónde es el circuito
enum SentidoPista { INDETERMINADO, HORARIO, ANTIHORARIO };

EstadoVehiculo estadoActual = AVANZAR_RECTO;
SentidoPista sentidoCarrera = INDETERMINADO; 

Servo servoDireccion;

unsigned long cronometroManiobra   = 0;
unsigned long tiempoUltimoGiro     = 0;
int girosContabilizados            = 0;
const int TOTAL_GIROS_META         = 12; // 4 esquinas * 3 vueltas

void setup() {
  Serial.begin(115200);
  
  // Sensores ultrasónicos
  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);
  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);
  digitalWrite(LEFT_TRIG, LOW);
  digitalWrite(RIGHT_TRIG, LOW);

  // Motores
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);

  // Centrar dirección al arrancar
  servoDireccion.attach(SERVO_PIN);
  servoDireccion.write(ANGULO_RECTO); 

  cronometroManiobra = millis();
  tiempoUltimoGiro   = millis();
  
  // Tiempo para soltar el carro en la pista
  delay(1500); 
}

void loop() {
  if (estadoActual == META_ALCANZADA) {
    detenerVehiculo();
    return;
  }

  // Leer distancias (con filtro para descartar errores)
  float distIzq = obtenerDistanciaSana(LEFT_TRIG, LEFT_ECHO);
  float distDer = obtenerDistanciaSana(RIGHT_TRIG, RIGHT_ECHO);

  switch (estadoActual) {

    case AVANZAR_RECTO:
      ejecutarMotores(VELOCIDAD_CRUCERO);
      servoDireccion.write(ANGULO_RECTO);

      // Buscar esquinas solo si ya pasó el tiempo de inmunidad
      if (millis() - tiempoUltimoGiro > TIEMPO_INMUNIDAD_MS) {
        
        // Si es la primera curva, descubrimos el sentido de la pista
        if (sentidoCarrera == INDETERMINADO) {
          if (distDer > UMBRAL_VACIO) {
            sentidoCarrera = HORARIO;
            Serial.println("Primera esquina a la derecha (horario).");
            iniciarGiroForzado(GIRO_DERECHA);
          } 
          else if (distIzq > UMBRAL_VACIO) {
            sentidoCarrera = ANTIHORARIO;
            Serial.println("Primera esquina a la izquierda (antihorario).");
            iniciarGiroForzado(GIRO_IZQUIERDA);
          }
        }
        // Ya sabemos el sentido, solo hacemos caso al sensor correspondiente
        else if (sentidoCarrera == HORARIO && distDer > UMBRAL_VACIO) {
          Serial.println("Curva a la derecha...");
          iniciarGiroForzado(GIRO_DERECHA);
        }
        else if (sentidoCarrera == ANTIHORARIO && distIzq > UMBRAL_VACIO) {
          Serial.println("Curva a la izquierda...");
          iniciarGiroForzado(GIRO_IZQUIERDA);
        }
      }
      break;

    case GIRANDO:
      ejecutarMotores(VELOCIDAD_GIRO);
      
      // Checar si ya toca enderezar
      if (millis() - cronometroManiobra >= TIEMPO_GIRO_MS) {
        Serial.println("Enderezando...");
        servoDireccion.write(ANGULO_RECTO); 
        cronometroManiobra = millis();
        estadoActual = ENDEREZADO_FORZADO;
      }
      break;

    case ENDEREZADO_FORZADO:
      ejecutarMotores(VELOCIDAD_CRUCERO);
      servoDireccion.write(ANGULO_RECTO); // Mantener ruedas rectas

      // Avanzar a ciegas un rato para alejarnos del borde interno de la curva
      if (millis() - cronometroManiobra >= TIEMPO_ENDEREZADO_MS) {
        girosContabilizados++;
        Serial.print("Giros listos: "); 
        Serial.println(girosContabilizados);
        
        tiempoUltimoGiro = millis(); 
        
        if (girosContabilizados >= TOTAL_GIROS_META) {
          estadoActual = META_ALCANZADA;
          Serial.println("¡Carrera terminada!");
        } else {
          estadoActual = AVANZAR_RECTO; // Volver a habilitar lectura de sensores
        }
      }
      break;
  }
}

// Control de movimiento
void iniciarGiroForzado(int anguloGiro) {
  servoDireccion.write(anguloGiro);
  cronometroManiobra = millis();
  estadoActual = GIRANDO;
}

void ejecutarMotores(int pwmVelocidad) {
  analogWrite(MOTOR_ENA, pwmVelocidad);
  digitalWrite(MOTOR_IN3, HIGH);  
  digitalWrite(MOTOR_IN4, LOW);
}

void detenerVehiculo() {
  analogWrite(MOTOR_ENA, 0); 
  digitalWrite(MOTOR_IN3, LOW);
  digitalWrite(MOTOR_IN4, LOW);
}

// Función para evitar lecturas falsas del ultrasonido (toma 3 muestras y usa la de en medio)
float obtenerDistanciaSana(int pinTrig, int pinEcho) {
  long muestras[3];

  for (int i = 0; i < 3; i++) {
    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10); 
    digitalWrite(pinTrig, LOW);

    long duracion = pulseIn(pinEcho, HIGH, 16000); 
    long calculoCm = duracion / 58;       

    if (calculoCm == 0) {
      muestras[i] = DISTANCIA_MAX_MAPEO; // Libre
    } else {
      muestras[i] = calculoCm;
    }
    delayMicroseconds(600); 
  }

  // Ordenar de menor a mayor (burbuja simple)
  if (muestras[0] > muestras[1]) { long t = muestras[0]; muestras[0] = muestras[1]; muestras[1] = t; }
  if (muestras[1] > muestras[2]) { long t = muestras[1]; muestras[1] = muestras[2]; muestras[2] = t; }
  if (muestras[0] > muestras[1]) { long t = muestras[0]; muestras[0] = muestras[1]; muestras[1] = t; }

  // Devolver la mediana
  return muestras[1];
}
