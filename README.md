# 🤖 WRO 2026 - Future Engineers Robot

📌 Este repositorio documenta la investigación, diseño y desarrollo de nuestro robot autónomo para la **World Robot Olympiad (WRO) 2026**. El proyecto integra un sistema de control basado en Arduino Mega, sensores de proximidad ultrasónicos laterales y un sistema de dirección asistida para resolver de forma eficiente los desafíos competitivos en la pista.

---

## 📌 Tabla de Contenidos
<details>
<summary><b>📂 Haz clic aquí para ver las carpetas del proyecto</b></summary>

* [📁 Models (Estructura y Chasis)](#)
* [📁 other (Lista de Materiales BOM)](#)
* [📁 schemes (Diagramas Eléctricos)](#)
* [📁 src (Código Fuente)](#)
* [📁 t-photos (Fotos del Equipo)](#)
* [📁 v-photos (Fotos del Robot)](#)
* [📁 videos (Demostraciones de Rendimiento)](#)
</details>

---

## 🌟 Gestión del Robot

### 1. Gestión de Movilidad
* **Chasis y Dirección:** Utilizamos un chasis vehicular comercial de cuatro ruedas. Cuenta con un sistema de dirección delantera tipo Ackermann controlado mediante un servo motor de alto torque para giros precisos, y tracción trasera impulsada por un motor DC acoplado.
* **Control de Tracción y Velocidades:** El motor trasero es gestionado por un módulo **Puente H L298N**. Para optimizar el rendimiento y la estabilidad del vehículo en pista, la programación implementa un perfil dinámico de **3 velocidades** controladas por señales PWM desde el Arduino Mega:
  * **Velocidad de Arranque:** Un pulso inicial controlado para romper la inercia del robot de forma suave sin que patine.
  * **Velocidad de Recta:** Máxima potencia segura para avanzar rápidamente y ganar tiempo en los tramos rectos.
  * **Velocidad de Giro:** Una velocidad reducida para de esta forma estabilizar el centro de gravedad del vehículo durante las curvas y evitar derrapes.

### 2. Gestión de Potencia y Sensores
* **Unidad de Procesamiento:** Toda la lógica del sistema está centralizada en un microcontrolador **Arduino Mega 2560**, elegido por su robustez, estabilidad y amplia cantidad de pines para manejar las señales PWM y de los sensores simultáneamente.
* **Sensores:** Cuenta con **dos sensores ultrasónicos HC-SR04** fijados en la parte frontal de la estructura sobre una base personalizada, orientados estratégicamente en diagonal hacia los laterales. Esta configuración permite medir constantemente las distancias izquierda y derecha para mantener el centrado dinámico dentro del carril.
* **Distribución Eléctrica:** El módulo L298N recibe energía independiente desde un pack de baterías ubicado en la parte posterior para accionar la potencia del motor, aislando el ruido eléctrico de la alimentación del circuito lógico del Arduino Mega.

### 3. Gestión de Obstáculos y Estrategia (Estado Actual)
* **Lógica de la Primera Prueba:** El algoritmo actual está diseñado específicamente para cumplir la meta de **completar 3 vueltas completas a la pista de forma autónoma y regresar con éxito al punto de inicio**.
* **Control del Recorrido:** Comparando las lecturas en tiempo real de ambos sensores ultrasónicos laterales, el Arduino calcula el desvío exacto respecto al centro del carril. Si detecta cercanía a una pared, ajusta inmediatamente el ángulo del servo de dirección delantera para corregir la trayectoria y conmuta automáticamente a la **Velocidad de Giro**. Al recuperar el centrado en un tramo despejado, el sistema regresa a la **Velocidad de Recta**, logrando un control fluido durante todo el circuito.

---

## 📄 Licencia
Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.
