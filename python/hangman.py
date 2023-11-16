import random


def seleccionar_palabra():
    palabras = ["python", "programacion", "computadora", "tecnologia", "inteligencia"]
    return random.choice(palabras)

def mostrar_tablero(palabra, letras_adivinadas):
    tablero = ""
    for letra in palabra:
        if letra in letras_adivinadas:
            tablero += letra + " "
        else:
            tablero += "_ "
    return tablero

def todas_letras_adivinadas(palabra, letras_adivinadas):
    for letra in palabra:
        if letra not in letras_adivinadas:
            return False
    return True

def jugar_ahorcado():
    palabra_secreta = seleccionar_palabra()
    letras_adivinadas = []
    intentos_maximos = 6
    intentos_realizados = 0

    while intentos_realizados < intentos_maximos:
        print("\n" + mostrar_tablero(palabra_secreta, letras_adivinadas))

        if todas_letras_adivinadas(palabra_secreta, letras_adivinadas):
            print("¡Felicidades! Has adivinado la palabra.")
            break

        letra = input("Ingresa una letra: ").lower()

        if letra.isalpha() and len(letra) == 1:
            if letra in letras_adivinadas:
                print("Ya has ingresado esa letra. Intenta con otra.")
            elif letra in palabra_secreta:
                letras_adivinadas.append(letra)
                print("¡Correcto! Has adivinado una letra.")
            else:
                intentos_realizados += 1
                print("Incorrecto. Te quedan", (intentos_maximos - intentos_realizados), "intentos.")
        else:
            print("Por favor, ingresa una letra válida.")

    if intentos_realizados == intentos_maximos:
        print("¡Perdiste! La palabra secreta era '{}'.".format(palabra_secreta))

if __name__ == "__main__":
    jugar_ahorcado()
