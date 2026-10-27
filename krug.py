import math
import matplotlib.pyplot as plt

class Tacka:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Krug:
    def __init__(self, cx, cy, r):
        self.cx = cx
        self.cy = cy
        self.r = r

    def crtaj(self, t):
        fig, ax = plt.subplots(figsize=(5, 5))
        
        # 1. Crtanje plave kružnice
        ax.add_patch(plt.Circle((self.cx, self.cy), self.r, fill=False, color='blue', linewidth=2))
        
        # 2. Crtanje tačke (uvek je crvena)
        ax.scatter(t.x, t.y, color='red', s=100)

        # Podešavanje ekrana da krug bude pravilan
        ax.set_aspect('equal')
        ax.grid(True, linestyle='--')
        
        # Prikaz na ekranu sajta
        plt.show()

# --- Pokretanje ---
krug = Krug(0, 0, 5)   # Centar (0,0), poluprečnik 5
tacka = Tacka(3, 4)        # Zadata tačka

krug.crtaj(tacka)
