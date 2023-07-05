import pygame
from pygame.locals import *
from pygame.sprite import collide_mask
from sys import exit

KEY_DICT = {
    K_KP0: '0',
    K_KP1: '1',
    K_KP2: '2',
    K_KP3: '3',
    K_KP4: '4',
    K_KP5: '5',
    K_KP6: '6',
    K_KP7: '7',
    K_KP8: '8',
    K_KP9: '9',
    K_PLUS: '+',
    K_KP_PLUS: '+',
    K_MINUS: '-',
    K_KP_MINUS: '-',
    K_SLASH: '/',
    K_KP_DIVIDE: '/',
    K_ASTERISK: ' *',
    K_KP_MULTIPLY: ' *',
    K_PERCENT: '%',
}


def get_trans(path, width=1920, height=1080):
    image = pygame.image.load(path).convert_alpha()
    return pygame.transform.scale(image, (width, height))


class Cord():
    def __init__(self, x, y, vel):
        self.l, self.r, self.u, self.d = False, False, False, False
        self.sx, self.sy = x, y
        self.x, self.y = x, y
        self.vel = vel
        self.lt = 0

    @property
    def Left(self):
        self.x -= self.vel
        self.sx -= self.vel
        self.l = True
        self.lt = 2

    @property
    def Right(self):
        self.x += self.vel
        self.sx += self.vel
        self.r = True
        self.lt = 3

    @property
    def Up(self):
        self.y -= self.vel
        self.sy -= self.vel
        self.u = True
        self.lt = 1

    @property
    def Down(self):
        self.y += self.vel
        self.sy += self.vel
        self.d = True
        self.lt = 0

    @property
    def NoMove(self):
        self.d, self.u, self.l, self.r = False, False, False, False


class Button(pygame.sprite.Sprite):
    def __init__(self, id):
        super().__init__()
        self.id = id
        self.op = "1234567890-+%*/"
        self.image = get_trans(f"img/T{id}m.png")
        self.rect = self.image.get_rect()
        self.mask = pygame.mask.from_surface(self.image)
        self.centroid = self.mask.centroid()
        self.choice = False
        self.press = False

    def update(self):
        self.rect.y = 3 if self.choice else 0
        self.rect.y = 6 if self.press else self.rect.y

    @property
    def get_op(self):
        return self.op[self.id - 1]


class Pillier(pygame.sprite.Sprite):
    def __init__(self, image):
        super().__init__()
        self.image = image
        self.rect = self.image.get_rect()
        self.mask = pygame.mask.from_surface(self.image)


class Player(pygame.sprite.Sprite):
    def __init__(self, x, y, vel, selfm):
        super().__init__()
        self.wR = [pygame.image.load(f"img/s_D{i}m.png") for i in range(1, 9)]
        self.wL = [pygame.image.load(f"img/s_G{i}m.png") for i in range(1, 9)]
        self.wU = [pygame.image.load(f"img/s_B{i}m.png") for i in range(0, 8)]
        self.wD = [pygame.image.load(f"img/s_F{i}m.png") for i in range(0, 8)]
        self.idk = [pygame.image.load(f"img/s_I{i}m.png") for i in range(0, 4)]

        self.image = get_trans("img/Shadow.png", 64, 64)
        self.image.set_alpha(110)

        self.rect = self.image.get_rect()
        self.mask = pygame.mask.from_surface(self.image)

        self.cor = Cord(x, y, vel)
        self.dim_w, self.dim_h = 500, 500
        self.iJ, self.cJ = False, 7
        self.wC = 0
        self.s = selfm

    def move(self, keys):

        self.cor.NoMove
        if keys[pygame.K_LEFT] and self.cor.x > self.cor.vel - 150:
            self.cor.Left
        elif keys[pygame.K_RIGHT] and self.cor.x < self.s.width - self.cor.vel - (self.dim_w - 150):
            self.cor.Right
        elif keys[pygame.K_UP] and self.cor.y > self.cor.vel:
            if self.dim_change(-1, 470, 700):
                self.cor.Up
        elif keys[pygame.K_DOWN] and self.cor.y < self.s.height - self.cor.vel - (self.dim_h - 50):
            if self.dim_change(1, 470, 700):
                self.cor.Down
        self.jump(keys)

    def dim_change(self, change, mn, mx):
        if mn <= self.dim_h + change <= mx:
            self.dim_w += change
            self.dim_h += change
            return 1
        return 0

    def jump(self, keys):
        self.aT = False
        if not(self.iJ):
            if keys[pygame.K_SPACE]:
                self.cor.NoMove
                self.iJ, self.wC = True, 0
        else:
            if self.cJ >= -7:
                self.cor.y -= (self.cJ * abs(self.cJ)) * 0.5
                self.cJ -= 1
            else:
                self.cJ, self.iJ = 7, False
                self.aT = True

    def move_print(self):
        choice = None
        data = [[self.cor.l, self.wL], [self.cor.r, self.wR],
                [self.cor.u, self.wU], [self.cor.d, self.wD]]
        if self.wC + 1 >= 9:
            self.wC = 0
        for co, wo in data:
            if co:
                choice = wo[self.wC]
                self.wC += 1
                break
        else:
            choice = self.idk[self.cor.lt]

        transform = pygame.transform.scale(choice, self.dim_getter)
        self.s.display.blit(transform, (self.cor.x, self.cor.y))

    def update(self, keys):
        self.move(keys)
        self.rect.x = self.cor.sx+self.dim_w//2.30
        self.rect.y = self.cor.sy+self.dim_h//1.15
        self.move_print()

    def collide_pil(self):
        rect1 = {"x": 5, "y": 5, "width": 50, "height": 50}
        rect2 = {"x": 20, "y": 10, "width": 10, "height": 10}

    @property
    def dim_getter(self):
        return (self.dim_w, self.dim_h)


class Board():
    def __init__(self, color, x, y, width, height, text=''):
        self.font = pygame.font.Font('./Puzzle-Tale-Pixel-Regular.ttf', 60)
        self.color = color
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.text = text
        self.text2 = ""

    def draw(self, win, outline=None, only_text=False):
        # Call this method to draw the button on the screen
        ptext = self.text + self.text2
        if not only_text:
            if outline:
                pygame.draw.rect(
                    win, outline, (self.x - 2, self.y - 2, self.width + 4, self.height + 4), 0)

            pygame.draw.rect(win, self.color, (self.x, self.y,
                             self.width, self.height), 0)

        if ptext != '':
            self.box_text(win, ptext)

    def box_text(self, win, text, color=Color('black')):
        x = self.x
        y = self.y
        words = list(text)

        for word in words:
            word_t = self.font.render(word, True, color)
            if word_t.get_width() + x <= (self.x + self.width):
                win.blit(word_t, (x, y))
                x += word_t.get_width() + 2
            else:
                y += word_t.get_height() + 4
                x = self.x
                win.blit(word_t, (x, y))
                x += word_t.get_width() + 2

    def isOver(self, pos):
        # Pos is the mouse position or a tuple of (x,y) coordinates
        if pos[0] > self.x and pos[0] < self.x + self.width:
            if pos[1] > self.y and pos[1] < self.y + self.height:
                return True
        return False


class Game():
    def __init__(self, width=1920, height=1080, fps=60):
        self.width, self.height, self.fps = width, height, fps
        flags = FULLSCREEN | DOUBLEBUF | HWSURFACE
        self.display = pygame.display.set_mode((width, height), flags, 16)
        self.load_images()
        self.player = Player(width//2, height//2, 13, self)
        self.touch = None

    def load_images(self):
        self.wallpaper = get_trans("img/All_Together.png")
        self.wall = [get_trans(f"img/bk-{i}.png") for i in range(1, 3)]
        self.buttons = list(map(Button, range(1, 16)))

    def init_pygame(self):
        pygame.init()
        pygame.event.set_allowed([QUIT, KEYDOWN, KEYUP])
        self.font = pygame.font.Font('./Puzzle-Tale-Pixel-Regular.ttf', 45)
        self.clock = pygame.time.Clock()

    def draw(self, phase):
        if phase == 1:
            self.display.blit(self.wallpaper, (0, 0))
            self.button_sprite.draw(self.display)
            self.active_sprite.draw(self.display)
        elif phase == 2:
            player, display = self.player, self.display
            cen = (167 <= player.cor.sx <= 1272) and player.cor.sy >= 332
            out = player.cor.sy >= 449
            if (not cen and not out):
                display.blit(self.wall[0], (0, 0))
            display.blit(self.wall[1], (0, 0))

    def calc(self, board):
        try:
            evl = board.text.replace('/', '//')
            res = eval(evl)
        except:
            res = "Invalide"
        board.text2 = f"={res}"

    def render(self, fps):
        text_to_show = self.font.render(str(int(fps)), 0, Color('Black'))
        self.display.blit(text_to_show, (0, 0))

    def main(self):
        self.init_pygame()

        self.active_sprite = pygame.sprite.Group()
        self.button_sprite = pygame.sprite.Group()

        list(map(self.button_sprite.add, self.buttons))
        self.active_sprite.add(self.player)

        board = Board(Color('black'), 520, 50, 900, 420)
        while True:
            player = self.player
            self.draw(1)
            board.draw(self.display, only_text=True)
            self.render(self.clock.get_fps())
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    exit()
                if event.type == pygame.KEYDOWN:
                    keys = pygame.key.get_pressed()
                    if keys[K_BACKSPACE]:
                        if len(board.text):
                            board.text = board.text[:-1]
                            board.text2 = ""
                    for key, val in KEY_DICT.items():
                        if keys[key]:
                            board.text += val
                            break

            self.button_sprite.update()
            player.update(pygame.key.get_pressed())

            px, py = player.mask.centroid()
            choice = [float('inf'), None]
            for btn in self.button_sprite.sprites():
                btn.choice = False
                btn.press -= 1 if btn.press else 0
                if not btn.press and not player.iJ:
                    if collide_mask(player, btn):
                        bx, by = btn.centroid
                        dist = (px - bx)**2 + (py - by)**2
                        choice[0] = dist if dist <= choice[0] else choice[0]
                        choice[1] = btn if dist <= choice[0] else choice[1]
            if choice[1] is not None:
                choice[1].choice = True
                if player.aT:
                    choice[1].press = 5
                    board.text += choice[1].get_op
            if len(board.text):
                self.calc(board)
            self.draw(2)
            self.clock.tick(self.fps)
            pygame.display.update()


if __name__ == '__main__':
    game = Game()
    game.main()
