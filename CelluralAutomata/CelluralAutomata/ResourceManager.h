#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <thread>
#include <memory>
#include <functional>


inline int ScreenWidth = 1920;
inline int ScreenHeight = (ScreenWidth/16)*10;

inline sf::Vector2f scale((ScreenWidth / ScreenHeight) * 2, (ScreenWidth / ScreenHeight) * 2);

inline int MoveSpeed = 300;
inline sf::Time speed = sf::seconds(1.);

inline float CursorSize = 1.f;

inline bool moved = false;

inline std::string filename = "testmap";

inline sf::Image worldImg;
inline sf::Texture mapTxt;
inline sf::RectangleShape mapshape;
inline sf::Image bufferworldImg;

inline sf::Image empires;

inline int width;
inline int height;

inline sf::Font defaultfont;

inline sf::Vector2f focusCoord;

inline uint32_t fullscreen;
inline bool fullscreenBR = false;

inline sf::Clock animateTime;
inline sf::Time elapsed;

inline int testingColor = 0;

inline sf::Image colorbars;

