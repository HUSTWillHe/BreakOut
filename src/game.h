/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <glad.h>
#include <glfw3.h>

#include "game_level.h"
#include "ball_object.h"
#include "particle_generator.h"
#include "post_processor.h"
#include "power_up.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // Game state
    GameState              State;	
    GLboolean              Keys[1024];
    GLuint                 Width, Height;
	std::vector<GameLevel> Levels;
	GLuint                 Level;
	std::vector<PowerUp>   PowerUps;
    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();
    // Initialize game state (load all shaders/textures/levels)
    void Init();
    // GameLoop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
	void DoCollisions();
	// Reset
    void ResetLevel();
    void ResetPlayer();
	void SpawnPowerUps(GameObject &block);
	void UpdatePowerUps(GLfloat dt);
};

#endif