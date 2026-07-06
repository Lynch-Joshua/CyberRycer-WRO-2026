# 🤖 FUTURE ENGINEERS - PANAMÁ ROBOTICS TEAM 2026

📌 Este repositorio documenta de forma completa la investigación, diseño y desarrollo de nuestro robot autónomo para la **Competencia Regional de la World Robot Olympiad (WRO) 2026 – Categoría Future Engineers**. El proyecto representa la implementación de un sistema embebido basado en **Arduino Mega 2560**, sensores de proximidad ultrasónicos y control de tracción adaptativo mediante hardware comercial, optimizado para resolver los desafíos de navegación autónoma con alta precisión en la pista regional.

---

## 📌 Tabla de Contenidos

▼ 📂 **Haz clic aquí para expandir el menú de navegación**
* 📁 [Models (Estructura y Chasis)](#1-gestión-de-movilidad-mobility-management)
* 📁 [other (Lista de Materiales BOM)](#2-gestión-de-potencia-y-sensores-power-and-sense-management)
* 📁 [schemes (Diagramas Eléctricos)](#2-gestión-de-potencia-y-sensores-power-and-sense-management)
* 📁 [src (Código Fuente)](#3-gestión-de-obstáculos-y-estrategia-obstacle-management)
* 📁 [t-photos (Fotos del Equipo)](#4-fotografías-team-and-vehicle-photos)
* 📁 [v-photos (Fotos del Robot)](#4-fotografías-team-and-vehicle-photos)
* 📁 [videos (Demostraciones de Rendimiento)](#5-videos-de-rendimiento-performance-videos)

---

## 🌟 Puntos Clave del Proyecto (Highlights)

* **Sistema de Movilidad Eficiente:** Construido sobre un chasis vehicular comercial de cuatro ruedas que garantiza balance y rigidez. Cuenta con un sistema de dirección delantera tipo Ackermann controlado por un servo motor y tracción trasera gestionada por el puente H L298N.
* **Percepción Dinámica:** Equipado con dos sensores ultrasónicos HC-SR04 montados estratégicamente en la parte frontal (uno orientado hacia el lateral izquierdo y otro orientado al frente) para medir distancias en tiempo real y ejecutar el centrado automático.
* **Control de Perfil de Velocidades:** Implementation de software basada en 3 niveles de velocidad por PWM (Arranque, Recta y Giro) para asegurar estabilidad y optimizar los tiempos en la pista de la regional.

---

## 🏎️ World Robot Olympiad (WRO) - Regional Future Engineers

La fase regional de *Future Engineers* evalúa la solidez técnica básica de los prototipos autónomos. El reto exige el desarrollo de un coche autónomo capaz de leer su entorno, esquivar obstáculos y completar recorridos definidos de manera inteligente y sin intervención humana.

---

## 🏁 Documentación Técnica del Proyecto (Criterios de Evaluación)

### 1. Gestión de Movilidad (Mobility Management)

Selección del Chasis: Optamos por un chasis comercial de tracción trasera y dirección delantera. Al no requerir diseño en 3D, nos enfocamos en el comportamiento dinámico y en la distribución de componentes para optimizar el centro de gravedad.

Mecanismo de Dirección: La dirección delantera utiliza la geometría Ackermann operada por un servo motor. Esto reduce el arrastre de los neumáticos en las curvas y ofrece un radio de giro preciso y repetible.

Sistema de Tracción: El movimiento trasero es impulsado por un motor DC de corriente directa. Para romper la fricción estática inicial y mantener el control, el software gestiona la potencia mediante 3 perfiles de velocidad por hardware:

Velocidad de Arranque: Un pulso alto de PWM durante milisegundos para iniciar la marcha de forma suave sin que el coche patine.

Velocidad de Recta: Configuración PWM máxima para aprovechar la velocidad punta en tramos lineales libres y limpios.

Velocidad de Giro: Potencia reducida en las curvas para estabilizar el centro de gravedad del vehículo y evitar derrapes.

* [Robot Parts & Design](./Models)
* [Steering System](./Models)

---

### 2. Gestión de Potencia y Sensores (Power and Sense Management)

Unidad de Control: Se seleccionó el microcontrolador Arduino Mega 2560 por su confiabilidad, tolerancia eléctrica y su amplia cantidad de pines digitales, permitiendo procesar las señales de los sensores y actuadores en paralelo.

Matriz de Sensores: El robot utiliza dos sensores ultrasónicos HC-SR04 fijados en la parte frontal con orientación diagonal-lateral sobre una base personalizada de madera. Esta disposición permite calcular la distancia relativa hacia los muros izquierdo y derecho simultáneamente.

Flujo de Energía en Cascada (Decisión de Diseño): La arquitectura eléctrica del robot utiliza un sistema de alimentación unificado y optimizado en cascada para simplificar el cableado:

El pack de baterías principal alimenta directamente las borneras de potencia del Puente H L298N para dar la fuerza necesaria al motor DC trasero.

Aprovechando el regulador interno de voltaje de 5V integrado en el módulo L298N, redirigimos esa salida regulada para alimentar directamente la electrónica lógica del Arduino Mega 2560.

Desde el pin de 5V y GND del Arduino, la energía pasa a los rieles de una mini protoboard, distribuyéndose finalmente de forma limpia hacia los dos sensores ultrasónicos HC-SR04 y el servo motor de dirección. Esta configuración evita el uso de reguladores externos o baterías adicionales pesadas, manteniendo el carro ligero.

Optimización del Protoboard: En el centro del robot implementamos únicamente los rieles laterales de positivo (+) y negativo (-) de una mini protoboard, descartando el uso del bloque central completo. Esta decisión responde a dos razones de ingeniería:

Reducción de Espacio y Peso: Al remover el bloque de conexiones central, maximizamos el espacio disponible en el chasis para organizar los cables and el Arduino Mega, eliminando peso muerto innecesario.

Seguridad y Robustez en Conexiones: Los puentes de señales en un protoboard completo tienden a aflojarse con las vibraciones de la carrera. Al conectar los cables de datos directamente de los sensores al Arduino Mega y usar la protoboard únicamente como un bus centralizado de distribución de energía, reducimos drásticamente el riesgo de un falso contacto o desconexión en plena competencia.

* [Bill of Materials (BOM)](./other)
* [Wiring Diagram](./schemes)
* [Sensors](./Models)

---

### 3. Gestión de Obstáculos y Estrategia (Obstacle Management)

Lógica del Recorrido (Meta Regional): La estrategia actual está diseñada para cumplir la primera gran prueba de la eliminatoria regional: completar 3 vueltas perfectas a la pista y retornar al punto de origen de manera autónoma.

* [Strategy](#3-gestión-de-obstáculos-y-estrategia-obstacle-management)

---

### 4. Fotografías (Team and Vehicle Photos)

Registro del Prototipo: Las imágenes detalladas del chasis, la electrónica centralizada sobre el Arduino Mega 2560 y el montaje angular frontal de los sensores se encuentran alojadas en la carpeta v-photos/.

Trabajo en Equipo: Las capturas de las jornadas de ensamblaje, calibración de hardware y pruebas de pista se ubican en t-photos/.

* [Vehicle Photos](./v-photos)
* [Team Members & Pictures](./t-photos)

---

### 5. Videos de Rendimiento (Performance Videos)

Demostración en Pista: En la carpeta videos/ se incluye el archivo multimedia que sirve como evidencia del coche autónomo completando de forma consecutiva las 3 vueltas reglamentarias en la simulación de pista regional, demostrando el correcto funcionamiento del cambio automático de velocidades por software.

* [Demonstration Videos](./videos)

---

### 6. Utilización de GitHub

Control de Versiones: Este repositorio se utiliza activamente para registrar el progreso del proyecto. Cada confirmación (commit) representa una fase de optimización en los umbrales de lectura de los sensores y el ajuste fino de las potencias PWM del motor trasero para la competencia regional.

* [Repository Link](https://github.com/Lynch-Joshua/berRycer-WRO-2026)

---

### 7. Factor de Ingeniería (Engineering Factor)

Eficiencia y Diseño Propio: El proyecto destaca por resolver un problema complejo de navegación autónoma utilizando componentes comerciales accesibles. La optimización del espacio mediante el bus de energía simplificado (sin el bloque central del protoboard) y la fabricación artesanal del soporte frontal de madera demuestran adaptabilidad, reducción de peso muerto y un diseño orientado a la resistencia contra vibraciones en pista.

* [Design Description](#7-factor-de-ingeniería-engineering-factor)

---

## 📄 Licencia

Este proyecto es de código abierto y está licenciado bajo los términos de la **Licencia MIT**. Consulta el archivo `LICENSE` adjunto para más información.
)](./src%20(%20source%20code%20))
* 📁 [t-photos (Fotos del Equipo)](./t-photos)
* 📁 [v-photos (Fotos del Robot)](./v-photos)
* 📁 [videos (Demostraciones de Rendimiento)](./videos)
</details>

---

## 🌟 Puntos Clave del Proyecto (Highlights)

* **Sistema de Movilidad Eficiente:** Construido sobre un chasis vehicular comercial de cuatro ruedas que garantiza balance y rigidez. Cuenta con un sistema de dirección delantera tipo Ackermann controlado por un servo motor y tracción trasera gestionada por el puente H L298N.
* **Percepción Dinámica:** Equipado con dos sensores ultrasónicos HC-SR04 montados estratégicamente en la parte frontal (uno orientado hacia el lateral izquierdo y otro orientado al frente) para medir distancias en tiempo real y ejecutar el centrado automático.
* **Control de Perfil de Velocidades:** Implementación de software basada en 3 niveles de velocidad por PWM (Arranque, Recta y Giro) para asegurar estabilidad y optimizar los tiempos en la pista de la regional.

---

## 🏎️ World Robot Olympiad (WRO) - Regional Future Engineers

La fase regional de *Future Engineers* evalúa la solidez técnica básica de los prototipos autónomos. El reto exige el desarrollo de un coche autónomo capaz de leer su entorno, esquivar obstáculos y completar recorridos definidos de manera inteligente y sin intervención humana.

---

## 🏁 Documentación Técnica del Proyecto (Criterios de Evaluación)

### 1. Mobility Management
La discusión sobre la gestión de la movilidad cubre cómo se controlan los movimientos del vehículo, los criterios de selección de los motores y el comportamiento dinámico del chasis seleccionado para la pista de la regional.

* [Robot Parts & Design](./Models)
* [Steering System (Ackermann)](./Models)
* [Traction & Motor Control (L298N)](./src%20(%20source%20code%20))

---

### 2. Power and Sense Management
Esta sección detalla la fuente de alimentación del vehículo y la matriz de sensores requerida para proporcionar al robot la información necesaria para superar los desafíos de navegación, optimizando el consumo y el espacio.

* [Bill of Materials (BOM)](./other)
* [Wiring Diagram & Power Flow](./schemes)
* [Sensors Setup (HC-SR04)](./Models)

---

### 3. Obstacle Management
La estrategia de gestión de obstáculos incluye la lógica diseñada para que el vehículo navegue de forma autónoma. Esto abarca el algoritmo de control de la dirección y la conmutación de los perfiles de velocidad por software.

* [Strategy (3-Lap Challenge)](#lógica-de-estrategia-regional)
* [Arduino Source Code](./src%20(%20source%20code%20))

---

### 4. Pictures – Team and Vehicle
Galería de registros visuales del proyecto. Las fotos del robot cubren los componentes mecánicos y electrónicos clave, mientras que la foto grupal identifica al equipo de cara a la competencia local.

* [Vehicle Photos](./v-photos)
* [Team Members & Pictures](./t-photos)

---

### 5. Performance Videos
Evidencia en video que demuestra el rendimiento del coche autónomo en las pruebas oficiales de la competencia, validando su comportamiento de inicio a fin.

* [Demonstration Videos](./videos)

---

### 6. GitHub Utilization
Uso de la plataforma GitHub para el control de versiones, organización de la documentación técnica y el registro del progreso del desarrollo del software mediante confirmaciones (commits) constantes.

* [Repository Link (Main Portada)](https://github.com/Lynch-Joshua/berRycer-WRO-2026)

---

### 7. Engineering Factor
Uso e integración inteligente de componentes electrónicos estándar (off-the-shelf) junto con adaptaciones de diseño propio hechas a medida para optimizar el rendimiento del prototipo.

* [Design Description](#lógica-de-diseño-propio)

---

## ⚙️ Detalles Adicionales de Implementación

### Lógica de Estrategia Regional
Nuestra estrategia está optimizada para la meta regional: **completar 3 vueltas perfectas a la pista y retornar de manera autónoma al origen**. El bucle del Arduino procesa las lecturas de los ultrasónicos en tiempo real: si el sensor de proximidad detecta un muro bajo el umbral crítico, el servo actúa la dirección Ackermann y reduce a la *Velocidad de Giro*. Al recuperar espacio libre, endereza y regresa a la *Velocidad de Recta*.

### Lógica de Diseño Propio
* **Flujo en Cascada:** Las baterías alimentan el L298N, el regulador de 5V del driver pasa energía limpia al Arduino Mega, y este distribuye la potencia mediante los rieles aislados de una mini protoboard hacia los sensores y el servo.
* **Estructura Artesanal:** Base delantera construida en madera para fijar con precisión los sensores en el ángulo diagonal idóneo, reduciendo vibraciones y eliminando peso muerto al descartar el bloque de conexiones central de la protoboard.

---

## 📄 Licencia
Este proyecto es de código abierto y está licenciado bajo los términos de la **Licencia MIT**. Consulta el archivo `LICENSE` adjunto para más información.
