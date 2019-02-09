# Arcade-RPG
This is a simulation of an RPG(role playing game) written in C++.

The game has spells, heroes and monsters. Heroes and monsters live in a world that 
is represented by a grid. Heroes can be involved in battles with monsters and use 
objects and spells to defeat them, or they can buy items to help them in their adventure.
Every time the heroes defeat some monsters gather some money and gain experience. When 
they have enough experience, the heroes level-up, which means that they become stronger 
in their individual abilities.

At a given moment the group of heroes (at least one and at most three) are in some
square of the grid and can be moved one square up, down, right or left (by w,a,s,d keys). 
Some grid squares may not be accessible by heroes or may have a market, where they can
buy or sell items and spells.

Every time heroes visit a common square, there is a chance that they get involved in a battle
with monsters of a similar level to that of heroes. The battle takes place in rounds,
starting with the heroes, and does not stop until the hp of all monsters or all heroes reaches zero.
If the heroes win, they get rewarded with coins and experience. If they lose, they lose half of their coins.
All heroes as well as the monsters regenerate in each round some amount of their hp,
unless it has reached zero. Also, heroes regenerate an amount of mp.

Compilation:
make

Execution:
./demo

Once the game starts, you can press G at any time to display the controls.

Enjoy :)

-------------------------
Contributors: Costas Pitharoulios, Simon Iyamu.
This project was one of our assignments in the Object Oriented Programming course in 2017.
