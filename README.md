# Game of Group 169 

## Team Meambers: 

pleituer: Lui Peter Hong Zhi

Unichoco: Chang Kwan Jack

Caijiahui0715: Cai Jiahui

frank719: Yao Yao

solid-wind: Chan Kin Richard


## Control

At first you will be greeted with the Main Menu, press up and down arrow key to naviage through the buttons, press space to select the buttons, it is recommended to check out the Help button for more information.

Here is a list of all the controls in game:

- Move around: WASD or Up Down Left Right
- Place markers: X
- Remove markers: Y
- Quit Game: Q
- Go back to Main Menu: B
- When in the selection screen, press number keys to type in the Level ID you want to play, Backspace to delete a character, Space to confirm selection and Paly the Level!
- Other controls will be mentioned next to the button, For example:
    
    Button [A]
    
    In this case, you will have to press the key A to select the button

## How To Play

You are the character in the maze, there are walls and passages, your goal is to find the end of the maze (denoted by a red and white target square)

You can select your own levels to play by typing in the level ID (from 0 to 999999) in the Selection Menu. As the level ID increases, the Maze will get harder. 

Mazes you have completed will be saved and can be resetted via a Reset button in the Main Menu (a comfirmation screen will appear)

## Features

- Fully compatible with Linux, Mac, and Windows
- Mazes are totally random
- Size of mazes varies and can get as large as 999 by 799
- All levels completed will be saved even after quitting the game
- A lot of STL containers like \<vector\> are used, especially in Maze generating
- Custom structs and classes are created to store all sorts of information
- There are a lot of files and making the MakeFile is a horrific experience

## Non-standard Libraries

Fact: No 3rd-party library is used, not even \<ncurses\>

## Quick Start

Type `make` to compile the files

Then type `./main` to execute the game (you might have to make fonts the terminal smaller and your terminal size larger)

You can type `make clean` to delete the `.o` files in Linux and Mac, or `make cleanw` in Windows 

Note: When playing, sometimes hitboxes are a bit weird and you might get stuck, please randomly move your charatcer to get around
