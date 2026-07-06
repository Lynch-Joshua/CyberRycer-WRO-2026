# 🤖 FUTURE ENGINEERS - PANAMÁ ROBOTICS TEAM 2026

📌 Este repositorio documenta de forma completa la investigación, diseño y desarrollo de nuestro robot autónomo para la Competencia Regional de la World Robot Olympiad (WRO) 2026 – Categoría Future Engineers. El proyecto representa la implementación de un sistema embebido basado en Arduino Mega 2560, sensores de proximidad ultrasónicos y control de tracción adaptativo mediante hardware comercial, optimizado para resolver los desafíos de navegación autónoma con alta precisión en la pista regional.

---

## 📌 Tabla de Contenidos

<details>
<summary><b>📂 Haz clic aquí para expandir el menú de navegación</b></summary>
<br>

* 📁 [Models (Estructura y Chasis)](./Models)
* 📁 [other (Lista de Materiales BOM)](./other)
* 📁 [schemes (Diagramas Eléctricos)](./schemes)
* 📁 [src (Código Fuente)](./src%20(%20source%20code%20))
* 📁 [t-photos (Fotos del Equipo)](./t-photos)
* 📁 [v-photos (Fotos del Robot)](./v-photos)
* 📁 [videos (Demostraciones de Rendimiento)](./videos)
</details>

---

## 🌟 Puntos Clave del Proyecto (Highlights)

* **Sistema de Movilidad Eficiente:** Construido sobre un chasis vehicular comercial de cuatro ruedas que garantiza balance y rigidez. Cuenta con un sistema de dirección delantera tipo Ackermann controlado por un servo motor y tracción trasera gestionada por el puente H L298N.
* **Percepción Dinámica:** Equipado con dos sensores ultrasónicos HC-SR04 montados estratégicamente en la parte frontal uno orientados hacia el lateral izquierdo y otro orientados al frente para medir distancias en tiempo real y ejecutar el centrado automático.
* **Control de Perfil de Velocidades:** Implementación de software basada en 3 niveles de velocidad por PWM (Arranque, Recta y Giro) para asegurar estabilidad y optimizar los tiempos en la pista de la regional.

---

## 🏎️ World Robot Olympiad (WRO) - Regional Future Engineers

La fase regional de Future Engineers evalúa la solidez técnica básica de los prototipos autónomos. El reto exige el desarrollo de un coche autónomo capaz de leer su entorno, esquivar obstáculos y completar recorridos definidos de manera inteligente y sin intervención humana.

---

## 🏁 Documentación Técnica del Proyecto (Criterios de Evaluación)

### 1. Gestión de Movilidad (Mobility Management)

* **Selección del Chasis:** Optamos por un chasis comercial de tracción trasera y dirección delantera. Al no requerir diseño en 3D, nos enfocamos en el comportamiento dinámico y en la distribución de componentes para optimizar el centro de gravedad.
* **Mecanismo de Dirección:** La dirección delantera utiliza la geometría Ackermann operada por un servo motor. Esto reduce el arrastre de los neumáticos en las curvas y ofrece un radio de giro preciso y repetible.
* **Sistema de Tracción:** El movimiento trasero es impulsado por un motor DC de corriente directa. Para romper la fricción estática inicial y mantener el control, el software gestiona la potencia mediante 3 perfiles de velocidad por hardware:
  * **Velocidad de Arranque:** Un pulso alto de PWM durante milisegundos para iniciar la marcha de forma suave sin que el coche patine.
  * **Velocidad de Recta:** Configuración PWM máxima para aprovechar la velocidad punta en tramos lineales libres y limpios.
  * **Velocidad de Giro:** Potencia reducida en las curvas para estabilizar el centro de gravedad del vehículo y evitar derrapes.

---

### 2. Gestión de Potencia y Sensores (Power and Sense Management)

* **Unidad de Control:** Se seleccionó el microcontrolador Arduino Mega 2560 por su confiabilidad, tolerancia eléctrica y su amplia cantidad de pines digitales, permitiendo procesar las señales de los sensores y actuadores en paralelo.
* **Matriz de Sensores:** El robot utiliza dos sensores ultrasónicos HC-SR04 fijados en la parte frontal con orientación diagonal-lateral sobre una base personalizada de madera. Esta disposición permite calcular la distancia relativa hacia los muros izquierdo y derecho simultáneamente.
* **Flujo de Energía en Cascada (Decisión de Diseño):** La arquitectura eléctrica del robot utiliza un sistema de alimentación unificado y optimizado en cascada para simplificar el cableado:
  * El pack de baterías principal alimenta directamente las borneras de potencia del Puente H L298N para dar la fuerza necesaria al motor DC trasero.
  * Aprovechando el regulador interno de voltaje de 5V integrado en el módulo L298N, redirigimos esa salida regulada para alimentar directamente la electrónica lógica del Arduino Mega 2560.
  * Desde el pin de 5V y GND del Arduino, la energía pasa a los rieles de una mini protoboard, distribuyéndose finalmente de forma limpia hacia los dos sensores ultrasónicos HC-SR04 y el servo motor de dirección. Esta configuración evita el uso de reguladores externos o baterías adicionales pesadas, manteniendo el carro ligero.
* **Optimización del Protoboard:** En el centro del robot implementamos únicamente los rieles laterales de positivo (+) y negativo (-) de una mini protoboard, descartando el uso del bloque central completo. Esta decisión responde a dos razones de ingeniería:
  * **Reducción de Espacio y Peso:** Al remover el bloque de conexiones central, maximizamos el espacio disponible en el chasis para organizar los cables y el Arduino Mega, eliminando peso muerto innecesario.
  * **Seguridad y Robustez en Conexiones:** Los puentes de señales en un protoboard completo tienden a aflojarse con las vibraciones de la carrera. Al conectar los cables de datos directamente de los sensores al Arduino Mega y usar la protoboard únicamente como un bus centralizado de distribución de energía, reducimos drásticamente el riesgo de un falso contacto o desconexión en plena competencia.

---

### 3. Gestión de Obstáculos y Estrategia (Obstacle Management)

* **Lógica del Recorrido (Meta Regional):** La estrategia actual está diseñada para cumplir la primera gran prueba de la eliminatoria regional: completar 3 vueltas perfectas a la pista y retornar al punto de origen de manera autónoma.
 unificado y optimizado en cascada para simplificar el cableado:
  * El pack de baterías principal alimenta directamente las borneras de potencia del Puente H L298N para dar la fuerza necesaria al motor DC trasero.
  * Aprovechando el regulador interno de voltaje de 5V integrado en el módulo L298N, redirigimos esa salida regulada para alimentar directamente la electrónica lógica del Arduino Mega 2560.
  * Desde el pin de 5V y GND del Arduino, la energía pasa a los rieles de una mini protoboard, distribuyéndose finalmente de forma limpia hacia los dos sensores ultrasónicos HC-SR04 y el servo motor de dirección. Esta configuración evita el uso de reguladores externos o baterías adicionales pesadas, manteniendo el carro ligero.
* **Optimización del Protoboard:** En el centro del robot implementamos únicamente los rieles laterales de positivo (+) y negativo (-) de una mini protoboard, descartando el uso del bloque central completo. Esta decisión responde a dos razones de ingeniería:
  * **Reducción de Espacio y Peso:** Al remover el bloque de conexiones central, maximizamos el espacio disponible en el chasis para organizar los cables y el Arduino Mega, eliminando peso muerto innecesario.
  * **Seguridad y Robustez en Conexiones:** Los puentes de señales en un protoboard completo tienden a aflojarse con las vibraciones de la carrera. Al conectar los cables de datos directamente de los sensores al Arduino Mega y usar la protoboard únicamente como un bus centralizado de distribución de energía, reducimos drásticamente el riesgo de un falso contacto o desconexión en plena competencia.

---

### 3. Gestión de Obstáculos y Estrategia (Obstacle Management)

* **Lógica del Recorrido (Meta Regional):** La estrategia actual está diseñada para cumplir la primera gran prueba de la eliminatoria regional: completar 3 vueltas perfectas a la pista y retornar al punto de origen de manera autónoma.

<details>
<summary><b>📂 Haz clic aquí para expandir el menú de navegación</b></summary>
<br>

* 📁 [Models (Estructura y Chasis)](./Models)
* 📁 [other (Lista de Materiales BOM)](./other)
* 📁 [schemes (Diagramas Eléctricos)](./schemes)
* 📁 [src (Código Fuente)](./src%20(%20source%20code%20))
* 📁 [t-photos (Fotos del Equipo)](./t-photos)
* 📁 [v-photos (Fotos del Robot)](./v-photos)
* 📁 [videos (Demostraciones de Rendimiento)](./videos)
</details>
