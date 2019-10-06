import pygame, sys
import numpy as np
from random import randint

ON = 1
OFF = 0

class GameOfLife:
    def __init__(self, width=100, height=100):
        self.width = width
        self.height = height
        self.state_new = np.zeros((height, width))
        self.state_old = np.zeros((height, width))

    def get_width(self):
        return self.width

    def get_height(self):
        return self.height

    def get_state_old(self, x, y):
        return self.state_old[y, x]

    def get_state_new(self, x, y):
        return self.state_new[y, x]


    def num_neighbors_with_state(self, x, y, required_state):
        res = 0

        for i in range(max(0, x-1), min(x+1, self.width-1)+1):
            for j in range(max(0, y-1), min(y+1, self.height-1)+1):
                if i == x and j == y:
                    continue
                if self.get_state_old(i, j) == required_state:
                    res += 1
        return res

    def set_square_state(self, x, y, st):
        self.state_new[y, x] = st

    def iterate_state(self):
        self.state_old = np.copy(self.state_new)

        for j in range(self.height):
            for i in range(self.width):
                cur_state = self.get_state_old(i, j)
                numberOfOnNeighbors = self.num_neighbors_with_state(i,j,ON)
                if cur_state == OFF and numberOfOnNeighbors == 3:
                    self.set_square_state(i, j, ON)
                elif cur_state == ON and (numberOfOnNeighbors < 2 or numberOfOnNeighbors > 3):
                    self.set_square_state(i, j, OFF)



def main():
    #screen dimensions
    size = width, height = 1000, 1000

    black = (0, 0, 0)
    white = (255, 255, 255)

    screen = pygame.display.set_mode(size)

    life = GameOfLife(int(width/10), int(height/10))

    size_x = width / life.get_width()
    size_y = height / life.get_height()

    num_live_cells = randint(280, 380)
    for n in range(num_live_cells):
        i, j = randint(int(life.get_width()/5), int(3*life.get_width()/4)), randint(int(life.get_height()/5), int(3*life.get_height()/4))
        life.set_square_state(i, j, ON)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.fill(black)
        scaled_x, scaled_y = 0, 0
        for j in range(life.get_height()):
            for i in range(life.get_width()):
                scaled_x = (i / life.get_width()) * width
                scaled_y = (j / life.get_height()) * height

                state = life.get_state_new(i, j)

                color = black
                if state == ON:
                    color = white

                pygame.draw.rect(screen, color, pygame.Rect(scaled_x, scaled_y, size_x, size_y))

        pygame.time.wait(50)
        pygame.display.flip()
        life.iterate_state()

if __name__ == "__main__":
    main()
