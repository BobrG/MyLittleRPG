# MyLittleRPG.
First try to write a computer RPG-game on C++;

# Explanation of central idea:
My game was designed as merge of two well-known RPG games - "Dungeon & Dragons" and "The Banner Saga". The main idea of the
game was to complete all dungeons and to reach the highest level of character. This game was a challenge to create smartly designed c++ rpg game with usage of classes and OOP;

# Game menu.
Game menu containes:
1. Unit menu - the window with description of choosen character, all his stats, special abilities and inventory;
2. Dungeons - the section which provides description of each **Dungeon** possible to enroll and demands for completing it. Here user can choose and complete the favorable **Dungeon**;
3. Arena - the section which provides ability to increse unit's level by fighting on the **Arena** in two variable modes: **Single battle** and **Team battle**;
4. Exit game.

# Battle.
In my game I've tried to create a step-to-step battle. Each battle is characterized by next parameters:
- *stamina* - is required to produce damage with weapon. Depends on the type of weapon, or unit's side effects;
- *inspiration* - is required to produce affection with *special skills*. Diffecrent skills require various amount of *inspiration*; 
- *initiation* - defines the order in which unit's battle. Depends on the unit's special characteristics;
Amout of *stamina* grows with every step and decreases with each attack, except *special skills*.
Inspiration grows with every simple attack and decreases with every use of *special skill*;
Each character can use one of type of attack:
1. Normal attack - *Slice*(1.1) and *Smash*(1.2) (increases *inspiration*)
   Randomizes special effect of weapon.
   Requres fixed amount of *stamina*
 2.Special class attack (requires amount of *inspiration*)
3.Use a special item.
Comments:
1.1 - the target is health points of unit and this type of attack requires more *stamina* than *Smash*;
1.2 - the target is defence points of unit and this type of attack requires less *stamina* tha *Slice*;

I considered two types of battle:
- Single battle.
- Team battle.

(Single battle underlies the team battle)

The actual battle follows next rules:
1. On each step both units - player and opponent are provided to choose an attack.
2. Every character can produce side affection which is taken into account.

# Buffs
(aka special effects)

# Characters.
(aka Units)
Game contains five types of characters:
- Berserk - Warrior;
- Wizard;
- Paladin;
- Defender;
- Demon Slayer;
(all names are still in progress of consideration!)
