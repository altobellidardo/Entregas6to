import pygame, random

pygame.init()

ANCHO = 800
ALTO = 600

hiscore = 0
forma = 0
tramaselec = 1

wn = pygame.display.set_mode((ANCHO, ALTO))
pygame.display.set_caption("Snake by Dardo")
clock = pygame.time.Clock()

# #elegir entre 3 fuentes
# fuente = pygame.font.SysFont("comicsansms", 23)
fuente = pygame.font.SysFont("bahnschrift", 24)
fuente2 = pygame.font.Font(None, 30)


def trama_secue(textura, mode):
    if mode == 1:
        if textura == 1 or textura == 2:
            return "#6E9E89"
        elif textura == 3:
            return "#A4D4BF"
        elif textura == 4:
            return "#2ACE86"
        elif textura == 5:
            return "#A4D4BF"
    else:
        if textura == 1 or textura == 2:
            textura += 1
            return textura
        elif textura == 3:
            textura = 4
            return textura
        elif textura == 4:
            textura = 5
            return textura
        elif textura == 5:
            textura = 1
            return textura


def trama_rand():
    proba = random.random()
    if proba <= 0.3:
        return "#A4D4BF"
    elif proba > 0.3 and proba <= 0.6:
        return "#6E9E89"
    elif proba > 0.6:
        return "#2ACE86"


def trama_igual():
    return "#58D68D"


def ojos(direction, snake):
    if direction == None:
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 3, snake.position[1] + 7, 6, 6)
        )
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 11, snake.position[1] + 7, 6, 6)
        )
    elif direction == "up":
        pygame.draw.rect(wn, "red", (snake.position[0] + 3, snake.position[1], 6, 6))
        pygame.draw.rect(wn, "red", (snake.position[0] + 11, snake.position[1], 6, 6))
    elif direction == "down":
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 3, snake.position[1] + 14, 6, 6)
        )
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 11, snake.position[1] + 14, 6, 6)
        )
    elif direction == "left":
        pygame.draw.rect(wn, "red", (snake.position[0], snake.position[1] + 3, 6, 6))
        pygame.draw.rect(wn, "red", (snake.position[0], snake.position[1] + 11, 6, 6))
    elif direction == "right":
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 14, snake.position[1] + 3, 6, 6)
        )
        pygame.draw.rect(
            wn, "red", (snake.position[0] + 14, snake.position[1] + 11, 6, 6)
        )


def verhiscore(score):
    global hiscore, newhiscore
    if score > hiscore:
        hiscore = score
        newhiscore = True


def lineas():  # traza cuadricula por cada "pixel"
    for x in range(0, ANCHO, 20):
        pygame.draw.line(wn, "blue", (x, 0), (x, ALTO))
    for y in range(0, ALTO, 20):
        pygame.draw.line(wn, "blue", (0, y), (ANCHO, y))


class Snake:
    def __init__(self, color):
        # inicia en el medio
        self.position = [ANCHO / 2, ALTO / 2]
        self.color = color


class Apple:
    def __init__(self):
        # dividido en cuadricula para alinear con snake
        self.position = [random.randint(0, 39) * 20, random.randint(0, 19) * 20]

    def nuevaposi(self):
        self.position = [random.randint(0, 39) * 20, random.randint(0, 19) * 20]


def salir():
    pygame.quit()
    exit()


def gameLoop():

    global hiscore, newhiscore, forma, tramaselec
    snake = Snake("#58D68D")
    apple = Apple()
    speed = 20  # avanza 1 cuadrado

    longitud = [snake]
    # para que no vuelva para atras / que no tome el sentido contrario
    direction = None

    textura = 1
    # score se puede remplazar por num_segmen-1
    score = 0
    newhiscore = False
    x_speed = 0
    y_speed = 0

    outgame = False
    game_over = False

    while not game_over:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                salir()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP or event.key == pygame.K_w:
                    if direction != "down":
                        x_speed = 0
                        y_speed = -speed
                        direction = "up"
                elif event.key == pygame.K_DOWN or event.key == pygame.K_s:
                    if direction != "up":
                        x_speed = 0
                        y_speed = speed
                        direction = "down"
                elif event.key == pygame.K_LEFT or event.key == pygame.K_a:
                    if direction != "right":
                        x_speed = -speed
                        y_speed = 0
                        direction = "left"
                elif event.key == pygame.K_RIGHT or event.key == pygame.K_d:
                    if direction != "left":
                        x_speed = speed
                        y_speed = 0
                        direction = "right"
                if event.key == pygame.K_SPACE:
                    pygame.draw.rect(wn, "white", (375, 250, 20, 100))
                    pygame.draw.rect(wn, "white", (425, 250, 20, 100))
                    pygame.display.update()
                    out = False
                    while not out:
                        for event in pygame.event.get():
                            if event.type == pygame.KEYDOWN:
                                if event.key == pygame.K_SPACE:
                                    out = True

        # si se come la manzana
        if snake.position == apple.position:
            score += 1
            apple.nuevaposi()

            if tramaselec == 1:
                nuevo = Snake(trama_secue(textura, 1))
                textura = trama_secue(textura, 2)
            elif tramaselec == 2:
                nuevo = Snake(trama_rand())
            elif tramaselec == 3:
                nuevo = Snake(trama_igual())
            longitud.append(nuevo)

        # si choca con los bordes en X y en Y
        if snake.position[0] < 0 or snake.position[0] >= 800:
            game_over = True
            outgame = True
        if snake.position[1] < 0 or snake.position[1] >= 600:
            game_over = True
            outgame = True

        wn.fill("black")
        # lineas()

        # hace el trazo de todo el cuerpo por cada segmento
        num_segmen = len(longitud)
        for v in range(num_segmen - 1, 0, -1):
            longitud[v].position[0] = longitud[v - 1].position[0]
            longitud[v].position[1] = longitud[v - 1].position[1]
            pygame.draw.rect(
                wn,
                longitud[v].color,
                (longitud[v].position[0], longitud[v].position[1], 20, 20),
            )

        # avanza en X y en Y segun tecla
        snake.position[0] += x_speed
        snake.position[1] += y_speed

        # si choca contra su propio cuerpo
        for x in range(1, num_segmen):
            if snake.position == longitud[x].position:
                game_over = True
                outgame = True

        # si la manzana aparece en el cuerpo que vuelva a aparecer
        for x in range(1, num_segmen):
            if apple.position == longitud[x].position:
                print("aparecio en el cuerpo")
                apple.nuevaposi()

        if forma == 0:
            # manzana en circulo
            pygame.draw.circle(
                wn, "red", (apple.position[0] + 10, apple.position[1] + 10), 10
            )
        if forma == 1:
            # manzana en rectangulo
            pygame.draw.rect(wn, "red", (apple.position[0], apple.position[1], 20, 20))

        # hace el trazo de la cabeza
        pygame.draw.rect(wn, "green", (snake.position[0], snake.position[1], 20, 20))

        # dibuja los ojos
        ojos(direction, snake)

        verhiscore(score)

        if newhiscore:
            txt_score_now = fuente2.render("puntaje " + str(score), True, "red")
        else:
            txt_score_now = fuente2.render("puntaje " + str(score), True, "white")
        wn.blit(txt_score_now, (5, 5))

        pygame.display.update()
        # fps
        clock.tick(10)

    # menu cuando perdas
    while outgame:
        wn.fill("white")

        texto = fuente.render(
            "Perdiste, presiona C para volver a jugar o Q para salir", True, "red"
        )
        txt_score = fuente.render(
            "Tu puntaje fue: " + str(score) + " puntos", True, "red"
        )
        if newhiscore:
            txt_hiscore = fuente.render(
                "Tu puntaje máximo fue: " + str(hiscore) + " puntos", True, "green"
            )
        else:
            txt_hiscore = fuente.render(
                "Tu puntaje máximo fue: " + str(hiscore) + " puntos", True, "red"
            )
        wn.blit(texto, (110, ALTO / 2 - 50))
        wn.blit(txt_score, (ANCHO / 2 - 130, ALTO / 2 - 20))
        wn.blit(txt_hiscore, (ANCHO / 2 - 170, ALTO / 2 + 10))
        wn.blit(
            fuente.render("G para cambiar la forma de la manzana", 0, "red"),
            (ANCHO / 2 - 200, ALTO / 2 + 90),
        )
        wn.blit(
            fuente.render("H para cambiar la trama de la serpiente", 0, "red"),
            (ANCHO / 2 - 200, ALTO / 2 + 110),
        )
        if forma == 0:
            wn.blit(fuente.render("circulo", True, "red"), (0, 0))
        else:
            wn.blit(fuente.render("cuadrado", True, "red"), (0, 0))

        if tramaselec == 1:
            wn.blit(fuente.render("trama secuencia", True, "red"), (0, 20))
        elif tramaselec == 2:
            wn.blit(fuente.render("trama random", True, "red"), (0, 20))
        elif tramaselec == 3:
            wn.blit(fuente.render("trama igual", True, "red"), (0, 20))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                salir()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    salir()
                if event.key == pygame.K_c:
                    gameLoop()
                if event.key == pygame.K_g:
                    if forma == 0:
                        forma = 1
                    else:
                        forma = 0
                if event.key == pygame.K_h:
                    if tramaselec < 3:
                        tramaselec += 1
                    else:
                        tramaselec = 1
        pygame.display.update()


if __name__ == "__main__":
    gameLoop()
