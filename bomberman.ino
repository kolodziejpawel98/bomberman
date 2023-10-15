#include <Gamebuino-Meta.h>
#include "player.hpp"

void setup()
{
    gb.begin();
    gb.setFrameRate(60);
}

void loop()
{
    while (!gb.update())
    {
    }
    gb.display.clear();
    xd();
}

// /import pygame

// # Inicjalizacja Pygame
// pygame.init()

// # Ustawienia ekranu
// screen_width, screen_height = 800, 600
// screen = pygame.display.set_mode((screen_width, screen_height))
// pygame.display.set_caption("Gra Topdown")

// # Kolor tła
// bg_color = (255, 255, 255)

// # Postać
// player_x, player_y = screen_width // 2, screen_height // 2
// player_speed = 200.0  # Prędkość postaci (piksele na sekundę)
// player_speed_x, player_speed_y = 0.0, 0.0  # Składowe prędkości

// # Czas
// clock = pygame.time.Clock()
// delta_time = 0.0

// # Główna pętla gry
// running = True

// while running:
//     for event in pygame.event.get():
//         if event.type == pygame.QUIT:
//             running = False

//     # Obliczanie czasu od ostatniej klatki
//     delta_time = clock.tick(60) / 1000.0  # Przeliczamy na sekundy

//     # Obliczanie nowej pozycji postaci
//     keys = pygame.key.get_pressed()

//     if keys[pygame.K_w]:
//         player_speed_y = -player_speed
//     elif keys[pygame.K_s]:
//         player_speed_y = player_speed
//     else:
//         player_speed_y = 0.0

//     if keys[pygame.K_a]:
//         player_speed_x = -player_speed
//     elif keys[pygame.K_d]:
//         player_speed_x = player_speed
//     else:
//         player_speed_x = 0.0

//     player_x += player_speed_x * delta_time
//     player_y += player_speed_y * delta_time

//     # Wyczyszczenie ekranu
//     screen.fill(bg_color)

//     # Narysowanie postaci
//     player_rect = pygame.Rect(player_x, player_y, 20, 20)  # Przykładowy rozmiar postaci
//     pygame.draw.rect(screen, (0, 0, 255), player_rect)

//     pygame.display.flip()

// # Zakończenie Pygame
// pygame.quit()
