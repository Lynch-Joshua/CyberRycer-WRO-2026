# 🤖 FUTURE ENGINEERS - PANAMÁ ROBOTICS TEAM 2026

📌 Este repositorio documenta de forma completa la investigación, diseño y desarrollo de nuestro robot autónomo para la **Competencia Regional de la World Robot Olympiad (WRO) 2026 – Categoría Future Engineers**. El proyecto representa la implementación de un sistema embebido basado en **Arduino Mega 2560**, sensores de proximidad ultrasónicos y control de tracción adaptativo mediante hardware comercial, optimizado para resolver los desafíos de navegación autónoma con alta precisión en la pista regional.

---

## 📌 Tabla de Contenidos
<details>
<summary><b>📂 Haz clic aquí para expandir el menú de navegación</b></summary>

* [📁 Models (Estructura y Chasis)](#)
* [📁 other (Lista de Materiales BOM)](#)
* [📁 schemes (Diagramas Eléctricos)](#)
* [📁 src (Código Fuente)](#)
* [📁 t-photos (Fotos del Equipo)](#)
* [📁 v-photos (Fotos del Robot)](#)
* [📁 videos (Demostraciones de Rendimiento)](#)
</details>

---

## 🌟 Puntos Clave del Proyecto (Highlights)
* **Sistema de Movilidad Eficiente:** Construido sobre un chasis vehicular comercial de cuatro ruedas que garantiza balance y rigidez. Cuenta con un sistema de dirección delantera tipo Ackermann controlado por un servo motor y tracción trasera gestionada por el puente H L298N.
* **Percepción Dinámica:** Equipado con dos sensores ultrasónicos HC-SR04 montados estratégicamente en la parte frontal orientados en diagonal hacia los laterales para medir distancias en tiempo real y ejecutar el centrado automático.
* **Control de Perfil de Velocidades:** Implementación de software basada en 3 niveles de velocidad por PWM (Arranque, Recta y Giro) para asegurar estabilidad y optimizar los tiempos en la pista de la regional.

---

## 🌍 World Robot Olympiad (WRO) - Regional Future Engineers
La fase regional de *Future Engineers* evalúa la solidez técnica básica de los prototipos autónomos. El reto exige el desarrollo de un coche autónomo capaz de leer su entorno, esquivar obstáculos y completar recorridos definidos de manera inteligente y sin intervención humana.

---

## 🏁 Documentación Técnica del Proyecto (Criterios de Evaluación)

### 1. Gestión de Movilidad (Mobility Management)
* **Selección del Chasis:** Optamos por un chasis comercial de tracción trasera y dirección delantera. Al no requerir diseño en 3D, nos enfocamos en el comportamiento dinámico y en la distribución de componentes para optimizar el centro de gravedad.
* **Mecanismo de Dirección:** La dirección delantera utiliza la geometría Ackermann operada por un servo motor. Esto reduce el arrastre de los neumáticos en las curvas y ofrece un radio de giro preciso y repetible.
* **Sistema de Tracción:** El movimiento trasero es impulsado por un motor DC de corriente directa. Para romper la fricción estática inicial y mantener el control, el software gestiona la potencia mediante **3 perfiles de velocidad por hardware**:
  * **Velocidad de Arranque:** Un pulso alto de PWM durante milisegundos para iniciar la marcha de forma suave sin que el coche patine.
  * **Velocidad de Recta:** Configuración PWM máxima para aprovechar la velocidad punta en tramos lineales libres y limpios.
  * **Velocidad de Giro:** Potencia reducida en las curvas para estabilizar el centro de gravedad del vehículo y evitar derrapes.

### 2. Gestión de Potencia y Sensores (Power and Sense Management)
* **Unidad de Control:** Se seleccionó el microcontrolador **Arduino Mega 2560** por su confiabilidad, tolerancia eléctrica y su amplia cantidad de pines digitales e interrupciones, permitiendo procesar las señales de los sensores y actuadores en paralelo.
* **Matriz de Sensores:** El robot utiliza **dos sensores ultrasónicos HC-SR04** fijados en la parte frontal con orientación diagonal-lateral sobre una base personalizada de madera. Esta disposición permite calcular la distancia relativa hacia los muros izquierdo y derecho simultáneamente, abstrayendo las paredes de la pista como referencias métricas de navegación.
* **Arquitectura de Energía:** Se diseñaron líneas de alimentación divididas de forma estricta:
  * El motor DC trasero y el servo de dirección reciben energía directamente desde un pack de baterías independiente conectado a las borneras del puente H **L298N**.
  * La electrónica lógica (Arduino Mega y Sensores) se alimenta de forma aislada, previniendo reinicios o "crashes" causados por caídas de tensión o ruidos electromagnéticos de los motores.

### 3. Gestión de Obstáculos y Estrategia (Obstacle Management)
* **Lógica del Recorrido (Meta Regional):** La estrategia actual está diseñada para cumplir la primera gran prueba de la eliminatoria regional: **completar 3 vueltas perfectas a la pista y retornar al punto de origen de manera autónoma**.
