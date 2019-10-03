import pygame, sys
import numpy as np
from random import randint

ON = 2
RESTING = 1
OFF = 0

class BriansBrain:
    def __init__(self, width=100, height=100, scale=5):
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
                if cur_state == OFF and (self.num_neighbors_with_state(i, j, ON) == 2):
                    self.set_square_state(i, j, ON)
                elif cur_state == ON:
                    self.set_square_state(i, j, RESTING)
                elif cur_state == RESTING:
                    self.set_square_state(i, j, OFF)



def main():
    #screen dimensions
    size = width, height = 1000, 1000

    black = (0, 0, 0)
    white = (255, 255, 255)
    grey = (110, 110, 170)

    screen = pygame.display.set_mode(size)

    brain = BriansBrain(int(width/10), int(height/10))

    size_x = width / brain.get_width()
    size_y = height / brain.get_height()

    num_cells = randint(80, 100)
    for n in range(num_cells):
        i, j = randint(int(brain.get_width()/3), int(2*brain.get_width()/3)), randint(int(brain.get_height()/3), int(2*brain.get_height()/3))
        brain.set_square_state(i, j, 2)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.fill(black)
        scaled_x, scaled_y = 0, 0
        for j in range(brain.get_height()):
            for i in range(brain.get_width()):
                scaled_x = (i / brain.get_width()) * width
                scaled_y = (j / brain.get_height()) * height

                color_n = brain.get_state_new(i, j)

                color = black
                if color_n == 1:
                    color = grey
                elif color_n == 2:
                    color = white

                pygame.draw.rect(screen, color, pygame.Rect(scaled_x, scaled_y, size_x, size_y))

        pygame.display.flip()
        brain.iterate_state()

if __name__ == "__main__":
    main()
