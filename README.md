# CyberRycer-WRO-2026
# 🤖 WRO 2026 - Future Engineers Robot

📌 Este repositorio documenta la investigación, diseño y desarrollo de nuestro robot autónomo para la **World Robot Olympiad (WRO) 2026**. El proyecto integra un sistema de control basado en Arduino Mega, sensores de proximidad y un sistema de dirección asistida para resolver de forma eficiente y autónoma los desafíos en la pista.


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

🌟 Gestión del Robot

 1. Gestión de Movilidad
* **Chasis y Dirección:** Utilizamos un chasis vehicular comercial de cuatro ruedas. Cuenta con un sistema de dirección delantera tipo Ackermann controlado mediante un servo motor de alto torque para giros precisos, y tracción trasera impulsada por un motor DC acoplado.
* **Control de Tracción:** El motor de tracción se gestiona mediante un módulo controlador de potencia (puente H) que regula tanto la velocidad como el sentido de la marcha.

 2. Gestión de Potencia y Sensores
* **Unidad de Procesamiento:** Toda la lógica del sistema está centralizada en un microcontrolador **Arduino Mega**, elegido por su amplia capacidad de pines y memoria para gestionar múltiples tareas simultáneas.
* **Sensores:** Para la detección de obstáculos en tiempo real, el robot cuenta con un sensor de distancia **ultrasónico HC-SR04** posicionado estratégicamente en la parte frontal de la estructura.
* **Distribución Eléctrica:** Se implementa una línea de alimentación separada para los motores/servos y otra para el circuito lógico de control, evitando así ruidos e interferencias electromagnéticas.

### 3. Gestión de Obstáculos y Estrategia
* **Lógica del Sistema:** El algoritmo principal realiza lecturas constantes del sensor ultrasónico frontal. Al detectar un obstáculo a una distancia menor al límite crítico, calcula el ángulo óptimo de evasión y actúa directamente sobre el servo de dirección y la potencia del motor trasero para corregir la trayectoria sin detener el vehículo.



## 📄 Licencia
Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.
