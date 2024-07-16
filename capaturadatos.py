import serial

# Configura el puerto serie y la velocidad de comunicación
ser = serial.Serial('/dev/ttyA0', 9600)  # Reemplaza 'COM3' con el puerto adecuado para tu Arduino

# Abre un archivo para guardar los datos
with open('datos_sensor.txt', 'w') as file:
    while True:
        try:
            # Lee una línea del puerto serie
            line = ser.readline().decode('utf-8').strip()
            # Escribe la línea en el archivo
            file.write(line + '\n')
            # Imprime la línea en la consola (opcional)
            print(line)
        except KeyboardInterrupt:
            print("Captura de datos detenida por el usuario.")
            break

ser.close()
