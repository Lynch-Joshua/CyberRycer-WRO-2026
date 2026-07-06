# 🤖 FUTURE ENGINEERS - PANAMÁ ROBOTICS TEAM 2026

📌 Este repositorio documenta de forma completa la investigación, diseño y desarrollo de nuestro robot autónomo para la **Competencia Regional de la World Robot Olympiad (WRO) 2026 – Categoría Future Engineers**. El proyecto representa la implementación de un sistema embebido basado en **Arduino Mega 2560**, sensores de proximidad ultrasónicos y control de tracción adaptativo mediante hardware comercial, optimizado para resolver los desafíos de navegación autónoma con alta precisión en la pista regional.

---

## 📌 Tabla de Contenidos

> 💡 **Tip:** Haz clic en la flecha de abajo 👇 para expandir la Tabla de Contenidos. Cada elemento es un enlace directo a las carpetas de este repositorio.

<details>
<summary>📂 <b>Haz clic aquí para expandir el menú de navegación</b></summary>
<br>

* 📁 [Models (Estructura y Chasis)](./Models)
* 📁 [other (Lista de Materiales BOM)](./other)
* 📁 schemes [(Diagramas Eléctricos)](./schemes)
* 📁 [src (Código Fuente)](./src%20(%20source%20code%20))
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
