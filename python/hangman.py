import random

# Lista de palabras para el juego del Ahorcado
listaPalabras = ["python", "ahorcado", "programación", "desafío", "conocimiento", "algoritmo"]

# Función para elegir una palabra al azar de la lista
def elegirPalabra(listaPalabras):
    return random.choice(listaPalabras)

# Función para inicializar el juego
def inicializarJuego():
    palabra = elegirPalabra(listaPalabras)
    palabra = palabra.lower()
    letrasPalabra = set(palabra)
    letrasAdivinadas = set()
    intentos = 6
    return palabra, letrasPalabra, letrasAdivinadas, intentos

# Función para mostrar el estado actual de la palabra con las letras adivinadas
def mostrarPalabra(palabra, letrasAdivinadas):
    mostrar = ""
    for letra in palabra:
        if letra in letrasAdivinadas:
            mostrar += letra
        else:
            mostrar += "_"
    return mostrar

# Función para jugar el juego
def jugarAhorcado():
    print("¡Bienvenido al juego del Ahorcado!")
    palabra, letrasPalabra, letrasAdivinadas, intentos = inicializarJuego()
    
    while intentos > 0:
        mostrarActual = mostrarPalabra(palabra, letrasAdivinadas)
        print(f"Palabra: {mostrarActual}")
        print(f"Intentos restantes: {intentos}")
        
        adivinanza = input("Adivina una letra: ").lower()
        
        if adivinanza in letrasAdivinadas:
            print("Ya has adivinado esa letra.")
        elif adivinanza in letrasPalabra:
            letrasAdivinadas.add(adivinanza)
            if letrasPalabra == letrasAdivinadas:
                print("¡Felicidades! Has adivinado la palabra:", palabra)
                break
        else:
            letrasAdivinadas.add(adivinanza)
            intentos -= 1

    if intentos == 0:
        print("Te has quedado sin intentos. La palabra era:", palabra)

# Ejecuta el juego
if __name__ == "__main__":
    jugarAhorcado()
