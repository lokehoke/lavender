import pyglet
import pyrr
from pyglet.gl import *
from pyglet.window import mouse

import core
import database


class OrthoCamera:
    def __init__(self):
        self.pos = pyrr.Vector3([0.0, 0.0, 0.0])
        self.zoom = 1.0
        self.width = 1.0
        self.height = 1.0

    def set_transform(self):
        transform = pyrr.Matrix44(
            [
                [self.zoom * 2 / self.width, 0, 0, 0],
                [0, self.zoom * 2 / self.height, 0, 0],
                [0, 0, 0, 0],
                [-1 + 2 * self.pos[0] / self.width, -1 + 2 * self.pos[1] / self.height, 0, 1]
            ]
        )
        tmp = transform.flatten()
        glLoadMatrixf((GLfloat * len(tmp))(*tmp))


def draw_rect(top_left, bottom_right):
    glBegin(GL_TRIANGLES)

    glVertex2f(top_left[0], top_left[1])
    glVertex2f(top_left[0], bottom_right[1])
    glVertex2f(bottom_right[0], bottom_right[1])

    glVertex2f(top_left[0], top_left[1])
    glVertex2f(bottom_right[0], bottom_right[1])
    glVertex2f(bottom_right[0], top_left[1])

    glEnd()


class GraphRenderer:
    def __init__(self):
        self._camera = OrthoCamera()

    def draw_node(self):
        glColor3f(1.0, 1.0, 1.0)
        draw_rect([20, 120], [60, 100])

    def draw(self):
        glPushMatrix()
        self._camera.set_transform()

        label = pyglet.text.Label("Hello world")
        label.draw()

        self.draw_node()

        glPopMatrix()

    def translate_view(self, delta):
        self._camera.pos += delta

    def zoom_view(self, delta):
        self._camera.zoom += delta[0] / 40
        self._camera.zoom = min(2.0, self._camera.zoom)
        self._camera.zoom = max(0.5, self._camera.zoom)

    def set_screen_size(self, width, height):
        self._camera.width = width
        self._camera.height = height


class LavenderWindow(pyglet.window.Window):
    def __init__(self, drawable, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._drawable = drawable

    def on_draw(self):
        self._drawable.set_screen_size(self.width, self.height)
        glClear(GL_COLOR_BUFFER_BIT)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        self._drawable.draw()

    def on_mouse_drag(self, x, y, dx, dy, buttons, modifiers):
        delta = pyrr.Vector3([dx, dy, 0])

        if buttons & pyglet.window.mouse.MIDDLE:
            self._drawable.translate_view(delta)
        if buttons & pyglet.window.mouse.RIGHT:
            self._drawable.zoom_view(delta)


def launch():
    core.init()
    module_store = core.get_plugin_store()

    database.init(module_store)

    graph_renderer = GraphRenderer()
    window = LavenderWindow(graph_renderer, width=1000, height=600)

    pyglet.app.run()


if __name__ == "__main__":
    launch()
