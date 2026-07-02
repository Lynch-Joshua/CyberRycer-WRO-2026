# 📁 schemes - Diagramas de Conexión Eléctrica

Aquí se alojarán los esquemas eléctricos y diagramas de cableado del robot.

### Resumen del Circuito (Flujo en Cascada):
1. **Línea de Potencia:** Baterías ➔ Borneras de 12V del Driver Puente H L298N ➔ Motor DC trasero.
2. **Línea Lógica:** Salida regulada de 5V del L298N ➔ Pin de alimentación del Arduino Mega 2560.
3. **Línea de Distribución:** Pines de 5V y GND del Arduino Mega ➔ Rieles positivo/negativo de una mini protoboard ➔ Alimentación de los dos sensores ultrasónicos HC-SR04 y el servo motor de dirección.
