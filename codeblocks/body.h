#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "world.h"

/**
 * Enumération pour attribuer un type à un corps
 */
enum Layer {
    Player, Enemy, Ball, Item, Easy, Hard, Retry
};
typedef enum Layer Layer;

struct Vector {
    float x;
    float y;
};
typedef struct Vector Vector;

struct Body {
    float velocity;
    Uint32 color;
    SDL_Surface *surface;
    SDL_Rect transform;
    Vector direction;
    Layer layer;
};
typedef struct Body Body;


Body *createBody(int x, int y, int w, int h, float velocity, Uint32 color, Layer layer);
void updateBodyPhysics(Body *body);
void drawBody(SDL_Renderer *screen, Body *body);

void limitPosition(Body *body);

void moveUp(Body *body);
void moveDown(Body *body);
void moveLeft(Body *body);
void moveRight(Body *body);
void destroyBody(Body *body);
bool isOffScreen(Body *body);
void follow(Body *follower, Body *followed);

#endif